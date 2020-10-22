// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#include "GlobalActorRefVariable.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetStringLibrary.h"
#include "CoreMinimal.h"

AActor* UGlobalActorRefVariable::GetGlobalActorRefVariableValue(UGlobalActorRefVariable* var)
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

AActor* UGlobalActorRefVariable::GetGlobalInternalActorRefVariableValue()
{
	return GetGlobalActorRefVariableValue(this);
}

void UGlobalActorRefVariable::SetGlobalActorRefVariableValue(UGlobalActorRefVariable* var, AActor* _value)
{
	if (!var) return;

	var->value = _value;
	var->dirty = true;
}

void UGlobalActorRefVariable::SetGlobalInternalActorRefVariableValue(AActor* _value)
{
	SetGlobalActorRefVariableValue(this, _value);
}

void UGlobalActorRefVariable::CopyGlobalActorRefVariableValue(UGlobalActorRefVariable* var, UGlobalActorRefVariable* other)
{
	if (!var) return;

	var->value = other->value;
	var->dirty = true;
}

void UGlobalActorRefVariable::CopyGlobalInternalActorRefVariableValue(UGlobalActorRefVariable* other)
{
	CopyGlobalActorRefVariableValue(this, other);
}

void UGlobalActorRefVariable::Save()
{
	if (dirty == false)
	{
		return;
	}

	UGameplayStatics::SaveGameToSlot(this, GetSaveLocation(), 0);
	dirty = false;
}

void UGlobalActorRefVariable::Load()
{
	UGlobalActorRefVariable* LoadGameInstance = Cast<UGlobalActorRefVariable>(UGameplayStatics::CreateSaveGameObject(UGlobalActorRefVariable::StaticClass()));
	LoadGameInstance = Cast<UGlobalActorRefVariable>(UGameplayStatics::LoadGameFromSlot(GetSaveLocation(), 0));
	
	if (LoadGameInstance != nullptr)
	{
		this->value = LoadGameInstance->value;
	}
}


FString UGlobalActorRefVariable::GetStringValue() const
{
    const auto& item = value;
    return item->GetName();
}

