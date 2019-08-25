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
class VARSYSTEM_API UGlobalFloatVariable : public UBaseVariable
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Var System")
		float value;
	
	// Get the value of a float variable.
	UFUNCTION(BlueprintPure, Category = "Var System", meta = (BlueprintThreadSafe))
	static float GetGlobalFloatValue(UGlobalFloatVariable* var);

	// Get the value of a float variable.
	float GetGlobalInternalFloatValue();

	// Set the value of a float variable.
	UFUNCTION(BlueprintCallable, Category = "Var System")
	static void SetGlobalFloatValue(UGlobalFloatVariable* var, float _value);

	// Set the value of a float variable.
	void SetGlobalInternalFloatValue(float _value);
	
	// Copy the value of a float variable.
	UFUNCTION(BlueprintCallable, Category = "Var System")
	static void CopyGlobalFloatValue(UGlobalFloatVariable* var, UGlobalFloatVariable* other);

	// Copy the value of a float variable.
	void CopyGlobalInternalFloatValue(UGlobalFloatVariable* other);

	/**** Base Variable Overrides ****/

	virtual void Save() override;

	virtual void Load() override;
};
