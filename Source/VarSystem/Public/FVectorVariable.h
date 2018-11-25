// Copyright Alexandru pasotee Oprea 2018. All Rights Reserved.

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

	UFUNCTION(BlueprintPure, Category = "Var System")
		static FVector GetFVectorValue(UFVectorVariable* var);

	UFUNCTION(BlueprintCallable, Category = "Var System")
		static void SetFVectorValue(UFVectorVariable* var, FVector _value);

	UFUNCTION(BlueprintCallable, Category = "Var System")
		static void CopyFVectorValue(UFVectorVariable* var, UFVectorVariable* other);

	/**** Base Variable Overrides ****/

	virtual void Save() override;

	virtual void Load() override;

};
