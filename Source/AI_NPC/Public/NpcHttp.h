// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Interfaces/IHttpRequest.h"
#include "Interfaces/IHttpResponse.h"   // 如果用到了 FHttpResponsePtr
#include "HttpModule.h"                 // 如果你要访问 FHttpModule::Get()

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "NpcHttp.generated.h"

/**
 * 
 */
UCLASS()
class AI_NPC_API UNpcHttp : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:

    // BlueprintCallable = 蓝图可直接调用
    UFUNCTION(BlueprintCallable, Category = "HTTP")
    static void CreateNpcPost(
        const FString& ApiKey,
        const FString& charName,
        const FString& voiceType,
        const FString& backstory,
        const FString& actions,
        const FString& ContentType 
    );

private:
    // HTTP 请求完成后的内部回调
    static void OnResponseReceived(
        FHttpRequestPtr Request,
        FHttpResponsePtr Response,
        bool bWasSuccessful);
};
