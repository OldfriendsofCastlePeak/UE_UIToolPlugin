// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
//#include "CommonUIType.h.generated.h"

UENUM(BlueprintType)
namespace CommonUIDirectionEnum
{
	//定义方向枚举类型
	enum EDirection
	{
		Up UMETA(DisplayName="上"), 
		Down UMETA(DisplayName="下"),
		Left UMETA(DisplayName="左"),
		Right UMETA(DisplayName="右"),
		Left_Up UMETA(DisplayName="左上"),
		Left_Down UMETA(DisplayName="左下"),
		Right_Up UMETA(DisplayName="右上"),
		Right_Down UMETA(DisplayName="右下"),
	};
}
