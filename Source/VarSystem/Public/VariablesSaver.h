// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#pragma once

#include "UObject/ObjectMacros.h"
#include "BaseVariable.h"
#include "VariablesSaver.generated.h"

/**
 * Implements an asset that can be used to store arbitrary text, such as notes
 * or documentation.
 */
UCLASS(BlueprintType, hidecategories=(Object))
class VARSYSTEM_API UVariablesSaver
	: public UBaseVariable
{
	GENERATED_BODY()

public:

	/** Holds the stored text. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "VarSystem")
		TArray<UBaseVariable*> Variables;

	/** Save all the current variables. */
	UFUNCTION(BlueprintCallable, Category = "Var System")
		static void SaveAllData(UVariablesSaver* Manager);

	/** Loads all the current variables. */
	UFUNCTION(BlueprintCallable, Category = "Var System")
		static void LoadAllDaa(UVariablesSaver* Manager);
};
