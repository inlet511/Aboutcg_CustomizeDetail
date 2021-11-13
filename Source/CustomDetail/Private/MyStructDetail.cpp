#include "MyStructDetail.h"
#include "DetailWidgetRow.h"
#include "SImage.h"
#include "Widgets/Input/SEditableTextBox.h"
#include "../../../../../../../Program Files/Epic Games/UE_4.22/Engine/Source/Editor/PropertyEditor/Public/IDetailChildrenBuilder.h"
#include "../../../../../../../Program Files/Epic Games/UE_4.22/Engine/Source/Runtime/Slate/Public/Widgets/Text/STextBlock.h"

#define LOCTEXT_NAMESPACE "Whatever"

void FMyStructDetail::CustomizeHeader(TSharedRef<IPropertyHandle> PropertyHandle, FDetailWidgetRow& HeaderRow, IPropertyTypeCustomizationUtils& CustomizationUtils)
{
// 	HeaderRow
// 	.NameContent()
// 	[
// 		PropertyHandle->CreatePropertyNameWidget()
// 	]
// 	.ValueContent()
// 	.MinDesiredWidth(125.0f)
// 	.MaxDesiredWidth(325.0f)
// 	[
// 		SAssignNew(EditableTextBox,SEditableTextBox)
// 		.OnTextCommitted(this,&FMyStructDetail::OnTextCommitted)
// 	];

	HeaderRow
		.WholeRowContent()
		[
			//PropertyHandle->CreatePropertyNameWidget()
			SNew(STextBlock)
			.Text(LOCTEXT("StructLabel","This is Struct Header Title"))
		];
}

void FMyStructDetail::CustomizeChildren(TSharedRef<IPropertyHandle> PropertyHandle, IDetailChildrenBuilder& ChildBuilder, IPropertyTypeCustomizationUtils& CustomizationUtils)
{

	StructTextHandle = PropertyHandle->GetChildHandle(GET_MEMBER_NAME_CHECKED(FMyStruct, MyText));
	StructIntHandle = PropertyHandle->GetChildHandle(GET_MEMBER_NAME_CHECKED(FMyStruct, MyInt));
	StructFloatHandle = PropertyHandle->GetChildHandle(GET_MEMBER_NAME_CHECKED(FMyStruct, MyFloat));

	FText myText;
	StructTextHandle->GetValue(myText);

	int32 myInt;
	StructIntHandle->GetValue(myInt);

	float myFloat;
	StructFloatHandle->GetValue(myFloat);

	// Struct 下的子元素
	// FText
	ChildBuilder.AddCustomRow(LOCTEXT("MyTextRowLabel", "MyTextRow")) //这个text实际上无法显示出来，无关紧要
		.NameContent()
		[
			SNew(STextBlock)
			.Text(LOCTEXT("MyTextLabel","MyText"))
		]
	.ValueContent()
		[
			SNew(SEditableTextBox)
			.Text(myText)
			.OnTextCommitted(this,&FMyStructDetail::OnTextCommitted)
		];

	// Int32
	ChildBuilder.AddCustomRow(FText()) //这个text实际上无法显示出来，无关紧要
		.NameContent()
		[
			SNew(STextBlock)
			.Text(LOCTEXT("MyIntLabel", "MyInt"))
		]
	.ValueContent()
		[
			SNew(SEditableTextBox)
			.Text(FText::FromString(FString::FromInt(myInt)))
			.OnTextCommitted(this, &FMyStructDetail::OnIntCommitted)
		];

	// Float
	ChildBuilder.AddCustomRow(FText()) //这个text实际上无法显示出来，无关紧要
		.NameContent()
		[
			SNew(STextBlock)
			.Text(LOCTEXT("MyFloatLabel", "MyFloat"))
		]
	.ValueContent()
		[
			SNew(SEditableTextBox)
			.Text(FText::FromString(FString::Printf(TEXT("%f"), myFloat)))
			.OnTextCommitted(this, &FMyStructDetail::OnFloatCommitted)
		];
}

TSharedRef<IPropertyTypeCustomization> FMyStructDetail::MakeInstance()
{
	return MakeShareable<FMyStructDetail>(new FMyStructDetail);
}


void FMyStructDetail::OnTextCommitted(const FText& InText, ETextCommit::Type InCommitType) const
{
	if(StructTextHandle.IsValid())
	{
		StructTextHandle->SetValue(InText);
	}
}

void FMyStructDetail::OnIntCommitted(const FText& InText, ETextCommit::Type InCommitType) const
{
	if (StructIntHandle.IsValid())
	{
		StructIntHandle->SetValue(FCString::Atoi(*InText.ToString()));
	}
}

void FMyStructDetail::OnFloatCommitted(const FText& InText, ETextCommit::Type InCommitType) const
{
	if (StructFloatHandle.IsValid())
	{
		StructFloatHandle->SetValue(FCString::Atof(*InText.ToString()));
	}
}

#undef LOCTEXT_NAMESPACE