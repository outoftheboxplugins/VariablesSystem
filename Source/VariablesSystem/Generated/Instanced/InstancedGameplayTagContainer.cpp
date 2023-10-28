// Copyright Out-of-the-Box Plugins 2018-2021. All Rights Reserved.
// GENERATED FILE DO NOT MODIFY DIRECTLY

#include "InstancedGameplayTagContainer.h"

#include "VSLog.h"

/* STATIC */ FGameplayTagContainer UInstancedGameplayTagContainer::GetInstancedGameplayTagContainerValue(UObject* Owner, UInstancedGameplayTagContainer* Variable)
{
	if (!Owner)
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Cannot get instance value without an owner. Returning default value. Callstack below:"));
		PrintScriptCallstack();

		return FGameplayTagContainer();
	}

	if (!Variable)
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Cannot get instance value without a variable. Returning default value. Callstack below:"));
		PrintScriptCallstack();

		return FGameplayTagContainer();
	}
	else
	{
		return Variable->GetInstancedGameplayTagContainerRef(Owner).Value;
	}
}

/* STATIC */ UInstancedGameplayTagContainer* UInstancedGameplayTagContainer::GetInstancedMutableGameplayTagContainer(UInstancedGameplayTagContainer* Variable)
{
	if (!Variable)
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Cannot get instance value without a variable. Returning default value. Callstack below:"));
		PrintScriptCallstack();

		return nullptr;
	}
	else
	{
		return Variable;
	}
}

/* STATIC */ void UInstancedGameplayTagContainer::SetInstancedGameplayTagContainerValue(UObject* Owner, UInstancedGameplayTagContainer* Variable, FGameplayTagContainer NewValue)
{
	if (!Owner)
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Cannot set instance value without an owner. Callstack below:"));
		PrintScriptCallstack();
	}
	else if (!Variable)
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Cannot set instance value without a variable. Callstack below:"));
		PrintScriptCallstack();
	}
	else
	{
		FInstancedGameplayTagContainerType& GameplayTagContainerRef = Variable->GetInstancedGameplayTagContainerRef(Owner);
		
		if(GameplayTagContainerRef.Value != NewValue)
		{
			GameplayTagContainerRef.Value = NewValue;
		}
	}
}

/* STATIC */ void UInstancedGameplayTagContainer::CopyInstancedGameplayTagContainerValue(UObject* Owner, UInstancedGameplayTagContainer* Variable, UObject* OtherOwner, UInstancedGameplayTagContainer* OtherVariable)
{
	if (!Owner || !OtherOwner)
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Cannot copy instance value without an owner. Callstack below:"));
		PrintScriptCallstack();
	}
	else if (!Variable || !OtherVariable)
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Cannot copy instance value without a variable. Callstack below:"));
		PrintScriptCallstack();
	}
	else
	{
		FInstancedGameplayTagContainerType& GameplayTagContainerRef = Variable->GetInstancedGameplayTagContainerRef(Owner);
		FInstancedGameplayTagContainerType& otherGameplayTagContainerRef = OtherVariable->GetInstancedGameplayTagContainerRef(OtherOwner);

		if(GameplayTagContainerRef.Value != otherGameplayTagContainerRef.Value)
		{
			GameplayTagContainerRef.Value = otherGameplayTagContainerRef.Value;
		}
	}
}

void UInstancedGameplayTagContainer::CleanupEntries()
{
    VariablesMap.Empty();
}

FInstancedGameplayTagContainerType& UInstancedGameplayTagContainer::GetInstancedGameplayTagContainerRef(UObject* Owner)
{
	return VariablesMap.FindOrAdd(Owner);
}

FString UInstancedGameplayTagContainer::GetStringValue() const
{
    FString Lines;

    for (auto& Variable : VariablesMap)
    {
        const auto& Value = Variable.Value;
        const auto& Owner = Variable.Key;

		FString ValueString = GetValueAsString(Value.Value);
		FString OwnerString = Owner ? Owner->GetName() : FString("Invalid Owner");
		FString Line = FString::Printf(TEXT("%s - %s \n"), *OwnerString, *ValueString);

		Lines.Append(Line);
    }

    Lines.TrimEndInline();

    if (Lines.IsEmpty())
    {
        Lines = FString("No values set yet.");
    }

    return Lines;
}

FString UInstancedGameplayTagContainer::GetValueAsString(FGameplayTagContainer Value) const
{
    const auto& Item = Value;
    return Item.ToString();
}

