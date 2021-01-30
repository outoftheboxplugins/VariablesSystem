// Copyright Out-of-the-Box Plugins 2018-2021. All Rights Reserved.

// GENERATED FILE DO NOT MODIFY DIRECTLY

#include "GlobalFVectorVariable.h"

#include "VSLog.h"

#include "CoreMinimal.h"

#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetStringLibrary.h"

/* STATIC */ FVector UGlobalFVectorVariable::GetGlobalFVectorVariableValue(const UGlobalFVectorVariable* Variable)
{
	if (Variable)
	{
		return Variable->Value;
	}
	else
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Cannot get value without a variable. Returning default value."));
		return FVector::ZeroVector;
	}
}

/* STATIC */ void UGlobalFVectorVariable::SetGlobalFVectorVariableValue(UGlobalFVectorVariable* Variable, FVector NewValue)
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

/* STATIC */ void UGlobalFVectorVariable::CopyGlobalFVectorVariableValue(UGlobalFVectorVariable* Variable, UGlobalFVectorVariable* OtherVariable)
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

FString UGlobalFVectorVariable::GetStringValue() const
{
    const auto& Item = Value;
    return UKismetStringLibrary::Conv_VectorToString(Item);
}

void UGlobalFVectorVariable::Save()
{
	if (Dirty == false)
	{
		return;
	}

	UGameplayStatics::SaveGameToSlot(this, GetSaveLocation(), 0);
	Dirty = false;
}

void UGlobalFVectorVariable::Load()
{
	UGlobalFVectorVariable* LoadGameInstance = Cast<UGlobalFVectorVariable>(UGameplayStatics::CreateSaveGameObject(UGlobalFVectorVariable::StaticClass()));
	LoadGameInstance = Cast<UGlobalFVectorVariable>(UGameplayStatics::LoadGameFromSlot(GetSaveLocation(), 0));
	
	if (LoadGameInstance != nullptr)
	{
		Value = LoadGameInstance->Value;
	}
}
