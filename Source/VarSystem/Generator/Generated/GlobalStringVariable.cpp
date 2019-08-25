// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#include "GlobalStringVariable.h"
#include "Kismet/GameplayStatics.h"

FString UGlobalStringVariable::GetGlobalStringValue(UGlobalStringVariable* var)
{
	if (var == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Missing variable"));
		return "";
	}
	else
	{
		return var->value;
	}
}

FString UGlobalStringVariable::GetGlobalInternalStringValue()
{
	return GetGlobalStringValue(this);
}

void UGlobalStringVariable::SetGlobalStringValue(UGlobalStringVariable* var, FString _value)
{
	if (!var) return;

	var->value = _value;
	var->dirty = true;
}

void UGlobalStringVariable::SetGlobalInternalStringValue(FString _value)
{
	SetGlobalStringValue(this, _value);
}

void UGlobalStringVariable::CopyGlobalStringValue(UGlobalStringVariable* var, UGlobalStringVariable* other)
{
	if (!var) return;

	var->value = other->value;
	var->dirty = true;
}

void UGlobalStringVariable::CopyGlobalInternalStringValue(UGlobalStringVariable* other)
{
	CopyGlobalStringValue(this, other);
}

void UGlobalStringVariable::Save()
{
	if (dirty == false)
	{
		return;
	}

	UGameplayStatics::SaveGameToSlot(this, GetSaveLocation(), 0);
	dirty = false;
}

void UGlobalStringVariable::Load()
{
	UGlobalStringVariable* LoadGameInstance = Cast<UGlobalStringVariable>(UGameplayStatics::CreateSaveGameObject(UGlobalStringVariable::StaticClass()));
	LoadGameInstance = Cast<UGlobalStringVariable>(UGameplayStatics::LoadGameFromSlot(GetSaveLocation(), 0));
	
	if (LoadGameInstance != nullptr)
	{
		this->value = LoadGameInstance->value;
	}
}


