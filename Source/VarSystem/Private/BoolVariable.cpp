// Copyright Alexandru pasotee Oprea 2018. All Rights Reserved.

#include "BoolVariable.h"
#include "Kismet/GameplayStatics.h"



bool UBoolVariable::GetBoolValue(UBoolVariable* var)
{
	if (var == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Missing variable"));
		return false;
	}
	else
	{
		return var->value;
	}
}

bool UBoolVariable::GetBoolValue()
{
	return GetBoolValue(this);
}

void UBoolVariable::SetBoolValue(UBoolVariable* var, bool _value)
{
	if (!var) return;

	var->value = _value;
	var->dirty = true;
}

void UBoolVariable::SetBoolValue(bool _value)
{
	SetBoolValue(this, _value);
}

void UBoolVariable::CopyBoolValue(UBoolVariable* var, UBoolVariable* other)
{
	if (!var) return;

	var->value = other->value;
	var->dirty = true;
}

void UBoolVariable::CopyBoolValue(UBoolVariable* other)
{
	CopyBoolValue(this, other);
}

void UBoolVariable::Save()
{
	if (dirty == false)
	{
		return;
	}

	UGameplayStatics::SaveGameToSlot(this, GetSaveLocation(), 0);
	dirty = false;
}

void UBoolVariable::Load()
{
	UBoolVariable* LoadGameInstance = Cast<UBoolVariable>(UGameplayStatics::CreateSaveGameObject(UBoolVariable::StaticClass()));
	LoadGameInstance = Cast<UBoolVariable>(UGameplayStatics::LoadGameFromSlot(GetSaveLocation(), 0));
	
	if (LoadGameInstance != nullptr)
	{
		this->value = LoadGameInstance->value;
	}
}

