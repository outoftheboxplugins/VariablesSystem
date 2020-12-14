// Copyright Out-of-the-Box Plugins 2018-2020. All Rights Reserved.

#pragma once

#include "Modules/ModuleInterface.h"

class FVSActions;

/**
 * Implements the VariablesSystem editor module.
 */

class FVariablesSystemEditorModule : public IModuleInterface
{
//IModuleInterface interface
private:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

// Register & Unregister
private:
	void RegisterAssetTools();
	void UnregisterAssetTools();

	void RegisterMenuExtensions();
	void UnregisterMenuExtensions();

// Extensions
private:
    TSharedRef<SDockTab> SpawnVariablesWatchTab(const FSpawnTabArgs& Args);

private:
	TSharedPtr<FVSActions> AssetActions;
};

IMPLEMENT_MODULE(FVariablesSystemEditorModule, VariablesSystemEditor);