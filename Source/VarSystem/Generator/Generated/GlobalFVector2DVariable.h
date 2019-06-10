// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#pragma once

#include "UObject/Object.h"
#include "UObject/ObjectMacros.h"
#include "BaseVariable.h"
#include "GlobalFVector2DVariable.generated.h"

/**
 *
 */

UCLASS(BlueprintType)
class VARSYSTEM_API UGlobalFVector2DVariable : public UBaseVariable
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Var System")
		FVector2D value;
	
	// Get the value of a FVector2D variable.
	UFUNCTION(BlueprintPure, Category = "Var System", meta = (BlueprintThreadSafe))
	static FVector2D GetGlobalFVector2DValue(UGlobalFVector2DVariable* var);

	// Get the value of a FVector2D variable.
	FVector2D GetGlobalFVector2DValue();

	// Set the value of a FVector2D variable.
	UFUNCTION(BlueprintCallable, Category = "Var System")
	static void SetGlobalFVector2DValue(UGlobalFVector2DVariable* var, FVector2D _value);

	// Set the value of a FVector2D variable.
	void SetGlobalFVector2DValue(FVector2D _value);
	
	// Copy the value of a FVector2D variable.
	UFUNCTION(BlueprintCallable, Category = "Var System")
	static void CopyGlobalFVector2DValue(UGlobalFVector2DVariable* var, UGlobalFVector2DVariable* other);

	// Copy the value of a FVector2D variable.
	void CopyGlobalFVector2DValue(UGlobalFVector2DVariable* other);

	/**** Base Variable Overrides ****/

	virtual void Save() override;

	virtual void Load() override;
};
