// Copyright Out-of-the-Box Plugins 2018-2025. All Rights Reserved.
// GENERATED FILE DO NOT MODIFY DIRECTLY

#include "InstancedStringVariable.h"

#include "VSLog.h"

/* STATIC */ FString UInstancedStringVariable::GetInstancedStringVariableValue(UObject* Owner, UInstancedStringVariable* Variable)
{
	if (!Owner)
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Cannot get instance value without an owner. Returning default value. Callstack below:"));
		PrintScriptCallstack();

		return "";
	}

	if (!Variable)
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Cannot get instance value without a variable. Returning default value. Callstack below:"));
		PrintScriptCallstack();

		return "";
	}
	else
	{
		return Variable->GetInstancedStringVariableRef(Owner).Value;
	}
}

/* STATIC */ UInstancedStringVariable* UInstancedStringVariable::GetInstancedMutableStringVariable(UInstancedStringVariable* Variable)
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

/* STATIC */ void UInstancedStringVariable::SetInstancedStringVariableValue(UObject* Owner, UInstancedStringVariable* Variable, FString NewValue)
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
		FInstancedStringVariableType& StringVariableRef = Variable->GetInstancedStringVariableRef(Owner);
		
		if(StringVariableRef.Value != NewValue)
		{
			StringVariableRef.Value = NewValue;
		}
	}
}

/* STATIC */ void UInstancedStringVariable::CopyInstancedStringVariableValue(UObject* Owner, UInstancedStringVariable* Variable, UObject* OtherOwner, UInstancedStringVariable* OtherVariable)
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
		FInstancedStringVariableType& StringVariableRef = Variable->GetInstancedStringVariableRef(Owner);
		FInstancedStringVariableType& otherStringVariableRef = OtherVariable->GetInstancedStringVariableRef(OtherOwner);

		if(StringVariableRef.Value != otherStringVariableRef.Value)
		{
			StringVariableRef.Value = otherStringVariableRef.Value;
		}
	}
}

void UInstancedStringVariable::CleanupEntries()
{
    VariablesMap.Empty();
}

FInstancedStringVariableType& UInstancedStringVariable::GetInstancedStringVariableRef(UObject* Owner)
{
	return VariablesMap.FindOrAdd(Owner);
}

FString UInstancedStringVariable::GetStringValue() const
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

FString UInstancedStringVariable::GetValueAsString(FString Value) const
{
    const auto& Item = Value;
    return Item;
}

