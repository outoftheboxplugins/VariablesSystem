// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#include "Modules/ModuleInterface.h"
#include "Modules/ModuleManager.h"
#include "Engine/World.h"
#include "BaseVariable.h"
#include "AssetRegistryModule.h"

/**
 * Implements the VarSystem module.
 */
class FVarSystemModule
    : public IModuleInterface
{
public:

    //~ IModuleInterface interface

    virtual void StartupModule() override
    {
        FWorldDelegates::OnWorldInitializedActors.AddRaw(this, &FVarSystemModule::OnWorldCreationEvent);
        FWorldDelegates::OnPostWorldCleanup.AddRaw(this, &FVarSystemModule::OnWorldDestructionEvent);
    }
    virtual void ShutdownModule() override
    {
        FWorldDelegates::OnWorldInitializedActors.RemoveAll(this);
        FWorldDelegates::OnPostWorldCleanup.RemoveAll(this);
    }

    virtual bool SupportsDynamicReloading() override
    {
        return true;
    }


    static TArray<UBaseVariable*> GetAllVariables()
    {
        TArray<UBaseVariable*> Variables;

        if (FModuleManager::Get().IsModuleLoaded("AssetRegistry"))
        {
            FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
            TArray<FAssetData> AssetData;
            AssetRegistryModule.Get().GetAssetsByClass(FName("BaseVariable"), AssetData);
            for (int i = 0; i < AssetData.Num(); i++) {
                UBaseVariable* VariableFound = Cast<UBaseVariable>(AssetData[i].GetAsset());
                if (VariableFound != NULL) {
                    Variables.Add(VariableFound);
                }
            }
        }

        return Variables;
    }

private:
    
    void OnWorldCreationEvent(const UWorld::FActorsInitializedParams& params)
    {
        TArray<UBaseVariable*> variables = GetAllVariables();
        for (UBaseVariable* variable : variables)
        {
            if (variable->ShouldLoad())
            {
                variable->Load();
            }
        }
    }

    void OnWorldDestructionEvent(UWorld* World, bool bSessionEnded, bool bCleanupResources)
    {
        TArray<UBaseVariable*> variables = GetAllVariables();
        for (UBaseVariable* variable : variables)
        {
            if (variable->ShouldSave())
            {
                variable->Save();
            }
        }
    }
};


IMPLEMENT_MODULE(FVarSystemModule, VarSystem);
