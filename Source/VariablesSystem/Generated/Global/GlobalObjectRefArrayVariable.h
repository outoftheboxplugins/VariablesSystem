// Copyright Out-of-the-Box Plugins 2018-2025. All Rights Reserved.
// GENERATED FILE DO NOT MODIFY DIRECTLY

#pragma once

#include "GlobalVariable.h"
#include "GlobalObjectRefArrayVariable.generated.h"

/**
 * Global ObjectRefArrayVariable implementation of the BaseVariable
 */

UCLASS(BlueprintType)
class VARIABLESSYSTEM_API UGlobalObjectRefArrayVariable : public UGlobalVariable
{
	GENERATED_BODY()

// Global static calls
public:
	// Get the value of a TArray<UObject*> variable.
	UFUNCTION(BlueprintPure, Category = "VariablesSystem", meta = (BlueprintThreadSafe, Keywords = "Get Global value"))
	static TArray<UObject*> GetGlobalObjectRefArrayVariableValue(const UGlobalObjectRefArrayVariable* Variable);

    // Get the reference of a TArray<UObject*> variable.
	UFUNCTION(BlueprintPure, Category = "VariablesSystem", meta = (BlueprintThreadSafe, Keywords = "Get Global value"))
	static UGlobalObjectRefArrayVariable* GetGlobalMutableObjectRefArrayVariable(UGlobalObjectRefArrayVariable* Variable);

	// Set the value of a TArray<UObject*> variable.
	UFUNCTION(BlueprintCallable, Category = "VariablesSystem", meta = (Keywords = "Set Global value"))
	static void SetGlobalObjectRefArrayVariableValue(UGlobalObjectRefArrayVariable* Variable, TArray<UObject*> NewValue);

	// Copy the value of a TArray<UObject*> variable.
	UFUNCTION(BlueprintCallable, Category = "VariablesSystem", meta = (Keywords = "Copy Global value"))
	static void CopyGlobalObjectRefArrayVariableValue(UGlobalObjectRefArrayVariable* Variable, UGlobalObjectRefArrayVariable* OtherVariable);

// BaseVariable Debug Interface
private:
    virtual FString GetStringValue() const override;

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "VariablesSystem")
	TArray<UObject*> Value = {};
};
