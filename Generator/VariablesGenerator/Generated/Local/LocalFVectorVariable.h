// Copyright Out-of-the-Box Plugins 2018-2020. All Rights Reserved.

#pragma once

#include "UObject/ObjectMacros.h"
#include "BaseVariable.h"
#include "LocalFVectorVariable.generated.h"

/**
 *
 */
UCLASS(BlueprintType)
class VARIABLESSYSTEM_API ULocalFVectorVariable : public UBaseVariable
{
	GENERATED_BODY()

public:
	TMap<UObject*, FVector> variables;

	// Get the value of a LocalFVectorVariable variable.
	FVector& GetLocalFVectorVariableRef(UObject* owner);
	
	// Get the value of a LocalFVectorVariable variable.
	UFUNCTION(BlueprintPure, Category = "Var System Local", meta = (BlueprintThreadSafe))
	static FVector GetLocalFVectorVariableValue(UObject* owner, ULocalFVectorVariable* var);

	// Set the value of a LocalFVectorVariable variable.
	UFUNCTION(BlueprintCallable, Category = "Var System Local")
	static void SetLocalFVectorVariableValue(UObject* owner, ULocalFVectorVariable* var, FVector _value);
	
	// Copy the value of a LocalFVectorVariable variable.
	UFUNCTION(BlueprintCallable, Category = "Var System Local")
	static void CopyLocalFVectorVariableValue(UObject* owner, ULocalFVectorVariable* var, UObject* otherOwner, ULocalFVectorVariable* other);

    virtual void Save() override;

    virtual void Load() override;

    virtual FString GetStringValue() const override;

private:
    FString GetValueAsString(FVector value) const;
};

