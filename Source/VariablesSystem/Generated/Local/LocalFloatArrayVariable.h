// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#pragma once

#include "UObject/ObjectMacros.h"
#include "BaseVariable.h"
#include "LocalFloatArrayVariable.generated.h"

/**
 *
 */
UCLASS(BlueprintType)
class VARIABLESSYSTEM_API ULocalFloatArrayVariable : public UBaseVariable
{
	GENERATED_BODY()

public:
	TMap<UObject*, TArray<float>> variables;

	// Get the value of a LocalFloatArrayVariable variable.
	TArray<float>& GetLocalFloatArrayVariableRef(UObject* owner);
	
	// Get the value of a LocalFloatArrayVariable variable.
	UFUNCTION(BlueprintPure, Category = "Var System Local", meta = (BlueprintThreadSafe))
	static TArray<float> GetLocalFloatArrayVariableValue(UObject* owner, ULocalFloatArrayVariable* var);

	// Set the value of a LocalFloatArrayVariable variable.
	UFUNCTION(BlueprintCallable, Category = "Var System Local")
	static void SetLocalFloatArrayVariableValue(UObject* owner, ULocalFloatArrayVariable* var, TArray<float> _value);
	
	// Copy the value of a LocalFloatArrayVariable variable.
	UFUNCTION(BlueprintCallable, Category = "Var System Local")
	static void CopyLocalFloatArrayVariableValue(UObject* owner, ULocalFloatArrayVariable* var, UObject* otherOwner, ULocalFloatArrayVariable* other);

    virtual void Save() override;

    virtual void Load() override;

    virtual FString GetStringValue() const override;

private:
    FString GetValueAsString(TArray<float> value) const;
};

