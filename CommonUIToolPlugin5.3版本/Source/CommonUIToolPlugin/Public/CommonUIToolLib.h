// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Button.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CommonUIToolLib.generated.h"

/**
 * 
 */
UCLASS()
class COMMONUITOOLPLUGIN_API UCommonUIToolLib : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
#pragma region UMG通用方法

	/**
	 * 该方法获取UI的第一级父UI对象
	 * @param InWidget 要查找其父UI的子UI
	 * @return 找到则返回父UI,否则返回nullptr
	 */
	UFUNCTION(BlueprintPure,Category="CommonUIToolLib|UMG")
	static UUserWidget* GetWidgetFirstOuterWidget(const UUserWidget* InWidget);

	/**
	 * 设置UI的X偏移值
	 * @param InWidget 要设置的UI
	 * @param InXValue 设置的X偏移值
	 */
	UFUNCTION(BlueprintCallable,Category="CommonUIToolLib|UI")
	static void SetUIWidgetTranslationXValue(UWidget* InWidget,const float InXValue);

	/**
	 * 设置UI的Y偏移值
	 * @param InWidget 要设置的UI
	 * @param InYValue 设置的Y偏移值
	 */
	UFUNCTION(BlueprintCallable,Category="CommonUIToolLib|UI")
	static void SetUIWidgetTranslationYValue(UWidget* InWidget,const float InYValue);

	/**
	 * 获取UI的X偏移值
	 * @param InWidget 要获取X偏移值的UI
	 * @param CurrentXValue 返回UI当前的X偏移值
	 */
	UFUNCTION(BlueprintPure,Category="CommonUIToolLib|UI")
	static void GetUIWidgetTranslationXValue(const UWidget* InWidget,float& CurrentXValue);

	/**
	 * 值获取UI的Y偏移值
	 * @param InWidget 要获取Y偏移值的UI
	 * @param CurrentYValue 返回UI当前的Y偏移值
	 */
	UFUNCTION(BlueprintPure,Category="CommonUIToolLib|UI")
	static void GetUIWidgetTranslationYValue(const UWidget* InWidget,float& CurrentYValue);

	/**
	 * 获取UI的偏移值
	 * @param InWidget 要获取偏移值的UI
	 * @param CurrentXValue 返回UI当前的偏移值
	 */
	UFUNCTION(BlueprintPure,Category="CommonUIToolLib|UI")
	static void GetUIWidgetTranslation(const UWidget* InWidget,FVector2D& CurrentXValue);
	
#pragma endregion

	
#pragma region FSlateBrush系列方法

	/**
	 * 构建一个FSlateBrush
	 * @return 返回构建的FSlateBrush
	 */
	UFUNCTION(BlueprintCallable,Category="CommonUIToolLib|Brush")
	static FSlateBrush MakeSlateBrush();

	/**
	 * 获取Bursh的Image
	 * @param InSlateBrush 传入的FSlateBrush
	 * @return 返回Bursh的Image
	 */
	UFUNCTION(BlueprintPure,Category="CommonUIToolLib|Brush")
	static UObject* GetBrushImage(const FSlateBrush& InSlateBrush);

	//设置Bursh的Image
	UFUNCTION(BlueprintCallable,Category="CommonUIToolLib|Brush")
	static void SetBrushImage(const FSlateBrush& InSlateBrush,const UObject* InImage);
	
	//获取Bursh的ImageSize
    UFUNCTION(BlueprintPure,Category="CommonUIToolLib|Brush")
    static FVector2D GetBrushImageSize(const FSlateBrush& InSlateBrush);
    
    //设置Bursh的ImageSize
    UFUNCTION(BlueprintCallable,Category="CommonUIToolLib|Brush")
    static void SetBrushImageSize(const FSlateBrush& InSlateBrush,const FVector2D InImageSize);

	//获取Bursh的TintClor
	UFUNCTION(BlueprintPure,Category="CommonUIToolLib|Brush")
	static FLinearColor GetBrushTintClor(const FSlateBrush& InSlateBrush);

	//设置Bursh的TintClor
	UFUNCTION(BlueprintCallable,Category="CommonUIToolLib|Brush")
	static void SetBrushTintClor(const FSlateBrush& InSlateBrush,const FLinearColor InColor);

	//获取Bursh的DrawAs
	UFUNCTION(BlueprintPure,Category="CommonUIToolLib|Brush")
	static ESlateBrushDrawType::Type GetBrushDrawAs(const FSlateBrush& InSlateBrush);

	//设置Bursh的DrawAs
	UFUNCTION(BlueprintCallable,Category="CommonUIToolLib|Brush")
	static void SetBrushDrawAs(const FSlateBrush& InSlateBrush,const  ESlateBrushDrawType::Type InDrawAsType);

	//获取Bursh的CornerRadii
	UFUNCTION(BlueprintPure,Category="CommonUIToolLib|Brush")
	static FVector4 GetBrushCornerRadii(const FSlateBrush& InSlateBrush);

	//设置Bursh的CornerRadii
	UFUNCTION(BlueprintCallable,Category="CommonUIToolLib|Brush")
	static void SetBrushCornerRadii(const FSlateBrush& InSlateBrush,const FVector4 InCornerRadii);

	//获取Bursh的OutlineColor
	UFUNCTION(BlueprintPure,Category="CommonUIToolLib|Brush")
	static FLinearColor GetBrushOutlineColor(const FSlateBrush& InSlateBrush);

	//设置Bursh的OutlineColor
	UFUNCTION(BlueprintCallable,Category="CommonUIToolLib|Brush")
	static void SetBrushOutlineColor(const FSlateBrush& InSlateBrush,const FLinearColor InOutlineColor);

	//获取Bursh的Width
	UFUNCTION(BlueprintPure,Category="CommonUIToolLib|Brush")
	static float GetBrushWidth(const FSlateBrush& InSlateBrush);

	//设置Bursh的Width
	UFUNCTION(BlueprintCallable,Category="CommonUIToolLib|Brush")
	static void SetBrushWidth(const FSlateBrush& InSlateBrush,const float InWidth);

	//获取Bursh的RoundingType
	UFUNCTION(BlueprintPure,Category="CommonUIToolLib|Brush")
	static ESlateBrushRoundingType::Type GetBrushRoundingType(const FSlateBrush& InSlateBrush);

	//设置Bursh的OutlineColor
	UFUNCTION(BlueprintCallable,Category="CommonUIToolLib|Brush")
	static void SetBrushRoundingType(const FSlateBrush& InSlateBrush,const ESlateBrushRoundingType::Type InRoundingType);

	//获取Bursh的bUseBrushTransparency
	UFUNCTION(BlueprintPure,Category="CommonUIToolLib|Brush")
	static bool GetBrushbUseBrushTransparency(const FSlateBrush& InSlateBrush);

	//设置Bursh的OutlineColor
	UFUNCTION(BlueprintCallable,Category="CommonUIToolLib|Brush")
	static void SetBrushbUseBrushTransparency(const FSlateBrush& InSlateBrush,const bool InbUseBrushTransparency);
	
	//获取Bursh的Tiling
	UFUNCTION(BlueprintPure,Category="CommonUIToolLib|Brush")
	static ESlateBrushTileType::Type GetBrushTiling(const FSlateBrush& InSlateBrush);

	//设置Bursh的Tiling
	UFUNCTION(BlueprintCallable,Category="CommonUIToolLib|Brush")
	static void SetBrushTiling(const FSlateBrush& InSlateBrush,const  ESlateBrushTileType::Type InTiling);

#pragma	endregion 

#pragma region FSliderStyle系列方法

	//获取FSliderStyle的NormalBarImage
	UFUNCTION(BlueprintPure,Category="CommonUIToolLib|SliderStyle")
	static FSlateBrush GetSliderNormalBarImage(const FSliderStyle InSliderStyle);

	//设置FSliderStyle的NormalBarImage
	UFUNCTION(BlueprintCallable,Category="CommonUIToolLib|SliderStyle")
	static void SetSliderNormalBarImage(const FSliderStyle& InSliderStyle,const FSlateBrush& InSlateBrush);

	//获取FSliderStyle的HoveredBarImage
	UFUNCTION(BlueprintPure,Category="CommonUIToolLib|SliderStyle")
	static FSlateBrush GetSliderHoveredBarImage(const FSliderStyle InSliderStyle);

	//设置FSliderStyle的HoveredBarImage
	UFUNCTION(BlueprintCallable,Category="CommonUIToolLib|SliderStyle")
	static void SetSliderHoveredBarImage(const FSliderStyle& InSliderStyle,const FSlateBrush& InSlateBrush);

	//获取FSliderStyle的DisabledBarImage
	UFUNCTION(BlueprintPure,Category="CommonUIToolLib|SliderStyle")
	static FSlateBrush GetSliderDisabledBarImage(const FSliderStyle InSliderStyle);

	//设置FSliderStyle的DisabledBarImage
	UFUNCTION(BlueprintCallable,Category="CommonUIToolLib|SliderStyle")
	static void SetSliderDisabledBarImage(const FSliderStyle& InSliderStyle,const FSlateBrush& InSlateBrush);

	//获取FSliderStyle的NormalThumbImage
	UFUNCTION(BlueprintPure,Category="CommonUIToolLib|SliderStyle")
	static FSlateBrush GetSliderNormalThumbImage(const FSliderStyle InSliderStyle);

	//设置FSliderStyle的NormalThumbImage
	UFUNCTION(BlueprintCallable,Category="CommonUIToolLib|SliderStyle")
	static void SetSliderNormalThumbImage(const FSliderStyle& InSliderStyle,const FSlateBrush& InSlateBrush);

	//获取FSliderStyle的HoveredThumbImage
	UFUNCTION(BlueprintPure,Category="CommonUIToolLib|SliderStyle")
	static FSlateBrush GetSliderHoveredThumbImage(const FSliderStyle InSliderStyle);

	//设置FSliderStyle的HoveredThumbImage
	UFUNCTION(BlueprintCallable,Category="CommonUIToolLib|SliderStyle")
	static void SetSliderHoveredThumbImage(const FSliderStyle& InSliderStyle,const FSlateBrush& InSlateBrush);

	//获取FSliderStyle的DisabledThumbImage
	UFUNCTION(BlueprintPure,Category="CommonUIToolLib|SliderStyle")
	static FSlateBrush GetSliderDisabledThumbImage(const FSliderStyle InSliderStyle);

	//设置FSliderStyle的DisabledThumbImage
	UFUNCTION(BlueprintCallable,Category="CommonUIToolLib|SliderStyle")
	static void SetSliderDisabledThumbImage(const FSliderStyle& InSliderStyle,const FSlateBrush& InSlateBrush);

	//获取FSliderStyle的Thickness
	UFUNCTION(BlueprintPure,Category="CommonUIToolLib|SliderStyle")
	static float GetSliderThickness(const FSliderStyle InSliderStyle);

	//设置FSliderStyle的Thickness
	UFUNCTION(BlueprintCallable,Category="CommonUIToolLib|SliderStyle")
	static void SetSliderThickness(const FSliderStyle& InSliderStyle,const float InThickness);
	
#pragma endregion 

#pragma region Image	
	//获取Image的图片资源文件
	UFUNCTION(BlueprintPure,Category="CommonUIToolLib|Image")
	static UObject* GetImageResource(const UImage* InImage);
	
	//设置图片的X值大小
	UFUNCTION(BlueprintCallable,Category="CommonUIToolLib|Image")
	static void SetImageSizeXValue(const UImage* InImage,const float NewImageXValue);

	//设置图片的Y值大小
	UFUNCTION(BlueprintCallable,Category="CommonUIToolLib|Image")
	static void SetImageSizeYValue(const UImage* InImage,const float NewImageYValue);
	
	//设置Image的大小
	UFUNCTION(BlueprintCallable,Category="CommonUIToolLib|Image")     
	static void SetImageSize(const UImage* InImage, const FVector2D NewImageSize);

	//通过Image的纹理资源大小再来设置图片的大小
	UFUNCTION(BlueprintCallable,Category="CommonUIToolLib|Image")
	static void SetImageSizeByResource(const UImage* InImage,const float& InScale);
	
	//设置图片的显示类型,例如Box、Border、Image、RoundBox
	UFUNCTION(BlueprintCallable,Category="CommonUIToolLib|Image")
	static void SetImageDrawAs(const UImage* InImage, const ESlateBrushDrawType::Type InDrawAs);
	
	//设置图片的最外层线的颜色,需要开启DrawAs的值为RoundedBox                                                   
	UFUNCTION(BlueprintCallable,Category="CommonUIToolLib|Image")                            
	static void SetImageOutlineWidth(const UImage* InImage,const float& InWidth); 

	//设置图片的最外层线的颜色,需要开启DrawAs的值为RoundedBox
	UFUNCTION(BlueprintCallable,Category="CommonUIToolLib|Image")
	static void SetImageOutlineColor(const UImage* InImage,const FLinearColor InLinearColor);

	//设置图片的圆角值，需要开启DrawAs的值为RoundedBox
	UFUNCTION(BlueprintCallable,Category="CommonUIToolLib|Image")
	static void SetImageOutlineCornerRadii(const UImage* InImage,const FVector4& InCornerRadii);
#pragma endregion

#pragma region Button
	
	/**
	 * 设置Button的Style属性的Normal的Tint颜色
	 * @param InButton 需要设置Normal的Tint颜色的Button
	 * @param InLinearColor 要设置的颜色
	 */
	UFUNCTION(BlueprintCallable,Category="CommonUIToolLib|Button")
	static void SetButtonNormalTintColor(const UButton* InButton, const FLinearColor InLinearColor);

	/**
	 * 设置Button的Style属性的Hovered的Tint颜色
	 * @param InButton 需要设置Hovered的Tint颜色的Button
	 * @param InLinearColor 要设置的颜色
	 */
	UFUNCTION(BlueprintCallable,Category="CommonUIToolLib|Button")
	static void SetButtonHoveredTintColor(const UButton* InButton, const FLinearColor InLinearColor);

	/**
	 * 设置Button的Style属性的Pressed的Tint颜色
	 * @param InButton 需要设置Pressed的Tint颜色的Button
	 * @param InLinearColor 要设置的颜色
	 */
	UFUNCTION(BlueprintCallable,Category="CommonUIToolLib|Button")
	static void SetButtonPressedTintColor(const UButton* InButton, const FLinearColor InLinearColor);

	/**
	 * 设置Button的Style属性的Disabled的Tint颜色
	 * @param InButton 需要设置Disabled的Tint颜色的Button
	 * @param InLinearColor 要设置的颜色
	 */
	UFUNCTION(BlueprintCallable,Category="CommonUIToolLib|Button")
	static void SetButtonDisabledTintColor(const UButton* InButton, const FLinearColor InLinearColor);

	/**
	 * 设置Button的Style属性的NormalForeground颜色
	 * @param InButton 需要设置NormalForeground颜色的Button
	 * @param InLinearColor 要设置的颜色
	 */
	UFUNCTION(BlueprintCallable,Category="CommonUIToolLib|Button")
	static void SetButtonNormalForeground(const UButton* InButton, const FLinearColor InLinearColor);

	/**
	 * 设置Button的Style属性的HoveredForeground颜色
	 * @param InButton 需要设置HoveredForeground颜色的Button
	 * @param InLinearColor 要设置的颜色
	 */
	UFUNCTION(BlueprintCallable,Category="CommonUIToolLib|Button")
	static void SetButtonHoveredForeground(const UButton* InButton, const FLinearColor InLinearColor);

	/**
	 * 设置Button的Style属性的PressedForeground颜色
	 * @param InButton 需要设置PressedForeground颜色的Button
	 * @param InLinearColor 要设置的颜色
	 */
	UFUNCTION(BlueprintCallable,Category="CommonUIToolLib|Button")
	static void SetButtonPressedForeground(const UButton* InButton, const FLinearColor InLinearColor);

	/**
	 * 设置Button的Style属性的DisabledForeground颜色
	 * @param InButton 需要设置DisabledForeground颜色的Button
	 * @param InLinearColor 要设置的颜色
	 */
	UFUNCTION(BlueprintCallable,Category="CommonUIToolLib|Button")
	static void SetButtonDisabledForeground(const UButton* InButton, const FLinearColor InLinearColor);

	/**
	 * 设置Button的NormalPadding
	 * @param InButton 需要设置NormalPadding的Button
	 * @param InMargin 要设置的值
	 */
	UFUNCTION(BlueprintCallable,Category="CommonUIToolLib|Button")
	static void SetButtonNormalPadding(const UButton* InButton,const FMargin InMargin);

	/**
	 * 设置Button的PressedPadding
	 * @param InButton 需要设置PressedPadding的Button
	 * @param InMargin 要设置的值
	 */
	UFUNCTION(BlueprintCallable,Category="CommonUIToolLib|Button")
	static void SetButtonPressedPadding(const UButton* InButton,const FMargin InMargin);

	/**
	 * 设置Button的PressedSound
	 * @param InButton 需要设置PressedSound的Button
	 * @param InSlateSound 要设置的值
	 */
	UFUNCTION(BlueprintCallable,Category="CommonUIToolLib|Button")
	static void SetButtonPressedSound(const UButton* InButton,const FSlateSound InSlateSound);

	/**
	 * 设置Button的HoveredSound
	 * @param InButton 需要设置HoveredSound的Button
	 * @param InSlateSound 要设置的值
	 */
	UFUNCTION(BlueprintCallable,Category="CommonUIToolLib|Button")
	static void SetButtonHoveredSound(const UButton* InButton,const FSlateSound InSlateSound);





	
#pragma endregion	

#pragma region Border
	//设置图片的显示类型,例如Box、Border、Image、RoundBox
	UFUNCTION(BlueprintCallable,Category="CommonUIToolLib|Image")
	static void SetBorderDrawAs(const UBorder* InBorder, const ESlateBrushDrawType::Type InDrawAs);
	
	//设置图片的最外层线的颜色,需要开启DrawAs的值为RoundedBox                                                   
	UFUNCTION(BlueprintCallable,Category="CommonUIToolLib|Image")                            
	static void SetBorderOutlineWidth(const UBorder* InBorder,const float& InWidth);

	//设置图片的Tint的颜色
	UFUNCTION(BlueprintCallable,Category="CommonUIToolLib|Image")
	static void SetBorderTintColor(const UBorder* InBorder,const FLinearColor InLinearColor);
	
	//设置图片的最外层线的颜色,需要开启DrawAs的值为RoundedBox
	UFUNCTION(BlueprintCallable,Category="CommonUIToolLib|Image")
	static void SetBorderOutlineColor(const UBorder* InBorder,const FLinearColor InLinearColor);

	//设置图片的圆角值，需要开启DrawAs的值为RoundedBox
	UFUNCTION(BlueprintCallable,Category="CommonUIToolLib|Image")
	static void SetBorderOutlineCornerRadii(const UBorder* InBorder,const FVector4& InCornerRadii);
#pragma endregion

#pragma region TextBlock
	//设置文本块的字体大小
	UFUNCTION(BlueprintCallable,Category="CommonUIToolLib|Text")
	static void SetTextFontSize(const UTextBlock* InText,const int FontSize);

	//设置文本块的字体
	UFUNCTION(BlueprintCallable,Category="CommonUIToolLib|Text")
	static void SetTextFontFamily(const UTextBlock* InText,const UObject* InFontFamily);
#pragma endregion	







#pragma region 字符串处理
	/**
	 * 将FTimeSpan转换为字符串
	 * @param InTimespan 
	 * @return 
	 */
	UFUNCTION(BlueprintPure,Category="CommonUIToolLib|FTimespan")
	static FString FTimespanToString(const FTimespan& InTimespan);
	
	/**
	 * 清除字符串的换行转义字符"\n"
	 * @param InStr 需要清除换行转义字符的字符串
	 * @return 清除完换行转义字符"\n"的字符串
	 */
	UFUNCTION(BlueprintPure,Category="CommonUIToolLib")
	static FString ClearWrapThansformChar(const FString& InStr);

	/**
	 * 将整型转换为字符串,如果整形值小于10,则在字符串前加0
	 * @param InInt 需要转换的整型
	 * @return 转换后的字符串
	 */
	UFUNCTION(BlueprintPure,Category="CommonUIToolLib")
	static FString AutoAddZero(const uint8 InInt);

	/**
	 * 精确根据WrapNum自动换行
	 * @param InStr 需要换行的字符串
	 * @param WrapNum 指定当一行的字数为多少时换到新的一行
	 * @return 换行后的字符串
	 */
	UFUNCTION(BlueprintPure,Category="CommonUIToolLib")
	static FString AutoWrapLineExactly(const FString& InStr,const uint8 WrapNum);
	
	/**
	 * 根据WrapNum自动换行,但是数字和小写字母每个字符只会计算为OtherCharPresentValue个汉字数
	 * @param InStr 需要换行的字符串
	 * @param WrapNum 指定当一行的字数为多少时换到新的一行
	 * @param bLessAChar 指定一行是多一个数字或小写字母还是少一个
	 * @param OtherCharPresentValue 指定数字和小写字母每个字符相当于汉子字符的多少
	 * @return 换行后的字符串
	 */
	UFUNCTION(BlueprintPure,Category="CommonUIToolLib")
	static FString AutoWrapLine(const FString& InStr,const uint8 WrapNum,const bool bLessAChar=true,const float OtherCharPresentValue=0.5);

	/**
	 * 根据WrapNum自动换行,也会到指定的字符換行。数字和小写字母每个字符只会计算为OtherCharPresentValue个汉字数,
	 * @param InStr 需要换行的字符串
	 * @param WrapNum 指定当一行的字数为多少时换到新的一行
	 * @param SpecifyStr 指定的换行字符
	 * @param bLessAChar 指定一行是多一个数字或小写字母还是少一个
	 * @param OtherCharPresentValue 指定数字和小写字母每个字符相当于汉子字符的多少
	 * @return 换行后的字符串
	 */
	UFUNCTION(BlueprintPure,Category="CommonUIToolLib")
	static FString AutoWrapLineSpecifyChar(const FString& InStr,const uint8 WrapNum,const FString&SpecifyStr,const bool bLessAChar=true,const float OtherCharPresentValue=0.5);

	/**
	 * 遇到指定的字符換行
	 * @param InStr 传入的字符串
	 * @param WarpLineStr 指定的换行字符
	 * @param SearchCase 是否区分大小写枚举
	 * @return 处理后的字符串
	 */
	UFUNCTION(BlueprintPure,Category="CommonUIToolLib")
	static FString AutoWrapLineBySpecifyStr(const FString& InStr,const FString& WarpLineStr,ESearchCase::Type SearchCase = ESearchCase::IgnoreCase);

	/**
	 * 保留指定位数的字符串
	 * @param InStr 传入的字符串
	 * @param PointNum 保留的位数
	 * @return 处理后的字符串
	 */
	UFUNCTION(BlueprintPure,Category="CommonUIToolLib")
	static FString ReserveSpecifyPointNum(const FString& InStr,const uint8 PointNum);

	/**
	 * 获取输入字符串的第一个字符Unicode编码
	 * @param CharStr 传入的字符串
	 * @return 字符的Unicode编码
	 */
	UFUNCTION(BlueprintPure,Category="CommonUIToolLib")
	static int32 GetCharCode(const FString& CharStr);

	/**
	 * 获取字符串的Unicode编码
	 * @param InStr 传入的字符串
	 * @param ReturnUnicodeArray 返回的Unicode数组
	 */
	UFUNCTION(BlueprintPure,Category="CommonUIToolLib")
	static void GetStringUniCode(const FString& InStr,TArray<int32>& ReturnUnicodeArray);

#pragma endregion

#pragma region 反射相关
	//获取类的所有属性名称
	UFUNCTION(BlueprintPure,Category="CommonUIToolLib")
	static void GetClassAllPropertyName(const UClass* InClass,TArray<FName>&PropertyNames);

	//根据属性名设置对应属性的uint8
	UFUNCTION(BlueprintCallable,Category="CommonUIToolLib|Byte")
	static void SetBytePropertyValue(UObject* InObject,const FName PropertyName,const uint8 InByte);

	//根据属性名获取对应属性的uint8
	UFUNCTION(BlueprintPure,Category="CommonUIToolLib|Byte")
	static uint8 GetBytePropertyValue(UObject* InObject,const FName PropertyName);
	
	//根据属性名设置对应属性的整型值
	UFUNCTION(BlueprintCallable,Category="CommonUIToolLib|Int")
	static void SetIntPropertyValue(UObject* InObject,const FName PropertyName,const int InInt);

	//根据属性名获取对应属性的整型值
	UFUNCTION(BlueprintPure,Category="CommonUIToolLib|Int")
	static int GetIntPropertyValue(UObject* InObject,const FName PropertyName);

	//根据属性名设置对应属性的单精度浮点值
	UFUNCTION(BlueprintCallable,Category="CommonUIToolLib|Float")
	static void SetFloatPropertyValue(UObject* InObject,const FName PropertyName,const float InFloat);
	
	//根据属性名获取对应属性的单精度浮点值
	UFUNCTION(BlueprintPure,Category="CommonUIToolLib||Float")
	static float GetFloatPropertyValue(UObject* InObject,const FName PropertyName);

	//根据属性名设置对应属性的双精度浮点值
	UFUNCTION(BlueprintCallable,Category="CommonUIToolLib|Double")
	static void SetDoublePropertyValue(UObject* InObject,const FName PropertyName,const double InDouble);

	//根据属性名获取对应属性的双精度浮点值
	UFUNCTION(BlueprintPure,Category="CommonUIToolLib|Double")
	static double GetDoublePropertyValue(UObject* InObject,const FName PropertyName);
	
	//根据属性名设置对应属性的布尔值
	UFUNCTION(BlueprintCallable,Category="CommonUIToolLib|Bool")
	static void SetBoolPropertyValue(UObject* InObject,const FName PropertyName,const bool InBool);
	
	//根据属性名获取对应属性的布尔值
	UFUNCTION(BlueprintPure,Category="CommonUIToolLib|Bool")
	static bool GetBoolPropertyValue(UObject* InObject,const FName PropertyName);

	//根据属性名设置对应属性的FName
	UFUNCTION(BlueprintCallable,Category="CommonUIToolLib|FName")
	static void SetFNamePropertyValue(UObject* InObject,const FName PropertyName,const FName InName);
	
	//根据属性名获取对应属性的FName
	UFUNCTION(BlueprintPure,Category="CommonUIToolLib|FName")
	static FName GetFNamePropertyValue(UObject* InObject,const FName PropertyName);

	//根据属性名设置对应属性的FString
	UFUNCTION(BlueprintCallable,Category="CommonUIToolLib|FString")
	static void SetFStringPropertyValue(UObject* InObject,const FName PropertyName,const FString InString);
	
	//根据属性名获取对应属性的FName
	UFUNCTION(BlueprintPure,Category="CommonUIToolLib|FString")
	static FString GetFStringPropertyValue(UObject* InObject,const FName PropertyName);

	//根据属性名设置对应属性的FText
	UFUNCTION(BlueprintCallable,Category="CommonUIToolLib|FText")
	static void SetFTextPropertyValue(UObject* InObject,const FName PropertyName,const FText InText);
	
	//根据属性名获取对应属性的FText
	UFUNCTION(BlueprintPure,Category="CommonUIToolLib|FText")
	static FText GetFTextPropertyValue(UObject* InObject,const FName PropertyName);

	//根据属性名设置对应属性的枚举值
	UFUNCTION(BlueprintCallable,Category="CommonUIToolLib|UEnum")
	static void SetUEnumPropertyValue(UObject* InObject,const FName PropertyName,const uint8 InMenuIndex);

	//根据属性名获取对应属性的枚举值
	UFUNCTION(BlueprintPure,Category="CommonUIToolLib|UEnum")
	static uint8 GetUEnumPropertyValue(UObject* InObject,const FName PropertyName,FString& EnumValueString);

	//根据属性名设置对应属性的Vector2D
	UFUNCTION(BlueprintCallable,Category="CommonUIToolLib|Vector2D")
	static void SetFVector2DPropertyValue(UObject* InObject,const FName PropertyName,const FVector2D InVector2D);

	//根据属性名获取对应属性的Vector2D
	UFUNCTION(BlueprintPure,Category="CommonUIToolLib|Vector2D")
	static FVector2D GetFVector2DPropertyValue(UObject* InObject,const FName PropertyName);
	
	//根据属性名设置对应属性的Vector
	UFUNCTION(BlueprintCallable,Category="CommonUIToolLib|Vector")
	static void SetFVectorPropertyValue(UObject* InObject,const FName PropertyName,const FVector InVector);

	//根据属性名获取对应属性的Vector
	UFUNCTION(BlueprintPure,Category="CommonUIToolLib|Vector")
	static FVector GetFVectorPropertyValue(UObject* InObject,const FName PropertyName);
	
	//根据属性名设置对应属性的Rotator
	UFUNCTION(BlueprintCallable,Category="CommonUIToolLib|Rotator")
	static void SetFRotatorPropertyValue(UObject* InObject,const FName PropertyName,const FRotator InRotator);

	//根据属性名获取对应属性的Rotator
	UFUNCTION(BlueprintPure,Category="CommonUIToolLib|Rotator")
	static FRotator GetFRotatorPropertyValue(UObject* InObject,const FName PropertyName);

	//根据属性名设置对应属性的Transform
	UFUNCTION(BlueprintCallable,Category="CommonUIToolLib|Transform")
	static void SetFTransformPropertyValue(UObject* InObject,const FName PropertyName,const FTransform InTransform);

	//根据属性名获取对应属性的Transform
	UFUNCTION(BlueprintPure,Category="CommonUIToolLib|Transform")
	static FTransform GetFTransformPropertyValue(UObject* InObject,const FName PropertyName);
	
	//根据属性名设置对应属性的UObject
	UFUNCTION(BlueprintCallable,Category="CommonUIToolLib|UObject")
	static void SetUObjectPropertyValue(UObject* InObject,const FName PropertyName,UObject* InNewObject);
	
	//根据属性名获取对应属性的UObject
	UFUNCTION(BlueprintPure,Category="CommonUIToolLib|UObject")
	static UObject* GetUObjectPropertyValue(UObject* InObject,const FName PropertyName);
	

	//获取对象上所有的函数方法
	UFUNCTION(BlueprintPure,Category="CommonUIToolLib|Function")
	static void GetObjectAllFunction(const UObject* InObject,TArray<UFunction*>& Functions);

	//根据函数名获取对象上的函数方法
	UFUNCTION(BlueprintPure,Category="CommonUIToolLib|Function")
	static void GetObjectFunction(const UObject* InObject,const FName FunctionName,UFunction*& Function);

	//获取UFunction的所有参数
	UFUNCTION(BlueprintPure,Category="CommonUIToolLib|Function")
	static void GetFunctionAllParams(const UFunction* InFunction,TMap<FName,FName>& Params);

	//获取UFunction的输入参数
	UFUNCTION(BlueprintPure,Category="CommonUIToolLib|Function")
	static void GetFunctionInputParams(const UFunction* InFunction,TMap<FName,FName>& Params);

	//获取UFunction的输出参数
	UFUNCTION(BlueprintPure,Category="CommonUIToolLib|Function")
	static void GetFunctionOutputParams(const UFunction* InFunction,TMap<FName,FName>& Params);
	
	//调用对象的函数方法
	UFUNCTION(BlueprintCallable,Category="CommonUIToolLib|Function")
	static void CallObjectFunction(UObject* InObject,const FName FunctionName);

	//调用具有一个字符参数的函数方法
	UFUNCTION(BlueprintCallable,Category="CommonUIToolLib|Function")
	static void CallObjectFunctionOneParam(UObject* InObject,const FName FunctionName,const FString InOneParam);

	//调用具有两个字符参数的函数方法
	UFUNCTION(BlueprintCallable,Category="CommonUIToolLib|Function")
	static void CallObjectFunctionTwoParam(UObject* InObject,const FName FunctionName,const FString InOneParam,const FString InTwoParam);

	//调用具有三个字符参数的函数方法
	UFUNCTION(BlueprintCallable,Category="CommonUIToolLib|Function")
	static void CallObjectFunctionThreeParam(UObject* InObject,const FName FunctionName,const FString InOneParam,const FString InTwoParam,const FString InThreeParam);


	
	//根据UFunction调用无参事件
	UFUNCTION(BlueprintCallable,Category="CommonUIToolLib|Function")
	static void CallNoParamsFunction(UObject* InObject,UFunction* InFunction);

	//根据UFunction调用有参事件
	UFUNCTION(BlueprintCallable,Category="CommonUIToolLib|Function")
	static void CallHaveParamsFunction(UObject* InObject,UFunction* InFunction,const FString ParamsJsonStr);
	
	//测试
	UFUNCTION(BlueprintCallable,Category="CommonUIToolLib|Function")
	static void CallFuncionTest(UObject* InObject,UFunction* InFunction, FString InStr)
	{
		TTuple<bool,bool,bool>OutParams;
		InvokeFunction(nullptr,InObject,InFunction,OutParams,InStr);

		UE_LOG(LogTemp,Warning,TEXT("TTuple 0 :%d"),OutParams.Get<0>());
		
		
		UE_LOG(LogTemp,Warning,TEXT("TTuple 1 :%d"),OutParams.Get<1>());

		UE_LOG(LogTemp,Warning,TEXT("TTuple 2 :%d"),OutParams.Get<2>());
		
		
	}


#pragma endregion
































	
	
template<typename... TReturns, typename... TArgs>
static void InvokeFunction(UClass* objClass, UObject* obj, UFunction* func, TTuple<TReturns...>& outParams, TArgs&&... args)
{
    objClass = obj != nullptr ? obj->GetClass() : objClass;
    UObject* context = obj != nullptr ? obj : objClass;
    uint8* outPramsBuffer = (uint8*)&outParams;

    if (func->HasAnyFunctionFlags(FUNC_Native)) //quick path for c++ functions
    {
        TTuple<TArgs..., TReturns...> params(Forward<TArgs>(args)..., TReturns()...);
        context->ProcessEvent(func, &params);
        //copy back out params
        for (TFieldIterator<FProperty> i(func); i; ++i)
        {
            FProperty* prop = *i;
            if (prop->PropertyFlags & CPF_OutParm)
            {
                void* propBuffer = prop->ContainerPtrToValuePtr<void*>(&params);
                prop->CopyCompleteValue(outPramsBuffer, propBuffer);
                outPramsBuffer += prop->GetSize();
            }
        }
        return;
    }

    TTuple<TArgs...> inParams(Forward<TArgs>(args)...);
    void* funcPramsBuffer = (uint8*)FMemory_Alloca(func->ParmsSize);
    uint8* inPramsBuffer = (uint8*)&inParams;

    for (TFieldIterator<FProperty> i(func); i; ++i)
    {
        FProperty* prop = *i;
        if (prop->GetFName().ToString().StartsWith("__"))
        {
            //ignore private param like __WolrdContext of function in blueprint funcion library
            continue;
        }
        void* propBuffer = prop->ContainerPtrToValuePtr<void*>(funcPramsBuffer);
        if (prop->PropertyFlags & CPF_OutParm)
        {
            prop->CopyCompleteValue(propBuffer, outPramsBuffer);
            outPramsBuffer += prop->GetSize();
        }
        else if (prop->PropertyFlags & CPF_Parm)
        {
            prop->CopyCompleteValue(propBuffer, inPramsBuffer);
            inPramsBuffer += prop->GetSize();
        }
    }

    context->ProcessEvent(func, funcPramsBuffer);   //call function
    outPramsBuffer = (uint8*)&outParams;    //reset to begin

    //copy back out params
    for (TFieldIterator<FProperty> i(func); i; ++i)
    {
        FProperty* prop = *i;
        if (prop->PropertyFlags & CPF_OutParm)
        {
            void* propBuffer = prop->ContainerPtrToValuePtr<void*>(funcPramsBuffer);
            prop->CopyCompleteValue(outPramsBuffer, propBuffer);
            outPramsBuffer += prop->GetSize();
        }
    }
}
















	
	
};
