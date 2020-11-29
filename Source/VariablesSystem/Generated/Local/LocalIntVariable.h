// Copyright Out-of-the-Box Plugins 2018-2020. All Rights Reserved.

#pragma once

#include "UObject/ObjectMacros.h"
#include "BaseVariable.h"
#include "LocalIntVariable.generated.h"

/**
 *
 */
UCLASS(BlueprintType)
class VARIABLESSYSTEM_API ULocalIntVariable : public UBaseVariable
{
	GENERATED_BODY()

public:
	TMap<UObject*, int32> variables;

	// Get the value of a LocalIntVariable variable.
	int32& GetLocalIntVariableRef(UObject* owner);
	
	// Get the value of a LocalIntVariable variable.
	UFUNCTION(BlueprintPure, Category = "Var System Local", meta = (BlueprintThreadSafe))
	static int32 GetLocalIntVariableValue(UObject* owner, ULocalIntVariable* var);

	// Set the value of a LocalIntVariable variable.
	UFUNCTION(BlueprintCallable, Category = "Var System Local")
	static void SetLocalIntVariableValue(UObject* owner, ULocalIntVariable* var, int32 _value);
	
	// Copy the value of a LocalIntVariable variable.
	UFUNCTION(BlueprintCallable, Category = "Var System Local")
	static void CopyLocalIntVariableValue(UObject* owner, ULocalIntVariable* var, UObject* otherOwner, ULocalIntVariable* other);

    virtual void Save() override;

    virtual void Load() override;

    virtual FString GetStringValue() const override;

private:
    FString GetValueAsString(int32 value) const;
};

