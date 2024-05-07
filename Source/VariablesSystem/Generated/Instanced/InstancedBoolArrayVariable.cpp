// Copyright Out-of-the-Box Plugins 2018-2023. All Rights Reserved.
// GENERATED FILE DO NOT MODIFY DIRECTLY

#include "InstancedBoolArrayVariable.h"

#include "VSLog.h"
#include "Kismet/KismetStringLibrary.h"

/* STATIC */ TArray<bool> UInstancedBoolArrayVariable::GetInstancedBoolArrayVariableValue(UObject* Owner, UInstancedBoolArrayVariable* Variable)
{
	if (!Owner)
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Cannot get instance value without an owner. Returning default value. Callstack below:"));
		PrintScriptCallstack();

		return TArray<bool>();
	}

	if (!Variable)
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Cannot get instance value without a variable. Returning default value. Callstack below:"));
		PrintScriptCallstack();

		return TArray<bool>();
	}
	else
	{
		return Variable->GetInstancedBoolArrayVariableRef(Owner).Value;
	}
}

/* STATIC */ UInstancedBoolArrayVariable* UInstancedBoolArrayVariable::GetInstancedMutableBoolArrayVariable(UInstancedBoolArrayVariable* Variable)
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

/* STATIC */ void UInstancedBoolArrayVariable::SetInstancedBoolArrayVariableValue(UObject* Owner, UInstancedBoolArrayVariable* Variable, TArray<bool> NewValue)
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
		FInstancedBoolArrayVariableType& BoolArrayVariableRef = Variable->GetInstancedBoolArrayVariableRef(Owner);
		
		if(BoolArrayVariableRef.Value != NewValue)
		{
			BoolArrayVariableRef.Value = NewValue;
		}
	}
}

/* STATIC */ void UInstancedBoolArrayVariable::CopyInstancedBoolArrayVariableValue(UObject* Owner, UInstancedBoolArrayVariable* Variable, UObject* OtherOwner, UInstancedBoolArrayVariable* OtherVariable)
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
		FInstancedBoolArrayVariableType& BoolArrayVariableRef = Variable->GetInstancedBoolArrayVariableRef(Owner);
		FInstancedBoolArrayVariableType& otherBoolArrayVariableRef = OtherVariable->GetInstancedBoolArrayVariableRef(OtherOwner);

		if(BoolArrayVariableRef.Value != otherBoolArrayVariableRef.Value)
		{
			BoolArrayVariableRef.Value = otherBoolArrayVariableRef.Value;
		}
	}
}

void UInstancedBoolArrayVariable::CleanupEntries()
{
    VariablesMap.Empty();
}

FInstancedBoolArrayVariableType& UInstancedBoolArrayVariable::GetInstancedBoolArrayVariableRef(UObject* Owner)
{
	return VariablesMap.FindOrAdd(Owner);
}

FString UInstancedBoolArrayVariable::GetStringValue() const
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

FString UInstancedBoolArrayVariable::GetValueAsString(TArray<bool> Value) const
{
    TArray<FString> StringValues;
    for(const auto& Item : Value)
    {
        StringValues.Add(UKismetStringLibrary::Conv_BoolToString(Item));
    }

    return UKismetStringLibrary::JoinStringArray(StringValues);
}

