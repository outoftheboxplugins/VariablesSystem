// Copyright Alexandru pasotee Oprea 2018. All Rights Reserved.

#include "FRotatorVariable.h"
#include "Kismet/GameplayStatics.h"



FRotator UFRotatorVariable::GetFRotatorValue(UFRotatorVariable* var)
{
	return var->value;
}

void UFRotatorVariable::SetFRotatorValue(UFRotatorVariable* var, FRotator _value)
{
	var->value = _value;
	var->dirty = true;
}

void UFRotatorVariable::CopyFRotatorValue(UFRotatorVariable* var, UFRotatorVariable* other)
{
	var->value = other->value;
	var->dirty = true;
}

void UFRotatorVariable::Save()
{
	if (dirty == false)
	{
		return;
	}

	UGameplayStatics::SaveGameToSlot(this, GetSaveLocation(), 0);
	dirty = false;
}

void UFRotatorVariable::Load()
{
	UFRotatorVariable* LoadGameInstance = Cast<UFRotatorVariable>(UGameplayStatics::CreateSaveGameObject(UFRotatorVariable::StaticClass()));
	LoadGameInstance = Cast<UFRotatorVariable>(UGameplayStatics::LoadGameFromSlot(GetSaveLocation(), 0));

	if (LoadGameInstance != nullptr)
	{
		this->value = LoadGameInstance->value;
	}
}

