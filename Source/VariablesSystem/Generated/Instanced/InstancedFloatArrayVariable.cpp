// Copyright Out-of-the-Box Plugins 2018-2023. All Rights Reserved.
// GENERATED FILE DO NOT MODIFY DIRECTLY

#include "InstancedFloatArrayVariable.h"

#include "VSLog.h"
#include "Kismet/KismetStringLibrary.h"

/* STATIC */ TArray<float> UInstancedFloatArrayVariable::GetInstancedFloatArrayVariableValue(UObject* Owner, UInstancedFloatArrayVariable* Variable)
{
	if (!Owner)
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Cannot get instance value without an owner. Returning default value. Callstack below:"));
		PrintScriptCallstack();

		return TArray<float>();
	}

	if (!Variable)
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Cannot get instance value without a variable. Returning default value. Callstack below:"));
		PrintScriptCallstack();

		return TArray<float>();
	}
	else
	{
		return Variable->GetInstancedFloatArrayVariableRef(Owner).Value;
	}
}

/* STATIC */ UInstancedFloatArrayVariable* UInstancedFloatArrayVariable::GetInstancedMutableFloatArrayVariable(UInstancedFloatArrayVariable* Variable)
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

/* STATIC */ void UInstancedFloatArrayVariable::SetInstancedFloatArrayVariableValue(UObject* Owner, UInstancedFloatArrayVariable* Variable, TArray<float> NewValue)
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
		FInstancedFloatArrayVariableType& FloatArrayVariableRef = Variable->GetInstancedFloatArrayVariableRef(Owner);
		
		if(FloatArrayVariableRef.Value != NewValue)
		{
			FloatArrayVariableRef.Value = NewValue;
		}
	}
}

/* STATIC */ void UInstancedFloatArrayVariable::CopyInstancedFloatArrayVariableValue(UObject* Owner, UInstancedFloatArrayVariable* Variable, UObject* OtherOwner, UInstancedFloatArrayVariable* OtherVariable)
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
		FInstancedFloatArrayVariableType& FloatArrayVariableRef = Variable->GetInstancedFloatArrayVariableRef(Owner);
		FInstancedFloatArrayVariableType& otherFloatArrayVariableRef = OtherVariable->GetInstancedFloatArrayVariableRef(OtherOwner);

		if(FloatArrayVariableRef.Value != otherFloatArrayVariableRef.Value)
		{
			FloatArrayVariableRef.Value = otherFloatArrayVariableRef.Value;
		}
	}
}

void UInstancedFloatArrayVariable::CleanupEntries()
{
    VariablesMap.Empty();
}

FInstancedFloatArrayVariableType& UInstancedFloatArrayVariable::GetInstancedFloatArrayVariableRef(UObject* Owner)
{
	return VariablesMap.FindOrAdd(Owner);
}

FString UInstancedFloatArrayVariable::GetStringValue() const
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

FString UInstancedFloatArrayVariable::GetValueAsString(TArray<float> Value) const
{
    TArray<FString> StringValues;
    for(const auto& Item : Value)
    {
        StringValues.Add(FString::SanitizeFloat(Item));
    }

    return UKismetStringLibrary::JoinStringArray(StringValues);
}
