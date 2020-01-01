// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#include "GlobalBoolVariable.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetStringLibrary.h"
#include "CoreMinimal.h"

bool UGlobalBoolVariable::GetGlobalBoolVariableValue(UGlobalBoolVariable* var)
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

bool UGlobalBoolVariable::GetGlobalInternalBoolVariableValue()
{
	return GetGlobalBoolVariableValue(this);
}

void UGlobalBoolVariable::SetGlobalBoolVariableValue(UGlobalBoolVariable* var, bool _value)
{
	if (!var) return;

	var->value = _value;
	var->dirty = true;
}

void UGlobalBoolVariable::SetGlobalInternalBoolVariableValue(bool _value)
{
	SetGlobalBoolVariableValue(this, _value);
}

void UGlobalBoolVariable::CopyGlobalBoolVariableValue(UGlobalBoolVariable* var, UGlobalBoolVariable* other)
{
	if (!var) return;

	var->value = other->value;
	var->dirty = true;
}

void UGlobalBoolVariable::CopyGlobalInternalBoolVariableValue(UGlobalBoolVariable* other)
{
	CopyGlobalBoolVariableValue(this, other);
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


FString UGlobalBoolVariable::GetStringValue() const
{
    const auto& item = value;
    return UKismetStringLibrary::Conv_BoolToString(item);
}

