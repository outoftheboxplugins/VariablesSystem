// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#pragma once

#include "UObject/ObjectMacros.h"
#include "BaseVariable.h"
#include "VariablesSystemSaver.generated.h"

/**
 * Implements an asset that can be used to store arbitrary text, such as notes
 * or documentation.
 */
UCLASS(BlueprintType, hidecategories=(Object))
class VARIABLESSYSTEM_API UVariablesSystemSaver
	: public UBaseVariable
{
	GENERATED_BODY()

public:

	/** Holds the stored text. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "VariablesSystem")
		TArray<UBaseVariable*> Variables;

	/** Save all the current variables. */
	UFUNCTION(BlueprintCallable, Category = "Var System")
		static void SaveAllData(UVariablesSystemSaver* Manager);

	/** Loads all the current variables. */
	UFUNCTION(BlueprintCallable, Category = "Var System")
		static void LoadAllDaa(UVariablesSystemSaver* Manager);
};
