




















// Copyright Out-of-the-Box Plugins 2018-2021. All Rights Reserved.

// GENERATED FILE DO NOT MODIFY DIRECTLY

#pragma once

#include "GlobalBaseVariable.h"
#include "GlobalObjectRefVariable.generated.h"

/**
 * Global ObjectRefVariable implementation of the BaseVariable
 */

UCLASS(BlueprintType)
class VARIABLESSYSTEM_API UGlobalObjectRefVariable : public UGlobalBaseVariable
{
	GENERATED_BODY()

// Global static calls
public:
	// Get the value of a UObject* variable.
	UFUNCTION(BlueprintPure, Category = "VariablesSystem", meta = (BlueprintThreadSafe, Keywords = "Get Global value"))
	static UObject* GetGlobalObjectRefVariableValue(const UGlobalObjectRefVariable* Variable);

	// Set the value of a UObject* variable.
	UFUNCTION(BlueprintCallable, Category = "VariablesSystem", meta = (Keywords = "Set Global value"))
	static void SetGlobalObjectRefVariableValue(UGlobalObjectRefVariable* Variable, UObject* NewValue);

	// Copy the value of a UObject* variable.
	UFUNCTION(BlueprintCallable, Category = "VariablesSystem", meta = (Keywords = "Copy Global value"))
	static void CopyGlobalObjectRefVariableValue(UGlobalObjectRefVariable* Variable, UGlobalObjectRefVariable* OtherVariable);

// BaseVariable Debug Interface
private:
    virtual FString GetStringValue() const override;

protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "VariablesSystem")
	UObject* Value;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "VariablesSystem")
	UObject* SavedValue;
};
