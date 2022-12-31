// Copyright Out-of-the-Box Plugins 2018-2023. All Rights Reserved.
// GENERATED FILE DO NOT MODIFY DIRECTLY

#include "GlobalObjectRefArrayVariable.h"

#include "VSLog.h"

#include "CoreMinimal.h"

#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetStringLibrary.h"

/* STATIC */ TArray<UObject*> UGlobalObjectRefArrayVariable::GetGlobalObjectRefArrayVariableValue(const UGlobalObjectRefArrayVariable* Variable)
{
	if (Variable)
	{
		return Variable->Value;
	}
	else
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Cannot get value without a variable. Returning default value. Callstack below:"));
		PrintScriptCallstack();

		return TArray<UObject*>();
	}
}

/* STATIC */ UGlobalObjectRefArrayVariable* UGlobalObjectRefArrayVariable::GetGlobalMutableObjectRefArrayVariable(UGlobalObjectRefArrayVariable* Variable)
{
    return Variable;
}

/* STATIC */ void UGlobalObjectRefArrayVariable::SetGlobalObjectRefArrayVariableValue(UGlobalObjectRefArrayVariable* Variable, TArray<UObject*> NewValue)
{
	if (Variable && Variable->Value != NewValue)
	{
		Variable->Value = NewValue;
		Variable->Dirty = true;
	}
	else if(!Variable)
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Cannot set value without a variable. Callstack below:"));
		PrintScriptCallstack();
	}
}

/* STATIC */ void UGlobalObjectRefArrayVariable::CopyGlobalObjectRefArrayVariableValue(UGlobalObjectRefArrayVariable* Variable, UGlobalObjectRefArrayVariable* OtherVariable)
{
	if (Variable && OtherVariable && Variable->Value != OtherVariable->Value)
	{
		Variable->Value = OtherVariable->Value;
		Variable->Dirty = true;
	}
	else if(!Variable)
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Cannot copy a value without a variable. Callstack below:"));
		PrintScriptCallstack();
	}
	else if(!OtherVariable)
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Cannot copy a value without an other variable. Callstack below:"));
		PrintScriptCallstack();
	}
}

FString UGlobalObjectRefArrayVariable::GetStringValue() const
{
    TArray<FString> StringValues;
    for(const auto& Item : Value)
    {
        StringValues.Add(Item ? Item->GetName() : "UNSET");
    }

    return UKismetStringLibrary::JoinStringArray(StringValues);
}
