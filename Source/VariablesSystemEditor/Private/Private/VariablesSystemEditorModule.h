// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#pragma once

#include "Modules/ModuleInterface.h"

/**
 * Implements the VariablesSystemEditor module.
 */

class FVariablesSystemEditorModule : public IModuleInterface
{
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
    void AddMenuExtension(FMenuBuilder& MenuBuilder);
    void OpenVariablesWatch();

private:
    // Extension of the Menu to start the variables watch
    TSharedPtr<FExtender> WatchMenuExtender;
	
    // Register actions for the variable assets type.
	TSharedPtr<FVariablesSystemActions> AssetActions;
};

IMPLEMENT_MODULE(FVariablesSystemEditorModule, VariablesSystemEditor);