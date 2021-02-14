// Copyright Out-of-the-Box Plugins 2018-2021. All Rights Reserved.

// GENERATED FILE DO NOT MODIFY DIRECTLY

#pragma once

#include "InstancedVariable.h"
#include "InstancedFVector2DVariable.generated.h"

/**
 * Instanced FVector2DVariable implementation of the BaseVariable
 */

UCLASS(BlueprintType)
class VARIABLESSYSTEM_API UInstancedFVector2DVariable : public UInstancedVariable
{
	GENERATED_BODY()

// Global static calls
public:
	// Get the value of a InstancedFVector2DVariable variable.
	UFUNCTION(BlueprintPure, Category = "VariablesSystem", meta = (BlueprintThreadSafe))
	static FVector2D GetInstancedFVector2DVariableValue(UObject* Owner, UInstancedFVector2DVariable* Variable);

	// Set the value of a InstancedFVector2DVariable variable.
	UFUNCTION(BlueprintCallable, Category = "VariablesSystem")
	static void SetInstancedFVector2DVariableValue(UObject* Owner, UInstancedFVector2DVariable* Variable, FVector2D NewValue);
	
	// Copy the value of a InstancedFVector2DVariable variable.
	UFUNCTION(BlueprintCallable, Category = "VariablesSystem")
	static void CopyInstancedFVector2DVariableValue(UObject* Owner, UInstancedFVector2DVariable* Variable, UObject* OtherOwner, UInstancedFVector2DVariable* OtherVariable);

private:
	virtual void CleanupEntries() override;

private:
	// Internal getter or creater used to modify values.
	FVector2D& GetInstancedFVector2DVariableRef(UObject* Owner);

// BaseVariable Debug Interface
private:
    virtual FString GetStringValue() const override;
	FString GetValueAsString(FVector2D Value) const;

private:
	TMap<FWeakObjectPtr, FVector2D> VariablesMap;
};

