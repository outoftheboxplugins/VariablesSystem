




















// Copyright Out-of-the-Box Plugins 2018-2020. All Rights Reserved.

#pragma once

#include "UObject/Object.h"
#include "UObject/ObjectMacros.h"
#include "BaseVariable.h"
#include "GlobalObjectRefVariable.generated.h"

/**
 *
 */

UCLASS(BlueprintType)
class VARIABLESSYSTEM_API UGlobalObjectRefVariable : public UBaseVariable
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Var System")
	UObject* value;
	
	// Get the value of a UObject* variable.
	UFUNCTION(BlueprintPure, Category = "Var System", meta = (BlueprintThreadSafe))
	static UObject* GetGlobalObjectRefVariableValue(UGlobalObjectRefVariable* var);

	// Get the value of a UObject* variable.
	UObject* GetGlobalInternalObjectRefVariableValue();

	// Set the value of a UObject* variable.
	UFUNCTION(BlueprintCallable, Category = "Var System")
	static void SetGlobalObjectRefVariableValue(UGlobalObjectRefVariable* var, UObject* _value);

	// Set the value of a UObject* variable.
	void SetGlobalInternalObjectRefVariableValue(UObject* _value);
	
	// Copy the value of a UObject* variable.
	UFUNCTION(BlueprintCallable, Category = "Var System")
	static void CopyGlobalObjectRefVariableValue(UGlobalObjectRefVariable* var, UGlobalObjectRefVariable* other);

	// Copy the value of a UObject* variable.
	void CopyGlobalInternalObjectRefVariableValue(UGlobalObjectRefVariable* other);

	/**** Base Variable Overrides ****/

	virtual void Save() override;

	virtual void Load() override;

    virtual FString GetStringValue() const override;
};
