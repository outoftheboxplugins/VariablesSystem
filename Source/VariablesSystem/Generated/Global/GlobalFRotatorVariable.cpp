// Copyright Out-of-the-Box Plugins 2018-2020. All Rights Reserved.

#include "GlobalFRotatorVariable.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetStringLibrary.h"
#include "CoreMinimal.h"

FRotator UGlobalFRotatorVariable::GetGlobalFRotatorVariableValue(UGlobalFRotatorVariable* var)
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

FRotator UGlobalFRotatorVariable::GetGlobalInternalFRotatorVariableValue()
{
	return GetGlobalFRotatorVariableValue(this);
}

void UGlobalFRotatorVariable::SetGlobalFRotatorVariableValue(UGlobalFRotatorVariable* var, FRotator _value)
{
	if (!var) return;

	var->value = _value;
	var->Dirty = true;
}

void UGlobalFRotatorVariable::SetGlobalInternalFRotatorVariableValue(FRotator _value)
{
	SetGlobalFRotatorVariableValue(this, _value);
}

void UGlobalFRotatorVariable::CopyGlobalFRotatorVariableValue(UGlobalFRotatorVariable* var, UGlobalFRotatorVariable* other)
{
	if (!var) return;

	var->value = other->value;
	var->Dirty = true;
}

void UGlobalFRotatorVariable::CopyGlobalInternalFRotatorVariableValue(UGlobalFRotatorVariable* other)
{
	CopyGlobalFRotatorVariableValue(this, other);
}

void UGlobalFRotatorVariable::Save()
{
	if (Dirty == false)
	{
		return;
	}

	UGameplayStatics::SaveGameToSlot(this, GetSaveLocation(), 0);
	Dirty = false;
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


FString UGlobalFRotatorVariable::GetStringValue() const
{
    const auto& item = value;
    return UKismetStringLibrary::Conv_RotatorToString(item);
}

