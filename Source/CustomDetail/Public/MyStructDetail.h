#pragma once

#include "CoreMinimal.h"
#include "IPropertyTypeCustomization.h"

class FMyStructDetail : public IPropertyTypeCustomization
{
public:
	virtual void CustomizeHeader(TSharedRef<IPropertyHandle> PropertyHandle, FDetailWidgetRow& HeaderRow, IPropertyTypeCustomizationUtils& CustomizationUtils) override;
	virtual void CustomizeChildren(TSharedRef<IPropertyHandle> PropertyHandle, IDetailChildrenBuilder& ChildBuilder, IPropertyTypeCustomizationUtils& CustomizationUtils) override;

	static TSharedRef<IPropertyTypeCustomization> MakeInstance();




private:
	//TSharedPtr<IPropertyHandle> m_PropertyHandle;
	//TSharedPtr<class SEditableTextBox> EditableTextBox;
	void OnTextCommitted(const FText& InText, ETextCommit::Type InCommitType) const;
	void OnIntCommitted(const FText& InText, ETextCommit::Type InCommitType) const;
	void OnFloatCommitted(const FText& InText, ETextCommit::Type InCommitType) const;
	TSharedPtr<IPropertyHandle> StructTextHandle;
	TSharedPtr<IPropertyHandle> StructIntHandle;
	TSharedPtr<IPropertyHandle> StructFloatHandle;
};