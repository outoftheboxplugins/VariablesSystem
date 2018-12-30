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
}

void UFloatVariable::CopyFloatValue(UFloatVariable* var, UFloatVariable* other)
{
	var->value = other->value;
}

void UFloatVariable::Save()
{
	UGameplayStatics::SaveGameToSlot(this, VariableDescription.ToString(), 0);
}

void UFloatVariable::Load()
{
	UFloatVariable* LoadGameInstance = Cast<UFloatVariable>(UGameplayStatics::CreateSaveGameObject(UFloatVariable::StaticClass()));
	LoadGameInstance = Cast<UFloatVariable>(UGameplayStatics::LoadGameFromSlot(VariableDescription.ToString(), 0));

	if (LoadGameInstance != nullptr)
	{
		this->value = LoadGameInstance->value;
	}
}

