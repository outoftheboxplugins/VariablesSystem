// Copyright Out-of-the-Box Plugins 2018-2020. All Rights Reserved.

// GENERATED FILE DO NOT MODIFY DIRECTLY

#include "GlobalStringVariable.h"

#include "VSLog.h"

#include "CoreMinimal.h"

#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetStringLibrary.h"

FString UGlobalStringVariable::GetGlobalStringVariableValue(const UGlobalStringVariable* Variable)
{
	if (Variable)
	{
		return Variable->Value;
	}
	else
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Cannot get value without a variable. Returning default value."));
		return "";
	}
}

void UGlobalStringVariable::SetGlobalStringVariableValue(UGlobalStringVariable* Variable, FString NewValue)
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

void UGlobalStringVariable::CopyGlobalStringVariableValue(UGlobalStringVariable* Variable, UGlobalStringVariable* Other)
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

void UGlobalStringVariable::Save()
{
	if (Dirty == false)
	{
		return;
	}

	UGameplayStatics::SaveGameToSlot(this, GetSaveLocation(), 0);
	Dirty = false;
}

void UGlobalStringVariable::Load()
{
	UGlobalStringVariable* LoadGameInstance = Cast<UGlobalStringVariable>(UGameplayStatics::CreateSaveGameObject(UGlobalStringVariable::StaticClass()));
	LoadGameInstance = Cast<UGlobalStringVariable>(UGameplayStatics::LoadGameFromSlot(GetSaveLocation(), 0));
	
	if (LoadGameInstance != nullptr)
	{
		Value = LoadGameInstance->Value;
	}
}

FString UGlobalStringVariable::GetStringValue() const
{
    const auto& item = Value;
    return item;
}
