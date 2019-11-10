// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#include "VariablesSystemEditorModule.h"

//TODO: Rename the second private folder.
//TODO: sort includes.
#include "Containers/Array.h"
#include "ISettingsModule.h"
#include "ISettingsSection.h"
#include "Modules/ModuleManager.h"
#include "Templates/SharedPointer.h"
#include "Toolkits/AssetEditorToolkit.h"

#include "AssetTools/VariablesSystemActions.h"
#include "Framework/Commands/UIAction.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "LevelEditor.h"
#include "SlateApplication.h"
#include "VariablesSystemEditor/Private/WatchWindow/CustomWindow.h"

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
    IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();

    AssetTools.UnregisterAssetTypeActions(AssetActions.ToSharedRef());
}

void FVariablesSystemEditorModule::RegisterMenuExtensions()
{
    WatchMenuExtender = MakeShareable(new FExtender());

    WatchMenuExtender->AddMenuExtension("WindowLayout", EExtensionHook::After, nullptr, FMenuExtensionDelegate::CreateRaw(this, &FVariablesSystemEditorModule::AddMenuExtension));

    FLevelEditorModule& LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");
    LevelEditorModule.GetMenuExtensibilityManager()->AddExtender(WatchMenuExtender);
}

void FVariablesSystemEditorModule::UnregisterMenuExtensions()
{
    FLevelEditorModule& LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");
    LevelEditorModule.GetMenuExtensibilityManager()->RemoveExtender(WatchMenuExtender);
}

void FVariablesSystemEditorModule::AddMenuExtension(FMenuBuilder& MenuBuilder)
{
    MenuBuilder.AddMenuEntry(
        FText(LOCTEXT("VariablesSystem_OpenWatchName", "Open Variables Watch")),
        LOCTEXT("VariablesSystem_OpenWatchTooltip", "Open an editor window to see the current values of all your variables."),
        FSlateIcon(),
        FUIAction(FExecuteAction::CreateRaw(this, &FVariablesSystemEditorModule::OpenVariablesWatch)));
}

void FVariablesSystemEditorModule::OpenVariablesWatch()
{
    // TODO: Prevent from opening a second window
    // TODO: Allow to select variables to show
    // TODO: Make it dockable
    // TODO: Make it refresh every second

    const FText TitleText = NSLOCTEXT("Paper2D", "Paper2D_ExtractSprites", "Extract sprites");
    // Create the window to pick the class
    TSharedRef<SWindow> ExtractSpritesWindow = SNew(SWindow)
        .Title(TitleText)
        .SizingRule(ESizingRule::UserSized)
        .ClientSize(FVector2D(1000.f, 700.f))
        .AutoCenter(EAutoCenter::PreferredWorkArea)
        .SupportsMinimize(false);

    TSharedRef<SVarEditorWindow> PaperExtractSpritesDialog = SNew(SVarEditorWindow);

    ExtractSpritesWindow->SetContent(PaperExtractSpritesDialog);
    TSharedPtr<SWindow> RootWindow = FGlobalTabmanager::Get()->GetRootWindow();
    if (RootWindow.IsValid())
    {
        FSlateApplication::Get().AddWindowAsNativeChild(ExtractSpritesWindow, RootWindow.ToSharedRef());
    }
    else
    {
        FSlateApplication::Get().AddWindow(ExtractSpritesWindow);
    }
}

#undef LOCTEXT_NAMESPACE