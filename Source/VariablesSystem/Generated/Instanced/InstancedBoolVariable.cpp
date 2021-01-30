// Copyright Out-of-the-Box Plugins 2018-2021. All Rights Reserved.

// GENERATED FILE DO NOT MODIFY DIRECTLY

#include "InstancedBoolVariable.h"

#include "VSLog.h"

/* STATIC */ bool UInstancedBoolVariable::GetInstancedBoolVariableValue(UObject* Owner, UInstancedBoolVariable* Variable)
{
	if (!Owner)
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Variable - %s: Cannot get instance value without an owner. Returning default value."), *GetName());
		return false;
	}

	if (!Variable)
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Variable - %s: Cannot get instance value without a variable. Returning default value."), *GetName());
		return false;
	}
	else
	{
		return Variable->GetInstancedBoolVariableRef(Owner);
	}
}

/* STATIC */ void UInstancedBoolVariable::SetInstancedBoolVariableValue(UObject* Owner, UInstancedBoolVariable* Variable, bool NewValue)
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
		bool& BoolVariableRef = Variable->GetInstancedBoolVariableRef(Owner);
		
		if(BoolVariableRef != NewValue)
		{
			BoolVariableRef = NewValue;
			Variable->Dirty = true;
		}
	}
}

/* STATIC */ void UInstancedBoolVariable::CopyInstancedBoolVariableValue(UObject* Owner, UInstancedBoolVariable* Variable, UObject* OtherOwner, UInstancedBoolVariable* OtherVariable)
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
		bool& BoolVariableRef = Variable->GetInstancedBoolVariableRef(Owner);
		bool& otherBoolVariableRef = OtherVariable->GetInstancedBoolVariableRef(OtherOwner);

		if(BoolVariableRef != otherBoolVariableRef)
		{
			BoolVariableRef = otherBoolVariableRef;
			Variable->Dirty = true;
		}
	}
}

void UInstancedBoolVariable::OnWorldCreationEvent(const UWorld::FActorsInitializedParams& params)
{
	CleanupVariables();
}

void UInstancedBoolVariable::OnWorldDestructionEvent(UWorld* World, bool bSessionEnded, bool bCleanupResources)
{
	CleanupVariables();
}

bool& UInstancedBoolVariable::GetInstancedBoolVariableRef(UObject* Owner)
{
	return VariablesMap.FindOrAdd(Owner);;
}

void UInstancedBoolVariable::CleanupVariables()
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

FString UInstancedBoolVariable::GetStringValue() const
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

FString UInstancedBoolVariable::GetValueAsString(bool Value) const
{
    const auto& Item = Value;
    return UKismetStringLibrary::Conv_BoolToString(Item);
}

