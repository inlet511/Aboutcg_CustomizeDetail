// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MyStruct.h"
#include "MyObject.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class CUSTOMDETAIL_API UMyObject : public UObject
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, Category = Help)
	FMyStruct MyStructVar;

	UPROPERTY(EditAnywhere, Category = Help)
		float SomeFloatVar;

	UPROPERTY(EditAnywhere, Category = Help)
		FText SomeTextVar;

	UPROPERTY(EditAnywhere, Category = Help)
		TArray<int32> SomeIntArray;

};
