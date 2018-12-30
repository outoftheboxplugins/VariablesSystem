#include "BaseVariable.h"

FString UBaseVariable::GetSaveLocation()
{
	FString SaveDestination;
	UObjectBaseUtility::GetName(SaveDestination);
	return SaveDestination;
}

