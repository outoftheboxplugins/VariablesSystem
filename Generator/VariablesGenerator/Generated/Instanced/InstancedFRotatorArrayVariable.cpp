// Copyright Out-of-the-Box Plugins 2018-2021. All Rights Reserved.
// GENERATED FILE DO NOT MODIFY DIRECTLY

#include "InstancedFRotatorArrayVariable.h"

#include "VSLog.h"

/* STATIC */ TArray<FRotator> UInstancedFRotatorArrayVariable::GetInstancedFRotatorArrayVariableValue(UObject* Owner, UInstancedFRotatorArrayVariable* Variable)
{
	if (!Owner)
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Cannot get instance value without an owner. Returning default value. Callstack below:"));
		PrintScriptCallstack();

		return TArray<FRotator>();
	}

	if (!Variable)
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Cannot get instance value without a variable. Returning default value. Callstack below:"));
		PrintScriptCallstack();

		return TArray<FRotator>();
	}
	else
	{
		return Variable->GetInstancedFRotatorArrayVariableRef(Owner);
	}
}

/* STATIC */ void UInstancedFRotatorArrayVariable::SetInstancedFRotatorArrayVariableValue(UObject* Owner, UInstancedFRotatorArrayVariable* Variable, TArray<FRotator> NewValue)
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
		TArray<FRotator>& FRotatorArrayVariableRef = Variable->GetInstancedFRotatorArrayVariableRef(Owner);
		
		if(FRotatorArrayVariableRef != NewValue)
		{
			FRotatorArrayVariableRef = NewValue;
		}
	}
}

/* STATIC */ void UInstancedFRotatorArrayVariable::CopyInstancedFRotatorArrayVariableValue(UObject* Owner, UInstancedFRotatorArrayVariable* Variable, UObject* OtherOwner, UInstancedFRotatorArrayVariable* OtherVariable)
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
		TArray<FRotator>& FRotatorArrayVariableRef = Variable->GetInstancedFRotatorArrayVariableRef(Owner);
		TArray<FRotator>& otherFRotatorArrayVariableRef = OtherVariable->GetInstancedFRotatorArrayVariableRef(OtherOwner);

		if(FRotatorArrayVariableRef != otherFRotatorArrayVariableRef)
		{
			FRotatorArrayVariableRef = otherFRotatorArrayVariableRef;
		}
	}
}

void UInstancedFRotatorArrayVariable::CleanupEntries()
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

TArray<FRotator>& UInstancedFRotatorArrayVariable::GetInstancedFRotatorArrayVariableRef(UObject* Owner)
{
	return VariablesMap.FindOrAdd(Owner);;
}

FString UInstancedFRotatorArrayVariable::GetStringValue() const
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

FString UInstancedFRotatorArrayVariable::GetValueAsString(TArray<FRotator> Value) const
{
    TArray<FString> StringValues;
    for(const auto& Item : Value)
    {
        StringValues.Add(UKismetStringLibrary::Conv_RotatorToString(Item));
    }

    return UKismetStringLibrary::JoinStringArray(StringValues);
}

