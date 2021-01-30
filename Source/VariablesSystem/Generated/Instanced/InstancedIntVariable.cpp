// Copyright Out-of-the-Box Plugins 2018-2021. All Rights Reserved.

// GENERATED FILE DO NOT MODIFY DIRECTLY

#include "InstancedIntVariable.h"

#include "VSLog.h"

/* STATIC */ int32 UInstancedIntVariable::GetInstancedIntVariableValue(UObject* Owner, UInstancedIntVariable* Variable)
{
	if (!Owner)
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Cannot get instance value without an owner. Returning default value. Callstack below:"));
		PrintScriptCallstack();

		return 0;
	}

	if (!Variable)
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Cannot get instance value without a variable. Returning default value. Callstack below:"));
		PrintScriptCallstack();

		return 0;
	}
	else
	{
		return Variable->GetInstancedIntVariableRef(Owner);
	}
}

/* STATIC */ void UInstancedIntVariable::SetInstancedIntVariableValue(UObject* Owner, UInstancedIntVariable* Variable, int32 NewValue)
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
		int32& IntVariableRef = Variable->GetInstancedIntVariableRef(Owner);
		
		if(IntVariableRef != NewValue)
		{
			IntVariableRef = NewValue;
			Variable->Dirty = true;
		}
	}
}

/* STATIC */ void UInstancedIntVariable::CopyInstancedIntVariableValue(UObject* Owner, UInstancedIntVariable* Variable, UObject* OtherOwner, UInstancedIntVariable* OtherVariable)
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
		int32& IntVariableRef = Variable->GetInstancedIntVariableRef(Owner);
		int32& otherIntVariableRef = OtherVariable->GetInstancedIntVariableRef(OtherOwner);

		if(IntVariableRef != otherIntVariableRef)
		{
			IntVariableRef = otherIntVariableRef;
			Variable->Dirty = true;
		}
	}
}

void UInstancedIntVariable::OnWorldCreationEvent(const UWorld::FActorsInitializedParams& params)
{
	CleanupVariables();
}

void UInstancedIntVariable::OnWorldDestructionEvent(UWorld* World, bool bSessionEnded, bool bCleanupResources)
{
	CleanupVariables();
}

int32& UInstancedIntVariable::GetInstancedIntVariableRef(UObject* Owner)
{
	return VariablesMap.FindOrAdd(Owner);;
}

void UInstancedIntVariable::CleanupVariables()
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

FString UInstancedIntVariable::GetStringValue() const
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

FString UInstancedIntVariable::GetValueAsString(int32 Value) const
{
    const auto& Item = Value;
    return UKismetStringLibrary::Conv_IntToString(Item);
}

