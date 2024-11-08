#!/bin/bash

# Git 저장소 위치
REPO_DIR="/home/hrkim/BloodGlucoseMeterPortable_RE1"

# 커밋 메시지
COMMIT_MESSAGE="자동 커밋: $(date +'%Y-%m-%d %H:%M:%S')"

# Git 명령어 실행
cd "$REPO_DIR" || { echo "Git 저장소 경로를 찾을 수 없습니다."; exit 1; }

# 변경 사항 추가 및 커밋
git add .
git commit -m "$COMMIT_MESSAGE"

# (선택) 원격 저장소에 푸시
# git push origin main

echo "자동 커밋 완료: $COMMIT_MESSAGE"
