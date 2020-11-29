// Copyright Out-of-the-Box Plugins 2018-2020. All Rights Reserved.

// GENERATED FILE DO NOT MODIFY DIRECTLY

#include "GlobalFRotatorVariable.h"

#include "VSLog.h"

#include "CoreMinimal.h"

#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetStringLibrary.h"

FRotator UGlobalFRotatorVariable::GetGlobalFRotatorVariableValue(const UGlobalFRotatorVariable* Variable)
{
	if (Variable)
	{
		return Variable->Value;
	}
	else
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Cannot get value without a variable. Returning default value."));
		return FRotator::ZeroRotator;
	}
}

void UGlobalFRotatorVariable::SetGlobalFRotatorVariableValue(UGlobalFRotatorVariable* Variable, FRotator NewValue)
{
	if (Variable && Variable->Value != NewValue)
	{
		Variable->Value = NewValue;
		Variable->Dirty = true;
	}
	else
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Cannot set value without a variable."));
	}
}

void UGlobalFRotatorVariable::CopyGlobalFRotatorVariableValue(UGlobalFRotatorVariable* Variable, UGlobalFRotatorVariable* Other)
{
	if (Variable && Other && Variable->Value != Other->Value)
	{
		Variable->Value = Other->Value;
		Variable->Dirty = true;
	}
	else if(!Variable)
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Cannot copy a value without a variable."));
	}
	else if(!Other)
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Cannot copy a value without an other variable."));
	}
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
		Value = LoadGameInstance->Value;
	}
}

FString UGlobalFRotatorVariable::GetStringValue() const
{
    const auto& item = Value;
    return UKismetStringLibrary::Conv_RotatorToString(item);
}
