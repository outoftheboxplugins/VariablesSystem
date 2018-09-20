// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UObject/Object.h"
#include "UObject/ObjectMacros.h"
#include "Engine/DataAsset.h"
#include "IntVariable.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class VARSYSTEM_API UIntVariable : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Var System")
	int32 value;
	
	UFUNCTION(BlueprintPure, Category = "Var System")
		static int32 GetValue(UIntVariable* var);

	UFUNCTION(BlueprintCallable, Category = "Var System")
		static void SetValue(UIntVariable* var, int32 _value);

	UFUNCTION(BlueprintCallable, Category = "Var System")
		static void CopyValue(UIntVariable* var, UIntVariable* other);

};
