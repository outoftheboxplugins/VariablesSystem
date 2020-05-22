// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#include "BaseVariable.h"

FString UBaseVariable::GetSaveLocation() const
{
	FString SaveDestination;
	UObjectBaseUtility::GetName(SaveDestination);
	return SaveDestination;
}