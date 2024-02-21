// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "CommonUIDataAsset.generated.h"

USTRUCT(BlueprintType)
struct FCommonUIItemStruct
{
	GENERATED_BODY()
public:	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="CommonUIItemStruct")
	FName ItemName;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="CommonUIItemStruct")
	FVector2D ItemSize;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="CommonUIItemStruct")
	FVector2D Translation;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="CommonUIItemStruct")
	UTexture2D* ItemImage;

	FCommonUIItemStruct():
		ItemName(FName()),
		ItemSize(FVector2D(100,30)),
		Translation(FVector2D(0,0)),
		ItemImage(nullptr)
	{
	}
	
};

/**
 * 
 */
UCLASS(Blueprintable,BlueprintType)
class COMMONUITOOLPLUGIN_API UCommonUIItemDataAsset : public UDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="CommonUIItemData")
	FCommonUIItemStruct UIItemStruct;
	
};

UCLASS(Blueprintable,BlueprintType)
class COMMONUITOOLPLUGIN_API UCommonUIItemsDataAsset : public UDataAsset
{
		GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="CommonUIItemData")
	TMap<FName,FCommonUIItemStruct>ChildStructMap;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="CommonUIItemData")
	TArray<FCommonUIItemStruct>ChildStructArray;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="CommonUIItemData")
	TMap<FName,UDataAsset*>ChildDataMap;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="CommonUIItemData")
	TArray<UDataAsset*>ChildDataArray;
};










