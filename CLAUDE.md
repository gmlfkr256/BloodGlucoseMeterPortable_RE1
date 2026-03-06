# CLAUDE.md

Happyzone 브랜드 휴대용 혈당측정기 임베디드 GUI. Qt Widgets (C++11), 리눅스 임베디드.

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
 ├─ QStackedWidget       ← 페이지 전환
 ├─ Singleton            ← 전역 상태 (언어, 사용자, GuiApi)
 ├─ TextResource         ← 다국어 텍스트/폰트
 ├─ Page/*               ← 각 화면 (update/pageShow/pageHide 필수)
 ├─ Component/*          ← 오버레이 UI (배터리, BLE, 시계, 메뉴)
 └─ Button/*             ← 커스텀 버튼
```

**페이지 전환 흐름:** `emit signalShowPageNum(PAGE_XXX)` → `MainWindow::setPageByPageNum()` → `pageHide()` → `pageShow()` → `update()`

**TextResource 구조:** `언어(DeviceLanguage) × 페이지(PageNum) × 키(QString)` → `QStringList`
지원 언어: KR, EN, JP, SC, TC, ES

**GuiApi:** FIFO(`/tmp/gapi_fifo`)로 하드웨어 데몬과 IPC 통신

## 주요 구현 패턴

- **자식 위젯 터치 좌표계**: `comText->geometry()`는 부모 위젯 기준. `this` 기준으로 변환 시 `.translated(labelWindow->pos())` 필요
- **nSelectTextIndex 예외 처리**: `mainwindow.cpp`에서 특정 페이지(HELP/FAQ/ERROR_HELP 계열)는 `nSelectTextIndex` 초기화 제외
- **페이지 플로우**: helpIndex→help→helpResponse / faqIndex→faq→faqResponse / errorHelpIndex→errorHelp→errorHelpResponse

## GlobalMain.h 스위치

| 매크로 | 기본값 | 설명 |
|---|---|---|
| `DEVICE` | `true` | `false` = PC 개발 모드 |
| `IMAGE_FILE_CHECK` | `false` | 이미지 파일 존재 여부 체크 |
| `WINDOW_CALI` | `false` | 캘리브레이션 창 모드 |
| `NEW_PASSWORD` | `true` | 신규 비밀번호 정책 |
| `FONT_DEBUG` | `false` | 폰트 디버그 출력 |
| `PICTURE_MODE` | `false` | 화면 캡처용 모드 |

## 작업 시작 규칙

- **새 브랜치 생성 필수**: 작업 시작 시 `feature/*` 또는 `bugfix/*` 브랜치를 새로 생성하고 시작한다
  ```bash
  git checkout -b feature/작업명
  ```

## 작업 제한 규칙

- **폰트 크기 변경 금지**: `textresource.cpp`의 폰트 크기는 임의로 변경하지 않는다
- **텍스트 문구 수정 금지**: `textresource.cpp`의 텍스트 내용은 임의로 수정하지 않는다. 명시적 요청 시에만 수정 가능

## 커밋 규칙

`feat` / `fix` / `docs` / `style` / `refactor` / `chore`

- **코드 변경 시 자동 커밋**: 코드 파일을 수정한 후에는 반드시 즉시 git commit을 수행한다. 사용자 요청을 기다리지 않고 변경 완료 시점에 자동으로 커밋한다.

## Git 브랜치

- `main`: 안정 버전 / `develop`: 통합 테스트 / `feature/*`, `bugfix/*`, `hotfix/*`
