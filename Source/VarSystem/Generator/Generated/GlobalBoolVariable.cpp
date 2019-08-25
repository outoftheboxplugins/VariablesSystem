// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#include "GlobalBoolVariable.h"
#include "Kismet/GameplayStatics.h"

bool UGlobalBoolVariable::GetGlobalBoolValue(UGlobalBoolVariable* var)
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

bool UGlobalBoolVariable::GetGlobalInternalBoolValue()
{
	return GetGlobalBoolValue(this);
}

void UGlobalBoolVariable::SetGlobalBoolValue(UGlobalBoolVariable* var, bool _value)
{
	if (!var) return;

	var->value = _value;
	var->dirty = true;
}

void UGlobalBoolVariable::SetGlobalInternalBoolValue(bool _value)
{
	SetGlobalBoolValue(this, _value);
}

void UGlobalBoolVariable::CopyGlobalBoolValue(UGlobalBoolVariable* var, UGlobalBoolVariable* other)
{
	if (!var) return;

	var->value = other->value;
	var->dirty = true;
}

void UGlobalBoolVariable::CopyGlobalInternalBoolValue(UGlobalBoolVariable* other)
{
	CopyGlobalBoolValue(this, other);
}

void UGlobalBoolVariable::Save()
{
	if (dirty == false)
	{
		return;
	}

	UGameplayStatics::SaveGameToSlot(this, GetSaveLocation(), 0);
	dirty = false;
}

void UGlobalBoolVariable::Load()
{
	UGlobalBoolVariable* LoadGameInstance = Cast<UGlobalBoolVariable>(UGameplayStatics::CreateSaveGameObject(UGlobalBoolVariable::StaticClass()));
	LoadGameInstance = Cast<UGlobalBoolVariable>(UGameplayStatics::LoadGameFromSlot(GetSaveLocation(), 0));
	
	if (LoadGameInstance != nullptr)
	{
		this->value = LoadGameInstance->value;
	}
}


