// Copyright Out-of-the-Box Plugins 2018-2021. All Rights Reserved.
// GENERATED FILE DO NOT MODIFY DIRECTLY

#pragma once

#include "InstancedVariable.h"
#include "InstancedIntArrayVariable.generated.h"

/**
 * Instanced IntArrayVariable implementation of the BaseVariable
 */

UCLASS(BlueprintType)
class VARIABLESSYSTEM_API UInstancedIntArrayVariable : public UInstancedVariable
{
	GENERATED_BODY()

// Global static calls
public:
	// Get the value of a InstancedIntArrayVariable variable.
	UFUNCTION(BlueprintPure, Category = "VariablesSystem", meta = (BlueprintThreadSafe))
	static TArray<int32> GetInstancedIntArrayVariableValue(UObject* Owner, UInstancedIntArrayVariable* Variable);

	// Set the value of a InstancedIntArrayVariable variable.
	UFUNCTION(BlueprintCallable, Category = "VariablesSystem")
	static void SetInstancedIntArrayVariableValue(UObject* Owner, UInstancedIntArrayVariable* Variable, TArray<int32> NewValue);
	
	// Copy the value of a InstancedIntArrayVariable variable.
	UFUNCTION(BlueprintCallable, Category = "VariablesSystem")
	static void CopyInstancedIntArrayVariableValue(UObject* Owner, UInstancedIntArrayVariable* Variable, UObject* OtherOwner, UInstancedIntArrayVariable* OtherVariable);

private:
	virtual void CleanupEntries() override;

private:
	// Internal getter or creater used to modify values.
	TArray<int32>& GetInstancedIntArrayVariableRef(UObject* Owner);

// BaseVariable Debug Interface
private:
    virtual FString GetStringValue() const override;
	FString GetValueAsString(TArray<int32> Value) const;

private:
	TMap<FWeakObjectPtr, TArray<int32>> VariablesMap;
};

