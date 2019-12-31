// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#pragma once

#include "UObject/ObjectMacros.h"
#include "BaseVariable.h"
#include "LocalFloatVariable.generated.h"

/**
 *
 */
UCLASS(BlueprintType)
class VARIABLESSYSTEM_API ULocalFloatVariable : public UBaseVariable
{
	GENERATED_BODY()

public:
	TMap<UObject*, float> variables;

	// Get the value of a LocalFloatVariable variable.
	float& GetLocalFloatVariableRef(UObject* owner);
	
	// Get the value of a LocalFloatVariable variable.
	UFUNCTION(BlueprintPure, Category = "Var System Local", meta = (BlueprintThreadSafe))
	static float GetLocalFloatVariableValue(UObject* owner, ULocalFloatVariable* var);

	// Set the value of a LocalFloatVariable variable.
	UFUNCTION(BlueprintCallable, Category = "Var System Local")
	static void SetLocalFloatVariableValue(UObject* owner, ULocalFloatVariable* var, float _value);
	
	// Copy the value of a LocalFloatVariable variable.
	UFUNCTION(BlueprintCallable, Category = "Var System Local")
	static void CopyLocalFloatVariableValue(UObject* owner, ULocalFloatVariable* var, UObject* otherOwner, ULocalFloatVariable* other);

    virtual void Save() override;

    virtual void Load() override;

    virtual FString GetStringValue() const override;
};

