// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#include "VariablesSystemFactory.h"

#include "UnrealEd/Public/Kismet2/SClassPickerDialog.h"
#include "VariablesSystem/Public/BaseVariable.h"
#include "VariablesSystemEditor/Private/Factories/VariablesSystemCreateNewFilter.h"

#define LOCTEXT_NAMESPACE "VariablesSystem"

UVariablesSystemFactory::UVariablesSystemFactory(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	Formats.Add(FString(TEXT("variable;")) + LOCTEXT("VariablesSystem_ExtensionTooltip", "VariablesSystem variable asset").ToString());
	SupportedClass = UBaseVariable::StaticClass();
	bCreateNew = false;
	bEditorImport = true;
}

bool UVariablesSystemFactory::ShouldShowInNewMenu() const
{
	return true;
}

bool UVariablesSystemFactory::ConfigureProperties()
{
    // Reset selection each time a new variable's properties should be selected.
    ChoosenVariableType = nullptr;

    // Prepare the configuration options.
    FClassViewerInitializationOptions Options;
    Options.Mode = EClassViewerMode::ClassPicker;

    // Use Custom Filter to allow only for options provided by the variables system.
    TSharedPtr<FVariablesSystemCreateNewFilter> Filter = MakeShareable(new FVariablesSystemCreateNewFilter);
    Options.ClassFilter = Filter;
    Filter->DisallowedClassFlags = CLASS_Abstract | CLASS_Deprecated | CLASS_NewerVersionExists | CLASS_HideDropDown | CLASS_CompiledFromBlueprint;
	Filter->AllowedChildrenOfClasses.Add(UBaseVariable::StaticClass());

    // Show the class picker dialog to choose a class.
	const FText TitleText = LOCTEXT("VariablesSystem_SelectClass", "Select the variable type.");
	UClass* ChosenClass = nullptr;
	const bool bPressedOk = SClassPickerDialog::PickClass(TitleText, Options, ChosenClass, UBaseVariable::StaticClass());

    // Copy the selection after dialog closed.
	if (bPressedOk)
	{
		ChoosenVariableType = ChosenClass;
	}

	return bPressedOk;
}

UObject* UVariablesSystemFactory::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	if (ChoosenVariableType != nullptr)
	{
		return NewObject<UBaseVariable>(InParent, ChoosenVariableType, Name, Flags | RF_Transactional);
	}
	else
	{
        UE_LOG(LogTemp, Error, TEXT("VariablesSystem - Could not create variable based on class. No class was selected."));
        return nullptr;
	}
}

#undef LOCTEXT_NAMESPACE