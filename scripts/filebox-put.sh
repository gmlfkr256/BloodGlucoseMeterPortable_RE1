#!/bin/sh
# filebox-put.sh <파일> <대상경로> — 리전 파일함(files.mooncatdev.com) 업로드, 맥·리눅스 범용판.
# 2026-09-18 리전(XW-0223) · 2026-09-28 개정(XW-0272 후속): autoFactory 판의 개선 2종을 되받았다.
#   1. 대상경로 접두 검사 — 이 기기 몫이 아닌 폴더로는 올라가지 않는다(조용한 오배치 방지).
#   2. 비밀번호·토큰을 명령줄(ps)에 드러내지 않는다 — 헤더 파일과 표준입력으로만 curl 에 넘긴다.
# 2026-10-01 임베디드판(XW-0330): 파일함 mac/filebox-put.sh 범용판에서 ALLOW_DEFAULT 와 자격 경로 두 줄만 바꿨다.
#   계정 `embedded`(XW-0329): 생성·수정·다운로드만, 삭제·공유 불가. Access 서비스 토큰 만료 2027-10-01.
#
# 대상경로는 파일함 루트 기준 **전체 경로**입니다(접두를 벗기지 않습니다).
#   예: "embedded/출처.md" · "embedded/배포/Blood_glucose_meter_portable-20260820.bin"
# 같은 이름은 덮어씁니다. 30MiB 상한(그 이상은 리전에 문의).
#
# 이 기기가 올릴 수 있는 최상위 폴더 — 기기마다 이 한 줄만 바꿉니다.
#   (일시적으로 바꾸려면 환경변수 FILEBOX_ALLOW="폴더1 폴더2")
ALLOW_DEFAULT="embedded"
#
# 준비 — 자격은 Hr 가 이 기기에 한 번 넣습니다(세션끼리 주고받지 않습니다):
#   ~/.config/embedded/filebox.env (600, 폴더 700) 에 5줄:
#     FILEBOX_URL  FILEBOX_USER  FILEBOX_PASS  CF_ACCESS_CLIENT_ID  CF_ACCESS_CLIENT_SECRET
#   경로를 바꾸려면 FILEBOX_ENV 로 지정합니다.
#
# 권한: 계정은 생성·수정만 가능하고 삭제·공유는 막혀 있습니다. 잘못 올린 파일은 리전에 지워 달라고 합니다.
# 주의: 파일함 API 를 python urllib 로 부르면 Cloudflare 1010 으로 403 이 납니다 — curl 만 씁니다.
#       파일함은 읽기·목록에 인증이 없습니다 — 자격·토큰이 든 파일은 올리지 않습니다.
# 필요: curl 7.71 이상(-H @파일 · --retry-all-errors), python3.
set -eu
[ $# -eq 2 ] || { echo "사용법: $0 <파일> <대상경로>   예: $0 ./출처.md embedded/출처.md" >&2; exit 2; }
f="$1"; dest="$2"
[ -f "$f" ] || { echo "[filebox-put] 파일이 없습니다: $f" >&2; exit 1; }

# 대상경로 검사 — 허용 폴더로 시작해야 하고, 위로 거슬러 가는 조각(..)은 받지 않는다
top="${dest%%/*}"
[ "$top" != "$dest" ] || { echo "[filebox-put] 대상경로에 폴더가 없습니다(루트에 올라감): $dest" >&2; exit 2; }
case "/$dest/" in
    */../*|*/./*|*//*) echo "[filebox-put] 대상경로에 '..'·'.'·빈 조각이 있습니다: $dest" >&2; exit 2 ;;
esac
ok=0
for a in ${FILEBOX_ALLOW:-$ALLOW_DEFAULT}; do
    [ "$top" = "$a" ] && ok=1
done
[ "$ok" -eq 1 ] || { echo "[filebox-put] 이 기기는 '$top/' 에 올리지 않습니다 (허용: ${FILEBOX_ALLOW:-$ALLOW_DEFAULT})" >&2; exit 2; }

size=$(wc -c < "$f")
[ "$size" -le 31457280 ] || { echo "[filebox-put] 30MiB 상한 초과($size bytes) — 분할하거나 리전에 문의하세요." >&2; exit 1; }

ENVF="${FILEBOX_ENV:-$HOME/.config/embedded/filebox.env}"
[ -f "$ENVF" ] || { echo "[filebox-put] 자격 파일 없음: $ENVF" >&2; exit 3; }
. "$ENVF"
: "${FILEBOX_URL:?}" "${FILEBOX_USER:?}" "${FILEBOX_PASS:?}" "${CF_ACCESS_CLIENT_ID:?}" "${CF_ACCESS_CLIENT_SECRET:?}"

umask 077
tmp=$(mktemp -d)
trap 'rm -rf "$tmp"' EXIT INT TERM
HDR="$tmp/h"
printf 'CF-Access-Client-Id: %s\nCF-Access-Client-Secret: %s\n' \
    "$CF_ACCESS_CLIENT_ID" "$CF_ACCESS_CLIENT_SECRET" > "$HDR"

R="--retry 3 --retry-delay 2 --retry-all-errors --connect-timeout 15"   # 같은 이름 덮어쓰기라 다시 보내도 안전
FILEBOX_USER="$FILEBOX_USER" FILEBOX_PASS="$FILEBOX_PASS" python3 -c \
    'import json,os; print(json.dumps({"username": os.environ["FILEBOX_USER"], "password": os.environ["FILEBOX_PASS"], "recaptcha": ""}))' \
    > "$tmp/login.json"
tok=$(curl -fsS $R --max-time 20 -H @"$HDR" -H 'Content-Type: application/json' \
      -X POST "$FILEBOX_URL/api/login" --data-binary @"$tmp/login.json")
printf 'X-Auth: %s\n' "$tok" >> "$HDR"

q() { python3 -c 'import sys,urllib.parse; print("/".join(urllib.parse.quote(s) for s in sys.argv[1].split("/") if s))' "$1"; }
dir=$(dirname "$dest")
if [ "$dir" != "." ]; then   # 상위 폴더 보장 — 이미 있으면 409 가 나며 정상입니다
    curl -sS -o /dev/null -H @"$HDR" -X POST "$FILEBOX_URL/api/resources/$(q "$dir")/" || true
fi
curl -fsS $R --max-time 600 -o /dev/null -H @"$HDR" -H 'Content-Type: application/octet-stream' \
     -X POST "$FILEBOX_URL/api/resources/$(q "$dest")?override=true" --data-binary @"$f"
echo "[filebox-put] OK -> $dest ($size bytes)"
