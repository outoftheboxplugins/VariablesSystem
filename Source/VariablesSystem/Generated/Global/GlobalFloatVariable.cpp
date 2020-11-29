// Copyright Out-of-the-Box Plugins 2018-2020. All Rights Reserved.

// GENERATED FILE DO NOT MODIFY DIRECTLY

#include "GlobalFloatVariable.h"

#include "VSLog.h"

#include "CoreMinimal.h"

#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetStringLibrary.h"

float UGlobalFloatVariable::GetGlobalFloatVariableValue(const UGlobalFloatVariable* Variable)
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

void UGlobalFloatVariable::SetGlobalFloatVariableValue(UGlobalFloatVariable* Variable, float NewValue)
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

void UGlobalFloatVariable::CopyGlobalFloatVariableValue(UGlobalFloatVariable* Variable, UGlobalFloatVariable* Other)
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

FString UGlobalFloatVariable::GetStringValue() const
{
    const auto& item = Value;
    return UKismetStringLibrary::Conv_FloatToString(item);
}
