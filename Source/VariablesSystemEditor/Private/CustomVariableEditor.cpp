// Copyright Out-of-the-Box Plugins 2018-2021. All Rights Reserved.

#include "CustomVariableEditor.h"

#include "EditorReimportHandler.h"
#include "EditorStyleSet.h"
#include "IStructureDetailsView.h"
#include "ToolMenus.h"
#include "UObject/NameTypes.h"
#include "Widgets/Docking/SDockTab.h"

#define LOCTEXT_NAMESPACE "AutomationWizard"

namespace CommandAssetEditor
{
static const FName AppIdentifier("CommandEditorApp");
static const FName CommandEditorTabId("CommandEditor");
static const FName CommandDetailsTabId("CommandDetails");
static const FName CommandSuggestionsTabId("CommandSuggestions");
}	 // namespace CommandAssetEditor

void FVsCustomVariableEditor::RegisterToolBar()
{
	const FName MenuName = GetToolMenuToolbarName();

	// Our button is already registered to the toolbar, no need to re-register.
	if (UToolMenus::Get()->IsMenuRegistered(MenuName))
	{
		return;
	}

	// Find the toolbar
	UToolMenu* ToolBar = UToolMenus::Get()->RegisterMenu(MenuName, "AssetEditor.DefaultToolBar", EMultiBoxType::ToolBar);
	const FToolMenuInsert InsertAfterAssetSection("Asset", EToolMenuInsertType::After);
}

void FVsCustomVariableEditor::Initialize(
	UGlobalCustomVariable* InCommand, const EToolkitMode::Type InMode, const TSharedPtr<class IToolkitHost>& InToolkitHost)
{
	CommandAsset = InCommand;
	CommandAsset->SetFlags(RF_Transactional);

	// clang-format off
	// create tab layout
	const TSharedRef<FTabManager::FLayout> Layout = FTabManager::NewLayout("Standalone_CommandAssetEditor")
	->AddArea
	(
		FTabManager::NewPrimaryArea() ->SetOrientation(Orient_Vertical)
		->Split
		(
			FTabManager::NewStack()
			->SetSizeCoefficient(0.1f)
			->SetHideTabWell( true )
			->AddTab(GetToolbarTabId(), ETabState::OpenedTab)
		)
		->Split
		(
			FTabManager::NewSplitter() ->SetOrientation(Orient_Horizontal) ->SetSizeCoefficient(0.9f)
			->Split
			(
			FTabManager::NewStack()
				->AddTab(CommandAssetEditor::CommandEditorTabId, ETabState::OpenedTab)
				->SetHideTabWell(true)
				->SetSizeCoefficient(0.7f)
			)
			->Split
			(
				FTabManager::NewStack()
				->SetSizeCoefficient(0.3f)
				->SetForegroundTab(CommandAssetEditor::CommandDetailsTabId)
				->AddTab( CommandAssetEditor::CommandDetailsTabId, ETabState::OpenedTab )
				->AddTab( CommandAssetEditor::CommandSuggestionsTabId, ETabState::OpenedTab )
			)
			
		)
	);
	// clang-format on

	RegisterToolBar();

	FAssetEditorToolkit::InitAssetEditor(InMode, InToolkitHost, CommandAssetEditor::AppIdentifier, Layout, true, true, InCommand);

	RegenerateMenusAndToolbars();
}

void FVsCustomVariableEditor::RegisterTabSpawners(const TSharedRef<FTabManager>& InTabManager)
{
	WorkspaceMenuCategory =
		InTabManager->AddLocalWorkspaceMenuCategory(LOCTEXT("WorkspaceMenu_CommandAssetEditor", "Command Asset Editor"));
	const auto WorkspaceMenuCategoryRef = WorkspaceMenuCategory.ToSharedRef();

	FAssetEditorToolkit::RegisterTabSpawners(InTabManager);

	InTabManager
		->RegisterTabSpawner(
			CommandAssetEditor::CommandDetailsTabId, FOnSpawnTab::CreateSP(this, &FVsCustomVariableEditor::SpawnTabCommandDetails))
		.SetDisplayName(LOCTEXT("CommandDetailsTabName", "Command Details"))
		.SetGroup(WorkspaceMenuCategoryRef)
		.SetIcon(FSlateIcon(FEditorStyle::GetStyleSetName(), "LevelEditor.Tabs.Viewports"));
}

void FVsCustomVariableEditor::UnregisterTabSpawners(const TSharedRef<FTabManager>& InTabManager)
{
	FAssetEditorToolkit::UnregisterTabSpawners(InTabManager);

	InTabManager->UnregisterTabSpawner(CommandAssetEditor::CommandEditorTabId);
	InTabManager->UnregisterTabSpawner(CommandAssetEditor::CommandDetailsTabId);
}

FText FVsCustomVariableEditor::GetBaseToolkitName() const
{
	return LOCTEXT("AppLabel", "Command Asset Editor");
}

FName FVsCustomVariableEditor::GetToolkitFName() const
{
	return FName("CommandAssetEditor");
}

FLinearColor FVsCustomVariableEditor::GetWorldCentricTabColorScale() const
{
	return FLinearColor(0.3f, 0.2f, 0.5f, 0.5f);
}

FString FVsCustomVariableEditor::GetWorldCentricTabPrefix() const
{
	return LOCTEXT("tWorldCentricCommandTabPrefix", "CommandAsset ").ToString();
}

void FVsCustomVariableEditor::AddReferencedObjects(FReferenceCollector& Collector)
{
	Collector.AddReferencedObject(CommandAsset);
}

void FVsCustomVariableEditor::PreChange(const UUserDefinedStruct* Struct, FStructureEditorUtils::EStructureEditorChangeInfo Info)
{
}

void FVsCustomVariableEditor::PostChange(const UUserDefinedStruct* Struct, FStructureEditorUtils::EStructureEditorChangeInfo Info)
{
	if (Struct && CommandAsset && CommandAsset->RowStruct == Struct)
	{
		HandlePostChange();
	}
}

void FVsCustomVariableEditor::HandlePostChange()
{
	FPropertyEditorModule& PropertyEditorModule = FModuleManager::GetModuleChecked<FPropertyEditorModule>("PropertyEditor");

	FDetailsViewArgs DetailsViewArgs;
	DetailsViewArgs.bUpdatesFromSelection = false;
	DetailsViewArgs.bLockable = false;
	DetailsViewArgs.bAllowSearch = false;
	DetailsViewArgs.bShowPropertyMatrixButton = false;
	DetailsViewArgs.NameAreaSettings = FDetailsViewArgs::HideNameArea;
	DetailsViewArgs.ViewIdentifier = NAME_None;
	DetailsViewArgs.bShowCustomFilterOption = false;
	DetailsViewArgs.bShowOptions = false;

	FStructureDetailsViewArgs StructViewArgs;

	TSharedRef<FStructOnScope> StructOnScope =
		MakeShared<FStructOnScope>(CommandAsset->RowStruct, CommandAsset->SavedData.GetData());
	TSharedRef<IStructureDetailsView> StructureDetailsView =
		PropertyEditorModule.CreateStructureDetailView(DetailsViewArgs, StructViewArgs, StructOnScope);

	SpawnedTab->SetContent(StructureDetailsView->GetWidget().ToSharedRef());
}

void FVsCustomVariableEditor::OnSuggestionFromPanelSelected(const FString& Suggestion)
{
	if (CommandEditorWidget.IsValid())
	{
		// CommandEditorWidget->AddExternalSuggestion(Suggestion);
	}
}

TSharedRef<SDockTab> FVsCustomVariableEditor::SpawnTabCommandDetails(const FSpawnTabArgs& Args)
{
	// clang-format off
	SAssignNew(SpawnedTab, SDockTab)
		.Icon( FEditorStyle::GetBrush("SoundClassEditor.Tabs.Properties") )
		.Label(NSLOCTEXT("EnvironmentQueryEditor", "PropertiesTab", "Details"))
		.Label(LOCTEXT("PropertiesTab", "Details"));
	// clang-format on

	HandlePostChange();

	return SpawnedTab.ToSharedRef();
}

#undef LOCTEXT_NAMESPACE
