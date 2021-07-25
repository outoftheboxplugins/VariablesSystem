// Copyright Out-of-the-Box Plugins 2018-2021. All Rights Reserved.
// GENERATED FILE DO NOT MODIFY DIRECTLY

#include "InstancedBoolVariable.h"

#include "VSLog.h"

/* STATIC */ bool UInstancedBoolVariable::GetInstancedBoolVariableValue(UObject* Owner, UInstancedBoolVariable* Variable)
{
	if (!Owner)
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Cannot get instance value without an owner. Returning default value. Callstack below:"));
		PrintScriptCallstack();

		return false;
	}

	if (!Variable)
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Cannot get instance value without a variable. Returning default value. Callstack below:"));
		PrintScriptCallstack();

		return false;
	}
	else
	{
		return Variable->GetInstancedBoolVariableRef(Owner).Value;
	}
}

/* STATIC */ UInstancedBoolVariable* UInstancedBoolVariable::GetInstancedMutableBoolVariable(UInstancedBoolVariable* Variable)
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

/* STATIC */ void UInstancedBoolVariable::SetInstancedBoolVariableValue(UObject* Owner, UInstancedBoolVariable* Variable, bool NewValue)
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
		FInstancedBoolVariableType& BoolVariableRef = Variable->GetInstancedBoolVariableRef(Owner);
		
		if(BoolVariableRef.Value != NewValue)
		{
			BoolVariableRef.Value = NewValue;
		}
	}
}

/* STATIC */ void UInstancedBoolVariable::CopyInstancedBoolVariableValue(UObject* Owner, UInstancedBoolVariable* Variable, UObject* OtherOwner, UInstancedBoolVariable* OtherVariable)
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
		FInstancedBoolVariableType& BoolVariableRef = Variable->GetInstancedBoolVariableRef(Owner);
		FInstancedBoolVariableType& otherBoolVariableRef = OtherVariable->GetInstancedBoolVariableRef(OtherOwner);

		if(BoolVariableRef.Value != otherBoolVariableRef.Value)
		{
			BoolVariableRef.Value = otherBoolVariableRef.Value;
		}
	}
}

void UInstancedBoolVariable::CleanupEntries()
{
    VariablesMap.Empty();
}

FInstancedBoolVariableType& UInstancedBoolVariable::GetInstancedBoolVariableRef(UObject* Owner)
{
	return VariablesMap.FindOrAdd(Owner);
}

FString UInstancedBoolVariable::GetStringValue() const
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

FString UInstancedBoolVariable::GetValueAsString(bool Value) const
{
    const auto& Item = Value;
    return UKismetStringLibrary::Conv_BoolToString(Item);
}

