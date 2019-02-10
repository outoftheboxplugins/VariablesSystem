// Copyright Alexandru pasotee Oprea 2018. All Rights Reserved.

#pragma once

#include "UObject/Object.h"
#include "UObject/ObjectMacros.h"
#include "BaseVariable.h"
#include "ActorRefVariable.generated.h"

/**
 *
 */
UCLASS(BlueprintType)
class VARSYSTEM_API UActorRefVariable : public UBaseVariable
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Var System")
	AActor* value;

	// Get the value of a AActor* variable.
	UFUNCTION(BlueprintPure, Category = "Var System")
	static AActor* GetAActorValue(UActorRefVariable* var);

	// Get the value of a AActor* variable.
	AActor* GetAActorValue();

	// Set the value of a AActor* variable.
	UFUNCTION(BlueprintCallable, Category = "Var System")
	static void SetAActorValue(UActorRefVariable* var, AActor* _value);

	// Set the value of a AActor* variable.
	void SetAActorValue(AActor* _value);
	
	// Copy the value of a AActor* variable.
	UFUNCTION(BlueprintCallable, Category = "Var System")
	static void CopyAActorValue(UActorRefVariable* var, UActorRefVariable* other);

	// Copy the value of a AActor* variable.
	void CopyAActorValue(UActorRefVariable* other);

	/**** Base Variable Overrides ****/

	virtual void Save() override;

	virtual void Load() override;
};
