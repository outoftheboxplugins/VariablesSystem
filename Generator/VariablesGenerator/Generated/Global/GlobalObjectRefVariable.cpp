// Copyright Out-of-the-Box Plugins 2018-2020. All Rights Reserved.

// GENERATED FILE DO NOT MODIFY DIRECTLY

#include "GlobalObjectRefVariable.h"

#include "VSLog.h"

#include "CoreMinimal.h"

#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetStringLibrary.h"

UObject* UGlobalObjectRefVariable::GetGlobalObjectRefVariableValue(const UGlobalObjectRefVariable* Variable)
{
	if (Variable)
	{
		return Variable->Value;
	}
	else
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Cannot get value without a variable. Returning default value."));
		return nullptr;
	}
}

void UGlobalObjectRefVariable::SetGlobalObjectRefVariableValue(UGlobalObjectRefVariable* Variable, UObject* NewValue)
{
	if (Variable && Variable->Value != NewValue)
	{
		Variable->Value = NewValue;
		Variable->Dirty = true;
	}
	else
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Cannot set value without a variable."));
	}
}

void UGlobalObjectRefVariable::CopyGlobalObjectRefVariableValue(UGlobalObjectRefVariable* Variable, UGlobalObjectRefVariable* Other)
{
	if (Variable && Other && Variable->Value != Other->Value)
	{
		Variable->Value = Other->Value;
		Variable->Dirty = true;
	}
	else if(!Variable)
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Cannot copy a value without a variable."));
	}
	else if(!Other)
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Cannot copy a value without an other variable."));
	}
}

FString UGlobalObjectRefVariable::GetStringValue() const
{
    const auto& item = Value;
    return item->GetName();
}
