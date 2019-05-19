// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#pragma once

#include "UObject/Object.h"
#include "UObject/ObjectMacros.h"
#include "BaseVariable.h"

#include "FVectorVariable.generated.h"

/**
 *
 */

UCLASS(BlueprintType)
class VARSYSTEM_API UFVectorVariable : public UBaseVariable
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Var System")
		FVector value;

	// Get the value of a FVector variable.
	UFUNCTION(BlueprintPure, Category = "Var System", meta = (BlueprintThreadSafe))
	static FVector GetFVectorValue(UFVectorVariable* var);

	// Get the value of a FVector variable.
	FVector GetFVectorValue();
	
	// Set the value of a FVector variable.
	UFUNCTION(BlueprintCallable, Category = "Var System")
	static void SetFVectorValue(UFVectorVariable* var, FVector _value);

	// Set the value of a FVector variable.
	void SetFVectorValue(FVector _value);

	// Copy the value of a FVector variable.
	UFUNCTION(BlueprintCallable, Category = "Var System")
	static void CopyFVectorValue(UFVectorVariable* var, UFVectorVariable* other);

	// Copy the value of a FVector variable.
	void CopyFVectorValue(UFVectorVariable* other);

	/**** Base Variable Overrides ****/

	virtual void Save() override;

	virtual void Load() override;

};
