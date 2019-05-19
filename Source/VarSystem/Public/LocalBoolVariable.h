// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#pragma once

#include "UObject/Object.h"
#include "UObject/ObjectMacros.h"
#include "BaseVariable.h"
#include "LocalBoolVariable.generated.h"

/**
 *
 */
UCLASS(BlueprintType)
class VARSYSTEM_API ULocalBoolVariable : public UBaseVariable
{
	GENERATED_BODY()

public:
	TMap<UObject*, bool> variables;

	// Get the value of a LocalBool variable.
	bool& GetLocalBoolRef(UObject* owner);
	
	// Get the value of a LocalBool variable.
	UFUNCTION(BlueprintPure, Category = "Var System Local", meta = (BlueprintThreadSafe))
	static bool GetLocalBool(UObject* owner, ULocalBoolVariable* var);

	// Set the value of a LocalBool variable.
	UFUNCTION(BlueprintCallable, Category = "Var System Local")
	static void SetLocalBoolValue(UObject* owner, ULocalBoolVariable* var, bool _value);
	
	// Copy the value of a LocalBool variable.
	UFUNCTION(BlueprintCallable, Category = "Var System Local")
	static void CopyLocalBoolValue(UObject* owner, ULocalBoolVariable* var, UObject* otherOwner, ULocalBoolVariable* other);
};
