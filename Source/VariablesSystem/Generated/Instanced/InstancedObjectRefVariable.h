// Copyright Out-of-the-Box Plugins 2018-2021. All Rights Reserved.

// GENERATED FILE DO NOT MODIFY DIRECTLY

#pragma once

#include "InstancedVariable.h"
#include "InstancedObjectRefVariable.generated.h"

/**
 * Instanced ObjectRefVariable implementation of the BaseVariable
 */

UCLASS(BlueprintType)
class VARIABLESSYSTEM_API UInstancedObjectRefVariable : public UInstancedVariable
{
	GENERATED_BODY()

// Global static calls
public:
	// Get the value of a InstancedObjectRefVariable variable.
	UFUNCTION(BlueprintPure, Category = "VariablesSystem", meta = (BlueprintThreadSafe))
	static UObject* GetInstancedObjectRefVariableValue(UObject* Owner, UInstancedObjectRefVariable* Variable);

	// Set the value of a InstancedObjectRefVariable variable.
	UFUNCTION(BlueprintCallable, Category = "VariablesSystem")
	static void SetInstancedObjectRefVariableValue(UObject* Owner, UInstancedObjectRefVariable* Variable, UObject* NewValue);
	
	// Copy the value of a InstancedObjectRefVariable variable.
	UFUNCTION(BlueprintCallable, Category = "VariablesSystem")
	static void CopyInstancedObjectRefVariableValue(UObject* Owner, UInstancedObjectRefVariable* Variable, UObject* OtherOwner, UInstancedObjectRefVariable* OtherVariable);

private:
	virtual void CleanupEntries() override;

private:
	// Internal getter or creater used to modify values.
	UObject*& GetInstancedObjectRefVariableRef(UObject* Owner);

// BaseVariable Debug Interface
private:
    virtual FString GetStringValue() const override;
	FString GetValueAsString(UObject* Value) const;

private:
	TMap<FWeakObjectPtr, UObject*> VariablesMap;
};

