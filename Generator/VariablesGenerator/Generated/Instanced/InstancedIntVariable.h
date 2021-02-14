// Copyright Out-of-the-Box Plugins 2018-2021. All Rights Reserved.

// GENERATED FILE DO NOT MODIFY DIRECTLY

#pragma once

#include "InstancedBaseVariable.h"
#include "InstancedIntVariable.generated.h"

/**
 * Instanced IntVariable implementation of the BaseVariable
 */

UCLASS(BlueprintType)
class VARIABLESSYSTEM_API UInstancedIntVariable : public UInstancedBaseVariable
{
	GENERATED_BODY()

// Global static calls
public:
	// Get the value of a InstancedIntVariable variable.
	UFUNCTION(BlueprintPure, Category = "VariablesSystem", meta = (BlueprintThreadSafe))
	static int32 GetInstancedIntVariableValue(UObject* Owner, UInstancedIntVariable* Variable);

	// Set the value of a InstancedIntVariable variable.
	UFUNCTION(BlueprintCallable, Category = "VariablesSystem")
	static void SetInstancedIntVariableValue(UObject* Owner, UInstancedIntVariable* Variable, int32 NewValue);
	
	// Copy the value of a InstancedIntVariable variable.
	UFUNCTION(BlueprintCallable, Category = "VariablesSystem")
	static void CopyInstancedIntVariableValue(UObject* Owner, UInstancedIntVariable* Variable, UObject* OtherOwner, UInstancedIntVariable* OtherVariable);

// World Callbacks
private:
	virtual void OnWorldCreationEvent(const UWorld::FActorsInitializedParams& params) override;
	virtual void OnWorldDestructionEvent(UWorld* World, bool bSessionEnded, bool bCleanupResources) override;

private:
	// Internal getter or creater used to modify values.
	int32& GetInstancedIntVariableRef(UObject* Owner);

	// Removes variables with invalid owner pointers.
	void CleanupVariables();

// BaseVariable Debug Interface
private:
    virtual FString GetStringValue() const override;
	FString GetValueAsString(int32 Value) const;

private:
	TMap<FWeakObjectPtr, int32> VariablesMap;
};

