// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#include "GlobalFVector2DVariable.h"
#include "Kismet/GameplayStatics.h"

FVector2D UGlobalFVector2DVariable::GetGlobalFVector2DValue(UGlobalFVector2DVariable* var)
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

FVector2D UGlobalFVector2DVariable::GetGlobalInternalFVector2DValue()
{
	return GetGlobalFVector2DValue(this);
}

void UGlobalFVector2DVariable::SetGlobalFVector2DValue(UGlobalFVector2DVariable* var, FVector2D _value)
{
	if (!var) return;

	var->value = _value;
	var->dirty = true;
}

void UGlobalFVector2DVariable::SetGlobalInternalFVector2DValue(FVector2D _value)
{
	SetGlobalFVector2DValue(this, _value);
}

void UGlobalFVector2DVariable::CopyGlobalFVector2DValue(UGlobalFVector2DVariable* var, UGlobalFVector2DVariable* other)
{
	if (!var) return;

	var->value = other->value;
	var->dirty = true;
}

void UGlobalFVector2DVariable::CopyGlobalInternalFVector2DValue(UGlobalFVector2DVariable* other)
{
	CopyGlobalFVector2DValue(this, other);
}

void UGlobalFVector2DVariable::Save()
{
	if (dirty == false)
	{
		return;
	}

	UGameplayStatics::SaveGameToSlot(this, GetSaveLocation(), 0);
	dirty = false;
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


