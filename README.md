# BloodGlucoseMeterPortable_RE1
- Device Happyzone 프로젝트입니다.

## 프로젝트 관리요령
- 이 프로젝트는 Git을 기반으로 구조적 관리를 진행하고 있으며, 아래 기준을 따릅니다.
---
### 브랜치 전략
- `main`: 실제 배포 가능한 안정화 버전만 유지합니다.
- `develop`: 기능 병합 및 테스트용 통합 브랜치입니다.
- `feature/*`: 기능 단위 작업 브랜치입니다. 예: `feture/login`
- `bugfix/*`, `hotfix/*`: 긴급 수정 시 사용합니다.
---
### 커밋 메시지 규칙 (Conventional Commits)
- `feat`: 새로운 기능 추가
- `fix`: 버그 수정
- `docs`: 문서 변경
- `style`: 코드 포맷팅, 세미콜론 누락 등 (로직 변화 없음)
- `refactor`: 코드 리팩토링 (기능 변화 없음)
- `chore`: 빌드 설정, 패키지 설정, 기타 자잘한 작업

- 예시
```bash
git commit -m "feat: 로그인 버튼 이벤트 연결"
```
---
## 수정 작업 시작 전 절차
- 수정 또는 기능 개발을 시작할 때는 아래 절차를 따릅니다.
- 모든 기능 개발은 `develop` 브랜치를 기준으로 시작합니다.
- 하지만 `main` 브랜치에 먼저 병합된 변경사항이 있을 수 있음으로,
- 항상 `develop`을 최신 상태로 갱신한 뒤 작업을 시작해야 합니다.
- 백업 루틴을 항상 실행합시다.


### 1. `develop` 브랜치를 최신화합니다. (항상 실행)
```bash
git checkout develop

git branch backup/develop_before_merge_$(date +%Y%m%d_%H%M%S)

git fetch origin
git merge origin/main
git pull origin develop
git push origin develop
```

- 다른 팀원이 먼저 올린 변경사항을 기반으로 작업해야 충돌을 줄일 수 있습니다.


### 2. 새로운 기능 브랜치 생성
- 수정할 기능이나 작업 단위를 명확히 하여 별도의 브랜치를 만듭니다.
```
git checkout -b feature/기능 이름
```

- 예시
```bash
git checkout -b feature/setting-page
```

- 브랜치를 왜 나누나요?
  - 작업 내용을 분리하면 기능별로 개발, 리뷰, 테스트, 배포가 쉬워지고, 실수도 줄어듭니다.


### 3. 실제 코드 수정 및 테스트
- 이제 로컬에서 원하는 기능을 구현하거나 버그를 수정합니다.
  - IDE 또는 에디터에서 코드 작성
  - 실행 테스트 또는 디버깅 진행
  - 변경된 파일이 저장되었는지 확인

```bash
git status
```


### 4. 변경사항 커밋 (메시지 규칙 지키기)
- 수정이 끝났다면 Git에 작업 내역을 저장(커밋)합니다
```bash
git add . # 모든 변경 파일 스테이지에 올리기
git commit -m "feat: 설정 페이지 UI 구성" # 작업 내용을 요약해 작성
```
- 메시지 규칙은 상단 내용을 참조


### 5. 최신 develop 내용 병합 (충돌 방지용)
- 작업 중간에 `develop` 브랜치가 업데이트되었을 수 있으니, 최신 내용을 병합합니다.
```bash
git fetch origin # 원격 저장소 정보 최신화
git merge origin/develop # 현재 작업 브랜치에 병합
```

- 충돌 발생시
  - 충돌 메시지가 뜨면 직접 파일 수정 후(수동수정),
```bash
git add 충돌수정파일
git commit
```


### 6. 작업 브랜치를 원격 저장소에 업로드
- 내 작업을 GitHub로 올려서 공유하거나 나중에 PR을 만들 수 있게 합니다.
```bash
git push -u origin feature/기능이름
```

- 예시
```bash
git push -u origin feature/settings-page
```
- `-u`옵션은 다음부터 `git push`만으로도 같은 브랜치를 자동 추적하도록 설정

- 흐름 요약

```bash
# 1. 최신 develop 가져오기
git checkout develop
git pull origin develop

# 2. 작업용 브랜치 만들기
git checkout -b feature/기능명

# 3. 코드 수정

# 4. 커밋
git add .
git commit -m "feat: 기능 설명"

# 5. 최신 develop 반영
git fetch origin
git merge origin/develop

# 6. 원격 저장소로 push
git push -u origin feature/기능명
```

