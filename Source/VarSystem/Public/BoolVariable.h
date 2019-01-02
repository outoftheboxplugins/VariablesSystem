// Copyright Alexandru pasotee Oprea 2018. All Rights Reserved.

#pragma once

#include "UObject/Object.h"
#include "UObject/ObjectMacros.h"
#include "BaseVariable.h"
#include "BoolVariable.generated.h"

/**
 *
 */
UCLASS(BlueprintType)
class VARSYSTEM_API UBoolVariable : public UBaseVariable
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Var System")
		bool value;

	// Get the value of a bool variable.
	UFUNCTION(BlueprintPure, Category = "Var System")
	static bool GetBoolValue(UBoolVariable* var);

	// Get the value of a bool variable.
	bool GetBoolValue();

	// Set the value of a bool variable.
	UFUNCTION(BlueprintCallable, Category = "Var System")
	static void SetBoolValue(UBoolVariable* var, bool _value);

	// Set the value of a bool variable.
	void SetBoolValue(bool _value);
	
	// Copy the value of a bool variable.
	UFUNCTION(BlueprintCallable, Category = "Var System")
	static void CopyBoolValue(UBoolVariable* var, UBoolVariable* other);

	// Copy the value of a bool variable.
	void CopyBoolValue(UBoolVariable* other);

	/**** Base Variable Overrides ****/

	virtual void Save() override;

	virtual void Load() override;
};
