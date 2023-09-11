// Copyright Out-of-the-Box Plugins 2018-2023. All Rights Reserved.
// GENERATED FILE DO NOT MODIFY DIRECTLY

#include "InstancedObjectRefArrayVariable.h"

#include "VSLog.h"
#include "Kismet/KismetStringLibrary.h"

/* STATIC */ TArray<UObject*> UInstancedObjectRefArrayVariable::GetInstancedObjectRefArrayVariableValue(UObject* Owner, UInstancedObjectRefArrayVariable* Variable)
{
	if (!Owner)
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Cannot get instance value without an owner. Returning default value. Callstack below:"));
		PrintScriptCallstack();

		return TArray<UObject*>();
	}

	if (!Variable)
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Cannot get instance value without a variable. Returning default value. Callstack below:"));
		PrintScriptCallstack();

		return TArray<UObject*>();
	}
	else
	{
		return Variable->GetInstancedObjectRefArrayVariableRef(Owner).Value;
	}
}

/* STATIC */ UInstancedObjectRefArrayVariable* UInstancedObjectRefArrayVariable::GetInstancedMutableObjectRefArrayVariable(UInstancedObjectRefArrayVariable* Variable)
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

/* STATIC */ void UInstancedObjectRefArrayVariable::SetInstancedObjectRefArrayVariableValue(UObject* Owner, UInstancedObjectRefArrayVariable* Variable, TArray<UObject*> NewValue)
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
		FInstancedObjectRefArrayVariableType& ObjectRefArrayVariableRef = Variable->GetInstancedObjectRefArrayVariableRef(Owner);
		
		if(ObjectRefArrayVariableRef.Value != NewValue)
		{
			ObjectRefArrayVariableRef.Value = NewValue;
		}
	}
}

/* STATIC */ void UInstancedObjectRefArrayVariable::CopyInstancedObjectRefArrayVariableValue(UObject* Owner, UInstancedObjectRefArrayVariable* Variable, UObject* OtherOwner, UInstancedObjectRefArrayVariable* OtherVariable)
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
		FInstancedObjectRefArrayVariableType& ObjectRefArrayVariableRef = Variable->GetInstancedObjectRefArrayVariableRef(Owner);
		FInstancedObjectRefArrayVariableType& otherObjectRefArrayVariableRef = OtherVariable->GetInstancedObjectRefArrayVariableRef(OtherOwner);

		if(ObjectRefArrayVariableRef.Value != otherObjectRefArrayVariableRef.Value)
		{
			ObjectRefArrayVariableRef.Value = otherObjectRefArrayVariableRef.Value;
		}
	}
}

void UInstancedObjectRefArrayVariable::CleanupEntries()
{
    VariablesMap.Empty();
}

FInstancedObjectRefArrayVariableType& UInstancedObjectRefArrayVariable::GetInstancedObjectRefArrayVariableRef(UObject* Owner)
{
	return VariablesMap.FindOrAdd(Owner);
}

FString UInstancedObjectRefArrayVariable::GetStringValue() const
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

FString UInstancedObjectRefArrayVariable::GetValueAsString(TArray<UObject*> Value) const
{
    TArray<FString> StringValues;
    for(const auto& Item : Value)
    {
        StringValues.Add(Item ? Item->GetName() : "UNSET");
    }

	return UKismetStringLibrary::JoinStringArray(StringValues);
}

