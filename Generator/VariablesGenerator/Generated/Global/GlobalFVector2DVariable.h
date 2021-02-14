// Copyright Out-of-the-Box Plugins 2018-2021. All Rights Reserved.

// GENERATED FILE DO NOT MODIFY DIRECTLY

#pragma once

#include "BaseVariable.h"
#include "GlobalFVector2DVariable.generated.h"

/**
 * Global FVector2DVariable implementation of the BaseVariable
 */

UCLASS(BlueprintType)
class VARIABLESSYSTEM_API UGlobalFVector2DVariable : public UBaseVariable
{
	GENERATED_BODY()

// Global static calls
public:
	// Get the value of a FVector2D variable.
	UFUNCTION(BlueprintPure, Category = "VariablesSystem", meta = (BlueprintThreadSafe, Keywords = "Get Global value"))
	static FVector2D GetGlobalFVector2DVariableValue(const UGlobalFVector2DVariable* Variable);

	// Set the value of a FVector2D variable.
	UFUNCTION(BlueprintCallable, Category = "VariablesSystem", meta = (Keywords = "Set Global value"))
	static void SetGlobalFVector2DVariableValue(UGlobalFVector2DVariable* Variable, FVector2D NewValue);

	// Copy the value of a FVector2D variable.
	UFUNCTION(BlueprintCallable, Category = "VariablesSystem", meta = (Keywords = "Copy Global value"))
	static void CopyGlobalFVector2DVariableValue(UGlobalFVector2DVariable* Variable, UGlobalFVector2DVariable* OtherVariable);

// BaseVariable Debug Interface
private:
    virtual FString GetStringValue() const override;
// BaseVariable Save&Load Interface
private:
	virtual void Save() override;
	virtual void Load() override;

protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "VariablesSystem")
	FVector2D Value;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "VariablesSystem")
	FVector2D SavedValue;
};
