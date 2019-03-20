// Copyright Alexandru pasotee Oprea 2018. All Rights Reserved.

#include "FRotatorVariable.h"
#include "Kismet/GameplayStatics.h"



FRotator UFRotatorVariable::GetFRotatorValue(UFRotatorVariable* var)
{
	if (var == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Missing variable"));
		return FRotator::ZeroRotator;
	}
	else
	{
		return var->value;
	}
}

FRotator UFRotatorVariable::GetFRotatorValue()
{
	return GetFRotatorValue(this);
}

void UFRotatorVariable::SetFRotatorValue(UFRotatorVariable* var, FRotator _value)
{
	if (!var) return;

	var->value = _value;
	var->dirty = true;
}

void UFRotatorVariable::SetFRotatorValue(FRotator _value)
{
	SetFRotatorValue(this, _value);
}

void UFRotatorVariable::CopyFRotatorValue(UFRotatorVariable* var, UFRotatorVariable* other)
{
	if (!var) return;

	var->value = other->value;
	var->dirty = true;
}

void UFRotatorVariable::CopyFRotatorValue(UFRotatorVariable* other)
{
	CopyFRotatorValue(this, other);
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

