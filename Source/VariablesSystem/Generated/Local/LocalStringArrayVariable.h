// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#pragma once

#include "UObject/ObjectMacros.h"
#include "BaseVariable.h"
#include "LocalStringArrayVariable.generated.h"

/**
 *
 */
UCLASS(BlueprintType)
class VARIABLESSYSTEM_API ULocalStringArrayVariable : public UBaseVariable
{
	GENERATED_BODY()

public:
	TMap<UObject*, TArray<FString>> variables;

	// Get the value of a LocalStringArrayVariable variable.
	TArray<FString>& GetLocalStringArrayVariableRef(UObject* owner);
	
	// Get the value of a LocalStringArrayVariable variable.
	UFUNCTION(BlueprintPure, Category = "Var System Local", meta = (BlueprintThreadSafe))
	static TArray<FString> GetLocalStringArrayVariableValue(UObject* owner, ULocalStringArrayVariable* var);

	// Set the value of a LocalStringArrayVariable variable.
	UFUNCTION(BlueprintCallable, Category = "Var System Local")
	static void SetLocalStringArrayVariableValue(UObject* owner, ULocalStringArrayVariable* var, TArray<FString> _value);
	
	// Copy the value of a LocalStringArrayVariable variable.
	UFUNCTION(BlueprintCallable, Category = "Var System Local")
	static void CopyLocalStringArrayVariableValue(UObject* owner, ULocalStringArrayVariable* var, UObject* otherOwner, ULocalStringArrayVariable* other);

    virtual void Save() override;

    virtual void Load() override;

    virtual FString GetStringValue() const override;

private:
    FString GetValueAsString(TArray<FString> value) const;
};

