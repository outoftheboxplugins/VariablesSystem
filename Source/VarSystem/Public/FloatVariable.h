// Copyright Alexandru pasotee Oprea 2018. All Rights Reserved.

#pragma once

#include "UObject/Object.h"
#include "UObject/ObjectMacros.h"
#include "BaseVariable.h"
#include "FloatVariable.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class VARSYSTEM_API UFloatVariable : public UBaseVariable
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Var System")
	float value;
	
	UFUNCTION(BlueprintPure, Category = "Var System")
		static float GetFloatValue(UFloatVariable* var);

	UFUNCTION(BlueprintCallable, Category = "Var System")
		static void SetFloatValue(UFloatVariable* var, float _value);

	UFUNCTION(BlueprintCallable, Category = "Var System")
		static void CopyFloatValue(UFloatVariable* var, UFloatVariable* other);

	/**** Base Variable Overrides ****/

	virtual void Save() override;

	virtual void Load() override;

};
