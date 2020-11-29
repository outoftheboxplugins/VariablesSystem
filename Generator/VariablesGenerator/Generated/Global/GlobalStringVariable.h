// Copyright Out-of-the-Box Plugins 2018-2020. All Rights Reserved.

#pragma once

#include "UObject/Object.h"
#include "UObject/ObjectMacros.h"
#include "BaseVariable.h"
#include "GlobalStringVariable.generated.h"

/**
 *
 */

UCLASS(BlueprintType)
class VARIABLESSYSTEM_API UGlobalStringVariable : public UBaseVariable
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Var System")
	FString value;
	
	// Get the value of a FString variable.
	UFUNCTION(BlueprintPure, Category = "Var System", meta = (BlueprintThreadSafe))
	static FString GetGlobalStringVariableValue(UGlobalStringVariable* var);

	// Get the value of a FString variable.
	FString GetGlobalInternalStringVariableValue();

	// Set the value of a FString variable.
	UFUNCTION(BlueprintCallable, Category = "Var System")
	static void SetGlobalStringVariableValue(UGlobalStringVariable* var, FString _value);

	// Set the value of a FString variable.
	void SetGlobalInternalStringVariableValue(FString _value);
	
	// Copy the value of a FString variable.
	UFUNCTION(BlueprintCallable, Category = "Var System")
	static void CopyGlobalStringVariableValue(UGlobalStringVariable* var, UGlobalStringVariable* other);

	// Copy the value of a FString variable.
	void CopyGlobalInternalStringVariableValue(UGlobalStringVariable* other);

	/**** Base Variable Overrides ****/

	virtual void Save() override;

	virtual void Load() override;

    virtual FString GetStringValue() const override;
};
