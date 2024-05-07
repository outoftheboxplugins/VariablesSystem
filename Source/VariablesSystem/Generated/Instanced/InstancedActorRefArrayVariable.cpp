// Copyright Out-of-the-Box Plugins 2018-2023. All Rights Reserved.
// GENERATED FILE DO NOT MODIFY DIRECTLY

#include "InstancedActorRefArrayVariable.h"

#include "VSLog.h"
#include "Kismet/KismetStringLibrary.h"

/* STATIC */ TArray<AActor*> UInstancedActorRefArrayVariable::GetInstancedActorRefArrayVariableValue(UObject* Owner, UInstancedActorRefArrayVariable* Variable)
{
	if (!Owner)
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Cannot get instance value without an owner. Returning default value. Callstack below:"));
		PrintScriptCallstack();

		return TArray<AActor*>();
	}

	if (!Variable)
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Cannot get instance value without a variable. Returning default value. Callstack below:"));
		PrintScriptCallstack();

		return TArray<AActor*>();
	}
	else
	{
		return Variable->GetInstancedActorRefArrayVariableRef(Owner).Value;
	}
}

/* STATIC */ UInstancedActorRefArrayVariable* UInstancedActorRefArrayVariable::GetInstancedMutableActorRefArrayVariable(UInstancedActorRefArrayVariable* Variable)
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

/* STATIC */ void UInstancedActorRefArrayVariable::SetInstancedActorRefArrayVariableValue(UObject* Owner, UInstancedActorRefArrayVariable* Variable, TArray<AActor*> NewValue)
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
		FInstancedActorRefArrayVariableType& ActorRefArrayVariableRef = Variable->GetInstancedActorRefArrayVariableRef(Owner);
		
		if(ActorRefArrayVariableRef.Value != NewValue)
		{
			ActorRefArrayVariableRef.Value = NewValue;
		}
	}
}

/* STATIC */ void UInstancedActorRefArrayVariable::CopyInstancedActorRefArrayVariableValue(UObject* Owner, UInstancedActorRefArrayVariable* Variable, UObject* OtherOwner, UInstancedActorRefArrayVariable* OtherVariable)
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
		FInstancedActorRefArrayVariableType& ActorRefArrayVariableRef = Variable->GetInstancedActorRefArrayVariableRef(Owner);
		FInstancedActorRefArrayVariableType& otherActorRefArrayVariableRef = OtherVariable->GetInstancedActorRefArrayVariableRef(OtherOwner);

		if(ActorRefArrayVariableRef.Value != otherActorRefArrayVariableRef.Value)
		{
			ActorRefArrayVariableRef.Value = otherActorRefArrayVariableRef.Value;
		}
	}
}

void UInstancedActorRefArrayVariable::CleanupEntries()
{
    VariablesMap.Empty();
}

FInstancedActorRefArrayVariableType& UInstancedActorRefArrayVariable::GetInstancedActorRefArrayVariableRef(UObject* Owner)
{
	return VariablesMap.FindOrAdd(Owner);
}

FString UInstancedActorRefArrayVariable::GetStringValue() const
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

FString UInstancedActorRefArrayVariable::GetValueAsString(TArray<AActor*> Value) const
{
    TArray<FString> StringValues;
    for(const auto& Item : Value)
    {
        StringValues.Add(Item ? Item->GetName() : "UNSET");
    }

    return UKismetStringLibrary::JoinStringArray(StringValues);
}

