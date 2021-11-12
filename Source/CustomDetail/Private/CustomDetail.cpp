// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "CustomDetail.h"
#include "PropertyEditorModule.h"
#include "MyDetailCustomization.h"
#include "MyStructDetail.h"

#define LOCTEXT_NAMESPACE "FCustomDetailModule"

void FCustomDetailModule::StartupModule()
{
	FPropertyEditorModule& PropertyModule = FModuleManager::GetModuleChecked<FPropertyEditorModule>("PropertyEditor");

	RegisterObjectCustomizations();
	RegisterPropertyTypeCustomizations();

	PropertyModule.NotifyCustomizationModuleChanged();//刷新
}

void FCustomDetailModule::ShutdownModule()
{
	//结束时卸载已经注册的Class和PropertyType
	if (FModuleManager::Get().IsModuleLoaded("PropertyEditor"))
	{
		FPropertyEditorModule& PropertyModule = FModuleManager::GetModuleChecked<FPropertyEditorModule>("PropertyEditor");
		for (auto It = RegisteredClassNames.CreateConstIterator(); It; ++It)
		{
			if (It->IsValid())
			{
				PropertyModule.UnregisterCustomClassLayout(*It);
			}
		}

		for (auto It = RegisteredPropertyTypes.CreateConstIterator(); It; ++It)
		{
			if (It->IsValid())
			{
				PropertyModule.UnregisterCustomPropertyTypeLayout(*It);
			}
		}

		PropertyModule.NotifyCustomizationModuleChanged(); //刷新
	}

}


void FCustomDetailModule::RegisterPropertyTypeCustomizations()
{
	RegisterCustomPropertyTypeLayout("MyStruct", FOnGetPropertyTypeCustomizationInstance::CreateStatic(&FMyStructDetail::MakeInstance));
}


void FCustomDetailModule::RegisterObjectCustomizations()
{
	RegisterCustomClassLayout("MyObject",FOnGetDetailCustomizationInstance::CreateStatic(&FMyDetailCustomization::MakeInstance));
}


void FCustomDetailModule::RegisterCustomClassLayout(FName ClassName, FOnGetDetailCustomizationInstance DetailLayoutDelegate)
{
	check(ClassName != NAME_None);
	RegisteredClassNames.Add(ClassName);

	FPropertyEditorModule& PropertyModule = FModuleManager::GetModuleChecked<FPropertyEditorModule>("PropertyEditor");
	PropertyModule.RegisterCustomClassLayout(ClassName, DetailLayoutDelegate);
}


void FCustomDetailModule::RegisterCustomPropertyTypeLayout(FName PropertyTypeName, FOnGetPropertyTypeCustomizationInstance PropertyTypeLayoutDelegate)
{
	check(PropertyTypeName != NAME_None);
	RegisteredPropertyTypes.Add(PropertyTypeName);

	FPropertyEditorModule& PropertyModule = FModuleManager::GetModuleChecked<FPropertyEditorModule>("PropertyEditor");
	PropertyModule.RegisterCustomPropertyTypeLayout(PropertyTypeName, PropertyTypeLayoutDelegate);

}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FCustomDetailModule, CustomDetail)