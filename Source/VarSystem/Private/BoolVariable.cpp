// Copyright Alexandru pasotee Oprea 2018. All Rights Reserved.

#include "BoolVariable.h"
#include "Kismet/GameplayStatics.h"
#include "UObjectBaseUtility.h"



bool UBoolVariable::GetBoolValue(UBoolVariable* var)
{
	return var->value;
}

void UBoolVariable::SetBoolValue(UBoolVariable* var, bool _value)
{
	var->value = _value;
}

void UBoolVariable::CopyBoolValue(UBoolVariable* var, UBoolVariable* other)
{
	var->value = other->value;
}

void UBoolVariable::Save()
{
	UGameplayStatics::SaveGameToSlot(this, VariableDescription.ToString(), 0);
}

void UBoolVariable::Load()
{
	FString SaveDestination;
	UObjectBaseUtility::GetName(SaveDestination);
	UBoolVariable* LoadGameInstance = Cast<UBoolVariable>(UGameplayStatics::CreateSaveGameObject(UBoolVariable::StaticClass()));
	LoadGameInstance = Cast<UBoolVariable>(UGameplayStatics::LoadGameFromSlot(SaveDestination, 0));
	
	if (LoadGameInstance != nullptr)
	{
		this->value = LoadGameInstance->value;
	}
}

