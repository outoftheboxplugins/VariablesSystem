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
}

void UIntVariable::CopyIntValue(UIntVariable* var, UIntVariable* other)
{
	var->value = other->value;
}

void UIntVariable::Save()
{
	UGameplayStatics::SaveGameToSlot(this, VariableDescription.ToString(), 0);
}

void UIntVariable::Load()
{
	UIntVariable* LoadGameInstance = Cast<UIntVariable>(UGameplayStatics::CreateSaveGameObject(UIntVariable::StaticClass()));
	LoadGameInstance = Cast<UIntVariable>(UGameplayStatics::LoadGameFromSlot(VariableDescription.ToString(), 0));

	if (LoadGameInstance != nullptr)
	{
		this->value = LoadGameInstance->value;
	}
}

