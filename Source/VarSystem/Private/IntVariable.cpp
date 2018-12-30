// Copyright Alexandru pasotee Oprea 2018. All Rights Reserved.

#include "IntVariable.h"
#include "Kismet/GameplayStatics.h"



int32 UIntVariable::GetIntValue(UIntVariable* var)
{
	return var->value;
}

void UIntVariable::SetIntValue(UIntVariable* var, int32 _value)
{
	var->value = _value;
	var->dirty = true;
}

void UIntVariable::CopyIntValue(UIntVariable* var, UIntVariable* other)
{
	var->value = other->value;
	var->dirty = true;
}

void UIntVariable::Save()
{
	if (dirty == false)
	{
		return;
	}

	UGameplayStatics::SaveGameToSlot(this, GetSaveLocation(), 0);
	dirty = false;
}

void UIntVariable::Load()
{
	UIntVariable* LoadGameInstance = Cast<UIntVariable>(UGameplayStatics::CreateSaveGameObject(UIntVariable::StaticClass()));
	LoadGameInstance = Cast<UIntVariable>(UGameplayStatics::LoadGameFromSlot(GetSaveLocation(), 0));

	if (LoadGameInstance != nullptr)
	{
		this->value = LoadGameInstance->value;
	}
}

