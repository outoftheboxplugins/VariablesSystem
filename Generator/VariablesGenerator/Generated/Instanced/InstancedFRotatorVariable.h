// Copyright Out-of-the-Box Plugins 2018-2021. All Rights Reserved.
// GENERATED FILE DO NOT MODIFY DIRECTLY

#pragma once

#include "InstancedVariable.h"
#include "InstancedFRotatorVariable.generated.h"

/**
 * Instanced FRotatorVariable implementation of the BaseVariable
 */

UCLASS(BlueprintType)
class VARIABLESSYSTEM_API UInstancedFRotatorVariable : public UInstancedVariable
{
	GENERATED_BODY()

// Global static calls
public:
	// Get the value of a InstancedFRotatorVariable variable.
	UFUNCTION(BlueprintPure, Category = "VariablesSystem", meta = (BlueprintThreadSafe))
	static FRotator GetInstancedFRotatorVariableValue(UObject* Owner, UInstancedFRotatorVariable* Variable);

	// Set the value of a InstancedFRotatorVariable variable.
	UFUNCTION(BlueprintCallable, Category = "VariablesSystem")
	static void SetInstancedFRotatorVariableValue(UObject* Owner, UInstancedFRotatorVariable* Variable, FRotator NewValue);
	
	// Copy the value of a InstancedFRotatorVariable variable.
	UFUNCTION(BlueprintCallable, Category = "VariablesSystem")
	static void CopyInstancedFRotatorVariableValue(UObject* Owner, UInstancedFRotatorVariable* Variable, UObject* OtherOwner, UInstancedFRotatorVariable* OtherVariable);

private:
	virtual void CleanupEntries() override;

private:
	// Internal getter or creater used to modify values.
	FRotator& GetInstancedFRotatorVariableRef(UObject* Owner);

// BaseVariable Debug Interface
private:
    virtual FString GetStringValue() const override;
	FString GetValueAsString(FRotator Value) const;

private:
	TMap<FWeakObjectPtr, FRotator> VariablesMap;
};

