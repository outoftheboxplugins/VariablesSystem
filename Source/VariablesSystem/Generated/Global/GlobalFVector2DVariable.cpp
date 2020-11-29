// Copyright Out-of-the-Box Plugins 2018-2020. All Rights Reserved.

// GENERATED FILE DO NOT MODIFY DIRECTLY

#include "GlobalFVector2DVariable.h"

#include "VSLog.h"

#include "CoreMinimal.h"

#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetStringLibrary.h"

FVector2D UGlobalFVector2DVariable::GetGlobalFVector2DVariableValue(const UGlobalFVector2DVariable* Variable)
{
	if (Variable)
	{
		return Variable->Value;
	}
	else
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Cannot get value without a variable. Returning default value."));
		return FVector2D::ZeroVector;
	}
}

void UGlobalFVector2DVariable::SetGlobalFVector2DVariableValue(UGlobalFVector2DVariable* Variable, FVector2D NewValue)
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

void UGlobalFVector2DVariable::CopyGlobalFVector2DVariableValue(UGlobalFVector2DVariable* Variable, UGlobalFVector2DVariable* Other)
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

void UGlobalFVector2DVariable::Save()
{
	if (Dirty == false)
	{
		return;
	}

	UGameplayStatics::SaveGameToSlot(this, GetSaveLocation(), 0);
	Dirty = false;
}

void UGlobalFVector2DVariable::Load()
{
	UGlobalFVector2DVariable* LoadGameInstance = Cast<UGlobalFVector2DVariable>(UGameplayStatics::CreateSaveGameObject(UGlobalFVector2DVariable::StaticClass()));
	LoadGameInstance = Cast<UGlobalFVector2DVariable>(UGameplayStatics::LoadGameFromSlot(GetSaveLocation(), 0));
	
	if (LoadGameInstance != nullptr)
	{
		Value = LoadGameInstance->Value;
	}
}

FString UGlobalFVector2DVariable::GetStringValue() const
{
    const auto& item = Value;
    return UKismetStringLibrary::Conv_Vector2dToString(item);
}
