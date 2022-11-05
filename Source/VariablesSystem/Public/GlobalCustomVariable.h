// Copyright Out-of-the-Box Plugins 2018-2023. All Rights Reserved.

#pragma once

#include <GameFramework/SaveGame.h>

#include "GlobalCustomVariable.generated.h"

/**
 * Implements an asset that can store custom structure types globally
 */
UCLASS(BlueprintType)
class VARIABLESSYSTEM_API UGlobalCustomVariable : public USaveGame
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<UScriptStruct> StructType;

	UPROPERTY(SaveGame)
	TArray<uint8> StructData;

	/**
	 * @brief Saves the current value of the variable to disk
	 */
	void Save();
	/**
	 * @brief Loads the value saved on disk and sets the instance to it
	 */
	void Load();

private:
	/**
	 * @brief Returns the save game location where we will be storing on disk, unique for each asset instance
	 * @return Path for the current variable instance
	 */
	FString GetSaveLocation() const;
};
