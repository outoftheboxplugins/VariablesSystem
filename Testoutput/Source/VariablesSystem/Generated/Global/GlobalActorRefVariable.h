




















// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#pragma once

#include "UObject/Object.h"
#include "UObject/ObjectMacros.h"
#include "BaseVariable.h"
#include "GlobalActorRefVariable.generated.h"

/**
 *
 */

UCLASS(BlueprintType)
class VARIABLESSYSTEM_API UGlobalActorRefVariable : public UBaseVariable
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Var System")
	AActor* value;
	
	// Get the value of a AActor* variable.
	UFUNCTION(BlueprintPure, Category = "Var System", meta = (BlueprintThreadSafe))
	static AActor* GetGlobalActorRefVariableValue(UGlobalActorRefVariable* var);

	// Get the value of a AActor* variable.
	AActor* GetGlobalInternalActorRefVariableValue();

	// Set the value of a AActor* variable.
	UFUNCTION(BlueprintCallable, Category = "Var System")
	static void SetGlobalActorRefVariableValue(UGlobalActorRefVariable* var, AActor* _value);

	// Set the value of a AActor* variable.
	void SetGlobalInternalActorRefVariableValue(AActor* _value);
	
	// Copy the value of a AActor* variable.
	UFUNCTION(BlueprintCallable, Category = "Var System")
	static void CopyGlobalActorRefVariableValue(UGlobalActorRefVariable* var, UGlobalActorRefVariable* other);

	// Copy the value of a AActor* variable.
	void CopyGlobalInternalActorRefVariableValue(UGlobalActorRefVariable* other);

	/**** Base Variable Overrides ****/

	virtual void Save() override;

	virtual void Load() override;

    virtual FString GetStringValue() const override;
};
