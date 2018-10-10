// Fill out your copyright notice in the Description page of Project Settings.

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

	UFUNCTION(BlueprintPure, Category = "Var System")
		static FRotator GetFRotatorValue(UFRotatorVariable* var);

	UFUNCTION(BlueprintCallable, Category = "Var System")
		static void SetFRotatorValue(UFRotatorVariable* var, FRotator _value);

	UFUNCTION(BlueprintCallable, Category = "Var System")
		static void CopyFRotatorValue(UFRotatorVariable* var, UFRotatorVariable* other);

};
