// Copyright Out-of-the-Box Plugins 2018-2020. All Rights Reserved.

#pragma once

#include "UObject/ObjectMacros.h"
#include "BaseVariable.h"
#include "LocalFRotatorVariable.generated.h"

/**
 *
 */
UCLASS(BlueprintType)
class VARIABLESSYSTEM_API ULocalFRotatorVariable : public UBaseVariable
{
	GENERATED_BODY()

public:
	TMap<UObject*, FRotator> variables;

	// Get the value of a LocalFRotatorVariable variable.
	FRotator& GetLocalFRotatorVariableRef(UObject* owner);
	
	// Get the value of a LocalFRotatorVariable variable.
	UFUNCTION(BlueprintPure, Category = "Var System Local", meta = (BlueprintThreadSafe))
	static FRotator GetLocalFRotatorVariableValue(UObject* owner, ULocalFRotatorVariable* var);

	// Set the value of a LocalFRotatorVariable variable.
	UFUNCTION(BlueprintCallable, Category = "Var System Local")
	static void SetLocalFRotatorVariableValue(UObject* owner, ULocalFRotatorVariable* var, FRotator _value);
	
	// Copy the value of a LocalFRotatorVariable variable.
	UFUNCTION(BlueprintCallable, Category = "Var System Local")
	static void CopyLocalFRotatorVariableValue(UObject* owner, ULocalFRotatorVariable* var, UObject* otherOwner, ULocalFRotatorVariable* other);

    virtual void Save() override;

    virtual void Load() override;

    virtual FString GetStringValue() const override;

private:
    FString GetValueAsString(FRotator value) const;
};

