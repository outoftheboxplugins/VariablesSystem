// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#pragma once

#include "UObject/ObjectMacros.h"
#include "BaseVariable.h"
#include "LocalFVector2DVariable.generated.h"

/**
 *
 */
UCLASS(BlueprintType)
class VARIABLESSYSTEM_API ULocalFVector2DVariable : public UBaseVariable
{
	GENERATED_BODY()

public:
	TMap<UObject*, FVector2D> variables;

	// Get the value of a LocalFVector2DVariable variable.
	FVector2D& GetLocalFVector2DVariableRef(UObject* owner);
	
	// Get the value of a LocalFVector2DVariable variable.
	UFUNCTION(BlueprintPure, Category = "Var System Local", meta = (BlueprintThreadSafe))
	static FVector2D GetLocalFVector2DVariable(UObject* owner, ULocalFVector2DVariable* var);

	// Set the value of a LocalFVector2DVariable variable.
	UFUNCTION(BlueprintCallable, Category = "Var System Local")
	static void SetLocalFVector2DVariableValue(UObject* owner, ULocalFVector2DVariable* var, FVector2D _value);
	
	// Copy the value of a LocalFVector2DVariable variable.
	UFUNCTION(BlueprintCallable, Category = "Var System Local")
	static void CopyLocalFVector2DVariableValue(UObject* owner, ULocalFVector2DVariable* var, UObject* otherOwner, ULocalFVector2DVariable* other);
};

