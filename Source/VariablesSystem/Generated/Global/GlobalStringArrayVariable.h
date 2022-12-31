// Copyright Out-of-the-Box Plugins 2018-2023. All Rights Reserved.
// GENERATED FILE DO NOT MODIFY DIRECTLY

#pragma once

#include "GlobalVariable.h"
#include "GlobalStringArrayVariable.generated.h"

/**
 * Global StringArrayVariable implementation of the BaseVariable
 */

UCLASS(BlueprintType)
class VARIABLESSYSTEM_API UGlobalStringArrayVariable : public UGlobalVariable
{
	GENERATED_BODY()

// Global static calls
public:
	// Get the value of a TArray<FString> variable.
	UFUNCTION(BlueprintPure, Category = "VariablesSystem", meta = (BlueprintThreadSafe, Keywords = "Get Global value"))
	static TArray<FString> GetGlobalStringArrayVariableValue(const UGlobalStringArrayVariable* Variable);

    // Get the reference of a TArray<FString> variable.
	UFUNCTION(BlueprintPure, Category = "VariablesSystem", meta = (BlueprintThreadSafe, Keywords = "Get Global value"))
	static UGlobalStringArrayVariable* GetGlobalMutableStringArrayVariable(UGlobalStringArrayVariable* Variable);

	// Set the value of a TArray<FString> variable.
	UFUNCTION(BlueprintCallable, Category = "VariablesSystem", meta = (Keywords = "Set Global value"))
	static void SetGlobalStringArrayVariableValue(UGlobalStringArrayVariable* Variable, TArray<FString> NewValue);

	// Copy the value of a TArray<FString> variable.
	UFUNCTION(BlueprintCallable, Category = "VariablesSystem", meta = (Keywords = "Copy Global value"))
	static void CopyGlobalStringArrayVariableValue(UGlobalStringArrayVariable* Variable, UGlobalStringArrayVariable* OtherVariable);

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
	TArray<FString> SavedValue;

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "VariablesSystem")
	TArray<FString> Value = {};
};
