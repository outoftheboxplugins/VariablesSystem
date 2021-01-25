// Copyright Out-of-the-Box Plugins 2018-2021. All Rights Reserved.

// GENERATED FILE DO NOT MODIFY DIRECTLY

#include "InstancedGameplayTagContainer.h"

#include "VSLog.h"

/* STATIC */ FGameplayTagContainer UInstancedGameplayTagContainer::GetInstancedGameplayTagContainerValue(UObject* Owner, UInstancedGameplayTagContainer* Variable)
{
	if (!Owner)
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Cannot get instance value without an owner. Returning default value."));
		return FGameplayTagContainer();
	}

	if (!Variable)
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Cannot get instance value without a variable. Returning default value."));
		return FGameplayTagContainer();
	}
	else
	{
		return Variable->GetInstancedGameplayTagContainerRef(Owner);
	}
}

/* STATIC */ void UInstancedGameplayTagContainer::SetInstancedGameplayTagContainerValue(UObject* Owner, UInstancedGameplayTagContainer* Variable, FGameplayTagContainer NewValue)
{
	if (!Owner)
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Cannot set instance value without an owner."));
	}
	else if (!Variable)
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Cannot set instance value without a variable."));
	}
	else
	{
		FGameplayTagContainer& GameplayTagContainerRef = Variable->GetInstancedGameplayTagContainerRef(Owner);
		
		if(GameplayTagContainerRef != NewValue)
		{
			GameplayTagContainerRef = NewValue;
			Variable->Dirty = true;
		}
	}
}

/* STATIC */ void UInstancedGameplayTagContainer::CopyInstancedGameplayTagContainerValue(UObject* Owner, UInstancedGameplayTagContainer* Variable, UObject* OtherOwner, UInstancedGameplayTagContainer* OtherVariable)
{
	if (!Owner || !OtherOwner)
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Cannot copy instance value without an owner."));
	}
	else if (!Variable || !OtherVariable)
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Cannot copy instance value without a variable."));
	}
	else
	{
		FGameplayTagContainer& GameplayTagContainerRef = Variable->GetInstancedGameplayTagContainerRef(Owner);
		FGameplayTagContainer& otherGameplayTagContainerRef = OtherVariable->GetInstancedGameplayTagContainerRef(OtherOwner);

		if(GameplayTagContainerRef != otherGameplayTagContainerRef)
		{
			GameplayTagContainerRef = otherGameplayTagContainerRef;
			Variable->Dirty = true;
		}
	}
}

void UInstancedGameplayTagContainer::OnWorldCreationEvent(const UWorld::FActorsInitializedParams& params)
{
	CleanupVariables();
}

void UInstancedGameplayTagContainer::OnWorldDestructionEvent(UWorld* World, bool bSessionEnded, bool bCleanupResources)
{
	CleanupVariables();
}

FGameplayTagContainer& UInstancedGameplayTagContainer::GetInstancedGameplayTagContainerRef(UObject* Owner)
{
	return VariablesMap.FindOrAdd(Owner);;
}

void UInstancedGameplayTagContainer::CleanupVariables()
{
	int32 index = 0;
	while(index < VariablesMap.Num())
	{
		TArray<FWeakObjectPtr> Owners;
		VariablesMap.GetKeys(Owners);

		if (!Owners[index].IsValid())
		{
			VariablesMap.Remove(Owners[index]);
		}
		else
		{
			index++;
		}
	}
}

