














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
	static AActor* GetGlobalActorRefValue(UGlobalActorRefVariable* var);

	// Get the value of a AActor* variable.
	AActor* GetGlobalInternalActorRefValue();

	// Set the value of a AActor* variable.
	UFUNCTION(BlueprintCallable, Category = "Var System")
	static void SetGlobalActorRefValue(UGlobalActorRefVariable* var, AActor* _value);

	// Set the value of a AActor* variable.
	void SetGlobalInternalActorRefValue(AActor* _value);
	
	// Copy the value of a AActor* variable.
	UFUNCTION(BlueprintCallable, Category = "Var System")
	static void CopyGlobalActorRefValue(UGlobalActorRefVariable* var, UGlobalActorRefVariable* other);

	// Copy the value of a AActor* variable.
	void CopyGlobalInternalActorRefValue(UGlobalActorRefVariable* other);

	/**** Base Variable Overrides ****/

	virtual void Save() override;

	virtual void Load() override;

    virtual FString GetStringValue() const override;
};
