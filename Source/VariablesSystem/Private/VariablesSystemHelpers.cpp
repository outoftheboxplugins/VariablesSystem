// Copyright Out-of-the-Box Plugins 2018-2023. All Rights Reserved.
#include "VariablesSystemHelpers.h"

#include "BaseVariable.h"

TArray<UBaseVariable*> UVariablesSystemHelpersBPLibrary::GetAllVariables()
{
    return UVariablesSystemHelpersBPLibrary::GetAllAssetsOfType<UBaseVariable>();
}

TArray<UGlobalVariable*> UVariablesSystemHelpersBPLibrary::GetAllGlobalVariables()
{
	return UVariablesSystemHelpersBPLibrary::GetAllAssetsOfType<UGlobalVariable>();
}

void UVariablesSystemHelpersBPLibrary::SaveAllVariables()
{
	for (auto& Variable : GetAllGlobalVariables())
	{
		Variable->Save();
	}
}

void UVariablesSystemHelpersBPLibrary::LoadAllVariables()
{
	for (auto& Variable : GetAllGlobalVariables())
	{
		Variable->Load();
	}
}
