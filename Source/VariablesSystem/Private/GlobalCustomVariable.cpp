// Copyright Out-of-the-Box Plugins 2018-2023. All Rights Reserved.

#include "GlobalCustomVariable.h"

#include <Kismet/GameplayStatics.h>

FString UGlobalCustomVariable::GetSaveLocation() const
{
	// TODO: Check if this is unique if we have 2 variables with the same name, but in different location
	return GetName();
}

void UGlobalCustomVariable::Save()
{
	UGameplayStatics::SaveGameToSlot(this, GetSaveLocation(), 0);
}

void UGlobalCustomVariable::Load()
{
	if (!UGameplayStatics::DoesSaveGameExist(GetSaveLocation(), 0))
	{
		return;
	}

	const UGlobalCustomVariable* SavedData = Cast<UGlobalCustomVariable>(UGameplayStatics::LoadGameFromSlot(GetSaveLocation(), 0));
	if (!SavedData)
	{
		return;
	}

	StructData = SavedData->StructData;
}
