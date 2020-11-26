// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#include "GlobalStringVariable.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetStringLibrary.h"
#include "CoreMinimal.h"

FString UGlobalStringVariable::GetGlobalStringVariableValue(UGlobalStringVariable* var)
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

FString UGlobalStringVariable::GetGlobalInternalStringVariableValue()
{
	return GetGlobalStringVariableValue(this);
}

void UGlobalStringVariable::SetGlobalStringVariableValue(UGlobalStringVariable* var, FString _value)
{
	if (!var) return;

	var->value = _value;
	var->dirty = true;
}

void UGlobalStringVariable::SetGlobalInternalStringVariableValue(FString _value)
{
	SetGlobalStringVariableValue(this, _value);
}

void UGlobalStringVariable::CopyGlobalStringVariableValue(UGlobalStringVariable* var, UGlobalStringVariable* other)
{
	if (!var) return;

	var->value = other->value;
	var->dirty = true;
}

void UGlobalStringVariable::CopyGlobalInternalStringVariableValue(UGlobalStringVariable* other)
{
	CopyGlobalStringVariableValue(this, other);
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


FString UGlobalStringVariable::GetStringValue() const
{
    const auto& item = value;
    return item;
}

