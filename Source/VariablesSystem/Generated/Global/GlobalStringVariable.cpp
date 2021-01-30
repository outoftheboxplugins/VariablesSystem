// Copyright Out-of-the-Box Plugins 2018-2021. All Rights Reserved.

// GENERATED FILE DO NOT MODIFY DIRECTLY

#include "GlobalStringVariable.h"

#include "VSLog.h"

#include "CoreMinimal.h"

#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetStringLibrary.h"

/* STATIC */ FString UGlobalStringVariable::GetGlobalStringVariableValue(const UGlobalStringVariable* Variable)
{
	if (Variable)
	{
		return Variable->Value;
	}
	else
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Variable - %s: Cannot get value without a variable. Returning default value."), *GetName());
		return "";
	}
}

/* STATIC */ void UGlobalStringVariable::SetGlobalStringVariableValue(UGlobalStringVariable* Variable, FString NewValue)
{
	if (Variable && Variable->Value != NewValue)
	{
		Variable->Value = NewValue;
		Variable->Dirty = true;
	}
	else
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Variable - %s: Cannot set value without a variable."), *GetName());
	}
}

/* STATIC */ void UGlobalStringVariable::CopyGlobalStringVariableValue(UGlobalStringVariable* Variable, UGlobalStringVariable* OtherVariable)
{
	if (Variable && OtherVariable && Variable->Value != OtherVariable->Value)
	{
		Variable->Value = OtherVariable->Value;
		Variable->Dirty = true;
	}
	else if(!Variable)
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Variable - %s: Cannot copy a value without a variable."), *GetName());
	}
	else if(!OtherVariable)
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Variable - %s: Cannot copy a value without an other variable."), *GetName());
	}
}

FString UGlobalStringVariable::GetStringValue() const
{
    const auto& Item = Value;
    return Item;
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
