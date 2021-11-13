#pragma once

#include "CoreMinimal.h"
#include "MyStruct.generated.h"

USTRUCT(BlueprintType)
struct CUSTOMDETAIL_API FMyStruct
{
	GENERATED_USTRUCT_BODY()
public:

	UPROPERTY(EditAnywhere,Category="StructCat")
	FText MyText;

	UPROPERTY(EditAnywhere, Category="StructCat")
	int32 MyInt;

	UPROPERTY(EditAnywhere, Category = "StructCat")
	float MyFloat;
};