// Copyright Out-of-the-Box Plugins 2018-2020. All Rights Reserved.

#pragma once

#include "UObject/Object.h"
#include "UObject/ObjectMacros.h"
#include "BaseVariable.h"
#include "GlobalBoolVariable.generated.h"

/**
 *
 */

UCLASS(BlueprintType)
class VARIABLESSYSTEM_API UGlobalBoolVariable : public UBaseVariable
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Var System")
	bool value;
	
	// Get the value of a bool variable.
	UFUNCTION(BlueprintPure, Category = "Var System", meta = (BlueprintThreadSafe))
	static bool GetGlobalBoolVariableValue(UGlobalBoolVariable* var);

	// Get the value of a bool variable.
	bool GetGlobalInternalBoolVariableValue();

	// Set the value of a bool variable.
	UFUNCTION(BlueprintCallable, Category = "Var System")
	static void SetGlobalBoolVariableValue(UGlobalBoolVariable* var, bool _value);

	// Set the value of a bool variable.
	void SetGlobalInternalBoolVariableValue(bool _value);
	
	// Copy the value of a bool variable.
	UFUNCTION(BlueprintCallable, Category = "Var System")
	static void CopyGlobalBoolVariableValue(UGlobalBoolVariable* var, UGlobalBoolVariable* other);

	// Copy the value of a bool variable.
	void CopyGlobalInternalBoolVariableValue(UGlobalBoolVariable* other);

	/**** Base Variable Overrides ****/

	virtual void Save() override;

	virtual void Load() override;

    virtual FString GetStringValue() const override;
};
