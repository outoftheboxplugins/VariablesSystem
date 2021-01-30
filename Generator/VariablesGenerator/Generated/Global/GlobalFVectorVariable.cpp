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
		UE_LOG(LogVariablesSystem, Warning, TEXT("Variable - %s: Cannot get value without a variable. Returning default value."), *GetName());
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
		UE_LOG(LogVariablesSystem, Warning, TEXT("Variable - %s: Cannot set value without a variable."), *GetName());
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
		UE_LOG(LogVariablesSystem, Warning, TEXT("Variable - %s: Cannot copy a value without a variable."), *GetName());
	}
	else if(!OtherVariable)
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Variable - %s: Cannot copy a value without an other variable."), *GetName());
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
