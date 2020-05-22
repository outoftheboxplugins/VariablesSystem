// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#include "VariablesSystemModule.h"

#include "VariablesSystem/Public/VariablesSystemHelpers.h"

void FVariablesSystemModule::StartupModule()
{
    FWorldDelegates::OnWorldInitializedActors.AddRaw(this, &FVariablesSystemModule::OnWorldCreationEvent);
    FWorldDelegates::OnPostWorldCleanup.AddRaw(this, &FVariablesSystemModule::OnWorldDestructionEvent);
}

void FVariablesSystemModule::ShutdownModule()
{
    FWorldDelegates::OnWorldInitializedActors.RemoveAll(this);
    FWorldDelegates::OnPostWorldCleanup.RemoveAll(this);
}

void FVariablesSystemModule::OnWorldCreationEvent(const UWorld::FActorsInitializedParams& params)
{
    TArray<UBaseVariable*> variables = UVariablesSystemHelpersBPLibrary::GetAllVariables();
    for (UBaseVariable* variable : variables)
    {
        if (variable->ShouldLoad())
        {
            variable->Load();
        }
    }
}

void FVariablesSystemModule::OnWorldDestructionEvent(UWorld* World, bool bSessionEnded, bool bCleanupResources)
{
    TArray<UBaseVariable*> variables = UVariablesSystemHelpersBPLibrary::GetAllVariables();
    for (UBaseVariable* variable : variables)
    {
        if (variable->ShouldSave())
        {
            variable->Save();
        }
    }
}