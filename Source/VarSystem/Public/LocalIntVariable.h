// Copyright Alexandru pasotee Oprea 2018. All Rights Reserved.

#pragma once

#include "UObject/Object.h"
#include "UObject/ObjectMacros.h"
#include "BaseVariable.h"
#include "LocalIntVariable.generated.h"

/**
 *
 */
UCLASS(BlueprintType)
class VARSYSTEM_API ULocalIntVariable : public UBaseVariable
{
	GENERATED_BODY()

public:
	TMap<UObject*, int32> variables;

	// Get the value of a LocalInt variable.
	int32& GetLocalIntRef(UObject* owner);
	
	// Get the value of a LocalInt variable.
	UFUNCTION(BlueprintPure, Category = "Var System Local")
	static int32 GetLocalInt(UObject* owner, ULocalIntVariable* var);

	// Set the value of a LocalInt variable.
	UFUNCTION(BlueprintCallable, Category = "Var System Local")
	static void SetLocalIntValue(UObject* owner, ULocalIntVariable* var, int32 _value);
	
	// Copy the value of a LocalInt variable.
	UFUNCTION(BlueprintCallable, Category = "Var System Local")
	static void CopyLocalIntValue(UObject* owner, ULocalIntVariable* var, UObject* otherOwner, ULocalIntVariable* other);
};
