// Copyright Out-of-the-Box Plugins 2018-2021. All Rights Reserved.
// GENERATED FILE DO NOT MODIFY DIRECTLY

#pragma once

#include "InstancedVariable.h"
#include "InstancedFRotatorArrayVariable.generated.h"

/**
 * Instanced FRotatorArrayVariable implementation of the BaseVariable
 */

UCLASS(BlueprintType)
class VARIABLESSYSTEM_API UInstancedFRotatorArrayVariable : public UInstancedVariable
{
	GENERATED_BODY()

// Global static calls
public:
	// Get the value of a InstancedFRotatorArrayVariable variable.
	UFUNCTION(BlueprintPure, Category = "VariablesSystem", meta = (BlueprintThreadSafe))
	static TArray<FRotator> GetInstancedFRotatorArrayVariableValue(UObject* Owner, UInstancedFRotatorArrayVariable* Variable);

	// Set the value of a InstancedFRotatorArrayVariable variable.
	UFUNCTION(BlueprintCallable, Category = "VariablesSystem")
	static void SetInstancedFRotatorArrayVariableValue(UObject* Owner, UInstancedFRotatorArrayVariable* Variable, TArray<FRotator> NewValue);
	
	// Copy the value of a InstancedFRotatorArrayVariable variable.
	UFUNCTION(BlueprintCallable, Category = "VariablesSystem")
	static void CopyInstancedFRotatorArrayVariableValue(UObject* Owner, UInstancedFRotatorArrayVariable* Variable, UObject* OtherOwner, UInstancedFRotatorArrayVariable* OtherVariable);

private:
	virtual void CleanupEntries() override;

private:
	// Internal getter or creater used to modify values.
	TArray<FRotator>& GetInstancedFRotatorArrayVariableRef(UObject* Owner);

// BaseVariable Debug Interface
private:
    virtual FString GetStringValue() const override;
	FString GetValueAsString(TArray<FRotator> Value) const;

private:
	TMap<FWeakObjectPtr, TArray<FRotator>> VariablesMap;
};

