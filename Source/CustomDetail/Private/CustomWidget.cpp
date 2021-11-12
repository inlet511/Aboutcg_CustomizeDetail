#include "CustomWidget.h"
#include "PropertyEditing.h"
#include "ModuleManager.h"
#include "MyObject.h"
#include "SBoxPanel.h"
#include "SBox.h"
#include "SBorder.h"

void SCustomWidget::Construct(const FArguments& InArgs)
{
	auto& PropertyModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");
	FDetailsViewArgs DetailsViewArgs;
	ConfigPanel = PropertyModule.CreateDetailView(DetailsViewArgs);
	ConfigPanel->SetObject(UMyObject::StaticClass()->GetDefaultObject(true), true);

	ChildSlot
	[
			SNew(SVerticalBox)
			+SVerticalBox::Slot()
			.AutoHeight()
			[
				SNew(SBox)
				.WidthOverride(300)
				.MinDesiredWidth(300)
				.MaxDesiredWidth(300)
				[
					SNew(SBorder)
					[
						ConfigPanel.ToSharedRef()
					]
				]
			]
	];
}

