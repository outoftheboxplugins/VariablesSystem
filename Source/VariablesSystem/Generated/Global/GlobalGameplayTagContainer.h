// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#pragma once

#include "UObject/Object.h"
#include "UObject/ObjectMacros.h"
#include "BaseVariable.h"
#include "GlobalGameplayTagContainer.generated.h"

/**
 *
 */

UCLASS(BlueprintType)
class VARIABLESSYSTEM_API UGlobalGameplayTagContainer : public UBaseVariable
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Var System")
	FGameplayTagContainer value;
	
	// Get the value of a FGameplayTagContainer variable.
	UFUNCTION(BlueprintPure, Category = "Var System", meta = (BlueprintThreadSafe))
	static FGameplayTagContainer GetGlobalGameplayTagContainerValue(UGlobalGameplayTagContainer* var);

	// Get the value of a FGameplayTagContainer variable.
	FGameplayTagContainer GetGlobalInternalGameplayTagContainerValue();

	// Set the value of a FGameplayTagContainer variable.
	UFUNCTION(BlueprintCallable, Category = "Var System")
	static void SetGlobalGameplayTagContainerValue(UGlobalGameplayTagContainer* var, FGameplayTagContainer _value);

	// Set the value of a FGameplayTagContainer variable.
	void SetGlobalInternalGameplayTagContainerValue(FGameplayTagContainer _value);
	
	// Copy the value of a FGameplayTagContainer variable.
	UFUNCTION(BlueprintCallable, Category = "Var System")
	static void CopyGlobalGameplayTagContainerValue(UGlobalGameplayTagContainer* var, UGlobalGameplayTagContainer* other);

	// Copy the value of a FGameplayTagContainer variable.
	void CopyGlobalInternalGameplayTagContainerValue(UGlobalGameplayTagContainer* other);

	/**** Base Variable Overrides ****/

	virtual void Save() override;

	virtual void Load() override;

    virtual FString GetStringValue() const override;
};
