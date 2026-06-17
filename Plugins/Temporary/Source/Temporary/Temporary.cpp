#include "Temporary.h"

void FMyPluginModule::StartupModule()
{
    UE_LOG(LogTemp, Warning, TEXT("Temporary 플러그인 모듈이 성공적으로 시작되었습니다!"));
}

void FMyPluginModule::ShutdownModule()
{
    UE_LOG(LogTemp, Warning, TEXT("Temporary 플러그인 모듈이 종료되었습니다."));
}

IMPLEMENT_MODULE(FMyPluginModule, Temporary)