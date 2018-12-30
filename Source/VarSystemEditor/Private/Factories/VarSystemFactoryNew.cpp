// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "VarSystemFactoryNew.h"

#include "Containers/UnrealString.h"
#include "BaseVariable.h"
#include "Misc/FileHelper.h"
#include "Modules/ModuleManager.h"
#include "Kismet2/SClassPickerDialog.h"

#define LOCTEXT_NAMESPACE "VarSystemFactory"

/* UVarSystemFactory constructors
 *****************************************************************************/

UVarSystemFactoryNew::UVarSystemFactoryNew(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	Formats.Add(FString(TEXT("txt;")) + NSLOCTEXT("UVarSystemFactory", "FormatTxt", "Text File").ToString());
	SupportedClass = UBaseVariable::StaticClass();
	bCreateNew = false;
	bEditorImport = true;
}

bool UVarSystemFactoryNew::ShouldShowInNewMenu() const
{
	return true;
}

UObject* UVarSystemFactoryNew::FactoryCreateFile(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, const FString& Filename, const TCHAR* Parms, FFeedbackContext* Warn, bool& bOutOperationCanceled)
{
	UBaseVariable* BaseVariable = nullptr;
	FString TextString;

	if (FFileHelper::LoadFileToString(TextString, *Filename))
	{
		BaseVariable = NewObject<UBaseVariable>(InParent, InClass, InName, Flags);
		BaseVariable->VariableDescription = FText::FromString(TextString);
	}

	bOutOperationCanceled = false;

	return BaseVariable;
}



bool UVarSystemFactoryNew::ConfigureProperties()
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
	Filter->AllowedChildrenOfClasses.Add(UBaseVariable::StaticClass());

	const FText TitleText = LOCTEXT("CreatAssetOptions", "Pick Asset Class");
	UClass* ChosenClass = nullptr;
	const bool bPressedOk = SClassPickerDialog::PickClass(TitleText, Options, ChosenClass, UBaseVariable::StaticClass());

	if (bPressedOk)
	{
		DataAssetClass = ChosenClass;
	}

	return bPressedOk;
}

UObject* UVarSystemFactoryNew::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	if (DataAssetClass != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Here."))
			return NewObject<UBaseVariable>(InParent, DataAssetClass, Name, Flags | RF_Transactional);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Better."))
			// if we have no data asset class, use the passed-in class instead
			check(Class->IsChildOf(UBaseVariable::StaticClass()));
		return NewObject<UBaseVariable>(InParent, Class, Name, Flags);
	}
}
#undef LOCTEXT_NAMESPACE
