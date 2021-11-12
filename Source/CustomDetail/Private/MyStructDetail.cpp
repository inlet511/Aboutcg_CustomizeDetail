#include "MyStructDetail.h"
#include "DetailWidgetRow.h"
#include "SImage.h"

void FMyStructDetail::CustomizeHeader(TSharedRef<IPropertyHandle> PropertyHandle, FDetailWidgetRow& HeaderRow, IPropertyTypeCustomizationUtils& CustomizationUtils)
{
	HeaderRow
	.NameContent()
	[
		PropertyHandle->CreatePropertyNameWidget()
	]
	.ValueContent()
	.MinDesiredWidth(125.0f)
	.MaxDesiredWidth(325.0f)
	[
		SNew(SImage)
	];
}

void FMyStructDetail::CustomizeChildren(TSharedRef<IPropertyHandle> PropertyHandle, IDetailChildrenBuilder& ChildBuilder, IPropertyTypeCustomizationUtils& CustomizationUtils)
{

}

TSharedRef<IPropertyTypeCustomization> FMyStructDetail::MakeInstance()
{
	return MakeShareable<FMyStructDetail>(new FMyStructDetail);
}

