// Copyright Out-of-the-Box Plugins 2018-2021. All Rights Reserved.
// GENERATED FILE DO NOT MODIFY DIRECTLY

#pragma once

#include "InstancedVariable.h"
	
	#include "GameplayTagContainer.h"

#include "InstancedGameplayTagContainer.generated.h"

USTRUCT(BlueprintType)
struct FInstancedGameplayTagContainerType
{
    GENERATED_BODY();

public:
    UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "VariablesSystem")
    FGameplayTagContainer Value  = FGameplayTagContainer();
};

/**
 * Instanced GameplayTagContainer implementation of the BaseVariable
 */

UCLASS(BlueprintType)
class VARIABLESSYSTEM_API UInstancedGameplayTagContainer : public UInstancedVariable
{
	GENERATED_BODY()

// Global static calls
public:
	// Get the value of a InstancedGameplayTagContainer variable.
	UFUNCTION(BlueprintPure, Category = "VariablesSystem", meta = (BlueprintThreadSafe))
	static FGameplayTagContainer GetInstancedGameplayTagContainerValue(UObject* Owner, UInstancedGameplayTagContainer* Variable);

	// Get the reference of a InstancedGameplayTagContainer variable.
	UFUNCTION(BlueprintPure, Category = "VariablesSystem", meta = (BlueprintThreadSafe))
	static UInstancedGameplayTagContainer* GetInstancedMutableGameplayTagContainer(UInstancedGameplayTagContainer* Variable);

	// Set the value of a InstancedGameplayTagContainer variable.
	UFUNCTION(BlueprintCallable, Category = "VariablesSystem")
	static void SetInstancedGameplayTagContainerValue(UObject* Owner, UInstancedGameplayTagContainer* Variable, FGameplayTagContainer NewValue);
	
	// Copy the value of a InstancedGameplayTagContainer variable.
	UFUNCTION(BlueprintCallable, Category = "VariablesSystem")
	static void CopyInstancedGameplayTagContainerValue(UObject* Owner, UInstancedGameplayTagContainer* Variable, UObject* OtherOwner, UInstancedGameplayTagContainer* OtherVariable);

private:
	virtual void CleanupEntries() override;

private:
	// Internal getter or creater used to modify values.
	FInstancedGameplayTagContainerType& GetInstancedGameplayTagContainerRef(UObject* Owner);

// BaseVariable Debug Interface
private:
    virtual FString GetStringValue() const override;
	FString GetValueAsString(FGameplayTagContainer Value) const;

public:
    UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "VariablesSystem")
    TMap<UObject*, FInstancedGameplayTagContainerType> VariablesMap;
};

