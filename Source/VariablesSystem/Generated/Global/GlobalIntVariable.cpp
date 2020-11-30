// Copyright Out-of-the-Box Plugins 2018-2020. All Rights Reserved.

// GENERATED FILE DO NOT MODIFY DIRECTLY

#include "GlobalIntVariable.h"

#include "VSLog.h"

#include "CoreMinimal.h"

#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetStringLibrary.h"

/* STATIC */ int32 UGlobalIntVariable::GetGlobalIntVariableValue(const UGlobalIntVariable* Variable)
{
	if (Variable)
	{
		return Variable->Value;
	}
	else
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Cannot get value without a variable. Returning default value."));
		return 0;
	}
}

/* STATIC */ void UGlobalIntVariable::SetGlobalIntVariableValue(UGlobalIntVariable* Variable, int32 NewValue)
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

/* STATIC */ void UGlobalIntVariable::CopyGlobalIntVariableValue(UGlobalIntVariable* Variable, UGlobalIntVariable* OtherVariable)
{
	if (Variable && OtherVariable && Variable->Value != OtherVariable->Value)
	{
		Variable->Value = OtherVariable->Value;
		Variable->Dirty = true;
	}
	else if(!Variable)
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Cannot copy a value without a variable."));
	}
	else if(!OtherVariable)
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Cannot copy a value without an other variable."));
	}
}

FString UGlobalIntVariable::GetStringValue() const
{
    const auto& Item = Value;
    return UKismetStringLibrary::Conv_IntToString(Item);
}

void UGlobalIntVariable::Save()
{
	if (Dirty == false)
	{
		return;
	}

	UGameplayStatics::SaveGameToSlot(this, GetSaveLocation(), 0);
	Dirty = false;
}

void UGlobalIntVariable::Load()
{
	UGlobalIntVariable* LoadGameInstance = Cast<UGlobalIntVariable>(UGameplayStatics::CreateSaveGameObject(UGlobalIntVariable::StaticClass()));
	LoadGameInstance = Cast<UGlobalIntVariable>(UGameplayStatics::LoadGameFromSlot(GetSaveLocation(), 0));
	
	if (LoadGameInstance != nullptr)
	{
		Value = LoadGameInstance->Value;
	}
}
