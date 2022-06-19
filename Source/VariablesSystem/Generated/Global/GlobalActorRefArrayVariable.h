// Copyright Out-of-the-Box Plugins 2018-2021. All Rights Reserved.
// GENERATED FILE DO NOT MODIFY DIRECTLY

#pragma once

#include "GlobalVariable.h"
#include "GlobalActorRefArrayVariable.generated.h"

/**
 * Global ActorRefArrayVariable implementation of the BaseVariable
 */

UCLASS(BlueprintType)
class VARIABLESSYSTEM_API UGlobalActorRefArrayVariable : public UGlobalVariable
{
	GENERATED_BODY()

// Global static calls
public:
	// Get the value of a TArray<AActor*> variable.
	UFUNCTION(BlueprintPure, Category = "VariablesSystem", meta = (BlueprintThreadSafe, Keywords = "Get Global value"))
	static TArray<AActor*> GetGlobalActorRefArrayVariableValue(const UGlobalActorRefArrayVariable* Variable);

    // Get the reference of a TArray<AActor*> variable.
	UFUNCTION(BlueprintPure, Category = "VariablesSystem", meta = (BlueprintThreadSafe, Keywords = "Get Global value"))
	static UGlobalActorRefArrayVariable* GetGlobalMutableActorRefArrayVariable(UGlobalActorRefArrayVariable* Variable);

	// Set the value of a TArray<AActor*> variable.
	UFUNCTION(BlueprintCallable, Category = "VariablesSystem", meta = (Keywords = "Set Global value"))
	static void SetGlobalActorRefArrayVariableValue(UGlobalActorRefArrayVariable* Variable, TArray<AActor*> NewValue);

	// Copy the value of a TArray<AActor*> variable.
	UFUNCTION(BlueprintCallable, Category = "VariablesSystem", meta = (Keywords = "Copy Global value"))
	static void CopyGlobalActorRefArrayVariableValue(UGlobalActorRefArrayVariable* Variable, UGlobalActorRefArrayVariable* OtherVariable);

// BaseVariable Debug Interface
private:
    virtual FString GetStringValue() const override;

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "VariablesSystem")
	TArray<AActor*> Value = {};
};
