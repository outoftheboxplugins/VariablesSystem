// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#include "StringVariable.h"
#include "Kismet/GameplayStatics.h"

FString UStringVariable::GetStringValue(UStringVariable* var)
{
	if (var == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Missing variable"));
		return FString("");
	}
	else
	{
		return var->value;
	}
}

FString UStringVariable::GetStringValue()
{
	return GetStringValue(this);
}

void UStringVariable::SetStringValue(UStringVariable* var, FString _value)
{
	if (!var) return;
	
	var->value = _value;
	var->dirty = true;
}

void UStringVariable::SetStringValue(FString _value)
{
	SetStringValue(this, _value);
}

void UStringVariable::CopyStringValue(UStringVariable* var, UStringVariable* other)
{
	if (!var) return;

	var->value = other->value;
	var->dirty = true;
}

void UStringVariable::CopyStringValue(UStringVariable* other)
{
	CopyStringValue(this, other);
}

void UStringVariable::Save()
{
	if (dirty == false)
	{
		return;
	}

	UGameplayStatics::SaveGameToSlot(this, GetSaveLocation(), 0);
	dirty = false;
}

void UStringVariable::Load()
{
	UStringVariable* LoadGameInstance = Cast<UStringVariable>(UGameplayStatics::CreateSaveGameObject(UStringVariable::StaticClass()));
	LoadGameInstance = Cast<UStringVariable>(UGameplayStatics::LoadGameFromSlot(GetSaveLocation(), 0));
	
	if (LoadGameInstance != nullptr)
	{
		this->value = LoadGameInstance->value;
	}
}

