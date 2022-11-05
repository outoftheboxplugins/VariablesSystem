// Copyright Out-of-the-Box Plugins 2018-2021. All Rights Reserved.

#include "CustomVariableEditor.h"

// TODO: Check if all the includes here are needed
// TODO: Put all the engine includes betwenn <>
#include "EditorReimportHandler.h"
#include "EditorStyleSet.h"
#include "IStructureDetailsView.h"
#include "ToolMenus.h"
#include "UObject/NameTypes.h"
#include "Widgets/Docking/SDockTab.h"

#define LOCTEXT_NAMESPACE "VariablesSystem"

namespace
{
const FName AppIdentifier("CustomVariableEditor");
const FName VariableDetailsTabId("VariableDetails");
}	 // namespace

void FVsCustomVariableEditor::Initialize(
	UGlobalCustomVariable* InVariable, const EToolkitMode::Type InMode, const TSharedPtr<IToolkitHost>& InToolkitHost)
{
	CommandAsset = InVariable;

	// TODO: Check if this is needed for undo/redo. Do we need to inherit from the undo client as well ?
	CommandAsset->SetFlags(RF_Transactional);

	// clang-format off
	const TSharedRef<FTabManager::FLayout> Layout = FTabManager::NewLayout("Standalone_CommandAssetEditor")
	->AddArea
	(
		//TODO: Add a second split tab where the user could change the struct blueprint directly so he doesn't have to open 2 editors at the same time
		FTabManager::NewPrimaryArea()->SetOrientation(Orient_Horizontal)
		->Split
		(
			
			FTabManager::NewStack()
			->SetSizeCoefficient(0.5f)
			->SetForegroundTab(VariableDetailsTabId)
			->AddTab(VariableDetailsTabId, ETabState::OpenedTab)
		)
	);
	// clang-format on

	FAssetEditorToolkit::InitAssetEditor(InMode, InToolkitHost, AppIdentifier, Layout, true, true, InVariable);
}

void FVsCustomVariableEditor::RegisterTabSpawners(const TSharedRef<FTabManager>& InTabManager)
{
	WorkspaceMenuCategory =
		InTabManager->AddLocalWorkspaceMenuCategory(LOCTEXT("WorkspaceMenu_CommandAssetEditor", "Command Asset Editor"));
	const auto WorkspaceMenuCategoryRef = WorkspaceMenuCategory.ToSharedRef();

	FAssetEditorToolkit::RegisterTabSpawners(InTabManager);

	InTabManager
		->RegisterTabSpawner(VariableDetailsTabId, FOnSpawnTab::CreateSP(this, &FVsCustomVariableEditor::SpawnTabCommandDetails))
		.SetDisplayName(LOCTEXT("CommandDetailsTabName", "Command Details"))
		.SetGroup(WorkspaceMenuCategoryRef)
		.SetIcon(FSlateIcon(FEditorStyle::GetStyleSetName(), "LevelEditor.Tabs.Viewports"));
}

void FVsCustomVariableEditor::UnregisterTabSpawners(const TSharedRef<FTabManager>& InTabManager)
{
	FAssetEditorToolkit::UnregisterTabSpawners(InTabManager);

	InTabManager->UnregisterTabSpawner(VariableDetailsTabId);
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
	if (Struct && CommandAsset && CommandAsset->StructType == Struct)
	{
		HandlePostChange();
	}
}

void FVsCustomVariableEditor::HandlePostChange()
{
	// TODO: can we handle struct changes better property wise?
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
		MakeShared<FStructOnScope>(CommandAsset->StructType, CommandAsset->StructData.GetData());
	TSharedRef<IStructureDetailsView> StructureDetailsView =
		PropertyEditorModule.CreateStructureDetailView(DetailsViewArgs, StructViewArgs, StructOnScope);

	// clang-format off
	TSharedRef<SWidget> Inspector = SNew(SVerticalBox)
		+ SVerticalBox::Slot()
		.AutoHeight()
		.HAlign(HAlign_Center)
		.Padding(30)
		[
			StructureDetailsView->GetWidget().ToSharedRef()
		]
		+ SVerticalBox::Slot()
		.AutoHeight()
		.HAlign(HAlign_Center)
		[
			SNew(SButton)
			.HAlign(HAlign_Center)
			.Text(LOCTEXT("Save", "Save"))
			.OnClicked_Lambda([=]()
			{
				CommandAsset->Save();
				return FReply::Handled();
			})
		]
		+ SVerticalBox::Slot()
		.AutoHeight()
		.HAlign(HAlign_Center)
		[
			SNew(SButton)
			.HAlign(HAlign_Center)
			.Text(LOCTEXT("Load", "Load"))
			.OnClicked_Lambda([=]()
			{
				CommandAsset->Load();
				return FReply::Handled();
			})
		];
	// clang-format on

	SpawnedTab->SetContent(Inspector);
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
