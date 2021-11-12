#include "MyDetailCustomization.h"
#include "DetailLayoutBuilder.h"
#include "DetailCategoryBuilder.h"
#include "STextBlock.h"
#include "DetailWidgetRow.h"

#define  LOCTEXT_NAMESPACE "MyDetailCustomization"

void FMyDetailCustomization::CustomizeDetails(IDetailLayoutBuilder& DetailBuilder)
{
	IDetailCategoryBuilder& DetailCategoryBuilderInstance = DetailBuilder.EditCategory(TEXT("CustomizeDetails"));
	DetailCategoryBuilderInstance.AddCustomRow(LOCTEXT("RowName", "MyRow"))
		.WholeRowContent()
		[
			SNew(STextBlock)
			.Text(LOCTEXT("TextFieldContent", "Some Texts Here for Editing and Displaying"))
		];
}

 TSharedRef<IDetailCustomization> FMyDetailCustomization::MakeInstance()
 {
	 return MakeShareable(new FMyDetailCustomization);
 }

#undef LOCTEXT_NAMESPACE