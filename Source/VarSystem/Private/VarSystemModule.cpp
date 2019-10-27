// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#include "Modules/ModuleInterface.h"
#include "Modules/ModuleManager.h"
#include "Engine/World.h"
#include "BaseVariable.h"
#include "AssetRegistryModule.h"

#include "Containers/Array.h"
#include "ISettingsModule.h"
#include "ISettingsSection.h"
#include "Modules/ModuleInterface.h"
#include "Modules/ModuleManager.h"
#include "Templates/SharedPointer.h"
#include "Toolkits/AssetEditorToolkit.h"

#include "ContentBrowserModule.h"
#include "Editor/LevelEditor/Public/LevelEditor.h"
#include "Developer/AssetTools/Public/IAssetTools.h"
#include "Developer/AssetTools/Public/AssetToolsModule.h"
#include "Misc/ScopedSlowTask.h"
#include "AssetRegistryModule.h"
#include "Misc/MessageDialog.h"
#include "EngineUtils.h"
#include "UnrealEd/Public/ObjectTools.h"
#include "EditorStyleSet.h"
#include "Engine/World.h"
#include "AssetTools/Private/SPackageReportDialog.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"
#include "Templates/SharedPointer.h"
#include "Framework/MultiBox/MultiBoxExtender.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "Containers/Array.h"
#include "AssetData.h"

#define LOCTEXT_NAMESPACE "VariablesSystem"


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

        // Register main menu dropdown entry
        TSharedPtr<FExtender> MenuExtender = MakeShareable(new FExtender);
        MenuExtender->AddMenuExtension("FileLoadAndSave", EExtensionHook::After, nullptr, FMenuExtensionDelegate::CreateRaw(this, &FVarSystemModule::CreateDepenCheckerMainMenuEntry));
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

    // Extend main menu for to add depend checker delegate
    void CreateDepenCheckerMainMenuEntry(FMenuBuilder& MenuBuilder)
    {
        MenuBuilder.BeginSection("VariablesSystem", LOCTEXT("WatchWindow", "WatchWindow"));
        MenuBuilder.AddMenuEntry(
            FText(LOCTEXT("VariablesWatch", "Variables Watch")),
            LOCTEXT("VariablesWatchTooltip", "Show all the variables inside a watch"),
            FSlateIcon(FEditorStyle::GetStyleSetName(), "DeveloperTools.MenuIcon"),
            FUIAction(FExecuteAction::CreateRaw(this, &FVarSystemModule::OnExtendMainMenu)));
        MenuBuilder.EndSection();
    }

    void OnExtendMainMenu()
    {

    }
};

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FVarSystemModule, VarSystem);
