// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#pragma once

#include "UObject/Object.h"
#include "UObject/ObjectMacros.h"
#include "BaseVariable.h"
#include "GlobalFVectorVariable.generated.h"

/**
 *
 */

UCLASS(BlueprintType)
class VARSYSTEM_API UGlobalFVectorVariable : public UBaseVariable
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Var System")
		FVector value;
	
	// Get the value of a FVector variable.
	UFUNCTION(BlueprintPure, Category = "Var System", meta = (BlueprintThreadSafe))
	static FVector GetGlobalFVectorValue(UGlobalFVectorVariable* var);

	// Get the value of a FVector variable.
	FVector GetGlobalInternalFVectorValue();

	// Set the value of a FVector variable.
	UFUNCTION(BlueprintCallable, Category = "Var System")
	static void SetGlobalFVectorValue(UGlobalFVectorVariable* var, FVector _value);

	// Set the value of a FVector variable.
	void SetGlobalInternalFVectorValue(FVector _value);
	
	// Copy the value of a FVector variable.
	UFUNCTION(BlueprintCallable, Category = "Var System")
	static void CopyGlobalFVectorValue(UGlobalFVectorVariable* var, UGlobalFVectorVariable* other);

	// Copy the value of a FVector variable.
	void CopyGlobalInternalFVectorValue(UGlobalFVectorVariable* other);

	/**** Base Variable Overrides ****/

	virtual void Save() override;

	virtual void Load() override;
};
