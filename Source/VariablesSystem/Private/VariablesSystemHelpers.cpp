// Copyright Out-of-the-Box Plugins 2018-2020. All Rights Reserved.

#include "VariablesSystemHelpers.h"

#include "BaseVariable.h"

TArray<UBaseVariable*> UVariablesSystemHelpersBPLibrary::GetAllVariables()
{
    return UVariablesSystemHelpersBPLibrary::GetAllAssetsOfType<UBaseVariable>();
}

TArray<UGlobalBaseVariable*> UVariablesSystemHelpersBPLibrary::GetAllGlobalVariables()
{
	return UVariablesSystemHelpersBPLibrary::GetAllAssetsOfType<UGlobalBaseVariable>();
}

void UVariablesSystemHelpersBPLibrary::SaveAllVariables()
{
	for (auto& Variable : GetAllGlobalVariables())
	{
		Variable->Load();
	}
}

void UVariablesSystemHelpersBPLibrary::LoadAllVariables()
{
	for (auto& Variable : GetAllGlobalVariables())
	{
		Variable->Load();
	}
}
