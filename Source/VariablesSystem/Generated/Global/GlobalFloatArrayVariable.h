// Copyright Out-of-the-Box Plugins 2018-2025. All Rights Reserved.
// GENERATED FILE DO NOT MODIFY DIRECTLY

#pragma once

#include "GlobalVariable.h"
#include "GlobalFloatArrayVariable.generated.h"

/**
 * Global FloatArrayVariable implementation of the BaseVariable
 */

UCLASS(BlueprintType)
class VARIABLESSYSTEM_API UGlobalFloatArrayVariable : public UGlobalVariable
{
	GENERATED_BODY()

// Global static calls
public:
	// Get the value of a TArray<float> variable.
	UFUNCTION(BlueprintPure, Category = "VariablesSystem", meta = (BlueprintThreadSafe, Keywords = "Get Global value"))
	static TArray<float> GetGlobalFloatArrayVariableValue(const UGlobalFloatArrayVariable* Variable);

    // Get the reference of a TArray<float> variable.
	UFUNCTION(BlueprintPure, Category = "VariablesSystem", meta = (BlueprintThreadSafe, Keywords = "Get Global value"))
	static UGlobalFloatArrayVariable* GetGlobalMutableFloatArrayVariable(UGlobalFloatArrayVariable* Variable);

	// Set the value of a TArray<float> variable.
	UFUNCTION(BlueprintCallable, Category = "VariablesSystem", meta = (Keywords = "Set Global value"))
	static void SetGlobalFloatArrayVariableValue(UGlobalFloatArrayVariable* Variable, TArray<float> NewValue);

	// Copy the value of a TArray<float> variable.
	UFUNCTION(BlueprintCallable, Category = "VariablesSystem", meta = (Keywords = "Copy Global value"))
	static void CopyGlobalFloatArrayVariableValue(UGlobalFloatArrayVariable* Variable, UGlobalFloatArrayVariable* OtherVariable);

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
	TArray<float> SavedValue;

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "VariablesSystem")
	TArray<float> Value = {};
};
