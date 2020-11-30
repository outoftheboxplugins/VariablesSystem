// Copyright Out-of-the-Box Plugins 2018-2020. All Rights Reserved.

// GENERATED FILE DO NOT MODIFY DIRECTLY

#include "GlobalBoolVariable.h"

#include "VSLog.h"

#include "CoreMinimal.h"

#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetStringLibrary.h"

/* STATIC */ bool UGlobalBoolVariable::GetGlobalBoolVariableValue(const UGlobalBoolVariable* Variable)
{
	if (Variable)
	{
		return Variable->Value;
	}
	else
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Cannot get value without a variable. Returning default value."));
		return false;
	}
}

/* STATIC */ void UGlobalBoolVariable::SetGlobalBoolVariableValue(UGlobalBoolVariable* Variable, bool NewValue)
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

/* STATIC */ void UGlobalBoolVariable::CopyGlobalBoolVariableValue(UGlobalBoolVariable* Variable, UGlobalBoolVariable* OtherVariable)
{
	if (Variable && OtherVariable && Variable->Value != OtherVariable->Value)
	{
		Variable->Value = OtherVariable->Value;
		Variable->Dirty = true;
	}
	else if(!Variable)
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Cannot copy a value without a variable."));
	}
	else if(!OtherVariable)
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Cannot copy a value without an other variable."));
	}
}

FString UGlobalBoolVariable::GetStringValue() const
{
    const auto& Item = Value;
    return UKismetStringLibrary::Conv_BoolToString(Item);
}

void UGlobalBoolVariable::Save()
{
	if (Dirty == false)
	{
		return;
	}

	UGameplayStatics::SaveGameToSlot(this, GetSaveLocation(), 0);
	Dirty = false;
}

void UGlobalBoolVariable::Load()
{
	UGlobalBoolVariable* LoadGameInstance = Cast<UGlobalBoolVariable>(UGameplayStatics::CreateSaveGameObject(UGlobalBoolVariable::StaticClass()));
	LoadGameInstance = Cast<UGlobalBoolVariable>(UGameplayStatics::LoadGameFromSlot(GetSaveLocation(), 0));
	
	if (LoadGameInstance != nullptr)
	{
		Value = LoadGameInstance->Value;
	}
}
