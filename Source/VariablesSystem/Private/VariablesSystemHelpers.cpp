// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#include "VariablesSystemHelpers.h"

TArray<UBaseVariable*> UVariablesSystemHelpersBPLibrary::GetAllVariables()
{
    return UVariablesSystemHelpersBPLibrary::GetAllAssetsOfType<UBaseVariable>();
}