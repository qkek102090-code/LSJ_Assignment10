#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Blueprint/UserWidget.h"
#include "AwesomeActor.generated.h"

UCLASS()
class TEST_API AAwesomeActor : public AActor
{
    GENERATED_BODY()

public:
    AAwesomeActor();

protected:
    virtual void BeginPlay() override;

public:
    // 에디터에서 플러그인에 만든 위젯 블루프린트를 지정할 변수
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
    TSubclassOf<UUserWidget> WidgetClass;

    // 생성된 위젯 인스턴스를 담아둘 변수
    UPROPERTY()
    UUserWidget* CurrentWidget;
};