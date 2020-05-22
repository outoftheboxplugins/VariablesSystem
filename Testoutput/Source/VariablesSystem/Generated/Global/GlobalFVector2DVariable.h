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
class VARIABLESSYSTEM_API UGlobalFVector2DVariable : public UBaseVariable
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Var System")
	FVector2D value;
	
	// Get the value of a FVector2D variable.
	UFUNCTION(BlueprintPure, Category = "Var System", meta = (BlueprintThreadSafe))
	static FVector2D GetGlobalFVector2DVariableValue(UGlobalFVector2DVariable* var);

	// Get the value of a FVector2D variable.
	FVector2D GetGlobalInternalFVector2DVariableValue();

	// Set the value of a FVector2D variable.
	UFUNCTION(BlueprintCallable, Category = "Var System")
	static void SetGlobalFVector2DVariableValue(UGlobalFVector2DVariable* var, FVector2D _value);

	// Set the value of a FVector2D variable.
	void SetGlobalInternalFVector2DVariableValue(FVector2D _value);
	
	// Copy the value of a FVector2D variable.
	UFUNCTION(BlueprintCallable, Category = "Var System")
	static void CopyGlobalFVector2DVariableValue(UGlobalFVector2DVariable* var, UGlobalFVector2DVariable* other);

	// Copy the value of a FVector2D variable.
	void CopyGlobalInternalFVector2DVariableValue(UGlobalFVector2DVariable* other);

	/**** Base Variable Overrides ****/

	virtual void Save() override;

	virtual void Load() override;

    virtual FString GetStringValue() const override;
};
