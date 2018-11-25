// Copyright Alexandru pasotee Oprea 2018. All Rights Reserved.

#pragma once

#include "UObject/Object.h"
#include "UObject/ObjectMacros.h"
#include "BaseVariable.h"
#include "StringVariable.generated.h"

/**
 *
 */
UCLASS(BlueprintType)
class VARSYSTEM_API UStringVariable : public UBaseVariable
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Var System")
		FString value;

	UFUNCTION(BlueprintPure, Category = "Var System")
		static FString GetStringValue(UStringVariable* var);

	UFUNCTION(BlueprintCallable, Category = "Var System")
		static void SetStringValue(UStringVariable* var, FString _value);

	UFUNCTION(BlueprintCallable, Category = "Var System")
		static void CopyStringValue(UStringVariable* var, UStringVariable* other);

	/**** Base Variable Overrides ****/

	virtual void Save() override;

	virtual void Load() override;

};
