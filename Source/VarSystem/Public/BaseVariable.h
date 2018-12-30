// Copyright Alexandru pasotee Oprea 2018. All Rights Reserved.

#pragma once

#include "Internationalization/Text.h"
#include "GameFramework/SaveGame.h"
#include "UObject/ObjectMacros.h"
#include "BaseVariable.generated.h"

/**
 * Implements an asset that can store specific types of variables.
 */
UCLASS(Abstract, BlueprintType, hidecategories=(Object)) 
class VARSYSTEM_API UBaseVariable : public USaveGame
{
	GENERATED_BODY()

public:
	/** Full description of the variable usage.. */
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="VarSystem")
	FText VariableDescription;

	/* Saves the current data of a variable.*/
	virtual void Save() {};

	/* Loads the data of a variable and assignees it. */
	virtual void Load() {};

protected:
	bool dirty = false;

	FString GetSaveLocation();
};
