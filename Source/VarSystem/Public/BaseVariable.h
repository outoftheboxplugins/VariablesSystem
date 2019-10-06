// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#pragma once

#include "Internationalization/Text.h"
#include "GameFramework/SaveGame.h"
#include "UObject/ObjectMacros.h"
#include "BaseVariable.generated.h"

UENUM(BlueprintType)
enum class EVarSystemSaveType : uint8
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
class VARSYSTEM_API UBaseVariable : public USaveGame
{
	GENERATED_BODY()

public:
	/** Full description of the variable usage. */
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="VarSystem")
	FText VariableDescription;

    /** Desired save-load behavior of the variable. */
    UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "VarSystem")
    EVarSystemSaveType SaveBehavior = EVarSystemSaveType::VSST_StartAndFinish;

	/* Saves the current data of a variable.*/
	virtual void Save() {};

	/* Loads the data of a variable and assignees it. */
	virtual void Load() {};

    bool ShouldSave() const { return SaveBehavior == EVarSystemSaveType::VSST_SaveOnFinish || SaveBehavior == EVarSystemSaveType::VSST_StartAndFinish; }
    bool ShouldLoad() const { return SaveBehavior == EVarSystemSaveType::VSST_LoadOnStart || SaveBehavior == EVarSystemSaveType::VSST_StartAndFinish; }

protected:
	bool dirty = false;

	FString GetSaveLocation();
};
