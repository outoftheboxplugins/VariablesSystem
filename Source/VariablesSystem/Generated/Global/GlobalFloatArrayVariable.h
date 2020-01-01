// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#pragma once

#include "UObject/Object.h"
#include "UObject/ObjectMacros.h"
#include "BaseVariable.h"
#include "GlobalFloatArrayVariable.generated.h"

/**
 *
 */

UCLASS(BlueprintType)
class VARIABLESSYSTEM_API UGlobalFloatArrayVariable : public UBaseVariable
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Var System")
	TArray<float> value;
	
	// Get the value of a TArray<float> variable.
	UFUNCTION(BlueprintPure, Category = "Var System", meta = (BlueprintThreadSafe))
	static TArray<float> GetGlobalFloatArrayVariableValue(UGlobalFloatArrayVariable* var);

	// Get the value of a TArray<float> variable.
	TArray<float> GetGlobalInternalFloatArrayVariableValue();

	// Set the value of a TArray<float> variable.
	UFUNCTION(BlueprintCallable, Category = "Var System")
	static void SetGlobalFloatArrayVariableValue(UGlobalFloatArrayVariable* var, TArray<float> _value);

	// Set the value of a TArray<float> variable.
	void SetGlobalInternalFloatArrayVariableValue(TArray<float> _value);
	
	// Copy the value of a TArray<float> variable.
	UFUNCTION(BlueprintCallable, Category = "Var System")
	static void CopyGlobalFloatArrayVariableValue(UGlobalFloatArrayVariable* var, UGlobalFloatArrayVariable* other);

	// Copy the value of a TArray<float> variable.
	void CopyGlobalInternalFloatArrayVariableValue(UGlobalFloatArrayVariable* other);

	/**** Base Variable Overrides ****/

	virtual void Save() override;

	virtual void Load() override;

    virtual FString GetStringValue() const override;
};
