// Copyright Out-of-the-Box Plugins 2018-2023. All Rights Reserved.
// GENERATED FILE DO NOT MODIFY DIRECTLY

#include "InstancedIntArrayVariable.h"

#include "VSLog.h"
#include "Kismet/KismetStringLibrary.h"

/* STATIC */ TArray<int32> UInstancedIntArrayVariable::GetInstancedIntArrayVariableValue(UObject* Owner, UInstancedIntArrayVariable* Variable)
{
	if (!Owner)
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Cannot get instance value without an owner. Returning default value. Callstack below:"));
		PrintScriptCallstack();

		return TArray<int32>();
	}

	if (!Variable)
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Cannot get instance value without a variable. Returning default value. Callstack below:"));
		PrintScriptCallstack();

		return TArray<int32>();
	}
	else
	{
		return Variable->GetInstancedIntArrayVariableRef(Owner).Value;
	}
}

/* STATIC */ UInstancedIntArrayVariable* UInstancedIntArrayVariable::GetInstancedMutableIntArrayVariable(UInstancedIntArrayVariable* Variable)
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

/* STATIC */ void UInstancedIntArrayVariable::SetInstancedIntArrayVariableValue(UObject* Owner, UInstancedIntArrayVariable* Variable, TArray<int32> NewValue)
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
		FInstancedIntArrayVariableType& IntArrayVariableRef = Variable->GetInstancedIntArrayVariableRef(Owner);
		
		if(IntArrayVariableRef.Value != NewValue)
		{
			IntArrayVariableRef.Value = NewValue;
		}
	}
}

/* STATIC */ void UInstancedIntArrayVariable::CopyInstancedIntArrayVariableValue(UObject* Owner, UInstancedIntArrayVariable* Variable, UObject* OtherOwner, UInstancedIntArrayVariable* OtherVariable)
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
		FInstancedIntArrayVariableType& IntArrayVariableRef = Variable->GetInstancedIntArrayVariableRef(Owner);
		FInstancedIntArrayVariableType& otherIntArrayVariableRef = OtherVariable->GetInstancedIntArrayVariableRef(OtherOwner);

		if(IntArrayVariableRef.Value != otherIntArrayVariableRef.Value)
		{
			IntArrayVariableRef.Value = otherIntArrayVariableRef.Value;
		}
	}
}

void UInstancedIntArrayVariable::CleanupEntries()
{
    VariablesMap.Empty();
}

FInstancedIntArrayVariableType& UInstancedIntArrayVariable::GetInstancedIntArrayVariableRef(UObject* Owner)
{
	return VariablesMap.FindOrAdd(Owner);
}

FString UInstancedIntArrayVariable::GetStringValue() const
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

FString UInstancedIntArrayVariable::GetValueAsString(TArray<int32> Value) const
{
    TArray<FString> StringValues;
    for(const auto& Item : Value)
    {
        StringValues.Add(UKismetStringLibrary::Conv_IntToString(Item));
    }

    return UKismetStringLibrary::JoinStringArray(StringValues);
}

