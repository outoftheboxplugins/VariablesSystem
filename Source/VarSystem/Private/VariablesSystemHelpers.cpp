#include "VariablesSystemHelpers.h"


TArray<UBaseVariable*> UVariablesSystemHelpersBPLibrary::GetAllVariables()
{
    return UVariablesSystemHelpersBPLibrary::GetAllAssetsOfType<UBaseVariable>();
}

