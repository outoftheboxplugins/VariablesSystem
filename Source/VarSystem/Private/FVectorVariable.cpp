// Copyright Alexandru pasotee Oprea 2018. All Rights Reserved.

#include "FVectorVariable.h"
#include "Kismet/GameplayStatics.h"



FVector UFVectorVariable::GetFVectorValue(UFVectorVariable* var)
{
	return var->value;
}

void UFVectorVariable::SetFVectorValue(UFVectorVariable* var, FVector _value)
{
	var->value = _value;
	var->dirty = true;
}

void UFVectorVariable::CopyFVectorValue(UFVectorVariable* var, UFVectorVariable* other)
{
	var->value = other->value;
	var->dirty = true;
}

void UFVectorVariable::Save()
{
	if (dirty == false)
	{
		return;
	}

	UGameplayStatics::SaveGameToSlot(this, GetSaveLocation(), 0);
	dirty = false;
}

void UFVectorVariable::Load()
{
	UFVectorVariable* LoadGameInstance = Cast<UFVectorVariable>(UGameplayStatics::CreateSaveGameObject(UFVectorVariable::StaticClass()));
	LoadGameInstance = Cast<UFVectorVariable>(UGameplayStatics::LoadGameFromSlot(GetSaveLocation(), 0));

	if (LoadGameInstance != nullptr)
	{
		this->value = LoadGameInstance->value;
	}
}

