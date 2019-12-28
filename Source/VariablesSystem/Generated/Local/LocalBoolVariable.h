// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#pragma once

#include "UObject/ObjectMacros.h"
#include "BaseVariable.h"
#include "LocalBoolVariable.generated.h"

/**
 *
 */
UCLASS(BlueprintType)
class VARIABLESSYSTEM_API ULocalBoolVariable : public UBaseVariable
{
	GENERATED_BODY()

public:
	TMap<UObject*, bool> variables;

	// Get the value of a LocalBoolVariable variable.
	bool& GetLocalBoolVariableRef(UObject* owner);
	
	// Get the value of a LocalBoolVariable variable.
	UFUNCTION(BlueprintPure, Category = "Var System Local", meta = (BlueprintThreadSafe))
	static bool GetLocalBoolVariable(UObject* owner, ULocalBoolVariable* var);

	// Set the value of a LocalBoolVariable variable.
	UFUNCTION(BlueprintCallable, Category = "Var System Local")
	static void SetLocalBoolVariableValue(UObject* owner, ULocalBoolVariable* var, bool _value);
	
	// Copy the value of a LocalBoolVariable variable.
	UFUNCTION(BlueprintCallable, Category = "Var System Local")
	static void CopyLocalBoolVariableValue(UObject* owner, ULocalBoolVariable* var, UObject* otherOwner, ULocalBoolVariable* other);
};

