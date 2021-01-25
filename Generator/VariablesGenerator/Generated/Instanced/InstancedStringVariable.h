// Copyright Out-of-the-Box Plugins 2018-2021. All Rights Reserved.

// GENERATED FILE DO NOT MODIFY DIRECTLY

#pragma once

#include "BaseVariable.h"
#include "InstancedStringVariable.generated.h"

/**
 * Instanced StringVariable implementation of the BaseVariable
 */

UCLASS(BlueprintType)
class VARIABLESSYSTEM_API UInstancedStringVariable : public UBaseVariable
{
	GENERATED_BODY()

// Global static calls
public:
	// Get the value of a InstancedStringVariable variable.
	UFUNCTION(BlueprintPure, Category = "VariablesSystem", meta = (BlueprintThreadSafe))
	static FString GetInstancedStringVariableValue(UObject* Owner, UInstancedStringVariable* Variable);

	// Set the value of a InstancedStringVariable variable.
	UFUNCTION(BlueprintCallable, Category = "VariablesSystem")
	static void SetInstancedStringVariableValue(UObject* Owner, UInstancedStringVariable* Variable, FString NewValue);
	
	// Copy the value of a InstancedStringVariable variable.
	UFUNCTION(BlueprintCallable, Category = "VariablesSystem")
	static void CopyInstancedStringVariableValue(UObject* Owner, UInstancedStringVariable* Variable, UObject* OtherOwner, UInstancedStringVariable* OtherVariable);

// World Callbacks
private:
	virtual void OnWorldCreationEvent(const UWorld::FActorsInitializedParams& params) override;
	virtual void OnWorldDestructionEvent(UWorld* World, bool bSessionEnded, bool bCleanupResources) override;

private:
	// Internal getter or creater used to modify values.
	FString& GetInstancedStringVariableRef(UObject* Owner);

	// Removes variables with invalid owner pointers.
	void CleanupVariables();

// BaseVariable Debug Interface
private:
    virtual FString GetStringValue() const override;
	FString GetValueAsString(FString Value) const;

private:
	TMap<FWeakObjectPtr, FString> VariablesMap;
};

