// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "VarSystemFactory.h"

#include "Containers/UnrealString.h"
#include "VarSystem.h"
#include "Misc/FileHelper.h"
#include "ClassViewerModule.h"
#include "Modules/ModuleManager.h"
#include "Kismet2/SClassPickerDialog.h"


/* UVarSystemFactory constructors
 *****************************************************************************/

UVarSystemFactory::UVarSystemFactory(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	Formats.Add(FString(TEXT("txt;")) + NSLOCTEXT("UVarSystemFactory", "FormatTxt", "Text File").ToString());
	SupportedClass = UVarSystem::StaticClass();
	bCreateNew = false;
	bEditorImport = true;
}

UObject* UVarSystemFactory::FactoryCreateFile(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, const FString& Filename, const TCHAR* Parms, FFeedbackContext* Warn, bool& bOutOperationCanceled)
{
	UVarSystem* VarSystem = nullptr;
	FString TextString;

	if (FFileHelper::LoadFileToString(TextString, *Filename))
	{
		VarSystem = NewObject<UVarSystem>(InParent, InClass, InName, Flags);
		VarSystem->Text = FText::FromString(TextString);
	}

	bOutOperationCanceled = false;

	return VarSystem;
}

bool UVarSystemFactory::ConfigureProperties()
{
	// nullptr the DataAssetClass so we can check for selection
	DataAssetClass = nullptr;

	// Load the classviewer module to display a class picker
	FClassViewerModule& ClassViewerModule = FModuleManager::LoadModuleChecked<FClassViewerModule>("ClassViewer");

	// Fill in options
	FClassViewerInitializationOptions Options;
	Options.Mode = EClassViewerMode::ClassPicker;

	TSharedPtr<FAssetClassParentFilter> Filter = MakeShareable(new FAssetClassParentFilter);
	Options.ClassFilter = Filter;

	Filter->DisallowedClassFlags = CLASS_Abstract | CLASS_Deprecated | CLASS_NewerVersionExists | CLASS_HideDropDown;
	Filter->AllowedChildrenOfClasses.Add(UVarSystem::StaticClass());

	const FText TitleText = LOCTEXT("CreateDataAssetOptions", "Pick Data Asset Class");
	UClass* ChosenClass = nullptr;
	const bool bPressedOk = SClassPickerDialog::PickClass(TitleText, Options, ChosenClass, UVarSystem::StaticClass());

	if (bPressedOk)
	{
		DataAssetClass = ChosenClass;
	}

	return bPressedOk;
}

UObject* UVarSystemFactory::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	if (DataAssetClass != nullptr)
	{
		return NewObject<UVarSystem>(InParent, DataAssetClass, Name, Flags | RF_Transactional);
	}
	else
	{
		// if we have no data asset class, use the passed-in class instead
		check(Class->IsChildOf(UVarSystem::StaticClass()));
		return NewObject<UVarSystem>(InParent, Class, Name, Flags);
	}
}
