// Copyright Out-of-the-Box Plugins 2018-2020. All Rights Reserved.

#include "GlobalFVector2DVariable.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetStringLibrary.h"
#include "CoreMinimal.h"

FVector2D UGlobalFVector2DVariable::GetGlobalFVector2DVariableValue(UGlobalFVector2DVariable* var)
{
	if (var == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Missing variable"));
		return FVector2D::ZeroVector;
	}
	else
	{
		return var->value;
	}
}

FVector2D UGlobalFVector2DVariable::GetGlobalInternalFVector2DVariableValue()
{
	return GetGlobalFVector2DVariableValue(this);
}

void UGlobalFVector2DVariable::SetGlobalFVector2DVariableValue(UGlobalFVector2DVariable* var, FVector2D _value)
{
	if (!var) return;

	var->value = _value;
	var->Dirty = true;
}

void UGlobalFVector2DVariable::SetGlobalInternalFVector2DVariableValue(FVector2D _value)
{
	SetGlobalFVector2DVariableValue(this, _value);
}

void UGlobalFVector2DVariable::CopyGlobalFVector2DVariableValue(UGlobalFVector2DVariable* var, UGlobalFVector2DVariable* other)
{
	if (!var) return;

	var->value = other->value;
	var->Dirty = true;
}

void UGlobalFVector2DVariable::CopyGlobalInternalFVector2DVariableValue(UGlobalFVector2DVariable* other)
{
	CopyGlobalFVector2DVariableValue(this, other);
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
		this->value = LoadGameInstance->value;
	}
}


FString UGlobalFVector2DVariable::GetStringValue() const
{
    const auto& item = value;
    return UKismetStringLibrary::Conv_Vector2dToString(item);
}

