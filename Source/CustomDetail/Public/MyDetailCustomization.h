#pragma once 
#include "CoreMinimal.h"
#include "IDetailCustomization.h"

class FMyDetailCustomization : public IDetailCustomization
{
public:
	virtual void CustomizeDetails(IDetailLayoutBuilder& DetailBuilder) override;

	// Make an Instance 
	static TSharedRef<IDetailCustomization> MakeInstance();
};