// Fill out your copyright notice in the Description page of Project Settings.


#include "NpcHttp.h"

#include "HttpModule.h"
#include "Interfaces/IHttpRequest.h"
#include "Interfaces/IHttpResponse.h"

void UNpcHttp::CreateNpcPost(
    const FString& ApiKey,
    const FString& charName,
    const FString& voiceType,
    const FString& backstory,
    const FString& actions,
    const FString& ContentType
    )
{
    //const FString Url = " https://api.convai.com/character/create ";
    //// 创建请求
    //TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request =
    //    FHttpModule::Get().CreateRequest();

    //// 绑定回调
    //Request->OnProcessRequestComplete().BindStatic(
    //    &UNpcHttp::OnResponseReceived);

    //// 组装请求
    //Request->SetURL(Url);
    //Request->SetVerb(TEXT("POST"));
    //Request->SetHeader(TEXT("Content-Type"), ContentType);
    //Request->SetHeader(TEXT("User-Agent"), TEXT("X-UnrealEngine-HttpPostHelper"));
    //Request->SetHeader(TEXT("CONVAI-API-KEY"), ApiKey);

    //TSharedPtr<FJsonObject> Json = MakeShared<FJsonObject>();
    //Json->SetStringField(TEXT("name"), charName);
    //Json->SetStringField(TEXT("voiceType"), voiceType);
    //Json->SetStringField(TEXT("backstory"), backstory);
    //Json->SetStringField(TEXT("actions"), actions);

    //FString BodyString;
    //TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&BodyString);
    //FJsonSerializer::Serialize(Json.ToSharedRef(), Writer);

    //Request->SetContentAsString(BodyString);

    //// 发送
    //Request->ProcessRequest();
}

void UNpcHttp::OnResponseReceived(FHttpRequestPtr Request,
    FHttpResponsePtr Response,
    bool bWasSuccessful)
{
    if (!bWasSuccessful || !Response.IsValid())
    {
        UE_LOG(LogTemp, Error, TEXT("HTTP POST Failed"));
        return;
    }

    int32 Code = Response->GetResponseCode();
    FString ResponseBody = Response->GetContentAsString();

    UE_LOG(LogTemp, Log,
        TEXT("HTTP POST Done. Code: %d, Body: %s"),
        Code, *ResponseBody);
}