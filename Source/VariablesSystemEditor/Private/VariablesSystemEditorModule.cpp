// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "Containers/Array.h"
#include "ISettingsModule.h"
#include "ISettingsSection.h"
#include "Modules/ModuleInterface.h"
#include "Modules/ModuleManager.h"
#include "Templates/SharedPointer.h"
#include "Toolkits/AssetEditorToolkit.h"

#include "AssetTools/VariablesSystemActions.h"
#include "Styles/VariablesSystemEditorStyle.h"
#include "VariablesSystemEditorSettings.h"
#include "Framework/Commands/UIAction.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"

#define LOCTEXT_NAMESPACE "VariablesSystem"


/**
 * Implements the VariablesSystemEditor module.
 */
class FVariablesSystemEditorModule
	: public IHasMenuExtensibility
	, public IHasToolBarExtensibility
	, public IModuleInterface
{
public:

	//~ IHasMenuExtensibility interface

	virtual TSharedPtr<FExtensibilityManager> GetMenuExtensibilityManager() override
	{
		return MenuExtensibilityManager;
	}

public:

	//~ IHasToolBarExtensibility interface

	virtual TSharedPtr<FExtensibilityManager> GetToolBarExtensibilityManager() override
	{
		return ToolBarExtensibilityManager;
	}

public:

	//~ IModuleInterface interface

	virtual void StartupModule() override
	{
		Style = MakeShareable(new FVariablesSystemEditorStyle());

//		FVariablesSystemEditorCommands::Register();

		RegisterAssetTools();
		RegisterMenuExtensions();
		RegisterSettings();
	}

	virtual void ShutdownModule() override
	{
		UnregisterAssetTools();
		UnregisterMenuExtensions();
		UnregisterSettings();
	}

	virtual bool SupportsDynamicReloading() override
	{
		return true;
	}

protected:

	/** Registers asset tool actions. */
	void RegisterAssetTools()
	{
		IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();

		RegisterAssetTypeAction(AssetTools, MakeShareable(new FVariablesSystemActions()));
	}

	/**
	 * Registers a single asset type action.
	 *
	 * @param AssetTools The asset tools object to register with.
	 * @param Action The asset type action to register.
	 */
	void RegisterAssetTypeAction(IAssetTools& AssetTools, TSharedRef<IAssetTypeActions> Action)
	{
		AssetTools.RegisterAssetTypeActions(Action);
		RegisteredAssetTypeActions.Add(Action);
	}

	/** Register the text asset editor settings. */
	void RegisterSettings()
	{
		ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings");

		if (SettingsModule != nullptr)
		{
			ISettingsSectionPtr SettingsSection = SettingsModule->RegisterSettings("Editor", "Plugins", "VariablesSystem",
				LOCTEXT("VariablesSystemSettingsName", "Var System"),
				LOCTEXT("VariablesSystemSettingsDescription", "Configure the Var System plug-in."),
				GetMutableDefault<UVariablesSystemEditorSettings>()
			);
		}
	}

	/** Unregisters asset tool actions. */
	void UnregisterAssetTools()
	{
		FAssetToolsModule* AssetToolsModule = FModuleManager::GetModulePtr<FAssetToolsModule>("AssetTools");

		if (AssetToolsModule != nullptr)
		{
			IAssetTools& AssetTools = AssetToolsModule->Get();

			for (auto Action : RegisteredAssetTypeActions)
			{
				AssetTools.UnregisterAssetTypeActions(Action);
			}
		}
	}

	/** Unregister the text asset editor settings. */
	void UnregisterSettings()
	{
		ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings");

		if (SettingsModule != nullptr)
		{
			SettingsModule->UnregisterSettings("Editor", "Plugins", "VariablesSystem");
		}
	}

protected:

    struct Local
    {
        static void AddMenuCommands(FMenuBuilder& MenuBuilder)
        {
            MenuBuilder.AddSubMenu(LOCTEXT("VariablesSystem", "Variables Watch"),
                LOCTEXT("VariablesSystem", "See the values of all the variables of your project."),
                FNewMenuDelegate::CreateStatic(&FVariablesSystemEditorModule::CreateToolListMenu));
        }
    };

	/** Registers main menu and tool bar menu extensions. */
	void RegisterMenuExtensions()
	{
		MenuExtensibilityManager = MakeShareable(new FExtensibilityManager);
		ToolBarExtensibilityManager = MakeShareable(new FExtensibilityManager);

        TSharedRef<FExtender> VariablesWatch(new FExtender());
        VariablesWatch->AddMenuExtension(
            "EditMain",
            EExtensionHook::After,
            nullptr,
            FMenuExtensionDelegate::CreateStatic(&Local::AddMenuCommands));

        MenuExtensibilityManager->AddExtender(VariablesWatch);
	}

	/** Unregisters main menu and tool bar menu extensions. */
	void UnregisterMenuExtensions()
	{
		MenuExtensibilityManager.Reset();
		ToolBarExtensibilityManager.Reset();
	}

    static void OpenVariablesWatch()
    {

    }

    static void CreateToolListMenu(FMenuBuilder& MenuBuilder)
    {
        FUIAction action(FExecuteAction::CreateStatic(&FVariablesSystemEditorModule::OpenVariablesWatch));

        MenuBuilder.AddMenuEntry(
            LOCTEXT("Variables", "VariablesCategory"),
            LOCTEXT("Variables", "VariablesCategoryTooltip"),
            FSlateIcon(),
            action
        );
    }

private:

	/** Holds the menu extensibility manager. */
	TSharedPtr<FExtensibilityManager> MenuExtensibilityManager;

	/** The collection of registered asset type actions. */
	TArray<TSharedRef<IAssetTypeActions>> RegisteredAssetTypeActions;

	/** Holds the plug-ins style set. */
	TSharedPtr<ISlateStyle> Style;

	/** Holds the tool bar extensibility manager. */
	TSharedPtr<FExtensibilityManager> ToolBarExtensibilityManager;
};


IMPLEMENT_MODULE(FVariablesSystemEditorModule, VariablesSystemEditor);


#undef LOCTEXT_NAMESPACE
