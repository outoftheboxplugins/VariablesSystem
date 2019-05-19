// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#pragma once

#include "UObject/Object.h"
#include "UObject/ObjectMacros.h"
#include "BaseVariable.h"
#include "IntVariable.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class VARSYSTEM_API UIntVariable : public UBaseVariable
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Var System")
	int32 value;
	
	// Get the value of a int variable.
	UFUNCTION(BlueprintPure, Category = "Var System", meta = (BlueprintThreadSafe))
	static int32 GetIntValue(UIntVariable* var);

	// Get the value of a int variable.
	int32 GetIntValue();

	// Set the value of a int variable.
	UFUNCTION(BlueprintCallable, Category = "Var System")
	static void SetIntValue(UIntVariable* var, int32 _value);
	
	// Set the value of a int variable.
	void SetIntValue(int32 _value);

	// Copy the value of a int variable.
	UFUNCTION(BlueprintCallable, Category = "Var System")
	static void CopyIntValue(UIntVariable* var, UIntVariable* other);
		
	// Copy the value of a int variable.
	void CopyIntValue(UIntVariable* other);

	/**** Base Variable Overrides ****/

	virtual void Save() override;

	virtual void Load() override;

};
