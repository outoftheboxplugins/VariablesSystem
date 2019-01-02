// Copyright Alexandru pasotee Oprea 2018. All Rights Reserved.

#pragma once

#include "UObject/Object.h"
#include "UObject/ObjectMacros.h"
#include "BaseVariable.h"
#include "FloatVariable.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class VARSYSTEM_API UFloatVariable : public UBaseVariable
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Var System")
	float value;
	
	// Get the value of a float variable.
	UFUNCTION(BlueprintPure, Category = "Var System")
	static float GetFloatValue(UFloatVariable* var);

	// Get the value of a float variable.
	float GetFloatValue();

	// Set the value of a float variable.
	UFUNCTION(BlueprintCallable, Category = "Var System")
	static void SetFloatValue(UFloatVariable* var, float _value);

	// Set the value of a float variable.
	void SetFloatValue(float _value);

	// Copy the value of a float variable.
	UFUNCTION(BlueprintCallable, Category = "Var System")
	static void CopyFloatValue(UFloatVariable* var, UFloatVariable* other);

	// Copy the value of a float variable.
	void CopyFloatValue(UFloatVariable* other);

	/**** Base Variable Overrides ****/

	virtual void Save() override;

	virtual void Load() override;

};
