// Copyright Out-of-the-Box Plugins 2018-2021. All Rights Reserved.
#include "VariablesSystemEditorModule.h"

#include "AssetToolsModule.h"
#include "VSActions.h"
#include "VSLog.h"
#include "VariablesWatchWidget.h"
#include "WorkspaceMenuStructure.h"
#include "WorkspaceMenuStructureModule.h"

namespace
{
const FName VSEditorModuleName = "VariablesSystemEditor";
const FName VariablesWatchTabName = "VariablesWatchTab";
}	 // namespace

#define LOCTEXT_NAMESPACE "VariablesSystemEditor"

//////////////////////////////////////////////////////////////////////////
// Public interface
FVariablesSystemEditorModule& FVariablesSystemEditorModule::GetModule()
{
	return FModuleManager::LoadModuleChecked<FVariablesSystemEditorModule>(VSEditorModuleName);
}

bool FVariablesSystemEditorModule::IsModuleLoaded()
{
	return FModuleManager::Get().IsModuleLoaded(VSEditorModuleName);
}

TSharedPtr<SDockTab> FVariablesSystemEditorModule::OpenOrAddVariablesToWatch(
	TArray<class UBaseVariable*> Variables /*= TArray<UBaseVariable*>()*/)
{
	TSharedPtr<SDockTab> WatchTab = FGlobalTabmanager::Get()->TryInvokeTab(VariablesWatchTabName);
	TSharedRef<SVSWatchWidget> VariablesWatch = StaticCastSharedRef<SVSWatchWidget>(WatchTab->GetContent());

	VariablesWatch->AddVariables(Variables);

	return WatchTab;
}

//////////////////////////////////////////////////////////////////////////
// IModuleInterface interface
void FVariablesSystemEditorModule::StartupModule()
{
	LOG_TRACE();

	RegisterAssetTools();
	RegisterCBExtensions();
	RegisterMenuExtensions();
}

void FVariablesSystemEditorModule::ShutdownModule()
{
	LOG_TRACE();

	UnregisterAssetTools();
	UnregisterCBExtensions();
	UnregisterMenuExtensions();
}

//////////////////////////////////////////////////////////////////////////
// Register & Unregister
void FVariablesSystemEditorModule::RegisterAssetTools()
{
	if (FAssetToolsModule::IsModuleLoaded())
	{
		IAssetTools& AssetTools = FAssetToolsModule::GetModule().Get();

		AssetActions = MakeShared<FVSActions>();
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
	FTabSpawnerEntry& WatchTab = FGlobalTabmanager::Get()->RegisterNomadTabSpawner(
		VariablesWatchTabName, FOnSpawnTab::CreateRaw(this, &FVariablesSystemEditorModule::SpawnVariablesWatchTab));

	WatchTab.SetDisplayName(LOCTEXT("VariablesSystem_OpenWatchDisplayName", "Variables Watch"))
		.SetTooltipText(LOCTEXT("VariablesSystem_OpenWatchTooltip", "See the values of your variables assets."))
		.SetGroup(WorkspaceMenu::GetMenuStructure().GetToolsCategory());
}

void FVariablesSystemEditorModule::UnregisterMenuExtensions()
{
	FGlobalTabmanager::Get()->UnregisterNomadTabSpawner(VariablesWatchTabName);
}

void FVariablesSystemEditorModule::RegisterCBExtensions()
{
	ContentBrowserExtensions = MakeShared<FVSContentBrowserExtensions>();
	ContentBrowserExtensions->Register();
}

void FVariablesSystemEditorModule::UnregisterCBExtensions()
{
	ContentBrowserExtensions->Unregister();
	ContentBrowserExtensions.Reset();
}

//////////////////////////////////////////////////////////////////////////
// Extensions
TSharedRef<SDockTab> FVariablesSystemEditorModule::SpawnVariablesWatchTab(const FSpawnTabArgs& Args)
{
	// clang-format off
	return SNew(SDockTab)
		.TabRole(ETabRole::NomadTab)
		[
			SNew(SVSWatchWidget)
		];
	// clang-format on
}

#undef LOCTEXT_NAMESPACE
