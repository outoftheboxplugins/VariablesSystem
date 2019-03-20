// Copyright Alexandru pasotee Oprea 2018. All Rights Reserved.

#include "IntVariable.h"
#include "Kismet/GameplayStatics.h"



int32 UIntVariable::GetIntValue(UIntVariable* var)
{
	if (var == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Missing variable"));
		return 0;
	}
	else
	{
		return var->value;
	}
}

int32 UIntVariable::GetIntValue()
{
	return GetIntValue(this);
}

void UIntVariable::SetIntValue(UIntVariable* var, int32 _value)
{
	if (!var) return;

	var->value = _value;
	var->dirty = true;
}

void UIntVariable::SetIntValue(int32 _value)
{
	SetIntValue(this, _value);
}

void UIntVariable::CopyIntValue(UIntVariable* var, UIntVariable* other)
{
	if (!var) return;

	var->value = other->value;
	var->dirty = true;
}

void UIntVariable::CopyIntValue(UIntVariable* other)
{
	CopyIntValue(this, other);
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

