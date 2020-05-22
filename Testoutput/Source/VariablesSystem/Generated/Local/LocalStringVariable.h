// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#pragma once

#include "UObject/ObjectMacros.h"
#include "BaseVariable.h"
#include "LocalStringVariable.generated.h"

/**
 *
 */
UCLASS(BlueprintType)
class VARIABLESSYSTEM_API ULocalStringVariable : public UBaseVariable
{
	GENERATED_BODY()

public:
	TMap<UObject*, FString> variables;

	// Get the value of a LocalStringVariable variable.
	FString& GetLocalStringVariableRef(UObject* owner);
	
	// Get the value of a LocalStringVariable variable.
	UFUNCTION(BlueprintPure, Category = "Var System Local", meta = (BlueprintThreadSafe))
	static FString GetLocalStringVariableValue(UObject* owner, ULocalStringVariable* var);

	// Set the value of a LocalStringVariable variable.
	UFUNCTION(BlueprintCallable, Category = "Var System Local")
	static void SetLocalStringVariableValue(UObject* owner, ULocalStringVariable* var, FString _value);
	
	// Copy the value of a LocalStringVariable variable.
	UFUNCTION(BlueprintCallable, Category = "Var System Local")
	static void CopyLocalStringVariableValue(UObject* owner, ULocalStringVariable* var, UObject* otherOwner, ULocalStringVariable* other);

    virtual void Save() override;

    virtual void Load() override;

    virtual FString GetStringValue() const override;

private:
    FString GetValueAsString(FString value) const;
};

