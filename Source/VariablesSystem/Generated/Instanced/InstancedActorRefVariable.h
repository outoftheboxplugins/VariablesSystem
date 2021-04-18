// Copyright Out-of-the-Box Plugins 2018-2021. All Rights Reserved.
// GENERATED FILE DO NOT MODIFY DIRECTLY

#pragma once

#include "InstancedVariable.h"
#include "InstancedActorRefVariable.generated.h"

/**
 * Instanced ActorRefVariable implementation of the BaseVariable
 */

UCLASS(BlueprintType)
class VARIABLESSYSTEM_API UInstancedActorRefVariable : public UInstancedVariable
{
	GENERATED_BODY()

// Global static calls
public:
	// Get the value of a InstancedActorRefVariable variable.
	UFUNCTION(BlueprintPure, Category = "VariablesSystem", meta = (BlueprintThreadSafe))
	static AActor* GetInstancedActorRefVariableValue(UObject* Owner, UInstancedActorRefVariable* Variable);

	// Set the value of a InstancedActorRefVariable variable.
	UFUNCTION(BlueprintCallable, Category = "VariablesSystem")
	static void SetInstancedActorRefVariableValue(UObject* Owner, UInstancedActorRefVariable* Variable, AActor* NewValue);
	
	// Copy the value of a InstancedActorRefVariable variable.
	UFUNCTION(BlueprintCallable, Category = "VariablesSystem")
	static void CopyInstancedActorRefVariableValue(UObject* Owner, UInstancedActorRefVariable* Variable, UObject* OtherOwner, UInstancedActorRefVariable* OtherVariable);

private:
	virtual void CleanupEntries() override;

private:
	// Internal getter or creater used to modify values.
	AActor*& GetInstancedActorRefVariableRef(UObject* Owner);

// BaseVariable Debug Interface
private:
    virtual FString GetStringValue() const override;
	FString GetValueAsString(AActor* Value) const;

private:
	TMap<FWeakObjectPtr, AActor*> VariablesMap;
};

