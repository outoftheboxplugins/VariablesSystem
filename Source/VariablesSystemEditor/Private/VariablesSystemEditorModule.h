// Copyright Out-of-the-Box Plugins 2018-2021. All Rights Reserved.
#pragma once

#include "Modules/ModuleInterface.h"
#include "VSContentBrowserExtensions.h"

class FVSActions;
class FVSCustomActions;

/**
 * Implements the VariablesSystem editor module.
 */

class FVariablesSystemEditorModule : public IModuleInterface
{
	// Public Interface
public:
	static FVariablesSystemEditorModule& GetModule();
	static bool IsModuleLoaded();

	TSharedPtr<class SDockTab> OpenOrAddVariablesToWatch(TArray<class UBaseVariable*> Variables = TArray<UBaseVariable*>());

	// IModuleInterface interface
private:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	// Register & Unregister
private:
	void RegisterAssetTools();
	void UnregisterAssetTools();

	void RegisterMenuExtensions();
	void UnregisterMenuExtensions();

	void RegisterCBExtensions();
	void UnregisterCBExtensions();

	// Extensions
private:
	TSharedRef<SDockTab> SpawnVariablesWatchTab(const FSpawnTabArgs& Args);

private:
	TSharedPtr<FVSActions> AssetActions;
	TSharedPtr<FVSCustomActions> CustomAssetActions;
	TSharedPtr<FVSContentBrowserExtensions> ContentBrowserExtensions;
};

IMPLEMENT_MODULE(FVariablesSystemEditorModule, VariablesSystemEditor);
