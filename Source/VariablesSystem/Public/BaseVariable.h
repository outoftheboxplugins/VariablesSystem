// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#pragma once

#include "Internationalization/Text.h"
#include "GameFramework/SaveGame.h"
#include "UObject/ObjectMacros.h"
#include "BaseVariable.generated.h"

UENUM(BlueprintType)
enum class EVariablesSystemSaveType : uint8
{
    VSST_None                  UMETA(DisplayName = "None"),
    VSST_LoadOnStart 	       UMETA(DisplayName = "LoadOnStart"),
    VSST_SaveOnFinish 	       UMETA(DisplayName = "SaveOnFinish"),
    VSST_StartAndFinish	       UMETA(DisplayName = "StartAndFinish")
};

/**
 * Implements an asset that can store specific types of variables.
 */
UCLASS(Abstract, BlueprintType, hidecategories=(Object)) 
class VARIABLESSYSTEM_API UBaseVariable : public USaveGame
{
	GENERATED_BODY()

public:
	/** Full description of the variable usage. */
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="VariablesSystem")
	FText VariableDescription;

    /** Desired save-load behavior of the variable. */
    UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "VariablesSystem")
    EVariablesSystemSaveType SaveBehavior = EVariablesSystemSaveType::VSST_StartAndFinish;

	/* Saves the current data of a variable.*/
	virtual void Save() {};

	/* Loads the data of a variable and assignees it. */
	virtual void Load() {};

    bool ShouldSave() const { return SaveBehavior == EVariablesSystemSaveType::VSST_SaveOnFinish || SaveBehavior == EVariablesSystemSaveType::VSST_StartAndFinish; }
    bool ShouldLoad() const { return SaveBehavior == EVariablesSystemSaveType::VSST_LoadOnStart || SaveBehavior == EVariablesSystemSaveType::VSST_StartAndFinish; }

    virtual FString GetStringValue() const { return FString("Invalid Value"); };

protected:
	bool dirty = false;

	FString GetSaveLocation();
};
