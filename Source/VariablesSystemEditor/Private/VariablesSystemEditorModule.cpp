// Copyright Out-of-the-Box Plugins 2018-2021. All Rights Reserved.
#include "VariablesSystemEditorModule.h"

#include "AssetToolsModule.h"
#include "ContentBrowserDataMenuContexts.h"
#include "ContentBrowserDataSubsystem.h"
#include "ToolMenus.h"
#include "VSFactory.h"
#include "VSLog.h"
#include "VariablesSystem/Generated/Global/GlobalIntVariable.h"
#include "VariablesWatchWidget.h"
#include "Windows/WindowsPlatformApplicationMisc.h"
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

static const TCHAR* VAR_PREFIX = TEXT("BPVar");

bool FVariablesSystemEditorModule::CanPasteVariable() const
{
	FString ClipboardText;
	FPlatformApplicationMisc::ClipboardPaste(ClipboardText);
	return ClipboardText.StartsWith(VAR_PREFIX, ESearchCase::CaseSensitive);
}

void FVariablesSystemEditorModule::OnPasteVariables(const FString& Path)
{
	if (!CanPasteVariable())
	{
		return;
	}

	FString ClipboardText;
	FPlatformApplicationMisc::ClipboardPaste(ClipboardText);

	UContentBrowserDataSubsystem* ContentBrowserDataSubsystem = GEditor->GetEditorSubsystem<UContentBrowserDataSubsystem>();
	FString PackagePath;
	ContentBrowserDataSubsystem->TryConvertVirtualPath(Path, PackagePath);

	FBPVariableDescription Description;
	FStringOutputDevice Errors;
	const TCHAR* Import = ClipboardText.GetCharArray().GetData() + FCString::Strlen(VAR_PREFIX);
	FBPVariableDescription::StaticStruct()->ImportText(
		Import, &Description, nullptr, 0, &Errors, FBPVariableDescription::StaticStruct()->GetName());
	if (Errors.IsEmpty())
	{
		if (Description.VarType.PinCategory == UEdGraphSchema_K2::PC_Int)
		{
			FAssetToolsModule& AssetToolsModule = FAssetToolsModule::GetModule();
			FString NewPackageName;
			FString NewAssetName;
			FString DefaultName = FString::Printf(TEXT("%s/%s"), *PackagePath, *Description.VarName.ToString());
			// Sequences created in VR editor will have a sequential VRSequencer00X naming scheme and be stored in Game/Sequences
			AssetToolsModule.Get().CreateUniqueAssetName(DefaultName, TEXT(""), NewPackageName, NewAssetName);

			UVSGlobalFactory* Factory = NewObject<UVSGlobalFactory>();
			UClass* TargetClass = UGlobalIntVariable::StaticClass();
			Factory->ChoosenVariableType = TargetClass;
			AssetToolsModule.Get().CreateAsset(NewAssetName, PackagePath, TargetClass, Factory);
		}
	}
}

//////////////////////////////////////////////////////////////////////////
// IModuleInterface interface
void FVariablesSystemEditorModule::StartupModule()
{
	LOG_TRACE();

	RegisterAssetTools();
	RegisterMenuExtensions();

	UToolMenu* ContextMenu = UToolMenus::Get()->ExtendMenu("ContentBrowser.AddNewContextMenu");
	FToolMenuSection& ContextMenuSection = ContextMenu->AddSection("AdvancedActions", INVTEXT("AdvancedActions"));

	ContextMenuSection.AddDynamicEntry("PasteVariables",
		FNewToolMenuSectionDelegate::CreateLambda(
			[=](FToolMenuSection& InSection)
			{
				UContentBrowserDataMenuContext_AddNewMenu* AddNewMenuContext =
					InSection.FindContext<UContentBrowserDataMenuContext_AddNewMenu>();
				if (AddNewMenuContext && AddNewMenuContext->bCanBeModified && AddNewMenuContext->bContainsValidPackagePath)
				{
					TArray<FName> SelectedPaths = AddNewMenuContext->SelectedPaths;

					InSection.AddMenuEntry("PasteVariables", LOCTEXT("PasteVariables", "PasteVariables"),
						LOCTEXT("PasteVariablesTooltip", "PasteVariablesTooltip"), FSlateIcon(),
						FUIAction(FExecuteAction::CreateLambda(
									  [=]()
									  {
										  const FString SelectedPath = SelectedPaths[0].ToString();
										  OnPasteVariables(SelectedPath);
									  }),
							FCanExecuteAction::CreateLambda(
								[=]()
								{
									const bool bCanPaste = SelectedPaths.Num() > 0 && CanPasteVariable();
									return bCanPaste;
								})));
				}
			}));
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

//////////////////////////////////////////////////////////////////////////
// Extensions
TSharedRef<SDockTab> FVariablesSystemEditorModule::SpawnVariablesWatchTab(const FSpawnTabArgs& Args)
{
	return SNew(SDockTab).TabRole(ETabRole::NomadTab)[SNew(SVSWatchWidget)];
}

#undef LOCTEXT_NAMESPACE
