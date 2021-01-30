// Copyright Out-of-the-Box Plugins 2018-2021. All Rights Reserved.

// GENERATED FILE DO NOT MODIFY DIRECTLY

#include "InstancedObjectRefVariable.h"

#include "VSLog.h"

/* STATIC */ UObject* UInstancedObjectRefVariable::GetInstancedObjectRefVariableValue(UObject* Owner, UInstancedObjectRefVariable* Variable)
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
		return Variable->GetInstancedObjectRefVariableRef(Owner);
	}
}

/* STATIC */ void UInstancedObjectRefVariable::SetInstancedObjectRefVariableValue(UObject* Owner, UInstancedObjectRefVariable* Variable, UObject* NewValue)
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
		UObject*& ObjectRefVariableRef = Variable->GetInstancedObjectRefVariableRef(Owner);
		
		if(ObjectRefVariableRef != NewValue)
		{
			ObjectRefVariableRef = NewValue;
			Variable->Dirty = true;
		}
	}
}

/* STATIC */ void UInstancedObjectRefVariable::CopyInstancedObjectRefVariableValue(UObject* Owner, UInstancedObjectRefVariable* Variable, UObject* OtherOwner, UInstancedObjectRefVariable* OtherVariable)
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
		UObject*& ObjectRefVariableRef = Variable->GetInstancedObjectRefVariableRef(Owner);
		UObject*& otherObjectRefVariableRef = OtherVariable->GetInstancedObjectRefVariableRef(OtherOwner);

		if(ObjectRefVariableRef != otherObjectRefVariableRef)
		{
			ObjectRefVariableRef = otherObjectRefVariableRef;
			Variable->Dirty = true;
		}
	}
}

void UInstancedObjectRefVariable::OnWorldCreationEvent(const UWorld::FActorsInitializedParams& params)
{
	CleanupVariables();
}

void UInstancedObjectRefVariable::OnWorldDestructionEvent(UWorld* World, bool bSessionEnded, bool bCleanupResources)
{
	CleanupVariables();
}

UObject*& UInstancedObjectRefVariable::GetInstancedObjectRefVariableRef(UObject* Owner)
{
	return VariablesMap.FindOrAdd(Owner);;
}

void UInstancedObjectRefVariable::CleanupVariables()
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

FString UInstancedObjectRefVariable::GetStringValue() const
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

FString UInstancedObjectRefVariable::GetValueAsString(UObject* Value) const
{
    const auto& Item = Value;
    return Item ? Item->GetName() : "UNSET";
}

