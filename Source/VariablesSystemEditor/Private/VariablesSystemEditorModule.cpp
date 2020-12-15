// Copyright Out-of-the-Box Plugins 2018-2020. All Rights Reserved.

#include "VariablesSystemEditorModule.h"

#include "VSLog.h"
#include "VariablesWatchWidget.h"

#include "AssetToolsModule.h"

#include "WorkspaceMenuStructure.h"
#include "WorkspaceMenuStructureModule.h"

namespace 
{
	const FName ModuleName = "VariablesSystemEditor";
	const FName VariablesWatchTabName = "VariablesWatchTab";
}

#define LOCTEXT_NAMESPACE "VariablesSystemEditor"

//////////////////////////////////////////////////////////////////////////
// Public interface
FVariablesSystemEditorModule& FVariablesSystemEditorModule::GetModule()
{
	return FModuleManager::LoadModuleChecked<FVariablesSystemEditorModule>(ModuleName);
}

bool FVariablesSystemEditorModule::IsModuleLoaded()
{
	return FModuleManager::Get().IsModuleLoaded(ModuleName);
}

TSharedRef<SDockTab> FVariablesSystemEditorModule::OpenOrAddVariablesToWatch(TArray<class UBaseVariable*> Variables /*= TArray<UBaseVariable*>()*/)
{
	TSharedRef<SDockTab> WatchTab = FGlobalTabmanager::Get()->InvokeTab(VariablesWatchTabName);
	TSharedRef<SVSWatchWidget> VariablesWatch = StaticCastSharedRef<SVSWatchWidget>(WatchTab->GetContent());

	VariablesWatch->AddVariables(Variables);

	return WatchTab;
}

//////////////////////////////////////////////////////////////////////////
//IModuleInterface interface
void FVariablesSystemEditorModule::StartupModule()
{
	LOG_TRACE();

    RegisterAssetTools();
    RegisterMenuExtensions();
}

void FVariablesSystemEditorModule::ShutdownModule()
{
	LOG_TRACE();

    UnregisterAssetTools();
    UnregisterMenuExtensions();
}

//////////////////////////////////////////////////////////////////////////
// Register & Unregister
void FVariablesSystemEditorModule::RegisterAssetTools()
{
	if (FAssetToolsModule::IsModuleLoaded())
	{
		IAssetTools& AssetTools = FAssetToolsModule::GetModule().Get();

		AssetActions = MakeShareable(new FVSActions);
		AssetTools.RegisterAssetTypeActions(AssetActions.ToSharedRef());
	}
	else
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("FAssetToolsModule not loaded, cannot register asset tools."))
	}
}

void FVariablesSystemEditorModule::UnregisterAssetTools()
{
    if (FAssetToolsModule::IsModuleLoaded())
    {
        IAssetTools& AssetTools = FAssetToolsModule::GetModule().Get();
        AssetTools.UnregisterAssetTypeActions(AssetActions.ToSharedRef());
    }
	else
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("FAssetToolsModule not loaded, cannot unregister asset tools."))
	}
}

void FVariablesSystemEditorModule::RegisterMenuExtensions()
{
    FTabSpawnerEntry& WatchTab = FGlobalTabmanager::Get()->RegisterNomadTabSpawner(VariablesWatchTabName, FOnSpawnTab::CreateRaw(this, &FVariablesSystemEditorModule::SpawnVariablesWatchTab));

    WatchTab
        .SetDisplayName(LOCTEXT("VariablesSystem_OpenWatchDisplayName", "Variables Watch"))
        .SetTooltipText(LOCTEXT("VariablesSystem_OpenWatchTooltip", "See the values of your variables assets."))
        .SetGroup(WorkspaceMenu::GetMenuStructure().GetToolsCategory());
}

void FVariablesSystemEditorModule::UnregisterMenuExtensions()
{
    FGlobalTabmanager::Get()->UnregisterNomadTabSpawner(VariablesWatchTabName);
}

//////////////////////////////////////////////////////////////////////////
// Extensions
TSharedRef<SDockTab> FVariablesSystemEditorModule::SpawnVariablesWatchTab(const FSpawnTabArgs& Args)
{
    return SNew(SDockTab)
        .TabRole(ETabRole::NomadTab)
        [
            SNew(SVSWatchWidget)
        ];
}

#undef LOCTEXT_NAMESPACE