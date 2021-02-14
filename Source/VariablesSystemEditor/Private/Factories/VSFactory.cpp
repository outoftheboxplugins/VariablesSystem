// Copyright Out-of-the-Box Plugins 2018-2020. All Rights Reserved.

#include "VSFactory.h"

#include "VSLog.h"
#include "BaseVariable.h"

#include "Kismet2/SClassPickerDialog.h"

#define LOCTEXT_NAMESPACE "VariablesSystemEditor"

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
	: Super(ObjectInitializer) { }

bool UVSFactory::ConfigureProperties()
{
	UClass* ChosenClass = nullptr;
	const bool bPressedOk = ConfigureVariableProperties(ChosenClass);

    // Copy the selection after dialog closed.
	ChoosenVariableType = bPressedOk ? ChosenClass : nullptr;

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

namespace FactoryHelpers
{
	template<typename T>
	bool ChooseClass(UClass*& OutChosenClass)
	{
		// Use Custom Filter to allow only for options provided by the variables system.
		TSharedPtr<FVSFactoryFilter> Filter = MakeShareable(new FVSFactoryFilter);
		Filter->DisallowedClassFlags = CLASS_Abstract;
		Filter->AllowedChildrenOfClasses.Add(T::StaticClass());

		// Prepare the configuration options.
		FClassViewerInitializationOptions Options;
		Options.Mode = EClassViewerMode::ClassPicker;
		Options.ClassFilter = Filter;

		// Show the class picker dialog to choose a class.
		const FText TitleText = LOCTEXT("ClassPicker", "Select the variable type.");
		return SClassPickerDialog::PickClass(TitleText, Options, OutChosenClass, T::StaticClass());
	}
}

UVSInstancedFactory::UVSInstancedFactory(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	SupportedClass = UInstancedBaseVariable::StaticClass();
}

bool UVSInstancedFactory::ConfigureVariableProperties(UClass*& OutChosenClass)
{
	return FactoryHelpers::ChooseClass<UInstancedBaseVariable>(OutChosenClass);
}

UVSGlobalFactory::UVSGlobalFactory(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	SupportedClass = UGlobalBaseVariable::StaticClass();
}

bool UVSGlobalFactory::ConfigureVariableProperties(UClass*& OutChosenClass)
{
	return FactoryHelpers::ChooseClass<UGlobalBaseVariable>(OutChosenClass);
}

#undef LOCTEXT_NAMESPACE
