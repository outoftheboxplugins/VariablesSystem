// Copyright Out-of-the-Box Plugins 2018-2021. All Rights Reserved.
// GENERATED FILE DO NOT MODIFY DIRECTLY

#include "GlobalGameplayTagContainer.h"

#include "VSLog.h"

#include "CoreMinimal.h"

#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetStringLibrary.h"

/* STATIC */ FGameplayTagContainer UGlobalGameplayTagContainer::GetGlobalGameplayTagContainerValue(const UGlobalGameplayTagContainer* Variable)
{
	if (Variable)
	{
		return Variable->Value;
	}
	else
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Cannot get value without a variable. Returning default value. Callstack below:"));
		PrintScriptCallstack();

		return FGameplayTagContainer();
	}
}

/* STATIC */ UGlobalGameplayTagContainer* UGlobalGameplayTagContainer::GetGlobalMutableGameplayTagContainer(UGlobalGameplayTagContainer* Variable)
{
    return Variable;
}

/* STATIC */ void UGlobalGameplayTagContainer::SetGlobalGameplayTagContainerValue(UGlobalGameplayTagContainer* Variable, FGameplayTagContainer NewValue)
{
	if (Variable && Variable->Value != NewValue)
	{
		Variable->Value = NewValue;
		Variable->Dirty = true;
	}
	else if(!Variable)
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Cannot set value without a variable. Callstack below:"));
		PrintScriptCallstack();
	}
}

/* STATIC */ void UGlobalGameplayTagContainer::CopyGlobalGameplayTagContainerValue(UGlobalGameplayTagContainer* Variable, UGlobalGameplayTagContainer* OtherVariable)
{
	if (Variable && OtherVariable && Variable->Value != OtherVariable->Value)
	{
		Variable->Value = OtherVariable->Value;
		Variable->Dirty = true;
	}
	else if(!Variable)
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Cannot copy a value without a variable. Callstack below:"));
		PrintScriptCallstack();
	}
	else if(!OtherVariable)
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Cannot copy a value without an other variable. Callstack below:"));
		PrintScriptCallstack();
	}
}

FString UGlobalGameplayTagContainer::GetStringValue() const
{
    const auto& Item = Value;
    return Item.ToString();
}
