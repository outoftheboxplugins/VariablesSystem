// Copyright Out-of-the-Box Plugins 2018-2021. All Rights Reserved.

// GENERATED FILE DO NOT MODIFY DIRECTLY

#pragma once

#include "BaseVariable.h"

#include "GlobalFVectorVariable.generated.h"

/**
 * Global FVectorVariable implementation of the BaseVariable
 */

UCLASS(BlueprintType)
class VARIABLESSYSTEM_API UGlobalFVectorVariable : public UBaseVariable
{
	GENERATED_BODY()

// Global static calls
public:
	// Get the value of a FVector variable.
	UFUNCTION(BlueprintPure, Category = "VariablesSystem", meta = (BlueprintThreadSafe, Keywords = "Get Global value"))
	static FVector GetGlobalFVectorVariableValue(const UGlobalFVectorVariable* Variable);

	// Set the value of a FVector variable.
	UFUNCTION(BlueprintCallable, Category = "VariablesSystem", meta = (Keywords = "Set Global value"))
	static void SetGlobalFVectorVariableValue(UGlobalFVectorVariable* Variable, FVector NewValue);

	// Copy the value of a FVector variable.
	UFUNCTION(BlueprintCallable, Category = "VariablesSystem", meta = (Keywords = "Copy Global value"))
	static void CopyGlobalFVectorVariableValue(UGlobalFVectorVariable* Variable, UGlobalFVectorVariable* OtherVariable);

// BaseVariable Debug Interface
private:
    virtual FString GetStringValue() const override;
// BaseVariable Save&Load Interface
private:
	virtual void Save() override;
	virtual void Load() override;

protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "VariablesSystem")
	FVector Value;
};
