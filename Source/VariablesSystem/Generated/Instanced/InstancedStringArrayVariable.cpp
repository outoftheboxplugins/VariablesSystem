// Copyright Out-of-the-Box Plugins 2018-2021. All Rights Reserved.
// GENERATED FILE DO NOT MODIFY DIRECTLY

#include "InstancedStringArrayVariable.h"

#include "VSLog.h"

/* STATIC */ TArray<FString> UInstancedStringArrayVariable::GetInstancedStringArrayVariableValue(UObject* Owner, UInstancedStringArrayVariable* Variable)
{
	if (!Owner)
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Cannot get instance value without an owner. Returning default value. Callstack below:"));
		PrintScriptCallstack();

		return TArray<FString>();
	}

	if (!Variable)
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Cannot get instance value without a variable. Returning default value. Callstack below:"));
		PrintScriptCallstack();

		return TArray<FString>();
	}
	else
	{
		return Variable->GetInstancedStringArrayVariableRef(Owner).Value;
	}
}

/* STATIC */ UInstancedStringArrayVariable* UInstancedStringArrayVariable::GetInstancedMutableStringArrayVariable(UInstancedStringArrayVariable* Variable)
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

/* STATIC */ void UInstancedStringArrayVariable::SetInstancedStringArrayVariableValue(UObject* Owner, UInstancedStringArrayVariable* Variable, TArray<FString> NewValue)
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
		FInstancedStringArrayVariableType& StringArrayVariableRef = Variable->GetInstancedStringArrayVariableRef(Owner);
		
		if(StringArrayVariableRef.Value != NewValue)
		{
			StringArrayVariableRef.Value = NewValue;
		}
	}
}

/* STATIC */ void UInstancedStringArrayVariable::CopyInstancedStringArrayVariableValue(UObject* Owner, UInstancedStringArrayVariable* Variable, UObject* OtherOwner, UInstancedStringArrayVariable* OtherVariable)
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
		FInstancedStringArrayVariableType& StringArrayVariableRef = Variable->GetInstancedStringArrayVariableRef(Owner);
		FInstancedStringArrayVariableType& otherStringArrayVariableRef = OtherVariable->GetInstancedStringArrayVariableRef(OtherOwner);

		if(StringArrayVariableRef.Value != otherStringArrayVariableRef.Value)
		{
			StringArrayVariableRef.Value = otherStringArrayVariableRef.Value;
		}
	}
}

void UInstancedStringArrayVariable::CleanupEntries()
{
    VariablesMap.Empty();
}

FInstancedStringArrayVariableType& UInstancedStringArrayVariable::GetInstancedStringArrayVariableRef(UObject* Owner)
{
	return VariablesMap.FindOrAdd(Owner);
}

FString UInstancedStringArrayVariable::GetStringValue() const
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

FString UInstancedStringArrayVariable::GetValueAsString(TArray<FString> Value) const
{
    TArray<FString> StringValues;
    for(const auto& Item : Value)
    {
        StringValues.Add(Item);
    }

    return UKismetStringLibrary::JoinStringArray(StringValues);
}

