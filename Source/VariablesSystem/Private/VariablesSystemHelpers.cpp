// Copyright Out-of-the-Box Plugins 2018-2020. All Rights Reserved.

#include "VariablesSystemHelpers.h"

#include "BaseVariable.h"

TArray<UBaseVariable*> UVariablesSystemHelpersBPLibrary::GetAllVariables()
{
    return UVariablesSystemHelpersBPLibrary::GetAllAssetsOfType<UBaseVariable>();
}

void UVariablesSystemHelpersBPLibrary::SaveAllVariables()
{
	for (auto& Variable : GetAllVariables())
	{
		Variable->Load();
	}
}

void UVariablesSystemHelpersBPLibrary::LoadAllVariables()
{
	for (auto& Variable : GetAllVariables())
	{
		Variable->Load();
	}
}
