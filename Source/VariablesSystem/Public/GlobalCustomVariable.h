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
	void SetStructType(TObjectPtr<UScriptStruct> InStructType);
	TObjectPtr<UScriptStruct> GetStructType() const;
	uint8* GetDataPtr() const;

	void CleanBeforeStructChange();
	void RestoreAfterStructChange();

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
	 * @brief Type of the struct we are currently holding
	 */
	UPROPERTY()
	TObjectPtr<UScriptStruct> StructType;
	/**
	 * @brief Data representing the struct we want to save/load
	 */
	UPROPERTY(SaveGame)
	TArray<uint8> StructSavedData;
	/**
	 * @brief Data representing the struct we own
	 */
	uint8* StructDataPtr = nullptr;

	void SaveStructData(FStructuredArchiveSlot Slot);
	void LoadStructData(FStructuredArchiveSlot Slot);

	UPROPERTY(Transient)
	TSet<TObjectPtr<UObject>> TemporarilyReferencedObjects;

private:
	/**
	 * @brief Returns the save game location where we will be storing on disk, unique for each asset instance
	 * @return Path for the current variable instance
	 */
	FString GetSaveLocation() const;
};
