// Copyright Out-of-the-Box Plugins 2018-2021. All Rights Reserved.

// GENERATED FILE DO NOT MODIFY DIRECTLY

#include "GlobalFRotatorVariable.h"

#include "VSLog.h"

#include "CoreMinimal.h"

#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetStringLibrary.h"

/* STATIC */ FRotator UGlobalFRotatorVariable::GetGlobalFRotatorVariableValue(const UGlobalFRotatorVariable* Variable)
{
	if (Variable)
	{
		return Variable->Value;
	}
	else
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Variable - %s: Cannot get value without a variable. Returning default value."), *GetName());
		return FRotator::ZeroRotator;
	}
}

/* STATIC */ void UGlobalFRotatorVariable::SetGlobalFRotatorVariableValue(UGlobalFRotatorVariable* Variable, FRotator NewValue)
{
	if (Variable && Variable->Value != NewValue)
	{
		Variable->Value = NewValue;
		Variable->Dirty = true;
	}
	else
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Variable - %s: Cannot set value without a variable."), *GetName());
	}
}

/* STATIC */ void UGlobalFRotatorVariable::CopyGlobalFRotatorVariableValue(UGlobalFRotatorVariable* Variable, UGlobalFRotatorVariable* OtherVariable)
{
	if (Variable && OtherVariable && Variable->Value != OtherVariable->Value)
	{
		Variable->Value = OtherVariable->Value;
		Variable->Dirty = true;
	}
	else if(!Variable)
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Variable - %s: Cannot copy a value without a variable."), *GetName());
	}
	else if(!OtherVariable)
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Variable - %s: Cannot copy a value without an other variable."), *GetName());
	}
}

FString UGlobalFRotatorVariable::GetStringValue() const
{
    const auto& Item = Value;
    return UKismetStringLibrary::Conv_RotatorToString(Item);
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
