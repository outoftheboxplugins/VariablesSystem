// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#include "GlobalFVectorVariable.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetStringLibrary.h"
#include "CoreMinimal.h"

FVector UGlobalFVectorVariable::GetGlobalFVectorValue(UGlobalFVectorVariable* var)
{
	if (var == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Missing variable"));
		return FVector::ZeroVector;
	}
	else
	{
		return var->value;
	}
}

FVector UGlobalFVectorVariable::GetGlobalInternalFVectorValue()
{
	return GetGlobalFVectorValue(this);
}

void UGlobalFVectorVariable::SetGlobalFVectorValue(UGlobalFVectorVariable* var, FVector _value)
{
	if (!var) return;

	var->value = _value;
	var->dirty = true;
}

void UGlobalFVectorVariable::SetGlobalInternalFVectorValue(FVector _value)
{
	SetGlobalFVectorValue(this, _value);
}

void UGlobalFVectorVariable::CopyGlobalFVectorValue(UGlobalFVectorVariable* var, UGlobalFVectorVariable* other)
{
	if (!var) return;

	var->value = other->value;
	var->dirty = true;
}

void UGlobalFVectorVariable::CopyGlobalInternalFVectorValue(UGlobalFVectorVariable* other)
{
	CopyGlobalFVectorValue(this, other);
}

void UGlobalFVectorVariable::Save()
{
	if (dirty == false)
	{
		return;
	}

	UGameplayStatics::SaveGameToSlot(this, GetSaveLocation(), 0);
	dirty = false;
}

void UGlobalFVectorVariable::Load()
{
	UGlobalFVectorVariable* LoadGameInstance = Cast<UGlobalFVectorVariable>(UGameplayStatics::CreateSaveGameObject(UGlobalFVectorVariable::StaticClass()));
	LoadGameInstance = Cast<UGlobalFVectorVariable>(UGameplayStatics::LoadGameFromSlot(GetSaveLocation(), 0));
	
	if (LoadGameInstance != nullptr)
	{
		this->value = LoadGameInstance->value;
	}
}


FString UGlobalFVectorVariable::GetStringValue() const
{
	return UKismetStringLibrary::Conv_VectorToString(value);
}

