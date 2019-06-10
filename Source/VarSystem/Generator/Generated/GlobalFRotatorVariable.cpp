// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#include "GlobalFRotatorVariable.h"
#include "Kismet/GameplayStatics.h"

FRotator UGlobalFRotatorVariable::GetGlobalFRotatorValue(UGlobalFRotatorVariable* var)
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

FRotator UGlobalFRotatorVariable::GetGlobalFRotatorValue()
{
	return GetGlobalFRotatorValue(this);
}

void UGlobalFRotatorVariable::SetGlobalFRotatorValue(UGlobalFRotatorVariable* var, FRotator _value)
{
	if (!var) return;

	var->value = _value;
	var->dirty = true;
}

void UGlobalFRotatorVariable::SetGlobalFRotatorValue(FRotator _value)
{
	SetGlobalFRotatorValue(this, _value);
}

void UGlobalFRotatorVariable::CopyGlobalFRotatorValue(UGlobalFRotatorVariable* var, UGlobalFRotatorVariable* other)
{
	if (!var) return;

	var->value = other->value;
	var->dirty = true;
}

void UGlobalFRotatorVariable::CopyGlobalFRotatorValue(UGlobalFRotatorVariable* other)
{
	CopyGlobalFRotatorValue(this, other);
}

void UGlobalFRotatorVariable::Save()
{
	if (dirty == false)
	{
		return;
	}

	UGameplayStatics::SaveGameToSlot(this, GetSaveLocation(), 0);
	dirty = false;
}

void UGlobalFRotatorVariable::Load()
{
	UGlobalFRotatorVariable* LoadGameInstance = Cast<UGlobalFRotatorVariable>(UGameplayStatics::CreateSaveGameObject(UGlobalFRotatorVariable::StaticClass()));
	LoadGameInstance = Cast<UGlobalFRotatorVariable>(UGameplayStatics::LoadGameFromSlot(GetSaveLocation(), 0));
	
	if (LoadGameInstance != nullptr)
	{
		this->value = LoadGameInstance->value;
	}
}


