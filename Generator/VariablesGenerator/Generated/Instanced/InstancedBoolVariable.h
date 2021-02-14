// Copyright Out-of-the-Box Plugins 2018-2021. All Rights Reserved.

// GENERATED FILE DO NOT MODIFY DIRECTLY

#pragma once

#include "InstancedVariable.h"
#include "InstancedBoolVariable.generated.h"

/**
 * Instanced BoolVariable implementation of the BaseVariable
 */

UCLASS(BlueprintType)
class VARIABLESSYSTEM_API UInstancedBoolVariable : public UInstancedVariable
{
	GENERATED_BODY()

// Global static calls
public:
	// Get the value of a InstancedBoolVariable variable.
	UFUNCTION(BlueprintPure, Category = "VariablesSystem", meta = (BlueprintThreadSafe))
	static bool GetInstancedBoolVariableValue(UObject* Owner, UInstancedBoolVariable* Variable);

	// Set the value of a InstancedBoolVariable variable.
	UFUNCTION(BlueprintCallable, Category = "VariablesSystem")
	static void SetInstancedBoolVariableValue(UObject* Owner, UInstancedBoolVariable* Variable, bool NewValue);
	
	// Copy the value of a InstancedBoolVariable variable.
	UFUNCTION(BlueprintCallable, Category = "VariablesSystem")
	static void CopyInstancedBoolVariableValue(UObject* Owner, UInstancedBoolVariable* Variable, UObject* OtherOwner, UInstancedBoolVariable* OtherVariable);

private:
	virtual void CleanupEntries() override;

private:
	// Internal getter or creater used to modify values.
	bool& GetInstancedBoolVariableRef(UObject* Owner);

// BaseVariable Debug Interface
private:
    virtual FString GetStringValue() const override;
	FString GetValueAsString(bool Value) const;

private:
	TMap<FWeakObjectPtr, bool> VariablesMap;
};

