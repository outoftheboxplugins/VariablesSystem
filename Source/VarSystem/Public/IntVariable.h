// Copyright Alexandru pasotee Oprea 2018. All Rights Reserved.

#pragma once

#include "UObject/Object.h"
#include "UObject/ObjectMacros.h"
#include "BaseVariable.h"
#include "IntVariable.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class VARSYSTEM_API UIntVariable : public UBaseVariable
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Var System")
	int32 value;
	
	UFUNCTION(BlueprintPure, Category = "Var System")
		static int32 GetIntValue(UIntVariable* var);

	UFUNCTION(BlueprintCallable, Category = "Var System")
		static void SetIntValue(UIntVariable* var, int32 _value);

	UFUNCTION(BlueprintCallable, Category = "Var System")
		static void CopyIntValue(UIntVariable* var, UIntVariable* other);

};
