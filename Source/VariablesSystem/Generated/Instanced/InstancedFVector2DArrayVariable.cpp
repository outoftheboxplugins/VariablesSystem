// Copyright Out-of-the-Box Plugins 2018-2023. All Rights Reserved.
// GENERATED FILE DO NOT MODIFY DIRECTLY

#include "InstancedFVector2DArrayVariable.h"

#include "VSLog.h"
#include "Kismet/KismetStringLibrary.h"

/* STATIC */ TArray<FVector2D> UInstancedFVector2DArrayVariable::GetInstancedFVector2DArrayVariableValue(UObject* Owner, UInstancedFVector2DArrayVariable* Variable)
{
	if (!Owner)
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Cannot get instance value without an owner. Returning default value. Callstack below:"));
		PrintScriptCallstack();

		return TArray<FVector2D>();
	}

	if (!Variable)
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Cannot get instance value without a variable. Returning default value. Callstack below:"));
		PrintScriptCallstack();

		return TArray<FVector2D>();
	}
	else
	{
		return Variable->GetInstancedFVector2DArrayVariableRef(Owner).Value;
	}
}

/* STATIC */ UInstancedFVector2DArrayVariable* UInstancedFVector2DArrayVariable::GetInstancedMutableFVector2DArrayVariable(UInstancedFVector2DArrayVariable* Variable)
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

/* STATIC */ void UInstancedFVector2DArrayVariable::SetInstancedFVector2DArrayVariableValue(UObject* Owner, UInstancedFVector2DArrayVariable* Variable, TArray<FVector2D> NewValue)
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
		FInstancedFVector2DArrayVariableType& FVector2DArrayVariableRef = Variable->GetInstancedFVector2DArrayVariableRef(Owner);
		
		if(FVector2DArrayVariableRef.Value != NewValue)
		{
			FVector2DArrayVariableRef.Value = NewValue;
		}
	}
}

/* STATIC */ void UInstancedFVector2DArrayVariable::CopyInstancedFVector2DArrayVariableValue(UObject* Owner, UInstancedFVector2DArrayVariable* Variable, UObject* OtherOwner, UInstancedFVector2DArrayVariable* OtherVariable)
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
		FInstancedFVector2DArrayVariableType& FVector2DArrayVariableRef = Variable->GetInstancedFVector2DArrayVariableRef(Owner);
		FInstancedFVector2DArrayVariableType& otherFVector2DArrayVariableRef = OtherVariable->GetInstancedFVector2DArrayVariableRef(OtherOwner);

		if(FVector2DArrayVariableRef.Value != otherFVector2DArrayVariableRef.Value)
		{
			FVector2DArrayVariableRef.Value = otherFVector2DArrayVariableRef.Value;
		}
	}
}

void UInstancedFVector2DArrayVariable::CleanupEntries()
{
    VariablesMap.Empty();
}

FInstancedFVector2DArrayVariableType& UInstancedFVector2DArrayVariable::GetInstancedFVector2DArrayVariableRef(UObject* Owner)
{
	return VariablesMap.FindOrAdd(Owner);
}

FString UInstancedFVector2DArrayVariable::GetStringValue() const
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

FString UInstancedFVector2DArrayVariable::GetValueAsString(TArray<FVector2D> Value) const
{
    TArray<FString> StringValues;
    for(const auto& Item : Value)
    {
        StringValues.Add(UKismetStringLibrary::Conv_Vector2dToString(Item));
    }

    return UKismetStringLibrary::JoinStringArray(StringValues);
}

