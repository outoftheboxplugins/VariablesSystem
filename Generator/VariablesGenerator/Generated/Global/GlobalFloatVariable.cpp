// Copyright Out-of-the-Box Plugins 2018-2020. All Rights Reserved.

#include "GlobalFloatVariable.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetStringLibrary.h"
#include "CoreMinimal.h"

float UGlobalFloatVariable::GetGlobalFloatVariableValue(UGlobalFloatVariable* var)
{
	if (var == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Missing variable"));
		return 0.0f;
	}
	else
	{
		return var->value;
	}
}

float UGlobalFloatVariable::GetGlobalInternalFloatVariableValue()
{
	return GetGlobalFloatVariableValue(this);
}

void UGlobalFloatVariable::SetGlobalFloatVariableValue(UGlobalFloatVariable* var, float _value)
{
	if (!var) return;

	var->value = _value;
	var->Dirty = true;
}

void UGlobalFloatVariable::SetGlobalInternalFloatVariableValue(float _value)
{
	SetGlobalFloatVariableValue(this, _value);
}

void UGlobalFloatVariable::CopyGlobalFloatVariableValue(UGlobalFloatVariable* var, UGlobalFloatVariable* other)
{
	if (!var) return;

	var->value = other->value;
	var->Dirty = true;
}

void UGlobalFloatVariable::CopyGlobalInternalFloatVariableValue(UGlobalFloatVariable* other)
{
	CopyGlobalFloatVariableValue(this, other);
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
		this->value = LoadGameInstance->value;
	}
}


FString UGlobalFloatVariable::GetStringValue() const
{
    const auto& item = value;
    return UKismetStringLibrary::Conv_FloatToString(item);
}

