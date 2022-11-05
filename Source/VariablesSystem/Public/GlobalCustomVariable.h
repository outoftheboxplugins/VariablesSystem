// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "UObject/Object.h"

#include "GlobalCustomVariable.generated.h"

/**
 *
 */
UCLASS(Blueprintable, BlueprintType)
class VARIABLESSYSTEM_API UGlobalCustomVariable : public USaveGame
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, Category = DataTable, meta = (DisplayThumbnail = "false"))
	TObjectPtr<UScriptStruct> RowStruct;

	UPROPERTY(SaveGame)
	TArray<uint8> SavedData;
	
	FString GetSaveLocation() const;

	void Save();
	void Load();

	// uint8* RowData;
};
