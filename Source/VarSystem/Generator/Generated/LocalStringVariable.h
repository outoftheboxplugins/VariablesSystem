// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#pragma once

#include "UObject/ObjectMacros.h"
#include "BaseVariable.h"
#include "LocalStringVariable.generated.h"

/**
 *
 */
UCLASS(BlueprintType)
class VARSYSTEM_API ULocalStringVariable : public UBaseVariable
{
	GENERATED_BODY()

public:
	TMap<UObject*, FString> variables;

	// Get the value of a LocalString variable.
	FString& GetLocalStringRef(UObject* owner);
	
	// Get the value of a LocalString variable.
	UFUNCTION(BlueprintPure, Category = "Var System Local", meta = (BlueprintThreadSafe))
	static FString GetLocalString(UObject* owner, ULocalStringVariable* var);

	// Set the value of a LocalString variable.
	UFUNCTION(BlueprintCallable, Category = "Var System Local")
	static void SetLocalStringValue(UObject* owner, ULocalStringVariable* var, FString _value);
	
	// Copy the value of a LocalString variable.
	UFUNCTION(BlueprintCallable, Category = "Var System Local")
	static void CopyLocalStringValue(UObject* owner, ULocalStringVariable* var, UObject* otherOwner, ULocalStringVariable* other);
};

