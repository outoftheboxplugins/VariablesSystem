// Copyright Out-of-the-Box Plugins 2018-2021. All Rights Reserved.
// GENERATED FILE DO NOT MODIFY DIRECTLY

#pragma once

#include "GlobalVariable.h"
#include "GlobalBoolArrayVariable.generated.h"

/**
 * Global BoolArrayVariable implementation of the BaseVariable
 */

UCLASS(BlueprintType)
class VARIABLESSYSTEM_API UGlobalBoolArrayVariable : public UGlobalVariable
{
	GENERATED_BODY()

// Global static calls
public:
	// Get the value of a TArray<bool> variable.
	UFUNCTION(BlueprintPure, Category = "VariablesSystem", meta = (BlueprintThreadSafe, Keywords = "Get Global value"))
	static TArray<bool> GetGlobalBoolArrayVariableValue(const UGlobalBoolArrayVariable* Variable);

    // Get the reference of a TArray<bool> variable.
	UFUNCTION(BlueprintPure, Category = "VariablesSystem", meta = (BlueprintThreadSafe, Keywords = "Get Global value"))
	static UGlobalBoolArrayVariable* GetGlobalMutableBoolArrayVariable(UGlobalBoolArrayVariable* Variable);

	// Set the value of a TArray<bool> variable.
	UFUNCTION(BlueprintCallable, Category = "VariablesSystem", meta = (Keywords = "Set Global value"))
	static void SetGlobalBoolArrayVariableValue(UGlobalBoolArrayVariable* Variable, TArray<bool> NewValue);

	// Copy the value of a TArray<bool> variable.
	UFUNCTION(BlueprintCallable, Category = "VariablesSystem", meta = (Keywords = "Copy Global value"))
	static void CopyGlobalBoolArrayVariableValue(UGlobalBoolArrayVariable* Variable, UGlobalBoolArrayVariable* OtherVariable);

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
	TArray<bool> SavedValue;

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "VariablesSystem")
	TArray<bool> Value;
};
