// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#pragma once

#include "UObject/Object.h"
#include "UObject/ObjectMacros.h"
#include "BaseVariable.h"
#include "LocalFVectorVariable.generated.h"

/**
 *
 */
UCLASS(BlueprintType)
class VARSYSTEM_API ULocalFVectorVariable : public UBaseVariable
{
	GENERATED_BODY()

public:
	TMap<UObject*, FVector> variables;

	// Get the value of a LocalFVector variable.
	FVector& GetLocalFVectorRef(UObject* owner);
	
	// Get the value of a LocalFVector variable.
	UFUNCTION(BlueprintPure, Category = "Var System Local", meta = (BlueprintThreadSafe))
	static FVector GetLocalFVector(UObject* owner, ULocalFVectorVariable* var);

	// Set the value of a LocalFVector variable.
	UFUNCTION(BlueprintCallable, Category = "Var System Local")
	static void SetLocalFVectorValue(UObject* owner, ULocalFVectorVariable* var, FVector _value);
	
	// Copy the value of a LocalFVector variable.
	UFUNCTION(BlueprintCallable, Category = "Var System Local")
	static void CopyLocalFVectorValue(UObject* owner, ULocalFVectorVariable* var, UObject* otherOwner, ULocalFVectorVariable* other);
};
