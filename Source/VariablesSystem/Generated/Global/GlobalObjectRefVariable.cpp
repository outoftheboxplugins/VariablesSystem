// Copyright Out-of-the-Box Plugins 2018-2020. All Rights Reserved.

#include "GlobalObjectRefVariable.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetStringLibrary.h"
#include "CoreMinimal.h"

UObject* UGlobalObjectRefVariable::GetGlobalObjectRefVariableValue(UGlobalObjectRefVariable* var)
{
	if (var == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Missing variable"));
		return nullptr;
	}
	else
	{
		return var->value;
	}
}

UObject* UGlobalObjectRefVariable::GetGlobalInternalObjectRefVariableValue()
{
	return GetGlobalObjectRefVariableValue(this);
}

void UGlobalObjectRefVariable::SetGlobalObjectRefVariableValue(UGlobalObjectRefVariable* var, UObject* _value)
{
	if (!var) return;

	var->value = _value;
	var->Dirty = true;
}

void UGlobalObjectRefVariable::SetGlobalInternalObjectRefVariableValue(UObject* _value)
{
	SetGlobalObjectRefVariableValue(this, _value);
}

void UGlobalObjectRefVariable::CopyGlobalObjectRefVariableValue(UGlobalObjectRefVariable* var, UGlobalObjectRefVariable* other)
{
	if (!var) return;

	var->value = other->value;
	var->Dirty = true;
}

void UGlobalObjectRefVariable::CopyGlobalInternalObjectRefVariableValue(UGlobalObjectRefVariable* other)
{
	CopyGlobalObjectRefVariableValue(this, other);
}

void UGlobalObjectRefVariable::Save()
{
	if (Dirty == false)
	{
		return;
	}

	UGameplayStatics::SaveGameToSlot(this, GetSaveLocation(), 0);
	Dirty = false;
}

void UGlobalObjectRefVariable::Load()
{
	UGlobalObjectRefVariable* LoadGameInstance = Cast<UGlobalObjectRefVariable>(UGameplayStatics::CreateSaveGameObject(UGlobalObjectRefVariable::StaticClass()));
	LoadGameInstance = Cast<UGlobalObjectRefVariable>(UGameplayStatics::LoadGameFromSlot(GetSaveLocation(), 0));
	
	if (LoadGameInstance != nullptr)
	{
		this->value = LoadGameInstance->value;
	}
}


FString UGlobalObjectRefVariable::GetStringValue() const
{
    const auto& item = value;
    return item->GetName();
}

