// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#pragma once

#include "UObject/Object.h"
#include "UObject/ObjectMacros.h"
#include "BaseVariable.h"
#include "LocalFVector2DVariable.generated.h"

/**
 *
 */
UCLASS(BlueprintType)
class VARSYSTEM_API ULocalFVector2DVariable : public UBaseVariable
{
	GENERATED_BODY()

public:
	TMap<UObject*, FVector2D> variables;

	// Get the value of a LocalFVector2D variable.
	FVector2D& GetLocalFVector2DRef(UObject* owner);
	
	// Get the value of a LocalFVector2D variable.
	UFUNCTION(BlueprintPure, Category = "Var System Local", meta = (BlueprintThreadSafe))
	static FVector2D GetLocalFVector2D(UObject* owner, ULocalFVector2DVariable* var);

	// Set the value of a LocalFVector2D variable.
	UFUNCTION(BlueprintCallable, Category = "Var System Local")
	static void SetLocalFVector2DValue(UObject* owner, ULocalFVector2DVariable* var, FVector2D _value);
	
	// Copy the value of a LocalFVector2D variable.
	UFUNCTION(BlueprintCallable, Category = "Var System Local")
	static void CopyLocalFVector2DValue(UObject* owner, ULocalFVector2DVariable* var, UObject* otherOwner, ULocalFVector2DVariable* other);
};

