// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#pragma once

#include "UObject/ObjectMacros.h"
#include "BaseVariable.h"
#include "LocalActorRefVariable.generated.h"

/**
 *
 */
UCLASS(BlueprintType)
class VARIABLESSYSTEM_API ULocalActorRefVariable : public UBaseVariable
{
	GENERATED_BODY()

public:
	TMap<UObject*, AActor*> variables;

	// Get the value of a LocalActorRefVariable variable.
	AActor*& GetLocalActorRefVariableRef(UObject* owner);
	
	// Get the value of a LocalActorRefVariable variable.
	UFUNCTION(BlueprintPure, Category = "Var System Local", meta = (BlueprintThreadSafe))
	static AActor* GetLocalActorRefVariableValue(UObject* owner, ULocalActorRefVariable* var);

	// Set the value of a LocalActorRefVariable variable.
	UFUNCTION(BlueprintCallable, Category = "Var System Local")
	static void SetLocalActorRefVariableValue(UObject* owner, ULocalActorRefVariable* var, AActor* _value);
	
	// Copy the value of a LocalActorRefVariable variable.
	UFUNCTION(BlueprintCallable, Category = "Var System Local")
	static void CopyLocalActorRefVariableValue(UObject* owner, ULocalActorRefVariable* var, UObject* otherOwner, ULocalActorRefVariable* other);
};

