// Fill out your copyright notice in the Description page of Project Settings.

#include "GlobalCustomVariable.h"

#include "Kismet/GameplayStatics.h"

FString UGlobalCustomVariable::GetSaveLocation() const
{
	FString SaveDestination;
	UObjectBaseUtility::GetName(SaveDestination);
	return SaveDestination;
}

void UGlobalCustomVariable::Save()
{
	UGameplayStatics::SaveGameToSlot(this, GetSaveLocation(), 0);
}

void UGlobalCustomVariable::Load()
{
	if (UGameplayStatics::DoesSaveGameExist(GetSaveLocation(), 0))
	{
		if (UGlobalCustomVariable* LoadGameInstance =
				Cast<UGlobalCustomVariable>(UGameplayStatics::LoadGameFromSlot(GetSaveLocation(), 0)))
		{
			SavedData = LoadGameInstance->SavedData;
		}
	}
}
