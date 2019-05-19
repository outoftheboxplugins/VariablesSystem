// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#pragma once

#include "UObject/Object.h"
#include "UObject/ObjectMacros.h"
#include "BaseVariable.h"
#include "StringVariable.generated.h"

/**
 *
 */
UCLASS(BlueprintType)
class VARSYSTEM_API UStringVariable : public UBaseVariable
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Var System")
	FString value;

	// Get the value of a string variable.
	UFUNCTION(BlueprintPure, Category = "Var System", meta = (BlueprintThreadSafe))
	static FString GetStringValue(UStringVariable* var);

	// Get the value of a string variable.
	FString GetStringValue();

	// Set the value of a string variable.
	UFUNCTION(BlueprintCallable, Category = "Var System")
	static void SetStringValue(UStringVariable* var, FString _value);

	// Set the value of a string variable.
	void SetStringValue(FString _value);

	// Copy the value of a string variable.
	UFUNCTION(BlueprintCallable, Category = "Var System")
	static void CopyStringValue(UStringVariable* var, UStringVariable* other);

	// Copy the value of a string variable.
	void CopyStringValue(UStringVariable* other);

	/**** Base Variable Overrides ****/

	virtual void Save() override;

	virtual void Load() override;

};
