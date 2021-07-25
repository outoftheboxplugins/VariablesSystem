// Copyright Out-of-the-Box Plugins 2018-2021. All Rights Reserved.
// GENERATED FILE DO NOT MODIFY DIRECTLY

#include "InstancedFRotatorArrayVariable.h"

#include "VSLog.h"

/* STATIC */ TArray<FRotator> UInstancedFRotatorArrayVariable::GetInstancedFRotatorArrayVariableValue(UObject* Owner, UInstancedFRotatorArrayVariable* Variable)
{
	if (!Owner)
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Cannot get instance value without an owner. Returning default value. Callstack below:"));
		PrintScriptCallstack();

		return TArray<FRotator>();
	}

	if (!Variable)
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Cannot get instance value without a variable. Returning default value. Callstack below:"));
		PrintScriptCallstack();

		return TArray<FRotator>();
	}
	else
	{
		return Variable->GetInstancedFRotatorArrayVariableRef(Owner).Value;
	}
}

/* STATIC */ UInstancedFRotatorArrayVariable* UInstancedFRotatorArrayVariable::GetInstancedMutableFRotatorArrayVariable(UInstancedFRotatorArrayVariable* Variable)
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

/* STATIC */ void UInstancedFRotatorArrayVariable::SetInstancedFRotatorArrayVariableValue(UObject* Owner, UInstancedFRotatorArrayVariable* Variable, TArray<FRotator> NewValue)
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
		FInstancedFRotatorArrayVariableType& FRotatorArrayVariableRef = Variable->GetInstancedFRotatorArrayVariableRef(Owner);
		
		if(FRotatorArrayVariableRef.Value != NewValue)
		{
			FRotatorArrayVariableRef.Value = NewValue;
		}
	}
}

/* STATIC */ void UInstancedFRotatorArrayVariable::CopyInstancedFRotatorArrayVariableValue(UObject* Owner, UInstancedFRotatorArrayVariable* Variable, UObject* OtherOwner, UInstancedFRotatorArrayVariable* OtherVariable)
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
		FInstancedFRotatorArrayVariableType& FRotatorArrayVariableRef = Variable->GetInstancedFRotatorArrayVariableRef(Owner);
		FInstancedFRotatorArrayVariableType& otherFRotatorArrayVariableRef = OtherVariable->GetInstancedFRotatorArrayVariableRef(OtherOwner);

		if(FRotatorArrayVariableRef.Value != otherFRotatorArrayVariableRef.Value)
		{
			FRotatorArrayVariableRef.Value = otherFRotatorArrayVariableRef.Value;
		}
	}
}

void UInstancedFRotatorArrayVariable::CleanupEntries()
{
    VariablesMap.Empty();
}

FInstancedFRotatorArrayVariableType& UInstancedFRotatorArrayVariable::GetInstancedFRotatorArrayVariableRef(UObject* Owner)
{
	return VariablesMap.FindOrAdd(Owner);
}

FString UInstancedFRotatorArrayVariable::GetStringValue() const
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

FString UInstancedFRotatorArrayVariable::GetValueAsString(TArray<FRotator> Value) const
{
    TArray<FString> StringValues;
    for(const auto& Item : Value)
    {
        StringValues.Add(UKismetStringLibrary::Conv_RotatorToString(Item));
    }

    return UKismetStringLibrary::JoinStringArray(StringValues);
}

