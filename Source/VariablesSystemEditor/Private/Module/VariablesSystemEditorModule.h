// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#pragma once

#include "Core/Public/Modules/ModuleInterface.h"

/**
 * Implements the VariablesSystemEditor module.
 */

class FVariablesSystemEditorModule : public IModuleInterface
{
public:
    /** The name under which the take variables watch tab is registered and invoked */
    const static FName VariablesWatchTabName;

//IModuleInterface interface
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	virtual bool SupportsDynamicReloading() override { return true; }

// Register & Unregister
protected:
	void RegisterAssetTools();
	void RegisterMenuExtensions();

	void UnregisterAssetTools();
	void UnregisterMenuExtensions();

// Extensions
private:
    TSharedRef<SDockTab> SpawnVariablesWatchTab(const FSpawnTabArgs& Args);

private:
    // Register actions for the variable assets type.
	TSharedPtr<FVariablesSystemActions> AssetActions;
};

IMPLEMENT_MODULE(FVariablesSystemEditorModule, VariablesSystemEditor);