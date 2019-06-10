// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#include "GlobalFloatVariable.h"
#include "Kismet/GameplayStatics.h"

float UGlobalFloatVariable::GetGlobalFloatValue(UGlobalFloatVariable* var)
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

float UGlobalFloatVariable::GetGlobalFloatValue()
{
	return GetGlobalFloatValue(this);
}

void UGlobalFloatVariable::SetGlobalFloatValue(UGlobalFloatVariable* var, float _value)
{
	if (!var) return;

	var->value = _value;
	var->dirty = true;
}

void UGlobalFloatVariable::SetGlobalFloatValue(float _value)
{
	SetGlobalFloatValue(this, _value);
}

void UGlobalFloatVariable::CopyGlobalFloatValue(UGlobalFloatVariable* var, UGlobalFloatVariable* other)
{
	if (!var) return;

	var->value = other->value;
	var->dirty = true;
}

void UGlobalFloatVariable::CopyGlobalFloatValue(UGlobalFloatVariable* other)
{
	CopyGlobalFloatValue(this, other);
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


