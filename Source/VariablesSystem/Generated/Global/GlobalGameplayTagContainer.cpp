// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#include "GlobalGameplayTagContainer.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetStringLibrary.h"
#include "CoreMinimal.h"

FGameplayTagContainer UGlobalGameplayTagContainer::GetGlobalGameplayTagContainerValue(UGlobalGameplayTagContainer* var)
{
	if (var == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Missing variable"));
		return FGameplayTagContainer();
	}
	else
	{
		return var->value;
	}
}

FGameplayTagContainer UGlobalGameplayTagContainer::GetGlobalInternalGameplayTagContainerValue()
{
	return GetGlobalGameplayTagContainerValue(this);
}

void UGlobalGameplayTagContainer::SetGlobalGameplayTagContainerValue(UGlobalGameplayTagContainer* var, FGameplayTagContainer _value)
{
	if (!var) return;

	var->value = _value;
	var->dirty = true;
}

void UGlobalGameplayTagContainer::SetGlobalInternalGameplayTagContainerValue(FGameplayTagContainer _value)
{
	SetGlobalGameplayTagContainerValue(this, _value);
}

void UGlobalGameplayTagContainer::CopyGlobalGameplayTagContainerValue(UGlobalGameplayTagContainer* var, UGlobalGameplayTagContainer* other)
{
	if (!var) return;

	var->value = other->value;
	var->dirty = true;
}

void UGlobalGameplayTagContainer::CopyGlobalInternalGameplayTagContainerValue(UGlobalGameplayTagContainer* other)
{
	CopyGlobalGameplayTagContainerValue(this, other);
}

void UGlobalGameplayTagContainer::Save()
{
	if (dirty == false)
	{
		return;
	}

	UGameplayStatics::SaveGameToSlot(this, GetSaveLocation(), 0);
	dirty = false;
}

void UGlobalGameplayTagContainer::Load()
{
	UGlobalGameplayTagContainer* LoadGameInstance = Cast<UGlobalGameplayTagContainer>(UGameplayStatics::CreateSaveGameObject(UGlobalGameplayTagContainer::StaticClass()));
	LoadGameInstance = Cast<UGlobalGameplayTagContainer>(UGameplayStatics::LoadGameFromSlot(GetSaveLocation(), 0));
	
	if (LoadGameInstance != nullptr)
	{
		this->value = LoadGameInstance->value;
	}
}


FString UGlobalGameplayTagContainer::GetStringValue() const
{
    const auto& item = value;
    return item.ToString();
}

