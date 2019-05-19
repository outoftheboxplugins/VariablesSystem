// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#pragma once

#include "UObject/Object.h"
#include "UObject/ObjectMacros.h"
#include "BaseVariable.h"
#include "LocalFRotatorVariable.generated.h"

/**
 *
 */
UCLASS(BlueprintType)
class VARSYSTEM_API ULocalFRotatorVariable : public UBaseVariable
{
	GENERATED_BODY()

public:
	TMap<UObject*, FRotator> variables;

	// Get the value of a LocalFRotator variable.
	FRotator& GetLocalFRotatorRef(UObject* owner);
	
	// Get the value of a LocalFRotator variable.
	UFUNCTION(BlueprintPure, Category = "Var System Local", meta = (BlueprintThreadSafe))
	static FRotator GetLocalFRotator(UObject* owner, ULocalFRotatorVariable* var);

	// Set the value of a LocalFRotator variable.
	UFUNCTION(BlueprintCallable, Category = "Var System Local")
	static void SetLocalFRotatorValue(UObject* owner, ULocalFRotatorVariable* var, FRotator _value);
	
	// Copy the value of a LocalFRotator variable.
	UFUNCTION(BlueprintCallable, Category = "Var System Local")
	static void CopyLocalFRotatorValue(UObject* owner, ULocalFRotatorVariable* var, UObject* otherOwner, ULocalFRotatorVariable* other);
};
