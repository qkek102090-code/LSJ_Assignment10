#include "AwesomeActor.h"
#include "Engine/Engine.h"

AAwesomeActor::AAwesomeActor()
{
    PrimaryActorTick.bCanEverTick = false;
}

void AAwesomeActor::BeginPlay()
{
    Super::BeginPlay();

    // 로그 출력
    UE_LOG(LogTemp, Warning, TEXT("TestActor가 Test 모듈에서 성공적으로 생성되었습니다!"));

    // 화면에 초록색 메시지 띄우기
    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, 500.f, FColor::Green, TEXT("모듈 테스트"));
    }
    if (WidgetClass)
    {
        APlayerController* PC = GetWorld()->GetFirstPlayerController();
        if (PC)
        {
            // 위젯 생성
            CurrentWidget = CreateWidget<UUserWidget>(PC, WidgetClass);

            if (CurrentWidget)
            {
                // 화면에 추가
                CurrentWidget->AddToViewport();
            }
        }
    }
}
