// Copyright Out-of-the-Box Plugins 2018-2020. All Rights Reserved.

#include "VSFactory.h"

#include "VSLog.h"
#include "BaseVariable.h"

#include "Kismet2/SClassPickerDialog.h"

#define LOCTEXT_NAMESPACE "VariablesSystem"

bool FVSFactoryFilter::IsClassAllowed(const FClassViewerInitializationOptions& InInitOptions, const UClass* InClass, TSharedRef< class FClassViewerFilterFuncs > InFilterFuncs)
{
	if (InFilterFuncs->IfInChildOfClassesSet(AllowedChildrenOfClasses, InClass) != EFilterReturn::Passed)
	{
		return false;
	}
	if (InClass->HasAnyClassFlags(DisallowedClassFlags))
	{
		return false;
	}

	return true;
}

bool FVSFactoryFilter::IsUnloadedClassAllowed(const FClassViewerInitializationOptions& InInitOptions, const TSharedRef< const class IUnloadedBlueprintData > InUnloadedClassData, TSharedRef< class FClassViewerFilterFuncs > InFilterFuncs)
{
	if (InFilterFuncs->IfInChildOfClassesSet(AllowedChildrenOfClasses, InUnloadedClassData) != EFilterReturn::Passed)
	{
		return false;
	}
	if (InUnloadedClassData->HasAnyClassFlags(DisallowedClassFlags))
	{
		return false;
	}

	return true;
}

UVSFactory::UVSFactory(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	SupportedClass = UBaseVariable::StaticClass();
	bCreateNew = true;
	bEditorImport = true;
}

bool UVSFactory::ShouldShowInNewMenu() const
{
	return true;
}

bool UVSFactory::ConfigureProperties()
{
    // Reset selection each time a new variable's properties should be selected.
    ChoosenVariableType = nullptr;

	// Use Custom Filter to allow only for options provided by the variables system.
	TSharedPtr<FVSFactoryFilter> Filter = MakeShareable(new FVSFactoryFilter);
	Filter->DisallowedClassFlags = CLASS_Abstract;
	Filter->AllowedChildrenOfClasses.Add(UBaseVariable::StaticClass());

    // Prepare the configuration options.
    FClassViewerInitializationOptions Options;
    Options.Mode = EClassViewerMode::ClassPicker;
    Options.ClassFilter = Filter;

    // Show the class picker dialog to choose a class.
	const FText TitleText = LOCTEXT("ClassPicker", "Select the variable type.");
	UClass* ChosenClass = nullptr;
	const bool bPressedOk = SClassPickerDialog::PickClass(TitleText, Options, ChosenClass, UBaseVariable::StaticClass());

    // Copy the selection after dialog closed.
	if (bPressedOk)
	{
		ChoosenVariableType = ChosenClass;
	}

	return bPressedOk;
}

UObject* UVSFactory::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	if (ChoosenVariableType != nullptr)
	{
		return NewObject<UBaseVariable>(InParent, ChoosenVariableType, Name, Flags);
	}
	else
	{
		UE_LOG(LogVariablesSystem, Error, TEXT("Could not create variable based on class. No class was selected."))
        return nullptr;
	}
}

#undef LOCTEXT_NAMESPACE
