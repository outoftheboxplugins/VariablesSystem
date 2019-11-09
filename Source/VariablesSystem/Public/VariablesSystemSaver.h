// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#pragma once

#include "BaseVariable.h"

#include "VariablesSystemSaver.generated.h"

//TODO: make the Variable System Saver a different asset alltogheter so we do not inherit from UBasevariable anymore.

/**
 * Executes Save & Load operation on an list of variables.
 */

UCLASS(BlueprintType, hidecategories=(Object))
class VARIABLESSYSTEM_API UVariablesSystemSaver : public UBaseVariable
{
	GENERATED_BODY()

// Save & Load commands
public:
    /** Save all the current variables. */
    UFUNCTION(BlueprintCallable, Category = "VariablesSystem")
        static void SaveAllData(UVariablesSystemSaver* Manager);

    /** Loads all the current variables. */
    UFUNCTION(BlueprintCallable, Category = "VariablesSystem")
        static void LoadAllData(UVariablesSystemSaver* Manager);

protected:
	/** Variables that should be loaded/saved.. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "VariablesSystem")
    TArray<UBaseVariable*> Variables;

};
