// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#include "GlobalIntVariable.h"
#include "Kismet/GameplayStatics.h"

int32 UGlobalIntVariable::GetGlobalIntValue(UGlobalIntVariable* var)
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

int32 UGlobalIntVariable::GetGlobalInternalIntValue()
{
	return GetGlobalIntValue(this);
}

void UGlobalIntVariable::SetGlobalIntValue(UGlobalIntVariable* var, int32 _value)
{
	if (!var) return;

	var->value = _value;
	var->dirty = true;
}

void UGlobalIntVariable::SetGlobalInternalIntValue(int32 _value)
{
	SetGlobalIntValue(this, _value);
}

void UGlobalIntVariable::CopyGlobalIntValue(UGlobalIntVariable* var, UGlobalIntVariable* other)
{
	if (!var) return;

	var->value = other->value;
	var->dirty = true;
}

void UGlobalIntVariable::CopyGlobalInternalIntValue(UGlobalIntVariable* other)
{
	CopyGlobalIntValue(this, other);
}

void UGlobalIntVariable::Save()
{
	if (dirty == false)
	{
		return;
	}

	UGameplayStatics::SaveGameToSlot(this, GetSaveLocation(), 0);
	dirty = false;
}

void UGlobalIntVariable::Load()
{
	UGlobalIntVariable* LoadGameInstance = Cast<UGlobalIntVariable>(UGameplayStatics::CreateSaveGameObject(UGlobalIntVariable::StaticClass()));
	LoadGameInstance = Cast<UGlobalIntVariable>(UGameplayStatics::LoadGameFromSlot(GetSaveLocation(), 0));
	
	if (LoadGameInstance != nullptr)
	{
		this->value = LoadGameInstance->value;
	}
}


