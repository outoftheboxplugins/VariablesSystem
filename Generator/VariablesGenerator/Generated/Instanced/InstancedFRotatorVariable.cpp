// Copyright Out-of-the-Box Plugins 2018-2021. All Rights Reserved.
// GENERATED FILE DO NOT MODIFY DIRECTLY

#include "InstancedFRotatorVariable.h"

#include "VSLog.h"

/* STATIC */ FRotator UInstancedFRotatorVariable::GetInstancedFRotatorVariableValue(UObject* Owner, UInstancedFRotatorVariable* Variable)
{
	if (!Owner)
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Cannot get instance value without an owner. Returning default value. Callstack below:"));
		PrintScriptCallstack();

		return FRotator::ZeroRotator;
	}

	if (!Variable)
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Cannot get instance value without a variable. Returning default value. Callstack below:"));
		PrintScriptCallstack();

		return FRotator::ZeroRotator;
	}
	else
	{
		return Variable->GetInstancedFRotatorVariableRef(Owner).Value;
	}
}

/* STATIC */ UInstancedFRotatorVariable* UInstancedFRotatorVariable::GetInstancedMutableFRotatorVariable(UInstancedFRotatorVariable* Variable)
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

/* STATIC */ void UInstancedFRotatorVariable::SetInstancedFRotatorVariableValue(UObject* Owner, UInstancedFRotatorVariable* Variable, FRotator NewValue)
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
		FInstancedFRotatorVariableType& FRotatorVariableRef = Variable->GetInstancedFRotatorVariableRef(Owner);
		
		if(FRotatorVariableRef.Value != NewValue)
		{
			FRotatorVariableRef.Value = NewValue;
		}
	}
}

/* STATIC */ void UInstancedFRotatorVariable::CopyInstancedFRotatorVariableValue(UObject* Owner, UInstancedFRotatorVariable* Variable, UObject* OtherOwner, UInstancedFRotatorVariable* OtherVariable)
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
		FInstancedFRotatorVariableType& FRotatorVariableRef = Variable->GetInstancedFRotatorVariableRef(Owner);
		FInstancedFRotatorVariableType& otherFRotatorVariableRef = OtherVariable->GetInstancedFRotatorVariableRef(OtherOwner);

		if(FRotatorVariableRef.Value != otherFRotatorVariableRef.Value)
		{
			FRotatorVariableRef.Value = otherFRotatorVariableRef.Value;
		}
	}
}

void UInstancedFRotatorVariable::CleanupEntries()
{
    VariablesMap.Empty();
}

FInstancedFRotatorVariableType& UInstancedFRotatorVariable::GetInstancedFRotatorVariableRef(UObject* Owner)
{
	return VariablesMap.FindOrAdd(Owner);
}

FString UInstancedFRotatorVariable::GetStringValue() const
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

FString UInstancedFRotatorVariable::GetValueAsString(FRotator Value) const
{
    const auto& Item = Value;
    return UKismetStringLibrary::Conv_RotatorToString(Item);
}

