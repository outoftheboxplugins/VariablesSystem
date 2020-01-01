// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#pragma once

#include "UObject/Object.h"
#include "UObject/ObjectMacros.h"
#include "BaseVariable.h"
#include "GlobalStringArrayVariable.generated.h"

/**
 *
 */

UCLASS(BlueprintType)
class VARIABLESSYSTEM_API UGlobalStringArrayVariable : public UBaseVariable
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Var System")
	TArray<FString> value;
	
	// Get the value of a TArray<FString> variable.
	UFUNCTION(BlueprintPure, Category = "Var System", meta = (BlueprintThreadSafe))
	static TArray<FString> GetGlobalStringArrayVariableValue(UGlobalStringArrayVariable* var);

	// Get the value of a TArray<FString> variable.
	TArray<FString> GetGlobalInternalStringArrayVariableValue();

	// Set the value of a TArray<FString> variable.
	UFUNCTION(BlueprintCallable, Category = "Var System")
	static void SetGlobalStringArrayVariableValue(UGlobalStringArrayVariable* var, TArray<FString> _value);

	// Set the value of a TArray<FString> variable.
	void SetGlobalInternalStringArrayVariableValue(TArray<FString> _value);
	
	// Copy the value of a TArray<FString> variable.
	UFUNCTION(BlueprintCallable, Category = "Var System")
	static void CopyGlobalStringArrayVariableValue(UGlobalStringArrayVariable* var, UGlobalStringArrayVariable* other);

	// Copy the value of a TArray<FString> variable.
	void CopyGlobalInternalStringArrayVariableValue(UGlobalStringArrayVariable* other);

	/**** Base Variable Overrides ****/

	virtual void Save() override;

	virtual void Load() override;

    virtual FString GetStringValue() const override;
};
