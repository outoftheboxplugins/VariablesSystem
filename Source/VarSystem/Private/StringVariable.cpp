// Copyright Alexandru pasotee Oprea 2018. All Rights Reserved.

#include "StringVariable.h"
#include "Kismet/GameplayStatics.h"



FString UStringVariable::GetStringValue(UStringVariable* var)
{
	return var->value;
}

void UStringVariable::SetStringValue(UStringVariable* var, FString _value)
{
	var->value = _value;
}

void UStringVariable::CopyStringValue(UStringVariable* var, UStringVariable* other)
{
	var->value = other->value;
}

void UStringVariable::Save()
{
	UGameplayStatics::SaveGameToSlot(this, SaveName.ToString(), 0);
}

void UStringVariable::Load()
{
	UStringVariable* LoadGameInstance = Cast<UStringVariable>(UGameplayStatics::CreateSaveGameObject(UStringVariable::StaticClass()));
	LoadGameInstance = Cast<UStringVariable>(UGameplayStatics::LoadGameFromSlot(SaveName.ToString(), 0));
	
	if (LoadGameInstance != nullptr)
	{
		this->value = LoadGameInstance->value;
	}
}

