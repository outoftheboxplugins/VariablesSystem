// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#pragma once

#include "UObject/Object.h"
#include "UObject/ObjectMacros.h"
#include "BaseVariable.h"
#include "GlobalFRotatorVariable.generated.h"

/**
 *
 */

UCLASS(BlueprintType)
class VARIABLESSYSTEM_API UGlobalFRotatorVariable : public UBaseVariable
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Var System")
	FRotator value;
	
	// Get the value of a FRotator variable.
	UFUNCTION(BlueprintPure, Category = "Var System", meta = (BlueprintThreadSafe))
	static FRotator GetGlobalFRotatorValue(UGlobalFRotatorVariable* var);

	// Get the value of a FRotator variable.
	FRotator GetGlobalInternalFRotatorValue();

	// Set the value of a FRotator variable.
	UFUNCTION(BlueprintCallable, Category = "Var System")
	static void SetGlobalFRotatorValue(UGlobalFRotatorVariable* var, FRotator _value);

	// Set the value of a FRotator variable.
	void SetGlobalInternalFRotatorValue(FRotator _value);
	
	// Copy the value of a FRotator variable.
	UFUNCTION(BlueprintCallable, Category = "Var System")
	static void CopyGlobalFRotatorValue(UGlobalFRotatorVariable* var, UGlobalFRotatorVariable* other);

	// Copy the value of a FRotator variable.
	void CopyGlobalInternalFRotatorValue(UGlobalFRotatorVariable* other);

	/**** Base Variable Overrides ****/

	virtual void Save() override;

	virtual void Load() override;

    virtual FString GetStringValue() const override;
};
