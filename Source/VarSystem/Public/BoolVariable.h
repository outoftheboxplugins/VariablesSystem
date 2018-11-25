// Copyright Alexandru pasotee Oprea 2018. All Rights Reserved.

#pragma once

#include "UObject/Object.h"
#include "UObject/ObjectMacros.h"
#include "BaseVariable.h"
#include "BoolVariable.generated.h"

/**
 *
 */
UCLASS(BlueprintType)
class VARSYSTEM_API UBoolVariable : public UBaseVariable
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Var System")
		bool value;

	UFUNCTION(BlueprintPure, Category = "Var System")
		static bool GetBoolValue(UBoolVariable* var);

	UFUNCTION(BlueprintCallable, Category = "Var System")
		static void SetBoolValue(UBoolVariable* var, bool _value);

	UFUNCTION(BlueprintCallable, Category = "Var System")
		static void CopyBoolValue(UBoolVariable* var, UBoolVariable* other);

	/**** Base Variable Overrides ****/

	virtual void Save() override;

	virtual void Load() override;
};
