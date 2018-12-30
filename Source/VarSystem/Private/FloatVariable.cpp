// Copyright Alexandru pasotee Oprea 2018. All Rights Reserved.

#include "FloatVariable.h"
#include "Kismet/GameplayStatics.h"



float UFloatVariable::GetFloatValue(UFloatVariable* var)
{
	return var->value;
}

void UFloatVariable::SetFloatValue(UFloatVariable* var, float _value)
{
	var->value = _value;
	var->dirty = true;
}

void UFloatVariable::CopyFloatValue(UFloatVariable* var, UFloatVariable* other)
{
	var->value = other->value;
	var->dirty = true;
}

void UFloatVariable::Save()
{
	UGameplayStatics::SaveGameToSlot(this, GetSaveLocation(), 0);
	dirty = false;
}

void UFloatVariable::Load()
{
	if (dirty == false)
	{
		return;
	}

	UFloatVariable* LoadGameInstance = Cast<UFloatVariable>(UGameplayStatics::CreateSaveGameObject(UFloatVariable::StaticClass()));
	LoadGameInstance = Cast<UFloatVariable>(UGameplayStatics::LoadGameFromSlot(GetSaveLocation(), 0));

	if (LoadGameInstance != nullptr)
	{
		this->value = LoadGameInstance->value;
	}
}

