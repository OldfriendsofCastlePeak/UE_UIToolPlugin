// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
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
#pragma region Brush系列方法
	//获取Bursh的Image
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
	
	//设置UI的X偏移值
	UFUNCTION(BlueprintCallable,Category="CommonUIToolLib|UI")
	static void SetUIWidgetTranslationXValue(UWidget* InWidget,const float NewXValue);

	//设置UI的Y偏移值
	UFUNCTION(BlueprintCallable,Category="CommonUIToolLib|UI")
	static void SetUIWidgetTranslationYValue(UWidget* InWidget,const float NewYValue);

	//设置UI的X偏移值
	UFUNCTION(BlueprintPure,Category="CommonUIToolLib|UI")
	static void GetUIWidgetTranslationXValue(const UWidget* InWidget,float& CurrentXValue);

	//设置UI的Y偏移值
	UFUNCTION(BlueprintPure,Category="CommonUIToolLib|UI")
	static void GetUIWidgetTranslationYValue(const UWidget* InWidget,float& CurrentYValue);

	//获取UI的偏移值
	UFUNCTION(BlueprintPure,Category="CommonUIToolLib|UI")
	static void GetUIWidgetTranslation(const UWidget* InWidget,FVector2D& CurrentXValue);



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




	//将FTimeSpan转换为字符串
	UFUNCTION(BlueprintPure,Category="CommonUIToolLib|FTimespan")
	static FString FTimespanToString(const FTimespan& InTimespan);
	
	//设置文本块的字体大小
	UFUNCTION(BlueprintCallable,Category="CommonUIToolLib|Text")
	static void SetTextFontSize(const UTextBlock* InText,const int FontSize);

	//设置文本块的字体
	UFUNCTION(BlueprintCallable,Category="CommonUIToolLib|Text")
	static void SetTextFontFamily(const UTextBlock* InText,const UObject* InFontFamily);
	









	//个位数前自动加0
	UFUNCTION(BlueprintPure,Category="CommonUIToolLib")
	static FString AutoAddZero(const uint8 InInt);

	//精确根据WrapNum自动换行
	UFUNCTION(BlueprintPure,Category="CommonUIToolLib")
	static FString AutoWrapLineExactly(const FString& InStr,const uint8 WrapNum);

	//根据WrapNum自动换行,但是数字和小写字母每个字符只会计算为OtherCharPresentValue个汉字数
	UFUNCTION(BlueprintPure,Category="CommonUIToolLib")
	static FString AutoWrapLine(const FString& InStr,const uint8 WrapNum,const bool bLessAChar=true,const float OtherCharPresentValue=0.5);

	//根据WrapNum自动换行,但是数字和小写字母每个字符只会计算为OtherCharPresentValue个汉字数
	UFUNCTION(BlueprintPure,Category="CommonUIToolLib")
	static FString AutoWrapLineSpecifyChar(const FString& InStr,const uint8 WrapNum,const FString&SpecifyStr,const bool bLessAChar=true,const float OtherCharPresentValue=0.5);
	
	//遇到指定的字符換行
	UFUNCTION(BlueprintPure,Category="CommonUIToolLib")
	static FString AutoWrapLineBySpecifyStr(const FString& InStr,const FString& WarpLineStr,ESearchCase::Type SearchCase = ESearchCase::IgnoreCase);
	
	//保留指定位数的小数
	UFUNCTION(BlueprintPure,Category="CommonUIToolLib")
	static FString ReserveSpecifyPointNum(const FString& InStr,const uint8 PointNum);

	//获取输入字符串的第一个字符Unicode编码
	UFUNCTION(BlueprintPure,Category="CommonUIToolLib")
	static int32 GetCharCode(const FString& CharStr);





	
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
