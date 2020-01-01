// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#pragma once

#include "UObject/ObjectMacros.h"
#include "BaseVariable.h"
#include "LocalGameplayTagContainer.generated.h"

/**
 *
 */
UCLASS(BlueprintType)
class VARIABLESSYSTEM_API ULocalGameplayTagContainer : public UBaseVariable
{
	GENERATED_BODY()

public:
	TMap<UObject*, FGameplayTagContainer> variables;

	// Get the value of a LocalGameplayTagContainer variable.
	FGameplayTagContainer& GetLocalGameplayTagContainerRef(UObject* owner);
	
	// Get the value of a LocalGameplayTagContainer variable.
	UFUNCTION(BlueprintPure, Category = "Var System Local", meta = (BlueprintThreadSafe))
	static FGameplayTagContainer GetLocalGameplayTagContainerValue(UObject* owner, ULocalGameplayTagContainer* var);

	// Set the value of a LocalGameplayTagContainer variable.
	UFUNCTION(BlueprintCallable, Category = "Var System Local")
	static void SetLocalGameplayTagContainerValue(UObject* owner, ULocalGameplayTagContainer* var, FGameplayTagContainer _value);
	
	// Copy the value of a LocalGameplayTagContainer variable.
	UFUNCTION(BlueprintCallable, Category = "Var System Local")
	static void CopyLocalGameplayTagContainerValue(UObject* owner, ULocalGameplayTagContainer* var, UObject* otherOwner, ULocalGameplayTagContainer* other);

    virtual void Save() override;

    virtual void Load() override;

    virtual FString GetStringValue() const override;

private:
    FString GetValueAsString(FGameplayTagContainer value) const;
};

