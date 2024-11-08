#!/bin/bash

# Git 저장소 위치
REPO_DIR="/home/hrkim/BloodGlucoseMeterPortable_RE1"

# 커밋 메시지
COMMIT_MESSAGE="자동 커밋: $(date +'%Y-%m-%d %H:%M:%S')"

# Git 저장소로 이동
cd "$REPO_DIR" || { echo "Git 저장소 경로를 찾을 수 없습니다."; exit 1; }

# Git 변경 사항 추가 및 커밋
git add .
git commit -m "$COMMIT_MESSAGE"

# 원격 저장소와 관련된 작업 제거
# git push origin main

echo "자동 커밋 완료: $COMMIT_MESSAGE"
