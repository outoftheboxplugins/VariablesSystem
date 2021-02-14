// Copyright Out-of-the-Box Plugins 2018-2021. All Rights Reserved.

// GENERATED FILE DO NOT MODIFY DIRECTLY

#pragma once

#include "InstancedBaseVariable.h"
#include "InstancedFVectorVariable.generated.h"

/**
 * Instanced FVectorVariable implementation of the BaseVariable
 */

UCLASS(BlueprintType)
class VARIABLESSYSTEM_API UInstancedFVectorVariable : public UInstancedBaseVariable
{
	GENERATED_BODY()

// Global static calls
public:
	// Get the value of a InstancedFVectorVariable variable.
	UFUNCTION(BlueprintPure, Category = "VariablesSystem", meta = (BlueprintThreadSafe))
	static FVector GetInstancedFVectorVariableValue(UObject* Owner, UInstancedFVectorVariable* Variable);

	// Set the value of a InstancedFVectorVariable variable.
	UFUNCTION(BlueprintCallable, Category = "VariablesSystem")
	static void SetInstancedFVectorVariableValue(UObject* Owner, UInstancedFVectorVariable* Variable, FVector NewValue);
	
	// Copy the value of a InstancedFVectorVariable variable.
	UFUNCTION(BlueprintCallable, Category = "VariablesSystem")
	static void CopyInstancedFVectorVariableValue(UObject* Owner, UInstancedFVectorVariable* Variable, UObject* OtherOwner, UInstancedFVectorVariable* OtherVariable);

// World Callbacks
private:
	virtual void OnWorldCreationEvent(const UWorld::FActorsInitializedParams& params) override;
	virtual void OnWorldDestructionEvent(UWorld* World, bool bSessionEnded, bool bCleanupResources) override;

private:
	// Internal getter or creater used to modify values.
	FVector& GetInstancedFVectorVariableRef(UObject* Owner);

	// Removes variables with invalid owner pointers.
	void CleanupVariables();

// BaseVariable Debug Interface
private:
    virtual FString GetStringValue() const override;
	FString GetValueAsString(FVector Value) const;

private:
	TMap<FWeakObjectPtr, FVector> VariablesMap;
};

