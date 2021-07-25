// Copyright Out-of-the-Box Plugins 2018-2021. All Rights Reserved.
// GENERATED FILE DO NOT MODIFY DIRECTLY

#include "InstancedActorRefVariable.h"

#include "VSLog.h"

/* STATIC */ AActor* UInstancedActorRefVariable::GetInstancedActorRefVariableValue(UObject* Owner, UInstancedActorRefVariable* Variable)
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
		return Variable->GetInstancedActorRefVariableRef(Owner).Value;
	}
}

/* STATIC */ UInstancedActorRefVariable* UInstancedActorRefVariable::GetInstancedMutableActorRefVariable(UInstancedActorRefVariable* Variable)
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

/* STATIC */ void UInstancedActorRefVariable::SetInstancedActorRefVariableValue(UObject* Owner, UInstancedActorRefVariable* Variable, AActor* NewValue)
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
		FInstancedActorRefVariableType& ActorRefVariableRef = Variable->GetInstancedActorRefVariableRef(Owner);
		
		if(ActorRefVariableRef.Value != NewValue)
		{
			ActorRefVariableRef.Value = NewValue;
		}
	}
}

/* STATIC */ void UInstancedActorRefVariable::CopyInstancedActorRefVariableValue(UObject* Owner, UInstancedActorRefVariable* Variable, UObject* OtherOwner, UInstancedActorRefVariable* OtherVariable)
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
		FInstancedActorRefVariableType& ActorRefVariableRef = Variable->GetInstancedActorRefVariableRef(Owner);
		FInstancedActorRefVariableType& otherActorRefVariableRef = OtherVariable->GetInstancedActorRefVariableRef(OtherOwner);

		if(ActorRefVariableRef.Value != otherActorRefVariableRef.Value)
		{
			ActorRefVariableRef.Value = otherActorRefVariableRef.Value;
		}
	}
}

void UInstancedActorRefVariable::CleanupEntries()
{
    VariablesMap.Empty();
}

FInstancedActorRefVariableType& UInstancedActorRefVariable::GetInstancedActorRefVariableRef(UObject* Owner)
{
	return VariablesMap.FindOrAdd(Owner);
}

FString UInstancedActorRefVariable::GetStringValue() const
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

FString UInstancedActorRefVariable::GetValueAsString(AActor* Value) const
{
    const auto& Item = Value;
    return Item ? Item->GetName() : "UNSET";
}

