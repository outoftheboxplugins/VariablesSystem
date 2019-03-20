// Copyright Alexandru pasotee Oprea 2018. All Rights Reserved.

#include "FloatVariable.h"
#include "Kismet/GameplayStatics.h"



float UFloatVariable::GetFloatValue(UFloatVariable* var)
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

float UFloatVariable::GetFloatValue()
{
	return GetFloatValue(this);
}

void UFloatVariable::SetFloatValue(UFloatVariable* var, float _value)
{
	if (!var) return;

	var->value = _value;
	var->dirty = true;
}

void UFloatVariable::SetFloatValue(float _value)
{
	SetFloatValue(this, _value);
}

void UFloatVariable::CopyFloatValue(UFloatVariable* var, UFloatVariable* other)
{
	if (!var) return;

	var->value = other->value;
	var->dirty = true;
}

void UFloatVariable::CopyFloatValue(UFloatVariable* other)
{
	CopyFloatValue(this, other);
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

