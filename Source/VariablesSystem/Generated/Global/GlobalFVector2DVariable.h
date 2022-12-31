// Copyright Out-of-the-Box Plugins 2018-2023. All Rights Reserved.
// GENERATED FILE DO NOT MODIFY DIRECTLY

#pragma once

#include "GlobalVariable.h"
#include "GlobalFVector2DVariable.generated.h"

/**
 * Global FVector2DVariable implementation of the BaseVariable
 */

UCLASS(BlueprintType)
class VARIABLESSYSTEM_API UGlobalFVector2DVariable : public UGlobalVariable
{
	GENERATED_BODY()

// Global static calls
public:
	// Get the value of a FVector2D variable.
	UFUNCTION(BlueprintPure, Category = "VariablesSystem", meta = (BlueprintThreadSafe, Keywords = "Get Global value"))
	static FVector2D GetGlobalFVector2DVariableValue(const UGlobalFVector2DVariable* Variable);

    // Get the reference of a FVector2D variable.
	UFUNCTION(BlueprintPure, Category = "VariablesSystem", meta = (BlueprintThreadSafe, Keywords = "Get Global value"))
	static UGlobalFVector2DVariable* GetGlobalMutableFVector2DVariable(UGlobalFVector2DVariable* Variable);

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
protected:
	virtual void Save(bool bForce = false) override;
	virtual void Load(bool bUpdateValue = true) override;

#if WITH_EDITOR
	virtual void PostEditChangeProperty(struct FPropertyChangedEvent& e) override;
#endif

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "VariablesSystem")
	FVector2D SavedValue;

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "VariablesSystem")
	FVector2D Value = {};
};
