// Copyright Out-of-the-Box Plugins 2018-2020. All Rights Reserved.

// GENERATED FILE DO NOT MODIFY DIRECTLY

#include "GlobalFloatVariable.h"

#include "VSLog.h"

#include "CoreMinimal.h"

#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetStringLibrary.h"

/* STATIC */ float UGlobalFloatVariable::GetGlobalFloatVariableValue(const UGlobalFloatVariable* Variable)
{
	if (Variable)
	{
		return Variable->Value;
	}
	else
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Cannot get value without a variable. Returning default value."));
		return 0.0f;
	}
}

/* STATIC */ void UGlobalFloatVariable::SetGlobalFloatVariableValue(UGlobalFloatVariable* Variable, float NewValue)
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

/* STATIC */ void UGlobalFloatVariable::CopyGlobalFloatVariableValue(UGlobalFloatVariable* Variable, UGlobalFloatVariable* OtherVariable)
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

FString UGlobalFloatVariable::GetStringValue() const
{
    const auto& Item = Value;
    return UKismetStringLibrary::Conv_FloatToString(Item);
}

void UGlobalFloatVariable::Save()
{
	if (Dirty == false)
	{
		return;
	}

	UGameplayStatics::SaveGameToSlot(this, GetSaveLocation(), 0);
	Dirty = false;
}

void UGlobalFloatVariable::Load()
{
	UGlobalFloatVariable* LoadGameInstance = Cast<UGlobalFloatVariable>(UGameplayStatics::CreateSaveGameObject(UGlobalFloatVariable::StaticClass()));
	LoadGameInstance = Cast<UGlobalFloatVariable>(UGameplayStatics::LoadGameFromSlot(GetSaveLocation(), 0));
	
	if (LoadGameInstance != nullptr)
	{
		Value = LoadGameInstance->Value;
	}
}
