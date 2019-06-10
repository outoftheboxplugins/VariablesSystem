// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#pragma once

#include "UObject/Object.h"
#include "UObject/ObjectMacros.h"
#include "BaseVariable.h"
#include "LocalActorRefVariable.generated.h"

/**
 *
 */
UCLASS(BlueprintType)
class VARSYSTEM_API ULocalActorRefVariable : public UBaseVariable
{
	GENERATED_BODY()

public:
	TMap<UObject*, AActor*> variables;

	// Get the value of a LocalActorRef variable.
	AActor*& GetLocalActorRefRef(UObject* owner);
	
	// Get the value of a LocalActorRef variable.
	UFUNCTION(BlueprintPure, Category = "Var System Local", meta = (BlueprintThreadSafe))
	static AActor* GetLocalActorRef(UObject* owner, ULocalActorRefVariable* var);

	// Set the value of a LocalActorRef variable.
	UFUNCTION(BlueprintCallable, Category = "Var System Local")
	static void SetLocalActorRefValue(UObject* owner, ULocalActorRefVariable* var, AActor* _value);
	
	// Copy the value of a LocalActorRef variable.
	UFUNCTION(BlueprintCallable, Category = "Var System Local")
	static void CopyLocalActorRefValue(UObject* owner, ULocalActorRefVariable* var, UObject* otherOwner, ULocalActorRefVariable* other);
};

