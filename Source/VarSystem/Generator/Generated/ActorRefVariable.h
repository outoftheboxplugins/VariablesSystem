

// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

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
	UFUNCTION(BlueprintPure, Category = "Var System", meta = (BlueprintThreadSafe))
	static AActor* GetActorRefValue(UActorRefVariable* var);

	// Get the value of a AActor* variable.
	AActor* GetActorRefValue();

	// Set the value of a AActor* variable.
	UFUNCTION(BlueprintCallable, Category = "Var System")
	static void SetActorRefValue(UActorRefVariable* var, AActor* _value);

	// Set the value of a AActor* variable.
	void SetActorRefValue(AActor* _value);
	
	// Copy the value of a AActor* variable.
	UFUNCTION(BlueprintCallable, Category = "Var System")
	static void CopyActorRefValue(UActorRefVariable* var, UActorRefVariable* other);

	// Copy the value of a AActor* variable.
	void CopyActorRefValue(UActorRefVariable* other);

	/**** Base Variable Overrides ****/

	virtual void Save() override;

	virtual void Load() override;
};
