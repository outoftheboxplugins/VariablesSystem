// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#pragma once

#include "UObject/Object.h"
#include "UObject/ObjectMacros.h"
#include "BaseVariable.h"
#include "GlobalFloatVariable.generated.h"

/**
 *
 */

UCLASS(BlueprintType)
class VARIABLESSYSTEM_API UGlobalFloatVariable : public UBaseVariable
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Var System")
	float value;
	
	// Get the value of a float variable.
	UFUNCTION(BlueprintPure, Category = "Var System", meta = (BlueprintThreadSafe))
	static float GetGlobalFloatVariableValue(UGlobalFloatVariable* var);

	// Get the value of a float variable.
	float GetGlobalInternalFloatVariableValue();

	// Set the value of a float variable.
	UFUNCTION(BlueprintCallable, Category = "Var System")
	static void SetGlobalFloatVariableValue(UGlobalFloatVariable* var, float _value);

	// Set the value of a float variable.
	void SetGlobalInternalFloatVariableValue(float _value);
	
	// Copy the value of a float variable.
	UFUNCTION(BlueprintCallable, Category = "Var System")
	static void CopyGlobalFloatVariableValue(UGlobalFloatVariable* var, UGlobalFloatVariable* other);

	// Copy the value of a float variable.
	void CopyGlobalInternalFloatVariableValue(UGlobalFloatVariable* other);

	/**** Base Variable Overrides ****/

	virtual void Save() override;

	virtual void Load() override;

    virtual FString GetStringValue() const override;
};
