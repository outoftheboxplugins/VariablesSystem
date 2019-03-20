// Copyright Alexandru pasotee Oprea 2018. All Rights Reserved.

#include "ActorRefVariable.h"
#include "Kismet/GameplayStatics.h"



AActor* UActorRefVariable::GetAActorValue(UActorRefVariable* var)
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

AActor* UActorRefVariable::GetAActorValue()
{
	return GetAActorValue(this);
}

void UActorRefVariable::SetAActorValue(UActorRefVariable* var, AActor* _value)
{
	if (!var) return;

	var->value = _value;
	var->dirty = true;
}

void UActorRefVariable::SetAActorValue(AActor* _value)
{
	SetAActorValue(this, _value);
}

void UActorRefVariable::CopyAActorValue(UActorRefVariable* var, UActorRefVariable* other)
{
	if (!var) return;

	var->value = other->value;
	var->dirty = true;
}

void UActorRefVariable::CopyAActorValue(UActorRefVariable* other)
{
	CopyAActorValue(this, other);
}

void UActorRefVariable::Save()
{
	if (dirty == false)
	{
		return;
	}

	UGameplayStatics::SaveGameToSlot(this, GetSaveLocation(), 0);
	dirty = false;
}

void UActorRefVariable::Load()
{
	UActorRefVariable* LoadGameInstance = Cast<UActorRefVariable>(UGameplayStatics::CreateSaveGameObject(UActorRefVariable::StaticClass()));
	LoadGameInstance = Cast<UActorRefVariable>(UGameplayStatics::LoadGameFromSlot(GetSaveLocation(), 0));
	
	if (LoadGameInstance != nullptr)
	{
		this->value = LoadGameInstance->value;
	}
}

