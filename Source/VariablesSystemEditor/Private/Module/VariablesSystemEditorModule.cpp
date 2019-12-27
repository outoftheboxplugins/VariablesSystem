// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#include "VariablesSystemEditorModule.h"

#include "AssetTools/VariablesSystemActions.h"
#include "EditorStyleSet.h"
#include "Modules/ModuleManager.h"
#include "VariablesSystemEditor/Private/EditorHelpers/VariablesSystemEditorHelpers.h"
#include "VariablesSystemEditor/Private/WatchWidget/VariablesWatchWidget.h"
#include "Widgets/Docking/SDockTab.h"
#include "WorkspaceMenuStructure/Public/WorkspaceMenuStructure.h"
#include "WorkspaceMenuStructure/Public/WorkspaceMenuStructureModule.h"

const FName FVariablesSystemEditorModule::VariablesWatchTabName = FName("VariablesWatchTab");

#define LOCTEXT_NAMESPACE "VariablesSystem"

void FVariablesSystemEditorModule::StartupModule()
{
    RegisterAssetTools();
    RegisterMenuExtensions();
}

void FVariablesSystemEditorModule::ShutdownModule()
{
    UnregisterAssetTools();
    UnregisterMenuExtensions();
}

void FVariablesSystemEditorModule::RegisterAssetTools()
{
    IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();

    AssetActions = MakeShareable(new FVariablesSystemActions);
    AssetTools.RegisterAssetTypeActions(AssetActions.ToSharedRef());
}

void FVariablesSystemEditorModule::UnregisterAssetTools()
{
    if (FModuleManager::Get().IsModuleLoaded("AssetTools"))
    {
        IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();
        AssetTools.UnregisterAssetTypeActions(AssetActions.ToSharedRef());
    }
}

void FVariablesSystemEditorModule::RegisterMenuExtensions()
{
    FTabSpawnerEntry& WatchTab = FGlobalTabmanager::Get()->RegisterNomadTabSpawner(VariablesWatchTabName, FOnSpawnTab::CreateRaw(this, &FVariablesSystemEditorModule::SpawnVariablesWatchTab));

    WatchTab
        .SetDisplayName(LOCTEXT("VariablesSystem_OpenWatchDisplayName", "Variables Watch"))
        .SetTooltipText(LOCTEXT("VariablesSystem_OpenWatchTooltip", "See the values of your variables assets."))
        .SetIcon(FSlateIcon(FEditorStyle::GetStyleSetName(), "Launcher.TabIcon"))
        .SetGroup(WorkspaceMenu::GetMenuStructure().GetToolsCategory());
}

void FVariablesSystemEditorModule::UnregisterMenuExtensions()
{
    FGlobalTabmanager::Get()->UnregisterNomadTabSpawner(FName("VariablesWatchTab"));
}

TSharedRef<SDockTab> FVariablesSystemEditorModule::SpawnVariablesWatchTab(const FSpawnTabArgs& Args)
{
    return SNew(SDockTab)
        .TabRole(ETabRole::NomadTab)
        [
            SNew(SVariablesWatchWidget)
        ];
}

#undef LOCTEXT_NAMESPACE