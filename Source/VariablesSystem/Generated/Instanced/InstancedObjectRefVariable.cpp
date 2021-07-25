// Copyright Out-of-the-Box Plugins 2018-2021. All Rights Reserved.
// GENERATED FILE DO NOT MODIFY DIRECTLY

#include "InstancedObjectRefVariable.h"

#include "VSLog.h"

/* STATIC */ UObject* UInstancedObjectRefVariable::GetInstancedObjectRefVariableValue(UObject* Owner, UInstancedObjectRefVariable* Variable)
{
	if (!Owner)
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Cannot get instance value without an owner. Returning default value. Callstack below:"));
		PrintScriptCallstack();

		return nullptr;
	}

	if (!Variable)
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Cannot get instance value without a variable. Returning default value. Callstack below:"));
		PrintScriptCallstack();

		return nullptr;
	}
	else
	{
		return Variable->GetInstancedObjectRefVariableRef(Owner).Value;
	}
}

/* STATIC */ UInstancedObjectRefVariable* UInstancedObjectRefVariable::GetInstancedMutableObjectRefVariable(UInstancedObjectRefVariable* Variable)
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

/* STATIC */ void UInstancedObjectRefVariable::SetInstancedObjectRefVariableValue(UObject* Owner, UInstancedObjectRefVariable* Variable, UObject* NewValue)
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
		FInstancedObjectRefVariableType& ObjectRefVariableRef = Variable->GetInstancedObjectRefVariableRef(Owner);
		
		if(ObjectRefVariableRef.Value != NewValue)
		{
			ObjectRefVariableRef.Value = NewValue;
		}
	}
}

/* STATIC */ void UInstancedObjectRefVariable::CopyInstancedObjectRefVariableValue(UObject* Owner, UInstancedObjectRefVariable* Variable, UObject* OtherOwner, UInstancedObjectRefVariable* OtherVariable)
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
		FInstancedObjectRefVariableType& ObjectRefVariableRef = Variable->GetInstancedObjectRefVariableRef(Owner);
		FInstancedObjectRefVariableType& otherObjectRefVariableRef = OtherVariable->GetInstancedObjectRefVariableRef(OtherOwner);

		if(ObjectRefVariableRef.Value != otherObjectRefVariableRef.Value)
		{
			ObjectRefVariableRef.Value = otherObjectRefVariableRef.Value;
		}
	}
}

void UInstancedObjectRefVariable::CleanupEntries()
{
    VariablesMap.Empty();
}

FInstancedObjectRefVariableType& UInstancedObjectRefVariable::GetInstancedObjectRefVariableRef(UObject* Owner)
{
	return VariablesMap.FindOrAdd(Owner);
}

FString UInstancedObjectRefVariable::GetStringValue() const
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

FString UInstancedObjectRefVariable::GetValueAsString(UObject* Value) const
{
    const auto& Item = Value;
    return Item ? Item->GetName() : "UNSET";
}

