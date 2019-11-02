// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "VariablesSystemEditorToolkit.h"

#include "Editor.h"
#include "EditorReimportHandler.h"
#include "EditorStyleSet.h"
#include "SVariablesSystemEditor.h"
#include "BaseVariable.h"
#include "UObject/NameTypes.h"
#include "Widgets/Docking/SDockTab.h"
#include "Window/CustomWindow.h"

//TODO: Delete those after moving.
#include "Modules/ModuleManager.h"
#include "AssetRegistryModule.h"


//TODO: delete duplicate.
static TArray<UBaseVariable*> GetAllVariables()
{
    TArray<UBaseVariable*> Variables;

    if (FModuleManager::Get().IsModuleLoaded("AssetRegistry"))
    {
        FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
        TArray<FAssetData> AssetData;
        AssetRegistryModule.Get().GetAssetsByClass(FName("BaseVariable"), AssetData);
        for (int i = 0; i < AssetData.Num(); i++) {
            UBaseVariable* VariableFound = Cast<UBaseVariable>(AssetData[i].GetAsset());
            if (VariableFound != NULL) {
                Variables.Add(VariableFound);
            }
        }
    }

    return Variables;
}

#define LOCTEXT_NAMESPACE "FVariablesSystemEditorToolkit"

DEFINE_LOG_CATEGORY_STATIC(LogVariablesSystemEditor, Log, All);


/* Local constants
 *****************************************************************************/

namespace VariablesSystemEditor
{
	static const FName AppIdentifier("VariablesSystemEditorApp");
	static const FName TabId("TextEditor");
}


/* FVariablesSystemEditorToolkit structors
 *****************************************************************************/

FVariablesSystemEditorToolkit::FVariablesSystemEditorToolkit(const TSharedRef<ISlateStyle>& InStyle)
	: BaseVariable(nullptr)
	, Style(InStyle)
{ }


FVariablesSystemEditorToolkit::~FVariablesSystemEditorToolkit()
{
	FReimportManager::Instance()->OnPreReimport().RemoveAll(this);
	FReimportManager::Instance()->OnPostReimport().RemoveAll(this);

	GEditor->UnregisterForUndo(this);
}


/* FVariablesSystemEditorToolkit interface
 *****************************************************************************/

void FVariablesSystemEditorToolkit::Initialize(UBaseVariable* InBaseVariable, const EToolkitMode::Type InMode, const TSharedPtr<class IToolkitHost>& InToolkitHost)
{
	BaseVariable = InBaseVariable;

	// Support undo/redo
	BaseVariable->SetFlags(RF_Transactional);
	GEditor->RegisterForUndo(this);

	// create tab layout
	const TSharedRef<FTabManager::FLayout> Layout = FTabManager::NewLayout("Standalone_VariablesSystemEditor")
		->AddArea
		(
			FTabManager::NewPrimaryArea()
				->SetOrientation(Orient_Horizontal)
				->Split
				(
					FTabManager::NewSplitter()
						->SetOrientation(Orient_Vertical)
						->SetSizeCoefficient(0.66f)
						->Split
						(
							FTabManager::NewStack()
								->AddTab(GetToolbarTabId(), ETabState::OpenedTab)
								->SetHideTabWell(true)
								->SetSizeCoefficient(0.1f)
								
						)
						->Split
						(
							FTabManager::NewStack()
								->AddTab(VariablesSystemEditor::TabId, ETabState::OpenedTab)
								->SetHideTabWell(true)
								->SetSizeCoefficient(0.9f)
						)
				)
		);

	FAssetEditorToolkit::InitAssetEditor(
		InMode,
		InToolkitHost,
		VariablesSystemEditor::AppIdentifier,
		Layout,
		true /*bCreateDefaultStandaloneMenu*/,
		true /*bCreateDefaultToolbar*/,
		InBaseVariable
	);

	RegenerateMenusAndToolbars();
}


/* FAssetEditorToolkit interface
 *****************************************************************************/

FString FVariablesSystemEditorToolkit::GetDocumentationLink() const
{
	return FString(TEXT("https://github.com/ue4plugins/VariablesSystem"));
}


void FVariablesSystemEditorToolkit::RegisterTabSpawners(const TSharedRef<FTabManager>& InTabManager)
{
    WorkspaceMenuCategory = InTabManager->AddLocalWorkspaceMenuCategory(LOCTEXT("WorkspaceMenu_VariablesSystemEditor", "Var System Editor"));
	auto WorkspaceMenuCategoryRef = WorkspaceMenuCategory.ToSharedRef();

	FAssetEditorToolkit::RegisterTabSpawners(InTabManager);

	InTabManager->RegisterTabSpawner(VariablesSystemEditor::TabId, FOnSpawnTab::CreateSP(this, &FVariablesSystemEditorToolkit::HandleTabManagerSpawnTab, VariablesSystemEditor::TabId))
		.SetDisplayName(LOCTEXT("TextEditorTabName", "Text Editor"))
		.SetGroup(WorkspaceMenuCategoryRef)
		.SetIcon(FSlateIcon(FEditorStyle::GetStyleSetName(), "LevelEditor.Tabs.Viewports"));
}


void FVariablesSystemEditorToolkit::UnregisterTabSpawners(const TSharedRef<FTabManager>& InTabManager)
{
	FAssetEditorToolkit::UnregisterTabSpawners(InTabManager);

	InTabManager->UnregisterTabSpawner(VariablesSystemEditor::TabId);
}


/* IToolkit interface
 *****************************************************************************/

FText FVariablesSystemEditorToolkit::GetBaseToolkitName() const
{
	return LOCTEXT("AppLabel", "Var System Editor");
}


FName FVariablesSystemEditorToolkit::GetToolkitFName() const
{
	return FName("VariablesSystemEditor");
}


FLinearColor FVariablesSystemEditorToolkit::GetWorldCentricTabColorScale() const
{
	return FLinearColor(0.3f, 0.2f, 0.5f, 0.5f);
}


FString FVariablesSystemEditorToolkit::GetWorldCentricTabPrefix() const
{
	return LOCTEXT("WorldCentricTabPrefix", "VariablesSystem ").ToString();
}


/* FGCObject interface
 *****************************************************************************/

void FVariablesSystemEditorToolkit::AddReferencedObjects(FReferenceCollector& Collector)
{
	Collector.AddReferencedObject(BaseVariable);
}


/* FEditorUndoClient interface
*****************************************************************************/

void FVariablesSystemEditorToolkit::PostUndo(bool bSuccess)
{ }


void FVariablesSystemEditorToolkit::PostRedo(bool bSuccess)
{
	PostUndo(bSuccess);
}


/* FVariablesSystemEditorToolkit callbacks
 *****************************************************************************/

TSharedRef<SDockTab> FVariablesSystemEditorToolkit::HandleTabManagerSpawnTab(const FSpawnTabArgs& Args, FName TabIdentifier)
{
	TSharedPtr<SWidget> TabWidget = SNullWidget::NullWidget;

	if (TabIdentifier == VariablesSystemEditor::TabId)
	{
		//TabWidget = SNew(SVariablesSystemEditor, BaseVariable, Style);
        TArray<UBaseVariable*> variables = GetAllVariables();
		TabWidget = SNew(SVarEditorWindow, variables, Style);
	}

	return SNew(SDockTab)
		.TabRole(ETabRole::PanelTab)
		[
			TabWidget.ToSharedRef()
		];
}

#undef LOCTEXT_NAMESPACE
