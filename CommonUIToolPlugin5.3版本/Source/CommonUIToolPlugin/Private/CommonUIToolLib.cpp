// Fill out your copyright notice in the Description page of Project Settings.


#include "CommonUIToolLib.h"
#include "CommonUIToolPlugin.h"
#include "Components/Border.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "Kismet/KismetStringLibrary.h"

#include "Backends/JsonStructDeserializerBackend.h"
#include "StructDeserializer.h"


namespace CommonUIToolReflexStruct
{
	struct FOneParamStruct
	{
		FString OneParam;
	};

	struct FTwoParamStruct
	{
		FString OneParam;
		FString TwoParam;
	};

	struct FThreeParamStruct
	{
		FString OneParam;
		FString TwoParam;
		FString ThreeParam;
	};
}

namespace CommonUIToolPlugin
{
	//小写a~z的Unicode编码
	static TArray<uint16>UnicodeLowerArray{
		97,98,99,100,101,		//a~e
		102,103,104,105,106,	//f~j
		107,108,109,110,111,	//k~o
		112,113,114,115,116,	//p~t
		117,118,119,120,121,	//u~y
		122						//z
	};
	
	//大写A~Z的Unicode编码
	static TArray<uint16>UnicodeUpperArray{
		65,66,67,68,69,			//A~E
		70,71,72,73,74,			//F~J
		75,76,77,78,79,			//K~O
		80,81,82,83,84,			//P~T
		85,86,87,88,89,			//U~Y
		90						//Z
	};

	//数字0~9的Unicode编码
	static TArray<uint16>UnicodeNumerArray{
		48,49,50,51,52,			//0~4
		53,54,55,56,57			//5~9
	};

	//英文符号
	static TArray<uint16>UnicodeEnglishSignArray{
		33,		//感叹号!
		34,		//引号""
		35,		//井号#
		36,		//美元符号$
		37,		//取余符号%
		38,		//且符号&
		39,		//撇号'
		40,		//左括号(
		41,		//右括号)
		42,		//星号*
		43,		//加号+
		44,		//逗号,
		45,		//减号-
		46,		//句号.
		47,		//左斜杠
		
		58,		//冒号:
		59,		//分号;
		60,		//小于号<
		61,		//等于号=
		62,		//大于号>
		63,		//问号?
		
		95,		//短横线2_
	};
}


#pragma region UMG通用方法
UUserWidget* UCommonUIToolLib::GetWidgetFirstOuterWidget(const UUserWidget* InWidget)
{
	if (!InWidget)
	{
		return nullptr;
	}
	UObject* TemOuter=InWidget->GetOuter();
	while (TemOuter)
	{
		if (TemOuter->IsA<UUserWidget>())
		{
			return Cast<UUserWidget>(TemOuter);
		}
		TemOuter=TemOuter->GetOuter();
	}
	return nullptr;
}

void UCommonUIToolLib::SetUIWidgetTranslationXValue(UWidget* InWidget, const float InXValue)
{
	if (!InWidget)
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("InWidget is Invalid"));
		return ;
	}
	InWidget->SetRenderTranslation(FVector2D(InXValue,InWidget->GetRenderTransform().Translation.Y));
}

void UCommonUIToolLib::SetUIWidgetTranslationYValue(UWidget* InWidget, const float InYValue)
{
	if (!InWidget)
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("InWidget is Invalid"));
		return ;
	}
	InWidget->SetRenderTranslation(FVector2D(InWidget->GetRenderTransform().Translation.X,InYValue));
}

void UCommonUIToolLib::GetUIWidgetTranslationXValue(const UWidget* InWidget, float& CurrentXValue)
{
	if (!InWidget)
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("InWidget is Invalid"));
		return ;
	}
	CurrentXValue=InWidget->GetRenderTransform().Translation.X;
}

void UCommonUIToolLib::GetUIWidgetTranslationYValue(const UWidget* InWidget, float& CurrentYValue)
{
	if (!InWidget)
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("InWidget is Invalid"));
		return ;
	}
	CurrentYValue=InWidget->GetRenderTransform().Translation.Y;
}

void UCommonUIToolLib::GetUIWidgetTranslation(const UWidget* InWidget,FVector2D& CurrentXValue)
{
	if (!InWidget)
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("InWidget is Invalid"));
		return ;
	}
	CurrentXValue=InWidget->GetRenderTransform().Translation;
}











#pragma endregion

#pragma region FSlateBrush系列方法实现



FSlateBrush UCommonUIToolLib::MakeSlateBrush()
{
	return FSlateBrush();
}

UObject* UCommonUIToolLib::GetBrushImage(
	const FSlateBrush& InSlateBrush)
{
	return InSlateBrush.GetResourceObject();
}

void UCommonUIToolLib::SetBrushImage(
	const FSlateBrush& InSlateBrush,
	const UObject* InImage)
{
	const_cast<FSlateBrush&>(InSlateBrush).SetResourceObject(const_cast<UObject*>(InImage));
}

FVector2D UCommonUIToolLib::GetBrushImageSize(
	const FSlateBrush& InSlateBrush)
{
	return InSlateBrush.ImageSize;
}

void UCommonUIToolLib::SetBrushImageSize(
	const FSlateBrush& InSlateBrush,
	const FVector2D InImageSize)
{
	const_cast<FSlateBrush&>(InSlateBrush).ImageSize=InImageSize;
}

FLinearColor UCommonUIToolLib::GetBrushTintClor(
	const FSlateBrush& InSlateBrush)
{
	return InSlateBrush.TintColor.GetSpecifiedColor();
}

void UCommonUIToolLib::SetBrushTintClor(
	const FSlateBrush& InSlateBrush,
	const FLinearColor InColor)
{
	const_cast<FSlateBrush&>(InSlateBrush).TintColor=InColor;
}

ESlateBrushDrawType::Type UCommonUIToolLib::GetBrushDrawAs(
	const FSlateBrush& InSlateBrush)
{
	return InSlateBrush.GetDrawType();
}

void UCommonUIToolLib::SetBrushDrawAs(
	const FSlateBrush& InSlateBrush,
	const ESlateBrushDrawType::Type InDrawAsType)
{
	const_cast<FSlateBrush&>(InSlateBrush).DrawAs=InDrawAsType;
}

FVector4 UCommonUIToolLib::GetBrushCornerRadii(
	const FSlateBrush& InSlateBrush)
{
	if (InSlateBrush.DrawAs== ESlateBrushDrawType::RoundedBox)
	{
		return InSlateBrush.OutlineSettings.CornerRadii;
	}
	return FVector4();
}

void UCommonUIToolLib::SetBrushCornerRadii(
	const FSlateBrush& InSlateBrush,
	const FVector4 InCornerRadii)
{
	if (InSlateBrush.DrawAs== ESlateBrushDrawType::RoundedBox)
	{
		const_cast<FSlateBrush&>(InSlateBrush).OutlineSettings.CornerRadii=InCornerRadii;
	}
}

FLinearColor UCommonUIToolLib::GetBrushOutlineColor(
	const FSlateBrush& InSlateBrush)
{
	if (InSlateBrush.DrawAs== ESlateBrushDrawType::RoundedBox)
	{
		return InSlateBrush.OutlineSettings.Color.GetSpecifiedColor();
	}
	return FLinearColor();
}

void UCommonUIToolLib::SetBrushOutlineColor(
	const FSlateBrush& InSlateBrush,
	const FLinearColor InOutlineColor)
{
	if (InSlateBrush.DrawAs== ESlateBrushDrawType::RoundedBox)
	{
		const_cast<FSlateBrush&>(InSlateBrush).OutlineSettings.Color=InOutlineColor;
	}
}

float UCommonUIToolLib::GetBrushWidth(
	const FSlateBrush& InSlateBrush)
{
	if (InSlateBrush.DrawAs== ESlateBrushDrawType::RoundedBox)
	{
		return InSlateBrush.OutlineSettings.Width;
	}
	return 0.f;
}

void UCommonUIToolLib::SetBrushWidth(
	const FSlateBrush& InSlateBrush,
	const float InWidth)
{
	if (InSlateBrush.DrawAs== ESlateBrushDrawType::RoundedBox)
	{
		const_cast<FSlateBrush&>(InSlateBrush).OutlineSettings.Width=InWidth;
	}
}

ESlateBrushRoundingType::Type UCommonUIToolLib::GetBrushRoundingType(
	const FSlateBrush& InSlateBrush)
{
	if (InSlateBrush.DrawAs== ESlateBrushDrawType::RoundedBox)
	{
		return InSlateBrush.OutlineSettings.RoundingType;
	}
	return ESlateBrushRoundingType::HalfHeightRadius;
}

void UCommonUIToolLib::SetBrushRoundingType(
	const FSlateBrush& InSlateBrush,
	const ESlateBrushRoundingType::Type InRoundingType)
{
	if (InSlateBrush.DrawAs== ESlateBrushDrawType::RoundedBox)
	{
		const_cast<FSlateBrush&>(InSlateBrush).OutlineSettings.RoundingType=InRoundingType;
	}
}

bool UCommonUIToolLib::GetBrushbUseBrushTransparency(
	const FSlateBrush& InSlateBrush)
{
	if (InSlateBrush.DrawAs== ESlateBrushDrawType::RoundedBox)
	{
		return InSlateBrush.OutlineSettings.bUseBrushTransparency;
	}
	return false;	
}

void UCommonUIToolLib::SetBrushbUseBrushTransparency(
	const FSlateBrush& InSlateBrush,
	const bool InbUseBrushTransparency)
{
	if (InSlateBrush.DrawAs== ESlateBrushDrawType::RoundedBox)
	{
		const_cast<FSlateBrush&>(InSlateBrush).OutlineSettings.bUseBrushTransparency=InbUseBrushTransparency;
	}
}

ESlateBrushTileType::Type UCommonUIToolLib::GetBrushTiling(
	const FSlateBrush& InSlateBrush)
{
	return InSlateBrush.GetTiling();
}

void UCommonUIToolLib::SetBrushTiling(
	const FSlateBrush& InSlateBrush,
	const ESlateBrushTileType::Type InTiling)
{
	const_cast<FSlateBrush&>(InSlateBrush).Tiling=InTiling;
}
#pragma endregion

#pragma region FSliderStyle系列方法实现

FSlateBrush UCommonUIToolLib::GetSliderNormalBarImage(
	const FSliderStyle InSliderStyle)
{
	return InSliderStyle.NormalBarImage;
}

void UCommonUIToolLib::SetSliderNormalBarImage(
	const FSliderStyle& InSliderStyle,
	const FSlateBrush& InSlateBrush)
{
	const_cast<FSliderStyle&>(InSliderStyle).SetNormalBarImage(InSlateBrush);
}

FSlateBrush UCommonUIToolLib::GetSliderHoveredBarImage(
	const FSliderStyle InSliderStyle)
{
	return InSliderStyle.HoveredBarImage;
}

void UCommonUIToolLib::SetSliderHoveredBarImage(
	const FSliderStyle& InSliderStyle,
	const FSlateBrush& InSlateBrush)
{
	const_cast<FSliderStyle&>(InSliderStyle).SetHoveredBarImage(InSlateBrush);
}

FSlateBrush UCommonUIToolLib::GetSliderDisabledBarImage(
	const FSliderStyle InSliderStyle)
{
	return InSliderStyle.DisabledBarImage;
}

void UCommonUIToolLib::SetSliderDisabledBarImage(
	const FSliderStyle& InSliderStyle,
	const FSlateBrush& InSlateBrush)
{
	const_cast<FSliderStyle&>(InSliderStyle).SetDisabledBarImage(InSlateBrush);
}

FSlateBrush UCommonUIToolLib::GetSliderNormalThumbImage(
	const FSliderStyle InSliderStyle)
{
	return InSliderStyle.NormalThumbImage;
}

void UCommonUIToolLib::SetSliderNormalThumbImage(
	const FSliderStyle& InSliderStyle,
	const FSlateBrush& InSlateBrush)
{
	const_cast<FSliderStyle&>(InSliderStyle).SetNormalThumbImage(InSlateBrush);
}

FSlateBrush UCommonUIToolLib::GetSliderHoveredThumbImage(
	const FSliderStyle InSliderStyle)
{
	return InSliderStyle.HoveredThumbImage;
}

void UCommonUIToolLib::SetSliderHoveredThumbImage(
	const FSliderStyle& InSliderStyle,
	const FSlateBrush& InSlateBrush)
{
	const_cast<FSliderStyle&>(InSliderStyle).SetHoveredThumbImage(InSlateBrush);
}

FSlateBrush UCommonUIToolLib::GetSliderDisabledThumbImage(
	const FSliderStyle InSliderStyle)
{
	return InSliderStyle.DisabledThumbImage;
}

void UCommonUIToolLib::SetSliderDisabledThumbImage(
	const FSliderStyle& InSliderStyle,
	const FSlateBrush& InSlateBrush)
{
	const_cast<FSliderStyle&>(InSliderStyle).SetDisabledThumbImage(InSlateBrush);
}

float UCommonUIToolLib::GetSliderThickness(
	const FSliderStyle InSliderStyle)
{
	return InSliderStyle.BarThickness;
}

void UCommonUIToolLib::SetSliderThickness(
	const FSliderStyle& InSliderStyle, const float InThickness)
{
	const_cast<FSliderStyle&>(InSliderStyle).SetBarThickness(InThickness);
}

#pragma endregion 

UObject* UCommonUIToolLib::GetImageResource(const UImage* InImage)
{
	if (!InImage)
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("InImage is Invalid"));
		return nullptr;
	}
	return InImage->GetBrush().GetResourceObject();
}

void UCommonUIToolLib::SetImageSizeXValue(const UImage* InImage,const float NewImageXValue)
{
	if (!InImage)
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("InImage is Invalid"));
		return ;
	}
	const_cast<UImage*>(InImage)->SetDesiredSizeOverride(FVector2D(NewImageXValue,InImage->GetBrush().ImageSize.Y));
}

void UCommonUIToolLib::SetImageSizeYValue(const UImage* InImage,const float NewImageYValue)
{
	if (!InImage)
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("InImage is Invalid"));
		return ;
	}
	const_cast<UImage*>(InImage)->SetDesiredSizeOverride(FVector2D(InImage->GetBrush().ImageSize.X,NewImageYValue));
}

void UCommonUIToolLib::SetImageSize(const UImage* InImage, const FVector2D NewImageSize)
{
	if (!InImage)                                       
	{                                                   
		UE_LOG(FCommonUIToolLog,Warning,TEXT("InImage is Invalid"));
		return;                                         
	}                                                   
	const_cast<UImage*>(InImage)->SetDesiredSizeOverride(NewImageSize);
}

void UCommonUIToolLib::SetImageSizeByResource(const UImage* InImage, const float& InScale)
{
	if (!InImage)                                       
	{                                                   
		UE_LOG(FCommonUIToolLog,Warning,TEXT("InImage is Invalid"));
		return;                                         
	}
	if (UTexture2D* ImageTexture2D=Cast<UTexture2D>(const_cast<UImage*>(InImage)->GetBrush().GetResourceObject()))
	{
		const_cast<UImage*>(InImage)->SetDesiredSizeOverride(FVector2D((((float)ImageTexture2D->GetSizeX())*InScale),(((float)ImageTexture2D->GetSizeY())*InScale)));
	}
	else
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("InImage.Brush.Image isn't UTexture2D"));
	}
	
}

void UCommonUIToolLib::SetImageDrawAs(const UImage* InImage, const ESlateBrushDrawType::Type InDrawAs)
{
	if (!InImage)                                       
	{                                                   
		UE_LOG(FCommonUIToolLog,Warning,TEXT("InImage is Invalid"));
		return;                                         
	}
	FSlateBrush NewFSlateBrush=const_cast<UImage*>(InImage)->GetBrush();
	NewFSlateBrush.DrawAs=InDrawAs;
	const_cast<UImage*>(InImage)->SetBrush(NewFSlateBrush);
}

void UCommonUIToolLib::SetImageOutlineWidth(const UImage* InImage, const float& InWidth)
{
	if (!InImage)                                       
	{                                                   
		UE_LOG(FCommonUIToolLog,Warning,TEXT("InImage is Invalid"));
		return;                                         
	}
	FSlateBrush NewFSlateBrush=const_cast<UImage*>(InImage)->GetBrush();
	NewFSlateBrush.OutlineSettings.Width=InWidth;
	const_cast<UImage*>(InImage)->SetBrush(NewFSlateBrush);
}

void UCommonUIToolLib::SetImageOutlineColor(const UImage* InImage, const FLinearColor InLinearColor)
{
	if (!InImage)                                       
	{                                                   
		UE_LOG(FCommonUIToolLog,Warning,TEXT("InImage is Invalid"));
		return;                                         
	}
	FSlateBrush NewFSlateBrush=const_cast<UImage*>(InImage)->GetBrush();
	NewFSlateBrush.OutlineSettings.Color=InLinearColor;
	const_cast<UImage*>(InImage)->SetBrush(NewFSlateBrush);
}

void UCommonUIToolLib::SetImageOutlineCornerRadii(const UImage* InImage, const FVector4& InCornerRadii)
{
	if (!InImage)                                       
	{                                                   
		UE_LOG(FCommonUIToolLog,Warning,TEXT("InImage is Invalid"));
		return;                                         
	}
	FSlateBrush NewFSlateBrush=const_cast<UImage*>(InImage)->GetBrush();
	NewFSlateBrush.OutlineSettings.CornerRadii=InCornerRadii;
}

#pragma region Button

void UCommonUIToolLib::SetButtonNormalTintColor(const UButton* InButton, const FLinearColor InLinearColor)
{
	if (!InButton)
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("InButton is Invalid"));
		return ;
	}
	const_cast<FButtonStyle&>(const_cast<UButton*>(InButton)->GetStyle()).Normal.TintColor=InLinearColor;
}

void UCommonUIToolLib::SetButtonHoveredTintColor(const UButton* InButton, const FLinearColor InLinearColor)
{
	if (!InButton)
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("InButton is Invalid"));
		return ;
	}
	const_cast<FButtonStyle&>(const_cast<UButton*>(InButton)->GetStyle()).Hovered.TintColor=InLinearColor;
}

void UCommonUIToolLib::SetButtonPressedTintColor(const UButton* InButton, const FLinearColor InLinearColor)
{
	if (!InButton)
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("InButton is Invalid"));
		return ;
	}
	const_cast<FButtonStyle&>(const_cast<UButton*>(InButton)->GetStyle()).Pressed.TintColor=InLinearColor;
}

void UCommonUIToolLib::SetButtonDisabledTintColor(const UButton* InButton, const FLinearColor InLinearColor)
{
	if (!InButton)
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("InButton is Invalid"));
		return ;
	}
	const_cast<FButtonStyle&>(const_cast<UButton*>(InButton)->GetStyle()).Disabled.TintColor=InLinearColor;
}

void UCommonUIToolLib::SetButtonNormalForeground(const UButton* InButton, const FLinearColor InLinearColor)
{
	if (!InButton)
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("InButton is Invalid"));
		return ;
	}
	const_cast<FButtonStyle&>(const_cast<UButton*>(InButton)->GetStyle()).NormalForeground =InLinearColor;
}

void UCommonUIToolLib::SetButtonHoveredForeground(const UButton* InButton, const FLinearColor InLinearColor)
{
	if (!InButton)
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("InButton is Invalid"));
		return ;
	}
	const_cast<FButtonStyle&>(const_cast<UButton*>(InButton)->GetStyle()).HoveredForeground =InLinearColor;
}

void UCommonUIToolLib::SetButtonPressedForeground(const UButton* InButton, const FLinearColor InLinearColor)
{
	if (!InButton)
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("InButton is Invalid"));
		return ;
	}
	const_cast<FButtonStyle&>(const_cast<UButton*>(InButton)->GetStyle()).PressedForeground =InLinearColor;
}

void UCommonUIToolLib::SetButtonDisabledForeground(const UButton* InButton, const FLinearColor InLinearColor)
{
	if (!InButton)
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("InButton is Invalid"));
		return ;
	}
	const_cast<FButtonStyle&>(const_cast<UButton*>(InButton)->GetStyle()).DisabledForeground =InLinearColor;
}

void UCommonUIToolLib::SetButtonNormalPadding(const UButton* InButton, const FMargin InMargin)
{
	if (!InButton)
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("InButton is Invalid"));
		return ;
	}
	const_cast<FButtonStyle&>(const_cast<UButton*>(InButton)->GetStyle()).NormalPadding =InMargin;
}

void UCommonUIToolLib::SetButtonPressedPadding(const UButton* InButton, const FMargin InMargin)
{
	if (!InButton)
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("InButton is Invalid"));
		return ;
	}
	const_cast<FButtonStyle&>(const_cast<UButton*>(InButton)->GetStyle()).PressedPadding =InMargin;
}

void UCommonUIToolLib::SetButtonPressedSound(const UButton* InButton,const FSlateSound InSlateSound)
{
	if (!InButton)
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("InButton is Invalid"));
		return ;
	}
	const_cast<FButtonStyle&>(const_cast<UButton*>(InButton)->GetStyle()).PressedSlateSound=InSlateSound;
}

void UCommonUIToolLib::SetButtonHoveredSound(const UButton* InButton,const FSlateSound InSlateSound)
{
	if (!InButton)
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("InButton is Invalid"));
		return ;
	}
	const_cast<FButtonStyle&>(const_cast<UButton*>(InButton)->GetStyle()).HoveredSlateSound=InSlateSound;
}


#pragma endregion
void UCommonUIToolLib::SetBorderDrawAs(const UBorder* InBorder, const ESlateBrushDrawType::Type InDrawAs)
{
	if (!InBorder)
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("InBorder is Invalid"));
		return ;
	}
	const_cast<UBorder*>(InBorder)->Background.DrawAs=InDrawAs;
}

void UCommonUIToolLib::SetBorderOutlineWidth(const UBorder* InBorder, const float& InWidth)
{
	if (!InBorder)
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("InBorder is Invalid"));
		return ;
	}
	const_cast<UBorder*>(InBorder)->Background.OutlineSettings.Width=InWidth;
}

void UCommonUIToolLib::SetBorderTintColor(const UBorder* InBorder, const FLinearColor InLinearColor)
{
	if (!InBorder)
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("InBorder is Invalid"));
		return ;
	}
	const_cast<UBorder*>(InBorder)->Background.TintColor=InLinearColor;
}

void UCommonUIToolLib::SetBorderOutlineColor(const UBorder* InBorder, const FLinearColor InLinearColor)
{
	if (!InBorder)
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("InBorder is Invalid"));
		return ;
	}
	const_cast<UBorder*>(InBorder)->Background.OutlineSettings.Color=InLinearColor;
}

void UCommonUIToolLib::SetBorderOutlineCornerRadii(const UBorder* InBorder, const FVector4& InCornerRadii)
{
	if (!InBorder)
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("InBorder is Invalid"));
		return ;
	}
	const_cast<UBorder*>(InBorder)->Background.OutlineSettings.CornerRadii=InCornerRadii;
}

void UCommonUIToolLib::SetTextFontSize(const UTextBlock* InText, const int FontSize)
{
	if (!InText)
	{
		return;
	}
	FSlateFontInfo SlateFontInfo=InText->GetFont();
	SlateFontInfo.Size=FontSize;
	const_cast<UTextBlock*>(InText)->SetFont(SlateFontInfo);
}

void UCommonUIToolLib::SetTextFontFamily(const UTextBlock* InText, const UObject* InFontFamily)
{
	if (!InText)
	{
		return;
	}
	FSlateFontInfo SlateFontInfo=InText->GetFont();
	SlateFontInfo.FontObject=InFontFamily;
	const_cast<UTextBlock*>(InText)->SetFont(SlateFontInfo);
}

#pragma region 字符串处理
FString UCommonUIToolLib::FTimespanToString(const FTimespan& InTimespan)
{
	return InTimespan.ToString();
}

FString UCommonUIToolLib::ClearWrapThansformChar(const FString& InStr)
{
	return InStr.Replace(TEXT("\n"), TEXT(""));
}

FString UCommonUIToolLib::AutoAddZero(const uint8 InInt)
{
	return InInt<10?FString("0")+FString::FromInt(InInt):FString::FromInt(InInt);
}

FString UCommonUIToolLib::AutoWrapLineExactly(const FString& InStr, const uint8 WrapNum)
{
	if (WrapNum==0)
		return InStr;

	FString TemStr(InStr),ReturnStr;

	while (TemStr.Len()>WrapNum)
	{
		ReturnStr=ReturnStr.IsEmpty()?ReturnStr+TemStr.Left(WrapNum):ReturnStr+FString("\n")+TemStr.Left(WrapNum);
		TemStr=TemStr.RightChop(WrapNum);
	}

	ReturnStr=ReturnStr.IsEmpty()?ReturnStr+TemStr:ReturnStr+FString("\n")+TemStr;
	
	return ReturnStr;
}

FString UCommonUIToolLib::AutoWrapLine(const FString& InStr, const uint8 WrapNum,const bool bLessAChar,const float OtherCharPresentValue)
{
	if (WrapNum==0)
		return InStr;

	FString TemStr(InStr),ReturnStr;

	float CurentCount=0;

	//遍历整个字符串,根据指定的每一行数量换行
	for (const TCHAR TemChar:TemStr)
	{
		//获取字符的Unicode编码
		const int16 TemCharCode=static_cast<int16>(TemChar);
		
		//0~9的编码为48~57,a~z的编码为97~122,空格的编码为32.
		if( CommonUIToolPlugin::UnicodeNumerArray.Find(TemCharCode)||
			CommonUIToolPlugin::UnicodeLowerArray.Find(TemCharCode)||
			TemCharCode==32)
		{
			//当前字符为数字或小写英文字符
			
			if (bLessAChar)
			{
				//是否达到换行数
				if (CurentCount+OtherCharPresentValue>WrapNum)
				{
					ReturnStr=ReturnStr.IsEmpty()?ReturnStr+TemChar:ReturnStr+FString("\n")+TemChar;
					CurentCount=0;
				}
				else
				{
					ReturnStr+=TemChar;
				}
				CurentCount+=OtherCharPresentValue;
			}
			else
			{
				//是否达到换行数
				if (CurentCount>=WrapNum)
				{
					ReturnStr=ReturnStr.IsEmpty()?ReturnStr+TemChar:ReturnStr+FString("\n")+TemChar;
					CurentCount=0;
				}
				else
				{
					ReturnStr+=TemChar;
				}
				CurentCount+=OtherCharPresentValue;
				
			}
		}
		else
		{
			if (bLessAChar)
			{
				//是否达到换行数
				if (CurentCount+1>WrapNum)
				{
					ReturnStr=ReturnStr.IsEmpty()?ReturnStr+TemChar:ReturnStr+FString("\n")+TemChar;
					CurentCount=0;
				}
				else
				{
					ReturnStr+=TemChar;
				}
				CurentCount+=1;
			}
			else
			{
				//是否达到换行数
				if (CurentCount>=WrapNum)
				{
					ReturnStr=ReturnStr.IsEmpty()?ReturnStr+TemChar:ReturnStr+FString("\n")+TemChar;
					CurentCount=0;
				}
				else
				{
					ReturnStr+=TemChar;
				}
				CurentCount+=1;
			}
			
		}
	}
	return ReturnStr;
}

FString UCommonUIToolLib::AutoWrapLineSpecifyChar(const FString& InStr, const uint8 WrapNum, const FString& SpecifyStr,
	const bool bLessAChar, const float OtherCharPresentValue)
{
	if (WrapNum==0)
		return InStr;

	FString TemStr(InStr),ReturnStr;
	
	float CurentCount=0;

	TSet<int16>SpecifyCharCode;

	//先将特殊字符的编码添加到TSet中
	for (const TCHAR TemChar:SpecifyStr)
	{
		SpecifyCharCode.Add(static_cast<int16>(TemChar));
	}

	//检测字符是否为特殊字符
	for (const TCHAR TemChar:TemStr)
	{
		const int16 TemCharCode=static_cast<int16>(TemChar);
		//0~9的编码为48~57,  a~z的编码为97~122
		//(TemCharCode>=48&&TemCharCode<=57)||(TemCharCode>=97&&TemCharCode<=122)||TemCharCode==32
		if (SpecifyCharCode.Find((TemCharCode)))
		{
			if (bLessAChar)
			{
				//是否达到换行数
				if (CurentCount+OtherCharPresentValue>WrapNum)
				{
					ReturnStr=ReturnStr.IsEmpty()?ReturnStr+TemChar:ReturnStr+FString("\n")+TemChar;
					CurentCount=0;
				}
				else
				{
					ReturnStr+=TemChar;
				}
				CurentCount+=OtherCharPresentValue;
			}
			else
			{
				//是否达到换行数
				if (CurentCount>=WrapNum)
				{
					ReturnStr=ReturnStr.IsEmpty()?ReturnStr+TemChar:ReturnStr+FString("\n")+TemChar;
					CurentCount=0;
				}
				else
				{
					ReturnStr+=TemChar;
				}
				CurentCount+=OtherCharPresentValue;
				
			}
		}
		else
		{
			if (bLessAChar)
			{
				//是否达到换行数
				if (CurentCount+1>WrapNum)
				{
					ReturnStr=ReturnStr.IsEmpty()?ReturnStr+TemChar:ReturnStr+FString("\n")+TemChar;
					CurentCount=0;
				}
				else
				{
					ReturnStr+=TemChar;
				}
				CurentCount+=1;
			}
			else
			{
				//是否达到换行数
				if (CurentCount>=WrapNum)
				{
					ReturnStr=ReturnStr.IsEmpty()?ReturnStr+TemChar:ReturnStr+FString("\n")+TemChar;
					CurentCount=0;
				}
				else
				{
					ReturnStr+=TemChar;
				}
				CurentCount+=1;
			}
			
		}
	}
	return ReturnStr;
}

FString UCommonUIToolLib::AutoWrapLineBySpecifyStr(const FString& InStr, const FString& WarpLineStr,
                                                   ESearchCase::Type SearchCase)
{
	FString ReturnStr(InStr);
	
	while (ReturnStr.Contains(WarpLineStr))
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("Contain:%s"),*WarpLineStr);
		ReturnStr=UKismetStringLibrary::Replace(ReturnStr,WarpLineStr,FString("\n"));
	}
	return ReturnStr;
}

FString UCommonUIToolLib::ReserveSpecifyPointNum(const FString& InStr, const uint8 PointNum)
{
	FString TemStr(InStr),ReturnStr,SplitLeftStr,SplitRightStr;
	if (TemStr.Split(TemStr,&SplitLeftStr,&SplitRightStr))
	{
		ReturnStr=PointNum==0?SplitLeftStr:SplitLeftStr+FString(".")+SplitRightStr.Left(PointNum);
	}
	else
	{
		ReturnStr=TemStr;
	}
	return ReturnStr;
}

int32 UCommonUIToolLib::GetCharCode(const FString& CharStr)
{
	if (CharStr.Len()>=1)
	{
		return static_cast<int32>(CharStr[0]);
	}
	UE_LOG(FCommonUIToolLog,Warning,TEXT("CharStr is empty"));
	return 0;
}

void UCommonUIToolLib::GetStringUniCode(const FString& InStr, TArray<int32>& ReturnUnicodeArray)
{
	// TArray<int32>ReturnArray;
	// for (TCHAR TemChar:*InStr)
	// {
	// 	ReturnArray.Add(static_cast<int32>(TemChar));
	// }
	// ReturnUnicodeArray=ReturnArray;
}
#pragma endregion

#pragma region 反射相关
void UCommonUIToolLib::GetClassAllPropertyName(const UClass* InClass, TArray<FName>&PropertyNames)
{
	if (!InClass)
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("InClass is Invalid"));
		return ;
	}
	PropertyNames.Empty();
	for (TFieldIterator<FProperty>Property(InClass);Property;++Property)
	{
		PropertyNames.Add(FName(*Property->GetName()));
	}
}

void UCommonUIToolLib::SetBytePropertyValue(UObject* InObject, const FName PropertyName, const uint8 InByte)
{
	if (!InObject)
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("InObject is Invalid"));
		return ;
	}
	const FByteProperty* ByteProperty = FindFProperty<FByteProperty>(InObject->GetClass(), PropertyName);
	if (!ByteProperty)
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("Isn't find specify PropertyName variable"));
		return ;
	}
	uint8* Data=ByteProperty->ContainerPtrToValuePtr<uint8>(InObject);
	ByteProperty->SetPropertyValue(Data,InByte);
}

uint8 UCommonUIToolLib::GetBytePropertyValue(UObject* InObject, const FName PropertyName)
{
	if (!InObject)
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("InObject is Invalid"));
		return 0;
	}
	const FByteProperty* ByteProperty = FindFProperty<FByteProperty>(InObject->GetClass(), PropertyName);
	if (!ByteProperty)
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("Isn't find specify PropertyName variable:%s"),*PropertyName.ToString());
		return 0;
	}
	return *ByteProperty->ContainerPtrToValuePtr<uint8>(InObject);
}

void UCommonUIToolLib::SetIntPropertyValue(UObject* InObject, const FName PropertyName,const int InInt)
{
	if (!InObject)
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("InObject is Invalid"));
		return ;
	}
	const FIntProperty* IntProperty = FindFProperty<FIntProperty>(InObject->GetClass(), PropertyName);
	if (!IntProperty)
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("Isn't find specify PropertyName variable"));
		return ;
	}
	int* Data=IntProperty->ContainerPtrToValuePtr<int>(InObject);
	IntProperty->SetIntPropertyValue(Data,(uint64)InInt);
}

int UCommonUIToolLib::GetIntPropertyValue(UObject* InObject, const FName PropertyName)
{
	if (!InObject)
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("InObject is Invalid"));
		return 0;
	}
	const FIntProperty* IntProperty = FindFProperty<FIntProperty>(InObject->GetClass(), PropertyName);
	if (!IntProperty)
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("Isn't find specify PropertyName variable"));
		return 0;
	}
	return *IntProperty->ContainerPtrToValuePtr<int>(InObject);
}

void UCommonUIToolLib::SetFloatPropertyValue(UObject* InObject, const FName PropertyName, const float InFloat)
{
	if (!InObject)
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("InObject is Invalid"));
		return ;
	}
	const FFloatProperty* FloatProperty = FindFProperty<FFloatProperty>(InObject->GetClass(), PropertyName);
	if (!FloatProperty)
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("Isn't find specify PropertyName variable:%s"),*PropertyName.ToString());
		return ;
	}
	float* Data=FloatProperty->ContainerPtrToValuePtr<float>(InObject);
	FloatProperty->SetFloatingPointPropertyValue(Data,InFloat);
}

float UCommonUIToolLib::GetFloatPropertyValue(UObject* InObject, const FName PropertyName)
{
	if (!InObject)
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("InObject is Invalid"));
		return 0;
	}
	const FFloatProperty* FloatProperty = FindFProperty<FFloatProperty>(InObject->GetClass(), PropertyName);
	if (!FloatProperty)
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("Isn't find specify PropertyName variable:%s"),*PropertyName.ToString());
		return 0;
	}
	return *FloatProperty->ContainerPtrToValuePtr<double>(InObject);
}

void UCommonUIToolLib::SetDoublePropertyValue(UObject* InObject, const FName PropertyName, const double InDouble)
{
	if (!InObject)
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("InObject is Invalid"));
		return ;
	}
	const FDoubleProperty* DoubleProperty = FindFProperty<FDoubleProperty>(InObject->GetClass(), PropertyName);
	if (!DoubleProperty)
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("Isn't find specify PropertyName variable:%s"),*PropertyName.ToString());
		return ;
	}
	double* Data=DoubleProperty->ContainerPtrToValuePtr<double>(InObject);
	DoubleProperty->SetFloatingPointPropertyValue(Data,InDouble);
}

double UCommonUIToolLib::GetDoublePropertyValue(UObject* InObject, const FName PropertyName)
{
	if (!InObject)
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("InObject is Invalid"));
		return 0;
	}
	const FDoubleProperty* DoubleProperty = FindFProperty<FDoubleProperty>(InObject->GetClass(), PropertyName);
	if (!DoubleProperty)
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("Isn't find specify PropertyName variable:%s"),*PropertyName.ToString());
		return 0;
	}
	return *DoubleProperty->ContainerPtrToValuePtr<double>(InObject);
}

void UCommonUIToolLib::SetBoolPropertyValue(UObject* InObject, const FName PropertyName, const bool InBool)
{
	if (!InObject)
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("InObject is Invalid"));
		return ;
	}
	const FBoolProperty* BoolProperty = FindFProperty<FBoolProperty>(InObject->GetClass(), PropertyName);
	if (!BoolProperty)
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("Isn't find specify PropertyName variable:%s"),*PropertyName.ToString());
		return ;
	}
	bool* Data=BoolProperty->ContainerPtrToValuePtr<bool>(InObject);
	BoolProperty->SetPropertyValue (Data,InBool);
}

bool UCommonUIToolLib::GetBoolPropertyValue(UObject* InObject, const FName PropertyName)
{
	if (!InObject)
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("InObject is Invalid"));
		return false;
	}
	const FBoolProperty* BoolProperty = FindFProperty<FBoolProperty>(InObject->GetClass(), PropertyName);
	if (!BoolProperty)
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("Isn't find specify PropertyName variable:%s"),*PropertyName.ToString());
		return false;
	}
	return *BoolProperty->ContainerPtrToValuePtr<bool>(InObject);
}

void UCommonUIToolLib::SetFNamePropertyValue(UObject* InObject, const FName PropertyName, const FName InName)
{
	if (!InObject)
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("InObject is Invalid"));
		return ;
	}
	const FNameProperty* NameProperty = FindFProperty<FNameProperty>(InObject->GetClass(), PropertyName);
	if (!NameProperty)
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("Isn't find specify PropertyName variable:%s"),*PropertyName.ToString());
		return ;
	}
	FName* Data=NameProperty->ContainerPtrToValuePtr<FName>(InObject);
	NameProperty->SetPropertyValue(Data,InName);
}

FName UCommonUIToolLib::GetFNamePropertyValue(UObject* InObject, const FName PropertyName)
{
	if (!InObject)
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("InObject is Invalid"));
		return TEXT("");
	}
	const FNameProperty* NameProperty = FindFProperty<FNameProperty>(InObject->GetClass(), PropertyName);
	if (!NameProperty)
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("Isn't find specify PropertyName variable:%s"),*PropertyName.ToString());
		return TEXT("");
	}
	return *NameProperty->ContainerPtrToValuePtr<FName>(InObject);
}

void UCommonUIToolLib::SetFStringPropertyValue(UObject* InObject, const FName PropertyName, const FString InString)
{
	if (!InObject)
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("InObject is Invalid"));
		return ;
	}
	const FStrProperty* StrProperty = FindFProperty<FStrProperty>(InObject->GetClass(), PropertyName);
	if (!StrProperty)
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("Isn't find specify PropertyName variable:%s"),*PropertyName.ToString());
		return ;
	}
	FString* Data=StrProperty->ContainerPtrToValuePtr<FString>(InObject);
	StrProperty->SetPropertyValue(Data,InString);
}

FString UCommonUIToolLib::GetFStringPropertyValue(UObject* InObject, const FName PropertyName)
{
	if (!InObject)
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("InObject is Invalid"));
		return TEXT("");
	}
	const FStrProperty* StrProperty = FindFProperty<FStrProperty>(InObject->GetClass(), PropertyName);
	if (!StrProperty)
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("Isn't find specify PropertyName variable:%s"),*PropertyName.ToString());
		return TEXT("");
	}
	return *StrProperty->ContainerPtrToValuePtr<FString>(InObject);
}

void UCommonUIToolLib::SetFTextPropertyValue(UObject* InObject, const FName PropertyName, const FText InText)
{
	if (!InObject)
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("InObject is Invalid"));
		return ;
	}
	const FTextProperty* TextProperty = FindFProperty<FTextProperty>(InObject->GetClass(), PropertyName);
	if (!TextProperty)
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("Isn't find specify PropertyName variable:%s"),*PropertyName.ToString());
		return ;
	}
	FText* Data=TextProperty->ContainerPtrToValuePtr<FText>(InObject);
	TextProperty->SetPropertyValue(Data,InText);
}

FText UCommonUIToolLib::GetFTextPropertyValue(UObject* InObject, const FName PropertyName)
{
	if (!InObject)
   {
   		UE_LOG(FCommonUIToolLog,Warning,TEXT("InObject is Invalid"));
   		return NSLOCTEXT("UCommonUIToolLib", "","");
   }
   const FTextProperty* TextProperty = FindFProperty<FTextProperty>(InObject->GetClass(), PropertyName);
   if (!TextProperty)
   {
   		UE_LOG(FCommonUIToolLog,Warning,TEXT("Isn't find specify PropertyName variable:%s"),*PropertyName.ToString());
   		return NSLOCTEXT("UCommonUIToolLib", "","");
   }
   return *TextProperty->ContainerPtrToValuePtr<FText>(InObject);
}

void UCommonUIToolLib::SetUEnumPropertyValue(UObject* InObject, const FName PropertyName, const uint8 InMenuIndex)
{
	if (!InObject)
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("InObject is Invalid"));
		return ;
	}
	const FByteProperty* ByteProperty = FindFProperty<FByteProperty>(InObject->GetClass(), PropertyName);
	if (!ByteProperty)
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("Isn't find specify PropertyName variable:%s"),*PropertyName.ToString());
		return ;
	}
	uint8* Data= ByteProperty->ContainerPtrToValuePtr<uint8>(InObject);
	ByteProperty->SetPropertyValue(Data,InMenuIndex);
}

uint8 UCommonUIToolLib::GetUEnumPropertyValue(UObject* InObject, const FName PropertyName,FString& EnumValueString)
{
	if (!InObject)
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("InObject is Invalid"));
		EnumValueString="";
		return 255;
	}
	const FByteProperty* ByteProperty = FindFProperty<FByteProperty>(InObject->GetClass(), PropertyName);
	if (!ByteProperty)
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("Isn't find specify PropertyName variable:%s"),*PropertyName.ToString());
		EnumValueString="";
		return 255;
	}
	const UEnum* EnumType=ByteProperty->GetIntPropertyEnum();
	if (!EnumType)
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("EnumType is invalid"));
		EnumValueString="";
		return 255;
	}
	const uint8 EnumIndex= *ByteProperty->ContainerPtrToValuePtr<uint8>(InObject);
	EnumValueString=EnumType->GetNameByIndex(EnumIndex).ToString();
	return EnumIndex;
}

void UCommonUIToolLib::SetFVector2DPropertyValue(UObject* InObject, const FName PropertyName, const FVector2D InVector2D)
{
	if (!InObject)
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("InObject is Invalid"));
		return ;
	}
	const FStructProperty* StructProperty=FindFProperty<FStructProperty>(InObject->GetClass(), PropertyName);
	if (!StructProperty)
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("Isn't find specify PropertyName variable:%s"),*PropertyName.ToString());
		return ;
	}
	FVector2D* Data= StructProperty->ContainerPtrToValuePtr<FVector2D>(InObject);
	Data->X=InVector2D.X;
	Data->Y=InVector2D.Y;
}

FVector2D UCommonUIToolLib::GetFVector2DPropertyValue(UObject* InObject, const FName PropertyName)
{
	if (!InObject)
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("InObject is Invalid"));
		return FVector2D();
	}
	const FStructProperty* StructProperty=FindFProperty<FStructProperty>(InObject->GetClass(), PropertyName);
	if (!StructProperty)
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("Isn't find specify PropertyName variable:%s"),*PropertyName.ToString());
		return FVector2D();
	}
	return *StructProperty->ContainerPtrToValuePtr<FVector2D>(InObject);
}

void UCommonUIToolLib::SetFVectorPropertyValue(UObject* InObject, const FName PropertyName, const FVector InVector)
{
	if (!InObject)
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("InObject is Invalid"));
		return ;
	}
	const FStructProperty* StructProperty=FindFProperty<FStructProperty>(InObject->GetClass(), PropertyName);
	if (!StructProperty)
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("Isn't find specify PropertyName variable:%s"),*PropertyName.ToString());
		return ;
	}
	FVector* Data=StructProperty->ContainerPtrToValuePtr<FVector>(InObject);
	Data->X=InVector.X;
	Data->Y=InVector.Y;
	Data->Z=InVector.Z;
}

FVector UCommonUIToolLib::GetFVectorPropertyValue(UObject* InObject, const FName PropertyName)
{
	if (!InObject)
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("InObject is Invalid"));
		return FVector();
	}
	const FStructProperty* StructProperty=FindFProperty<FStructProperty>(InObject->GetClass(), PropertyName);
	if (!StructProperty)
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("Isn't find specify PropertyName variable:%s"),*PropertyName.ToString());
		return FVector();
	}
	return *StructProperty->ContainerPtrToValuePtr<FVector>(InObject);
}

void UCommonUIToolLib::SetFRotatorPropertyValue(UObject* InObject, const FName PropertyName, const FRotator InRotator)
{
	if (!InObject)
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("InObject is Invalid"));
		return ;
	}
	const FStructProperty* StructProperty=FindFProperty<FStructProperty>(InObject->GetClass(), PropertyName);
	if (!StructProperty)
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("Isn't find specify PropertyName variable:%s"),*PropertyName.ToString());
		return ;
	}
	FRotator* Data=StructProperty->ContainerPtrToValuePtr<FRotator>(InObject);
	Data->Pitch=InRotator.Pitch;
	Data->Yaw=InRotator.Yaw;
	Data->Roll=InRotator.Roll;
}

FRotator UCommonUIToolLib::GetFRotatorPropertyValue(UObject* InObject, const FName PropertyName)
{
	if (!InObject)
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("InObject is Invalid"));
		return FRotator();
	}
	const FStructProperty* StructProperty=FindFProperty<FStructProperty>(InObject->GetClass(), PropertyName);
	if (!StructProperty)
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("Isn't find specify PropertyName variable:%s"),*PropertyName.ToString());
		return FRotator();
	}
	return *StructProperty->ContainerPtrToValuePtr<FRotator>(InObject);
}

void UCommonUIToolLib::SetFTransformPropertyValue(UObject* InObject, const FName PropertyName, const FTransform InTransform)
{
	if (!InObject)
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("InObject is Invalid"));
		return ;
	}
	const FStructProperty* StructProperty=FindFProperty<FStructProperty>(InObject->GetClass(), PropertyName);
	if (!StructProperty)
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("Isn't find specify PropertyName variable:%s"),*PropertyName.ToString());
		return ;
	}
	FTransform* Data=StructProperty->ContainerPtrToValuePtr<FTransform>(InObject);
	Data->SetLocation(InTransform.GetLocation());
	Data->SetRotation(InTransform.GetRotation());
	Data->SetScale3D(InTransform.GetScale3D());
}

FTransform UCommonUIToolLib::GetFTransformPropertyValue(UObject* InObject, const FName PropertyName)
{
	if (!InObject)
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("InObject is Invalid"));
		return FTransform();
	}
	const FStructProperty* StructProperty=FindFProperty<FStructProperty>(InObject->GetClass(), PropertyName);
	if (!StructProperty)
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("Isn't find specify PropertyName variable:%s"),*PropertyName.ToString());
		return FTransform();
	}
	return *StructProperty->ContainerPtrToValuePtr<FTransform>(InObject);
}

void UCommonUIToolLib::SetUObjectPropertyValue(UObject* InObject, const FName PropertyName,UObject* InNewObject)
{
	if (!InObject)
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("InObject is Invalid"));
		return ;
	}
	const FObjectProperty* ObjectProperty = FindFProperty<FObjectProperty>(InObject->GetClass(), PropertyName);
	if (!ObjectProperty)
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("Isn't find specify PropertyName variable:%s"),*PropertyName.ToString());
		return ;
	}
	ObjectProperty->SetPropertyValue(ObjectProperty->ContainerPtrToValuePtr<UObject>(InObject),InNewObject);
}

UObject* UCommonUIToolLib::GetUObjectPropertyValue(UObject* InObject, const FName PropertyName)
{
	if (!InObject)
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("InObject is Invalid"));
		return nullptr;
	}
	const FObjectProperty* ObjectProperty = FindFProperty<FObjectProperty>(InObject->GetClass(), PropertyName);
	if (!ObjectProperty)
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("Isn't find specify PropertyName variable:%s"),*PropertyName.ToString());
		return nullptr;
	}
	return ObjectProperty->GetObjectPropertyValue(ObjectProperty->ContainerPtrToValuePtr<UObject>(InObject));
}

void UCommonUIToolLib::GetObjectAllFunction(const UObject* InObject, TArray<UFunction*>& Functions)
{
	TArray<UFunction*>FunctionsArray;
	if (!InObject)
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("InObject is Invalid"));
		return ;
	}
	for (TFieldIterator<UFunction>FunctionIt(InObject->GetClass());FunctionIt;++FunctionIt)
	{
		UFunction* Function=*FunctionIt;
		FunctionsArray.Add(Function);
	}
	Functions=FunctionsArray;
}

void UCommonUIToolLib::GetObjectFunction(const UObject* InObject, const FName FunctionName, UFunction*& Function)
{
	if (!InObject)
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("InObject is Invalid"));
		return ;
	}
	UFunction* TemFunction = InObject->GetClass()->FindFunctionByName(FunctionName,EIncludeSuperFlag::ExcludeSuper) ;
	if (!TemFunction)
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("Isn't find specify FunctionName :%s"),*FunctionName.ToString());
		return ;
	}
	Function=TemFunction;
}

void UCommonUIToolLib::GetFunctionAllParams(const UFunction* InFunction, TMap<FName, FName>& Params)
{
	TMap<FName, FName>ReturnParams;
	if (!InFunction)
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("InFunction is invalid:%s"),*InFunction->GetName());
		return ;
	}
	for (TFieldIterator<FProperty> ParamIt(InFunction); ParamIt; ++ParamIt)
	{
		const FProperty* Param = *ParamIt;
		ReturnParams.Add(FName(Param->GetName()),FName(Param->GetCPPType()));
	}
	Params=ReturnParams;
}

void UCommonUIToolLib::GetFunctionInputParams(const UFunction* InFunction, TMap<FName, FName>& Params)
{
	TMap<FName, FName>ReturnParams;
	if (!InFunction)
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("InFunction is invalid:%s"),*InFunction->GetName());
		return ;
	}
	for (TFieldIterator<FProperty> ParamIt(InFunction); ParamIt; ++ParamIt)
	{	
		if (((ParamIt->PropertyFlags&CPF_OutParm)!=CPF_OutParm)&&((ParamIt->PropertyFlags&CPF_ReturnParm)!=CPF_ReturnParm))
		{
			const FProperty* Param = *ParamIt;
			ReturnParams.Add(FName(Param->GetName()),FName(Param->GetCPPType()));
		}
	}
	Params=ReturnParams;
}

void UCommonUIToolLib::GetFunctionOutputParams(const UFunction* InFunction, TMap<FName, FName>& Params)
{
	TMap<FName, FName>ReturnParams;
	if (!InFunction)
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("InFunction is invalid:%s"),*InFunction->GetName());
		return ;
	}
	for (TFieldIterator<FProperty> ParamIt(InFunction); ParamIt; ++ParamIt)
	{
		if (ParamIt->PropertyFlags&CPF_OutParm||ParamIt->PropertyFlags&CPF_ReturnParm)
		{
			const FProperty* Param = *ParamIt;
			ReturnParams.Add(FName(Param->GetName()),FName(Param->GetCPPType()));
		}
	}
	Params=ReturnParams;
}


void UCommonUIToolLib::CallObjectFunction(
	UObject* InObject,
	const FName FunctionName)
{
	if (!InObject)
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("InObject is Invalid"));
		return ;
	}
	if (FunctionName.IsNone())
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("FunctionName.IsNone()"));
		return ;
	}
	UFunction* Function = InObject->FindFunction(FunctionName);
	if (!Function)
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("Isn't find specify FunctionName :%s"),*FunctionName.ToString());
		return ;
	}
	void* Params=FMemory_Alloca(Function->ParmsSize);
	InObject->ProcessEvent(Function,Params);
}

void UCommonUIToolLib::CallObjectFunctionOneParam(
	UObject* InObject,
	const FName FunctionName,
	const FString InOneParam)
{
	if (!InObject)
    	{
    		UE_LOG(FCommonUIToolLog,Warning,TEXT("InObject is Invalid"));
    		return ;
    	}
		if (FunctionName.IsNone())
		{
			UE_LOG(FCommonUIToolLog,Warning,TEXT("FunctionName.IsNone()"));
			return ;
		}
    	UFunction* Function = InObject->FindFunction(FunctionName);
    	if (!Function)
    	{
    		UE_LOG(FCommonUIToolLog,Warning,TEXT("Isn't find specify FunctionName :%s"),*FunctionName.ToString());
    		return ;
    	}
		//构建结构体,用来储存1个字符参数
		CommonUIToolReflexStruct::FOneParamStruct OneParamStruct;
		OneParamStruct.OneParam=InOneParam;
	
    	InObject->ProcessEvent(Function,&OneParamStruct);
}

void UCommonUIToolLib::CallObjectFunctionTwoParam(
	UObject* InObject,
	const FName FunctionName,
	const FString InOneParam,
	const FString InTwoParam)
{
	if (!InObject)
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("InObject is Invalid"));
		return ;
	}
	if (FunctionName.IsNone())
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("FunctionName.IsNone()"));
		return ;
	}
	UFunction* Function = InObject->FindFunction(FunctionName);
	if (!Function)
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("Isn't find specify FunctionName :%s"),*FunctionName.ToString());
		return ;
	}
	//构建结构体,用来储存1个字符参数
	CommonUIToolReflexStruct::FTwoParamStruct TwoParamStruct;
	TwoParamStruct.OneParam=InOneParam;
	TwoParamStruct.TwoParam=InTwoParam;
	
	InObject->ProcessEvent(Function,&TwoParamStruct);
}

void UCommonUIToolLib::CallObjectFunctionThreeParam(
	UObject* InObject,
	const FName FunctionName,
	const FString InOneParam,
	const FString InTwoParam,
	const FString InThreeParam)
{
	if (!InObject)
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("InObject is Invalid"));
		return ;
	}
	if (FunctionName.IsNone())
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("FunctionName.IsNone()"));
		return ;
	}
	UFunction* Function = InObject->FindFunction(FunctionName);
	if (!Function)
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("Isn't find specify FunctionName :%s"),*FunctionName.ToString());
		return ;
	}
	//构建结构体,用来储存1个字符参数
	CommonUIToolReflexStruct::FThreeParamStruct ThreeParamStruct;
	ThreeParamStruct.OneParam=InOneParam;
	ThreeParamStruct.TwoParam=InTwoParam;
	ThreeParamStruct.ThreeParam=InThreeParam;
	
	InObject->ProcessEvent(Function,&ThreeParamStruct);
}


void UCommonUIToolLib::CallNoParamsFunction(UObject* InObject,UFunction* InFunction)
{
	if (!InFunction||InFunction->NumParms>0)
    {
    	UE_LOG(FCommonUIToolLog,Warning,TEXT("InFunction is Invalid or expects parameters"));
    	return ;
    }
	InObject->ProcessEvent(InFunction,nullptr);
}

void UCommonUIToolLib::CallHaveParamsFunction(UObject* InObject,UFunction* InFunction,const FString ParamsJsonStr)
{
	if (!InFunction)
	{
		UE_LOG(FCommonUIToolLog,Warning,TEXT("InFunction is Invalid or NumParms is zero"));
		return ;
	}
	//参数为0则调用无参版本
	if (InFunction->NumParms==0)
	{
		InObject->ProcessEvent(InFunction,nullptr);
		return;
	}
	//声明参数数组
	TArray<uint8> ParamArray;
	//将给定数量的未初始化的元素添加到参数数组中
	ParamArray.AddUninitialized(InFunction->ParmsSize);
	//在未初始化的内存上初始化结构体,使用参数数组申请的内存
	InFunction->InitializeStruct(ParamArray.GetData());

	//创建一个Json对象，用来存放键值对
	TSharedPtr<FJsonObject> ParamJsonObject = MakeShared<FJsonObject>();

	//遍历函数,把参数名添加进Json对象中
	for (TFieldIterator<FProperty>FunctionParam(InFunction); FunctionParam; ++FunctionParam)
	{
		FProperty* FunctionParamProperty = *FunctionParam;
		if (FunctionParamProperty->PropertyFlags & CPF_Parm)
		{
			//将参数名作为键值添加进Json对象中,值暂时设置为NULL
			ParamJsonObject->SetField(FunctionParamProperty->GetNameCPP(),nullptr);
			//MakeShared<FJsonValueString>("")
		}
	}

	//ParamJsonObject有效才对其进行赋值操作
	if (ParamJsonObject)
	{
		////将传入的ParamsJsonStr中转为Json对象再将Key对应的Value填入ParamJsonObject
		TSharedRef<TJsonReader<>> JsonReader = TJsonReaderFactory<>::Create(ParamsJsonStr);
		TSharedPtr<FJsonObject> InJsonObject;
		if (FJsonSerializer::Deserialize(JsonReader, InJsonObject))
		{
				//遍历函数参数，获取参数名称和类型
				for (TFieldIterator<FProperty> FunctionParam(InFunction); FunctionParam; ++FunctionParam)
				{
					FProperty* FunctionParamProperty = *FunctionParam;

					//属性为传入参数时才进行操作
					if (FunctionParamProperty->PropertyFlags & CPF_Parm)
					{
						//获取参数类型
						FString FunctionParamType = FunctionParamProperty->GetCPPType();
						//获取参数名,用于根据参数获取/设置Json对象的Value
						const FString FunctionParamName = FunctionParamProperty->GetNameCPP();
						//
						if (FunctionParamType.Equals("bool"))
						{
							bool TempValue = InJsonObject->GetBoolField(FunctionParamName);
							ParamJsonObject->SetBoolField(FunctionParamName, TempValue);
						//	
						}else if (FunctionParamType.Equals("FString"))
						{
							FString TempValue = InJsonObject->GetStringField(FunctionParamName);
							ParamJsonObject->SetStringField(FunctionParamName, TempValue);
						//	
						}else if (FunctionParamType.Equals("int32"))
						{
							int32 TempValue = InJsonObject->GetNumberField(FunctionParamName);
							ParamJsonObject->SetNumberField(FunctionParamName, TempValue);
						//	
						}else if (FunctionParamType.Equals("int64"))
						{
							int64 TempValue = InJsonObject->GetNumberField(FunctionParamName);
							ParamJsonObject->SetNumberField(FunctionParamName, TempValue);
						}
					}else if (FunctionParamProperty->PropertyFlags & CPF_ReturnParm)
					{

					}
				}
		}else
		{
			UE_LOG(FCommonUIToolLog,Warning,TEXT("ParamsJsonStr is not convert Json Object"));
		}
	}
	
	TArray<uint8> ParamsContainer;
	//用于将任意数据存储到指定内存位置的归档
	FMemoryWriter Writer(ParamsContainer);
	TSharedRef<TJsonWriter<UCS2CHAR>> JsonWriter = TJsonWriter<UCS2CHAR>::Create(&Writer);
	
	FJsonSerializer::Serialize(ParamJsonObject.ToSharedRef(), JsonWriter);

	//用于从指定内存位置读取任意数据的归档
	FMemoryReader Reader(ParamsContainer);
	FJsonStructDeserializerBackend DeserializerBackend(Reader);
	FStructDeserializer::Deserialize(ParamArray.GetData(), *InFunction, DeserializerBackend);
	InObject->ProcessEvent(InFunction, ParamArray.GetData());	
}
#pragma endregion

