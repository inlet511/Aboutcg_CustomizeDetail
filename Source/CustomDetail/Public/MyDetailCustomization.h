#pragma once 
#include "CoreMinimal.h"
#include "IDetailCustomization.h"

class FMyDetailCustomization : public IDetailCustomization
{
public:
	virtual void CustomizeDetails(IDetailLayoutBuilder& DetailBuilder) override;

	//ʵ����
	//static TSharedRef<IDetailCustomization> MakeInstance();
};