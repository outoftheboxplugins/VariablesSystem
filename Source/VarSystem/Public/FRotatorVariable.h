// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#pragma once

#include "UObject/Object.h"
#include "UObject/ObjectMacros.h"
#include "BaseVariable.h"
#include "FRotatorVariable.generated.h"

/**
 *
 */
UCLASS(BlueprintType)
class VARSYSTEM_API UFRotatorVariable : public UBaseVariable
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Var System")
	FRotator value;

	// Get the value of a FRotator variable.
	UFUNCTION(BlueprintPure, Category = "Var System", meta = (BlueprintThreadSafe))
	static FRotator GetFRotatorValue(UFRotatorVariable* var);

	// Get the value of a FRotator variable.
	FRotator GetFRotatorValue();

	// Set the value of a FRotator variable.
	UFUNCTION(BlueprintCallable, Category = "Var System")
	static void SetFRotatorValue(UFRotatorVariable* var, FRotator _value);

	// Set the value of a FRotator variable.
	void SetFRotatorValue(FRotator _value);

	// Copy the value of a FRotator variable.
	UFUNCTION(BlueprintCallable, Category = "Var System")
	static void CopyFRotatorValue(UFRotatorVariable* var, UFRotatorVariable* other);

	// Copy the value of a FRotator variable.
	void CopyFRotatorValue(UFRotatorVariable* other);

	/**** Base Variable Overrides ****/

	virtual void Save() override;

	virtual void Load() override;

};
