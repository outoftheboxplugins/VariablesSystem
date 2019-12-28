// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

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
	var->dirty = true;
}

void UGlobalFloatVariable::SetGlobalInternalFloatVariableValue(float _value)
{
	SetGlobalFloatVariableValue(this, _value);
}

void UGlobalFloatVariable::CopyGlobalFloatVariableValue(UGlobalFloatVariable* var, UGlobalFloatVariable* other)
{
	if (!var) return;

	var->value = other->value;
	var->dirty = true;
}

void UGlobalFloatVariable::CopyGlobalInternalFloatVariableValue(UGlobalFloatVariable* other)
{
	CopyGlobalFloatVariableValue(this, other);
}

void UGlobalFloatVariable::Save()
{
	if (dirty == false)
	{
		return;
	}

	UGameplayStatics::SaveGameToSlot(this, GetSaveLocation(), 0);
	dirty = false;
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
	return UKismetStringLibrary::Conv_FloatToString(value);
}

