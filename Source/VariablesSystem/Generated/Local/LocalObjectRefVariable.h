// Copyright Out-of-the-Box Plugins 2018-2020. All Rights Reserved.

#pragma once

#include "UObject/ObjectMacros.h"
#include "BaseVariable.h"
#include "LocalObjectRefVariable.generated.h"

/**
 *
 */
UCLASS(BlueprintType)
class VARIABLESSYSTEM_API ULocalObjectRefVariable : public UBaseVariable
{
	GENERATED_BODY()

public:
	TMap<UObject*, UObject*> variables;

	// Get the value of a LocalObjectRefVariable variable.
	UObject*& GetLocalObjectRefVariableRef(UObject* owner);
	
	// Get the value of a LocalObjectRefVariable variable.
	UFUNCTION(BlueprintPure, Category = "Var System Local", meta = (BlueprintThreadSafe))
	static UObject* GetLocalObjectRefVariableValue(UObject* owner, ULocalObjectRefVariable* var);

	// Set the value of a LocalObjectRefVariable variable.
	UFUNCTION(BlueprintCallable, Category = "Var System Local")
	static void SetLocalObjectRefVariableValue(UObject* owner, ULocalObjectRefVariable* var, UObject* _value);
	
	// Copy the value of a LocalObjectRefVariable variable.
	UFUNCTION(BlueprintCallable, Category = "Var System Local")
	static void CopyLocalObjectRefVariableValue(UObject* owner, ULocalObjectRefVariable* var, UObject* otherOwner, ULocalObjectRefVariable* other);

    virtual void Save() override;

    virtual void Load() override;

    virtual FString GetStringValue() const override;

private:
    FString GetValueAsString(UObject* value) const;
};

