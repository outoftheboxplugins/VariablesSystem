// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#include "GlobalIntVariable.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetStringLibrary.h"
#include "CoreMinimal.h"

int32 UGlobalIntVariable::GetGlobalIntVariableValue(UGlobalIntVariable* var)
{
	if (var == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Missing variable"));
		return 0;
	}
	else
	{
		return var->value;
	}
}

int32 UGlobalIntVariable::GetGlobalInternalIntVariableValue()
{
	return GetGlobalIntVariableValue(this);
}

void UGlobalIntVariable::SetGlobalIntVariableValue(UGlobalIntVariable* var, int32 _value)
{
	if (!var) return;

	var->value = _value;
	var->dirty = true;
}

void UGlobalIntVariable::SetGlobalInternalIntVariableValue(int32 _value)
{
	SetGlobalIntVariableValue(this, _value);
}

void UGlobalIntVariable::CopyGlobalIntVariableValue(UGlobalIntVariable* var, UGlobalIntVariable* other)
{
	if (!var) return;

	var->value = other->value;
	var->dirty = true;
}

void UGlobalIntVariable::CopyGlobalInternalIntVariableValue(UGlobalIntVariable* other)
{
	CopyGlobalIntVariableValue(this, other);
}

void UGlobalIntVariable::Save()
{
	if (dirty == false)
	{
		return;
	}

	UGameplayStatics::SaveGameToSlot(this, GetSaveLocation(), 0);
	dirty = false;
}

void UGlobalIntVariable::Load()
{
	UGlobalIntVariable* LoadGameInstance = Cast<UGlobalIntVariable>(UGameplayStatics::CreateSaveGameObject(UGlobalIntVariable::StaticClass()));
	LoadGameInstance = Cast<UGlobalIntVariable>(UGameplayStatics::LoadGameFromSlot(GetSaveLocation(), 0));
	
	if (LoadGameInstance != nullptr)
	{
		this->value = LoadGameInstance->value;
	}
}


FString UGlobalIntVariable::GetStringValue() const
{
	return UKismetStringLibrary::Conv_IntToString(value);
}

