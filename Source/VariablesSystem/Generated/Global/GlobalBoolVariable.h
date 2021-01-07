// Copyright Out-of-the-Box Plugins 2018-2021. All Rights Reserved.

// GENERATED FILE DO NOT MODIFY DIRECTLY

#pragma once

#include "BaseVariable.h"

#include "GlobalBoolVariable.generated.h"

/**
 * Global BoolVariable implementation of the BaseVariable
 */

UCLASS(BlueprintType)
class VARIABLESSYSTEM_API UGlobalBoolVariable : public UBaseVariable
{
	GENERATED_BODY()

// Global static calls
public:
	// Get the value of a bool variable.
	UFUNCTION(BlueprintPure, Category = "VariablesSystem", meta = (BlueprintThreadSafe, Keywords = "Get Global value"))
	static bool GetGlobalBoolVariableValue(const UGlobalBoolVariable* Variable);

	// Set the value of a bool variable.
	UFUNCTION(BlueprintCallable, Category = "VariablesSystem", meta = (Keywords = "Set Global value"))
	static void SetGlobalBoolVariableValue(UGlobalBoolVariable* Variable, bool NewValue);

	// Copy the value of a bool variable.
	UFUNCTION(BlueprintCallable, Category = "VariablesSystem", meta = (Keywords = "Copy Global value"))
	static void CopyGlobalBoolVariableValue(UGlobalBoolVariable* Variable, UGlobalBoolVariable* OtherVariable);

// BaseVariable Debug Interface
private:
    virtual FString GetStringValue() const override;
// BaseVariable Save&Load Interface
private:
	virtual void Save() override;
	virtual void Load() override;

protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "VariablesSystem")
	bool Value;
};
