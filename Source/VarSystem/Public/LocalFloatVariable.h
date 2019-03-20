// Copyright Alexandru pasotee Oprea 2018. All Rights Reserved.

#pragma once

#include "UObject/Object.h"
#include "UObject/ObjectMacros.h"
#include "BaseVariable.h"
#include "LocalFloatVariable.generated.h"

/**
 *
 */
UCLASS(BlueprintType)
class VARSYSTEM_API ULocalFloatVariable : public UBaseVariable
{
	GENERATED_BODY()

public:
	TMap<UObject*, float> variables;

	// Get the value of a LocalFloat variable.
	float& GetLocalFloatRef(UObject* owner);
	
	// Get the value of a LocalFloat variable.
	UFUNCTION(BlueprintPure, Category = "Var System Local")
	static float GetLocalFloat(UObject* owner, ULocalFloatVariable* var);

	// Set the value of a LocalFloat variable.
	UFUNCTION(BlueprintCallable, Category = "Var System Local")
	static void SetLocalFloatValue(UObject* owner, ULocalFloatVariable* var, float _value);
	
	// Copy the value of a LocalFloat variable.
	UFUNCTION(BlueprintCallable, Category = "Var System Local")
	static void CopyLocalFloatValue(UObject* owner, ULocalFloatVariable* var, UObject* otherOwner, ULocalFloatVariable* other);
};
