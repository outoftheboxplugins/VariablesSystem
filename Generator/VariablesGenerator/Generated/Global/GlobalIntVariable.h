// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#pragma once

#include "UObject/Object.h"
#include "UObject/ObjectMacros.h"
#include "BaseVariable.h"
#include "GlobalIntVariable.generated.h"

/**
 *
 */

UCLASS(BlueprintType)
class VARIABLESSYSTEM_API UGlobalIntVariable : public UBaseVariable
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Var System")
	int32 value;
	
	// Get the value of a int32 variable.
	UFUNCTION(BlueprintPure, Category = "Var System", meta = (BlueprintThreadSafe))
	static int32 GetGlobalIntVariableValue(UGlobalIntVariable* var);

	// Get the value of a int32 variable.
	int32 GetGlobalInternalIntVariableValue();

	// Set the value of a int32 variable.
	UFUNCTION(BlueprintCallable, Category = "Var System")
	static void SetGlobalIntVariableValue(UGlobalIntVariable* var, int32 _value);

	// Set the value of a int32 variable.
	void SetGlobalInternalIntVariableValue(int32 _value);
	
	// Copy the value of a int32 variable.
	UFUNCTION(BlueprintCallable, Category = "Var System")
	static void CopyGlobalIntVariableValue(UGlobalIntVariable* var, UGlobalIntVariable* other);

	// Copy the value of a int32 variable.
	void CopyGlobalInternalIntVariableValue(UGlobalIntVariable* other);

	/**** Base Variable Overrides ****/

	virtual void Save() override;

	virtual void Load() override;

    virtual FString GetStringValue() const override;
};
