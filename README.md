# 과제 보고서: 모듈 및 독립 플러그인 구축

## 1. 플러그인 및 모듈 제작 과정
- **프로젝트 구성**: 주 게임 모듈(`Assignment10`) 기반의 C++ 프로젝트 생성
- **런타임 모듈 추가**: `Source/Test` 폴더를 수동 구축하고 `Test.Build.cs` 설정을 통해 종속성 연결 및 `.uproject`에 등록
- **독립 플러그인 구축**: `Plugins/Temporary` 경로에 명세서 기준을 만족하는 `.uplugin` 메타데이터 및 모듈 인터페이스(`StartupModule`, `ShutdownModule`) 수동 구현
- **기능 연동**: `Test` 모듈의 `AwesomeActor`를 주 게임 모듈의 캐릭터 `BeginPlay`에서 성공적으로 스폰 및 UI 위젯 화면 표시 구현

## 2. 트러블 슈팅
이번 과제를 진행하며 겪은 주요 문제와 해결 과정입니다.

### 팩터 1: 플러그인 이름 변경 시 UBT 빌드 그래프 충돌 (Exited with code 9)
- **문제**: 플러그인 이름을 `MyPlugin`에서 `Temporary`로 변경한 후, 기존 `Intermediate` 폴더 내 빌드 규칙과 새 규칙이 충돌하며 `Action graph is invalid` 에러 발생.
- **해결**: 프로젝트 및 플러그인 내부의 `Binaries`, `Intermediate` 캐시 폴더를 물리적으로 삭제한 뒤, `.uproject` 파일의 플러그인 활성화 이름을 `Temporary`로 일치시키고 프로젝트 파일을 재생성(Generate)하여 클린 빌드로 해결.

### 팩터 2: UUserWidget 참조 시 링크 에러 (LNK2019 Unresolved External Symbol)
- **문제**: `AwesomeActor`에서 플러그인 내부의 위젯 UI를 화면에 띄우기 위해 `CreateWidget` 및 `AddToViewport`를 사용했으나 컴파일 단계에서 심볼을 찾지 못하는 링킹 에러 발생.
- **해결**: `Test.Build.cs` 파일의 `PublicDependencyModuleNames`에 엔진의 UI 모듈인 `"UMG"`, `"Slate"`, `"SlateCore"`를 명시적으로 추가하여 외부 모듈 참조 의존성을 해결함.