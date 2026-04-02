# CLAUDE.md

Happyzone 브랜드 휴대용 혈당측정기 임베디드 GUI. Qt Widgets (C++11), 리눅스 임베디드 (iMX 계열).

## 작업 시작

- 반드시 이 Notion 페이지를 조회하여 프로젝트 컨텍스트를 확인할 것
- URL: https://www.notion.so/322dad42c86881339e6edf4b03570a3a
- 공통 작업 규칙: https://www.notion.so/327dad42c86881658ff7fb031b6f19b1
- 다른 프로젝트 참조 필요 시 페이지 상단 "중앙 허브" 링크 활용
- 워크트리 진입점 섹션에 활성 워크트리가 있으면 복원 후 작업 이어갈 것
- 세션 종료 시 워크트리 정보를 Notion 워크트리 진입점 섹션에 기록할 것

## 빌드

```bash
mkdir -p build_test && cd build_test
qmake ../BloodGlucoseMeterPortable_RE1.pro && make -j$(nproc)
```

- PC 개발 모드: `GlobalMain.h`에서 `DEVICE false`로 변경 (640×480 창, GuiApi 미호출)
- 테스트 프레임워크/lint 없음

## 아키텍처

```
MainWindow (QMainWindow)
 ├─ QStackedWidget       ← 페이지 전환 (인덱스 기반)
 ├─ Singleton            ← 전역 상태 (언어, 사용자, GuiApi)
 ├─ TextResource         ← 다국어 텍스트/폰트
 ├─ Page/* (74개)        ← 각 화면 (update/pageShow/pageHide 필수)
 ├─ Component/* (13개)   ← 오버레이 UI (배터리, BLE, 시계, 메뉴)
 └─ Button/* (14개)      ← 커스텀 버튼
```

**페이지 전환 흐름:** `emit signalShowPageNum(PAGE_XXX)` → `MainWindow::setPageByPageNum()` → `pageHide()` → `pageShow()` → `update()`

**TextResource 구조:** `언어(DeviceLanguage) × 페이지(PageNum) × 키(QString)` → `QStringList`
지원 언어: KR, EN, JP, SC, TC, ES. `@` 문자 = 페이지 분리 마커 (640×480 화면에 맞춤)

**GuiApi:** FIFO(`/tmp/gapi_fifo`)로 하드웨어 데몬과 IPC 통신

## 주요 구현 패턴

- **자식 위젯 터치 좌표계**: `comText->geometry()`는 부모 위젯 기준. `this` 기준으로 변환 시 `.translated(labelWindow->pos())` 필요
- **nSelectTextIndex 예외 처리**: `mainwindow.cpp`에서 특정 페이지(HELP/FAQ/ERROR_HELP 계열)는 `nSelectTextIndex` 초기화 제외
- **페이지 플로우**: helpIndex→help→helpResponse / faqIndex→faq→faqResponse / errorHelpIndex→errorHelp→errorHelpResponse
- **@ 마커**: QStringList 항목 내 `@`로 페이지 분리, 640×480 화면에 맞춤

## GlobalMain.h 스위치

| 매크로 | 기본값 | 설명 |
|---|---|---|
| `DEVICE` | `true` | `false` = PC 개발 모드 |
| `IMAGE_FILE_CHECK` | `false` | 이미지 파일 존재 여부 체크 |
| `WINDOW_CALI` | `false` | 캘리브레이션 창 모드 |
| `NEW_PASSWORD` | `true` | 신규 비밀번호 정책 |
| `FONT_DEBUG` | `false` | 폰트 디버그 출력 |
| `PICTURE_MODE` | `false` | 화면 캡처용 모드 |
| `DEBUG_FLAG_BATTERY` | `false` | 배터리 디버그 로그 |

## 코드 수정 원칙

- **최소 변경 원칙**: 요청된 범위만 수정하고, 불필요한 리팩토링이나 개선을 하지 않는다
- **기존 코드 우선 이해**: 수정 전 반드시 해당 파일을 읽고 맥락을 파악한다
- **다른 파일 미수정**: 명시적으로 요청하지 않는 한 다른 파일은 건드리지 않는다
- **주석 규칙**: 개발자 메모는 `//hrkim 날짜` 형식으로 작성한다

## 작업 제한 규칙

- **폰트 크기 변경 금지**: `textresource.cpp`의 폰트 크기는 임의로 변경하지 않는다
- **텍스트 문구 수정 금지**: `textresource.cpp`의 텍스트 내용은 임의로 수정하지 않는다. 명시적 요청 시에만 수정 가능

## 브랜치 전략

- **네이밍 규칙 (모노레포)**: `(접두사)/embedded/(작업명)`
  - 접두사: `dev` (새 기능/개발), `fix` (버그 수정), `refactor` (리팩터링)
  - 예시: `dev/embedded/help-2step`, `fix/embedded/battery-debug`
- **새 작업 시 반드시 브랜치 생성** — main에서 직접 작업 금지
- 브랜치 생성 전 반드시 `git pull` 실행
- `main`: 안정 버전 / `develop`: 통합 테스트

## 커밋 규칙

`feat` / `fix` / `docs` / `style` / `refactor` / `chore`

- **커밋 메시지는 한국어로 작성**한다
- **코드 변경 시 자동 커밋**: 코드 파일을 수정한 후에는 반드시 즉시 git commit을 수행한다. 사용자 요청을 기다리지 않고 변경 완료 시점에 자동으로 커밋한다.
