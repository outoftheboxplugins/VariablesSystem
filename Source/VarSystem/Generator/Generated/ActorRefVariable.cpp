// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#include "ActorRefVariable.h"
#include "Kismet/GameplayStatics.h"

AActor* UActorRefVariable::GetActorRefValue(UActorRefVariable* var)
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

AActor* UActorRefVariable::GetActorRefValue()
{
	return GetActorRefValue(this);
}

void UActorRefVariable::SetActorRefValue(UActorRefVariable* var, AActor* _value)
{
	if (!var) return;

	var->value = _value;
	var->dirty = true;
}

void UActorRefVariable::SetActorRefValue(AActor* _value)
{
	SetActorRefValue(this, _value);
}

void UActorRefVariable::CopyActorRefValue(UActorRefVariable* var, UActorRefVariable* other)
{
	if (!var) return;

	var->value = other->value;
	var->dirty = true;
}

void UActorRefVariable::CopyActorRefValue(UActorRefVariable* other)
{
	CopyActorRefValue(this, other);
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


