// Copyright Out-of-the-Box Plugins 2018-2021. All Rights Reserved.
// GENERATED FILE DO NOT MODIFY DIRECTLY

#pragma once

#include "GlobalVariable.h"
#include "GlobalActorRefVariable.generated.h"

/**
 * Global ActorRefVariable implementation of the BaseVariable
 */

UCLASS(BlueprintType)
class VARIABLESSYSTEM_API UGlobalActorRefVariable : public UGlobalVariable
{
	GENERATED_BODY()

// Global static calls
public:
	// Get the value of a AActor* variable.
	UFUNCTION(BlueprintPure, Category = "VariablesSystem", meta = (BlueprintThreadSafe, Keywords = "Get Global value"))
	static AActor* GetGlobalActorRefVariableValue(const UGlobalActorRefVariable* Variable);

    // Get the reference of a AActor* variable.
	UFUNCTION(BlueprintPure, Category = "VariablesSystem", meta = (BlueprintThreadSafe, Keywords = "Get Global value"))
	static UGlobalActorRefVariable* GetGlobalMutableActorRefVariable(UGlobalActorRefVariable* Variable);

	// Set the value of a AActor* variable.
	UFUNCTION(BlueprintCallable, Category = "VariablesSystem", meta = (Keywords = "Set Global value"))
	static void SetGlobalActorRefVariableValue(UGlobalActorRefVariable* Variable, AActor* NewValue);

	// Copy the value of a AActor* variable.
	UFUNCTION(BlueprintCallable, Category = "VariablesSystem", meta = (Keywords = "Copy Global value"))
	static void CopyGlobalActorRefVariableValue(UGlobalActorRefVariable* Variable, UGlobalActorRefVariable* OtherVariable);

// BaseVariable Debug Interface
private:
    virtual FString GetStringValue() const override;

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "VariablesSystem")
	AActor* Value;
};
