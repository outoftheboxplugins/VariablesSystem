// Copyright Alexandru pasotee Oprea 2018. All Rights Reserved.

#pragma once

#include "UObject/Object.h"
#include "UObject/ObjectMacros.h"
#include "BaseVariable.h"
#include "LocalStringVariable.generated.h"

/**
 *
 */
UCLASS(BlueprintType)
class VARSYSTEM_API ULocalFStringVariable : public UBaseVariable
{
	GENERATED_BODY()

public:
	TMap<UObject*, FString> variables;

	// Get the value of a LocalFString variable.
	FString& GetLocalFStringRef(UObject* owner);
	
	// Get the value of a LocalFString variable.
	UFUNCTION(BlueprintPure, Category = "Var System Local")
	static FString GetLocalFString(UObject* owner, ULocalFStringVariable* var);

	// Set the value of a LocalFString variable.
	UFUNCTION(BlueprintCallable, Category = "Var System Local")
	static void SetLocalFStringValue(UObject* owner, ULocalFStringVariable* var, FString _value);
	
	// Copy the value of a LocalFString variable.
	UFUNCTION(BlueprintCallable, Category = "Var System Local")
	static void CopyLocalFStringValue(UObject* owner, ULocalFStringVariable* var, UObject* otherOwner, ULocalFStringVariable* other);
};
