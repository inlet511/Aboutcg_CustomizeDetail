#include "MyDetailCustomization.h"
#include "DetailLayoutBuilder.h"
#include "DetailCategoryBuilder.h"
#include "STextBlock.h"
#include "DetailWidgetRow.h"
#include "PropertyCustomizationHelpers.h"
#include "SBoxPanel.h"
#include "SImage.h"

#define  LOCTEXT_NAMESPACE "MyDetailCustomization"

void FMyDetailCustomization::CustomizeDetails(IDetailLayoutBuilder& DetailBuilder)
{
	// Create a custom Category
	IDetailCategoryBuilder& CustomCategoryBuilder = DetailBuilder.EditCategory(TEXT("CustomizeCategory"));
	CustomCategoryBuilder.AddCustomRow(LOCTEXT("RowName", "MyRow"))
		.WholeRowContent()
		[
			SNew(STextBlock)
			.Text(LOCTEXT("TextFieldContent", "Custom Content Here"))
		];


	// Create another custom Category
	IDetailCategoryBuilder& AnotherDetailCategoryBuilderInstance = DetailBuilder.EditCategory(TEXT("AnotherCat"));

	TSharedPtr<IPropertyHandle> TextPropertyHandle = DetailBuilder.GetProperty("SomeTextVar");
	TSharedPtr<IPropertyHandle> FloatPropertyHandle = DetailBuilder.GetProperty("SomeFloatVar");

	AnotherDetailCategoryBuilderInstance.AddCustomRow(LOCTEXT("SecondRowName", "SecondRow"))
		.WholeRowContent()
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
		.HAlign(HAlign_Fill)
		[
			SNew(SProperty, TextPropertyHandle)
		]
	+ SHorizontalBox::Slot()
		.HAlign(HAlign_Fill)
		[
			SNew(SProperty, FloatPropertyHandle)
			.CustomWidget() // Demo to show how to customize SProperty
			[
				SNew(SImage)
			]
		]
		];


	// Also show SomeTextVar and SomeFloatVar in their original Category
	DetailBuilder.AddPropertyToCategory(TextPropertyHandle);
	DetailBuilder.AddPropertyToCategory(FloatPropertyHandle);



}

 TSharedRef<IDetailCustomization> FMyDetailCustomization::MakeInstance()
 {
	 return MakeShareable(new FMyDetailCustomization);
 }

#undef LOCTEXT_NAMESPACE