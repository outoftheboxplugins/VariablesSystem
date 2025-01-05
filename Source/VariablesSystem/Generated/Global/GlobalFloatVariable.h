// Copyright Out-of-the-Box Plugins 2018-2025. All Rights Reserved.
// GENERATED FILE DO NOT MODIFY DIRECTLY

#pragma once

#include "GlobalVariable.h"

#include "GlobalFloatVariable.generated.h"

/**
 * Global FloatVariable implementation of the BaseVariable
 */

UCLASS(BlueprintType)
class VARIABLESSYSTEM_API UGlobalFloatVariable : public UGlobalVariable
{
	GENERATED_BODY()

	// Global static calls
public:
	// Get the value of a float variable.
	UFUNCTION(BlueprintPure, Category = "VariablesSystem", meta = (BlueprintThreadSafe, Keywords = "Get Global value"))
	static double GetGlobalFloatVariableValue(const UGlobalFloatVariable* Variable);

	// Get the reference of a float variable.
	UFUNCTION(BlueprintPure, Category = "VariablesSystem", meta = (BlueprintThreadSafe, Keywords = "Get Global value"))
	static UGlobalFloatVariable* GetGlobalMutableFloatVariable(UGlobalFloatVariable* Variable);

	// Set the value of a float variable.
	UFUNCTION(BlueprintCallable, Category = "VariablesSystem", meta = (Keywords = "Set Global value"))
	static void SetGlobalFloatVariableValue(UGlobalFloatVariable* Variable, double NewValue);

	// Copy the value of a float variable.
	UFUNCTION(BlueprintCallable, Category = "VariablesSystem", meta = (Keywords = "Copy Global value"))
	static void CopyGlobalFloatVariableValue(UGlobalFloatVariable* Variable, UGlobalFloatVariable* OtherVariable);

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
	double SavedValue;

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "VariablesSystem")
	double Value = {};
};
