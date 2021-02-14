// Copyright Out-of-the-Box Plugins 2018-2021. All Rights Reserved.

// GENERATED FILE DO NOT MODIFY DIRECTLY

#pragma once

#include "InstancedBaseVariable.h"
#include "InstancedFloatVariable.generated.h"

/**
 * Instanced FloatVariable implementation of the BaseVariable
 */

UCLASS(BlueprintType)
class VARIABLESSYSTEM_API UInstancedFloatVariable : public UInstancedBaseVariable
{
	GENERATED_BODY()

// Global static calls
public:
	// Get the value of a InstancedFloatVariable variable.
	UFUNCTION(BlueprintPure, Category = "VariablesSystem", meta = (BlueprintThreadSafe))
	static float GetInstancedFloatVariableValue(UObject* Owner, UInstancedFloatVariable* Variable);

	// Set the value of a InstancedFloatVariable variable.
	UFUNCTION(BlueprintCallable, Category = "VariablesSystem")
	static void SetInstancedFloatVariableValue(UObject* Owner, UInstancedFloatVariable* Variable, float NewValue);
	
	// Copy the value of a InstancedFloatVariable variable.
	UFUNCTION(BlueprintCallable, Category = "VariablesSystem")
	static void CopyInstancedFloatVariableValue(UObject* Owner, UInstancedFloatVariable* Variable, UObject* OtherOwner, UInstancedFloatVariable* OtherVariable);

private:
	virtual void CleanupEntries() override;

private:
	// Internal getter or creater used to modify values.
	float& GetInstancedFloatVariableRef(UObject* Owner);

// BaseVariable Debug Interface
private:
    virtual FString GetStringValue() const override;
	FString GetValueAsString(float Value) const;

private:
	TMap<FWeakObjectPtr, float> VariablesMap;
};

