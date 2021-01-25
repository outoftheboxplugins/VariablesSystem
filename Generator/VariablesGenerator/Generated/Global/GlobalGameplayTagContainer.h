// Copyright Out-of-the-Box Plugins 2018-2021. All Rights Reserved.

// GENERATED FILE DO NOT MODIFY DIRECTLY

#pragma once

#include "BaseVariable.h"
	
	#include "C:\Unreal\UnrealEngine\Engine\Source\Runtime\GameplayTags\Classes\GameplayTagContainer.h"

#include "GlobalGameplayTagContainer.generated.h"

/**
 * Global GameplayTagContainer implementation of the BaseVariable
 */

UCLASS(BlueprintType)
class VARIABLESSYSTEM_API UGlobalGameplayTagContainer : public UBaseVariable
{
	GENERATED_BODY()

// Global static calls
public:
	// Get the value of a FGameplayTagContainer variable.
	UFUNCTION(BlueprintPure, Category = "VariablesSystem", meta = (BlueprintThreadSafe, Keywords = "Get Global value"))
	static FGameplayTagContainer GetGlobalGameplayTagContainerValue(const UGlobalGameplayTagContainer* Variable);

	// Set the value of a FGameplayTagContainer variable.
	UFUNCTION(BlueprintCallable, Category = "VariablesSystem", meta = (Keywords = "Set Global value"))
	static void SetGlobalGameplayTagContainerValue(UGlobalGameplayTagContainer* Variable, FGameplayTagContainer NewValue);

	// Copy the value of a FGameplayTagContainer variable.
	UFUNCTION(BlueprintCallable, Category = "VariablesSystem", meta = (Keywords = "Copy Global value"))
	static void CopyGlobalGameplayTagContainerValue(UGlobalGameplayTagContainer* Variable, UGlobalGameplayTagContainer* OtherVariable);


protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "VariablesSystem")
	FGameplayTagContainer Value;
};
