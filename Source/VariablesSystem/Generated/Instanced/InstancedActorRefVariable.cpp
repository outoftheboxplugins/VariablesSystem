// Copyright Out-of-the-Box Plugins 2018-2020. All Rights Reserved.

// GENERATED FILE DO NOT MODIFY DIRECTLY

#include "InstancedActorRefVariable.h"

#include "VSLog.h"

/* STATIC */ AActor* UInstancedActorRefVariable::GetInstancedActorRefVariableValue(UObject* Owner, UInstancedActorRefVariable* Variable)
{
	if (!Owner)
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Cannot get instance value without an owner. Returning default value."));
		return nullptr;
	}

	if (!Variable)
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Cannot get instance value without a variable. Returning default value."));
		return nullptr;
	}
	else
	{
		return Variable->GetInstancedActorRefVariableRef(Owner);
	}
}

/* STATIC */ void UInstancedActorRefVariable::SetInstancedActorRefVariableValue(UObject* Owner, UInstancedActorRefVariable* Variable, AActor* NewValue)
{
	if (!Owner)
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Cannot set instance value without an owner."));
	}
	else if (!Variable)
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Cannot set instance value without a variable."));
	}
	else
	{
		AActor*& ActorRefVariableRef = Variable->GetInstancedActorRefVariableRef(Owner);
		
		if(ActorRefVariableRef != NewValue)
		{
			ActorRefVariableRef = NewValue;
			Variable->Dirty = true;
		}
	}
}

/* STATIC */ void UInstancedActorRefVariable::CopyInstancedActorRefVariableValue(UObject* Owner, UInstancedActorRefVariable* Variable, UObject* OtherOwner, UInstancedActorRefVariable* OtherVariable)
{
	if (!Owner || !OtherOwner)
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Cannot copy instance value without an owner."));
	}
	else if (!Variable || !OtherVariable)
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Cannot copy instance value without a variable."));
	}
	else
	{
		AActor*& ActorRefVariableRef = Variable->GetInstancedActorRefVariableRef(Owner);
		AActor*& otherActorRefVariableRef = OtherVariable->GetInstancedActorRefVariableRef(OtherOwner);

		if(ActorRefVariableRef != otherActorRefVariableRef)
		{
			ActorRefVariableRef = otherActorRefVariableRef;
			Variable->Dirty = true;
		}
	}
}

AActor*& UInstancedActorRefVariable::GetInstancedActorRefVariableRef(UObject* Owner)
{
	return VariablesMap.FindOrAdd(Owner);;
}

FString UInstancedActorRefVariable::GetStringValue() const
{
    FString Lines;

    for (auto& Variable : VariablesMap)
    {
        const auto& Value = Variable.Value;
        const auto& Owner = Variable.Key;

        FString ValueString = GetValueAsString(Value);
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
    return Item->GetName();
}

