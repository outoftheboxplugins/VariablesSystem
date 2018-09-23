// Fill out your copyright notice in the Description page of Project Settings.

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
		static float GetValue(UFloatVariable* var);

	UFUNCTION(BlueprintCallable, Category = "Var System")
		static void SetValue(UFloatVariable* var, float _value);

	UFUNCTION(BlueprintCallable, Category = "Var System")
		static void CopyValue(UFloatVariable* var, UFloatVariable* other);

};
