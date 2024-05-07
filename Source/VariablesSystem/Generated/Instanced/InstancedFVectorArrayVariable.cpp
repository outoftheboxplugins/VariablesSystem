// Copyright Out-of-the-Box Plugins 2018-2023. All Rights Reserved.
// GENERATED FILE DO NOT MODIFY DIRECTLY

#include "InstancedFVectorArrayVariable.h"

#include "VSLog.h"
#include "Kismet/KismetStringLibrary.h"

/* STATIC */ TArray<FVector> UInstancedFVectorArrayVariable::GetInstancedFVectorArrayVariableValue(UObject* Owner, UInstancedFVectorArrayVariable* Variable)
{
	if (!Owner)
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Cannot get instance value without an owner. Returning default value. Callstack below:"));
		PrintScriptCallstack();

		return TArray<FVector>();
	}

	if (!Variable)
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Cannot get instance value without a variable. Returning default value. Callstack below:"));
		PrintScriptCallstack();

		return TArray<FVector>();
	}
	else
	{
		return Variable->GetInstancedFVectorArrayVariableRef(Owner).Value;
	}
}

/* STATIC */ UInstancedFVectorArrayVariable* UInstancedFVectorArrayVariable::GetInstancedMutableFVectorArrayVariable(UInstancedFVectorArrayVariable* Variable)
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

/* STATIC */ void UInstancedFVectorArrayVariable::SetInstancedFVectorArrayVariableValue(UObject* Owner, UInstancedFVectorArrayVariable* Variable, TArray<FVector> NewValue)
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
		FInstancedFVectorArrayVariableType& FVectorArrayVariableRef = Variable->GetInstancedFVectorArrayVariableRef(Owner);
		
		if(FVectorArrayVariableRef.Value != NewValue)
		{
			FVectorArrayVariableRef.Value = NewValue;
		}
	}
}

/* STATIC */ void UInstancedFVectorArrayVariable::CopyInstancedFVectorArrayVariableValue(UObject* Owner, UInstancedFVectorArrayVariable* Variable, UObject* OtherOwner, UInstancedFVectorArrayVariable* OtherVariable)
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
		FInstancedFVectorArrayVariableType& FVectorArrayVariableRef = Variable->GetInstancedFVectorArrayVariableRef(Owner);
		FInstancedFVectorArrayVariableType& otherFVectorArrayVariableRef = OtherVariable->GetInstancedFVectorArrayVariableRef(OtherOwner);

		if(FVectorArrayVariableRef.Value != otherFVectorArrayVariableRef.Value)
		{
			FVectorArrayVariableRef.Value = otherFVectorArrayVariableRef.Value;
		}
	}
}

void UInstancedFVectorArrayVariable::CleanupEntries()
{
    VariablesMap.Empty();
}

FInstancedFVectorArrayVariableType& UInstancedFVectorArrayVariable::GetInstancedFVectorArrayVariableRef(UObject* Owner)
{
	return VariablesMap.FindOrAdd(Owner);
}

FString UInstancedFVectorArrayVariable::GetStringValue() const
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

FString UInstancedFVectorArrayVariable::GetValueAsString(TArray<FVector> Value) const
{
    TArray<FString> StringValues;
    for(const auto& Item : Value)
    {
        StringValues.Add(UKismetStringLibrary::Conv_VectorToString(Item));
    }

    return UKismetStringLibrary::JoinStringArray(StringValues);
}

