// Copyright Out-of-the-Box Plugins 2018-2021. All Rights Reserved.

// GENERATED FILE DO NOT MODIFY DIRECTLY

#include "InstancedActorRefVariable.h"

#include "VSLog.h"

/* STATIC */ AActor* UInstancedActorRefVariable::GetInstancedActorRefVariableValue(UObject* Owner, UInstancedActorRefVariable* Variable)
{
	if (!Owner)
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Variable - %s: Cannot get instance value without an owner. Returning default value."), *GetName());
		return nullptr;
	}

	if (!Variable)
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Variable - %s: Cannot get instance value without a variable. Returning default value."), *GetName());
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
		UE_LOG(LogVariablesSystem, Warning, TEXT("Variable - %s: Cannot set instance value without an owner."), *GetName());
	}
	else if (!Variable)
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Variable - %s: Cannot set instance value without a variable."), *GetName());
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
		UE_LOG(LogVariablesSystem, Warning, TEXT("Variable - %s: Cannot copy instance value without an owner."), *GetName());
	}
	else if (!Variable || !OtherVariable)
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Variable - %s: Cannot copy instance value without a variable."), *GetName());
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

void UInstancedActorRefVariable::OnWorldCreationEvent(const UWorld::FActorsInitializedParams& params)
{
	CleanupVariables();
}

void UInstancedActorRefVariable::OnWorldDestructionEvent(UWorld* World, bool bSessionEnded, bool bCleanupResources)
{
	CleanupVariables();
}

AActor*& UInstancedActorRefVariable::GetInstancedActorRefVariableRef(UObject* Owner)
{
	return VariablesMap.FindOrAdd(Owner);;
}

void UInstancedActorRefVariable::CleanupVariables()
{
	int32 index = 0;
	while(index < VariablesMap.Num())
	{
		TArray<FWeakObjectPtr> Owners;
		VariablesMap.GetKeys(Owners);

		if (!Owners[index].IsValid())
		{
			VariablesMap.Remove(Owners[index]);
		}
		else
		{
			index++;
		}
	}
}

FString UInstancedActorRefVariable::GetStringValue() const
{
    FString Lines;

    for (auto& Variable : VariablesMap)
    {
        const auto& Value = Variable.Value;
        const auto& Owner = Variable.Key;

		FString ValueString = GetValueAsString(Value);
		FString OwnerString = Owner.IsValid() ? Owner.Get()->GetName() : FString("Invalid Owner");
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

