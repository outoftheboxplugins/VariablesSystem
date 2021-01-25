// Copyright Out-of-the-Box Plugins 2018-2021. All Rights Reserved.

// GENERATED FILE DO NOT MODIFY DIRECTLY

#pragma once

#include "BaseVariable.h"
	
	#include "C:\Unreal\UnrealEngine\Engine\Source\Runtime\GameplayTags\Classes\GameplayTagContainer.h"

#include "InstancedGameplayTagContainer.generated.h"

/**
 * Instanced GameplayTagContainer implementation of the BaseVariable
 */

UCLASS(BlueprintType)
class VARIABLESSYSTEM_API UInstancedGameplayTagContainer : public UBaseVariable
{
	GENERATED_BODY()

// Global static calls
public:
	// Get the value of a InstancedGameplayTagContainer variable.
	UFUNCTION(BlueprintPure, Category = "VariablesSystem", meta = (BlueprintThreadSafe))
	static FGameplayTagContainer GetInstancedGameplayTagContainerValue(UObject* Owner, UInstancedGameplayTagContainer* Variable);

	// Set the value of a InstancedGameplayTagContainer variable.
	UFUNCTION(BlueprintCallable, Category = "VariablesSystem")
	static void SetInstancedGameplayTagContainerValue(UObject* Owner, UInstancedGameplayTagContainer* Variable, FGameplayTagContainer NewValue);
	
	// Copy the value of a InstancedGameplayTagContainer variable.
	UFUNCTION(BlueprintCallable, Category = "VariablesSystem")
	static void CopyInstancedGameplayTagContainerValue(UObject* Owner, UInstancedGameplayTagContainer* Variable, UObject* OtherOwner, UInstancedGameplayTagContainer* OtherVariable);

// World Callbacks
private:
	virtual void OnWorldCreationEvent(const UWorld::FActorsInitializedParams& params) override;
	virtual void OnWorldDestructionEvent(UWorld* World, bool bSessionEnded, bool bCleanupResources) override;

private:
	// Internal getter or creater used to modify values.
	FGameplayTagContainer& GetInstancedGameplayTagContainerRef(UObject* Owner);

	// Removes variables with invalid owner pointers.
	void CleanupVariables();


private:
	TMap<FWeakObjectPtr, FGameplayTagContainer> VariablesMap;
};

