// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "VarSystemEditorToolkit.h"

#include "Editor.h"
#include "EditorReimportHandler.h"
#include "EditorStyleSet.h"
#include "SVarSystemEditor.h"
#include "BaseVariable.h"
#include "UObject/NameTypes.h"
#include "Widgets/Docking/SDockTab.h"

#define LOCTEXT_NAMESPACE "FVarSystemEditorToolkit"

DEFINE_LOG_CATEGORY_STATIC(LogVarSystemEditor, Log, All);


/* Local constants
 *****************************************************************************/

namespace VarSystemEditor
{
	static const FName AppIdentifier("VarSystemEditorApp");
	static const FName TabId("TextEditor");
}


/* FVarSystemEditorToolkit structors
 *****************************************************************************/

FVarSystemEditorToolkit::FVarSystemEditorToolkit(const TSharedRef<ISlateStyle>& InStyle)
	: BaseVariable(nullptr)
	, Style(InStyle)
{ }


FVarSystemEditorToolkit::~FVarSystemEditorToolkit()
{
	FReimportManager::Instance()->OnPreReimport().RemoveAll(this);
	FReimportManager::Instance()->OnPostReimport().RemoveAll(this);

	GEditor->UnregisterForUndo(this);
}


/* FVarSystemEditorToolkit interface
 *****************************************************************************/

void FVarSystemEditorToolkit::Initialize(UBaseVariable* InBaseVariable, const EToolkitMode::Type InMode, const TSharedPtr<class IToolkitHost>& InToolkitHost)
{
	BaseVariable = InBaseVariable;

	// Support undo/redo
	BaseVariable->SetFlags(RF_Transactional);
	GEditor->RegisterForUndo(this);

	// create tab layout
	const TSharedRef<FTabManager::FLayout> Layout = FTabManager::NewLayout("Standalone_VarSystemEditor")
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
								->AddTab(VarSystemEditor::TabId, ETabState::OpenedTab)
								->SetHideTabWell(true)
								->SetSizeCoefficient(0.9f)
						)
				)
		);

	FAssetEditorToolkit::InitAssetEditor(
		InMode,
		InToolkitHost,
		VarSystemEditor::AppIdentifier,
		Layout,
		true /*bCreateDefaultStandaloneMenu*/,
		true /*bCreateDefaultToolbar*/,
		InBaseVariable
	);

	RegenerateMenusAndToolbars();
}


/* FAssetEditorToolkit interface
 *****************************************************************************/

FString FVarSystemEditorToolkit::GetDocumentationLink() const
{
	return FString(TEXT("https://github.com/ue4plugins/VarSystem"));
}


void FVarSystemEditorToolkit::RegisterTabSpawners(const TSharedRef<FTabManager>& InTabManager)
{
	WorkspaceMenuCategory = InTabManager->AddLocalWorkspaceMenuCategory(LOCTEXT("WorkspaceMenu_VarSystemEditor", "Var System Editor"));
	auto WorkspaceMenuCategoryRef = WorkspaceMenuCategory.ToSharedRef();

	FAssetEditorToolkit::RegisterTabSpawners(InTabManager);

	InTabManager->RegisterTabSpawner(VarSystemEditor::TabId, FOnSpawnTab::CreateSP(this, &FVarSystemEditorToolkit::HandleTabManagerSpawnTab, VarSystemEditor::TabId))
		.SetDisplayName(LOCTEXT("TextEditorTabName", "Text Editor"))
		.SetGroup(WorkspaceMenuCategoryRef)
		.SetIcon(FSlateIcon(FEditorStyle::GetStyleSetName(), "LevelEditor.Tabs.Viewports"));
}


void FVarSystemEditorToolkit::UnregisterTabSpawners(const TSharedRef<FTabManager>& InTabManager)
{
	FAssetEditorToolkit::UnregisterTabSpawners(InTabManager);

	InTabManager->UnregisterTabSpawner(VarSystemEditor::TabId);
}


/* IToolkit interface
 *****************************************************************************/

FText FVarSystemEditorToolkit::GetBaseToolkitName() const
{
	return LOCTEXT("AppLabel", "Var System Editor");
}


FName FVarSystemEditorToolkit::GetToolkitFName() const
{
	return FName("VarSystemEditor");
}


FLinearColor FVarSystemEditorToolkit::GetWorldCentricTabColorScale() const
{
	return FLinearColor(0.3f, 0.2f, 0.5f, 0.5f);
}


FString FVarSystemEditorToolkit::GetWorldCentricTabPrefix() const
{
	return LOCTEXT("WorldCentricTabPrefix", "VarSystem ").ToString();
}


/* FGCObject interface
 *****************************************************************************/

void FVarSystemEditorToolkit::AddReferencedObjects(FReferenceCollector& Collector)
{
	Collector.AddReferencedObject(BaseVariable);
}


/* FEditorUndoClient interface
*****************************************************************************/

void FVarSystemEditorToolkit::PostUndo(bool bSuccess)
{ }


void FVarSystemEditorToolkit::PostRedo(bool bSuccess)
{
	PostUndo(bSuccess);
}


/* FVarSystemEditorToolkit callbacks
 *****************************************************************************/

TSharedRef<SDockTab> FVarSystemEditorToolkit::HandleTabManagerSpawnTab(const FSpawnTabArgs& Args, FName TabIdentifier)
{
	TSharedPtr<SWidget> TabWidget = SNullWidget::NullWidget;

	if (TabIdentifier == VarSystemEditor::TabId)
	{
		TabWidget = SNew(SVarSystemEditor, BaseVariable, Style);
	}

	return SNew(SDockTab)
		.TabRole(ETabRole::PanelTab)
		[
			TabWidget.ToSharedRef()
		];
}


#undef LOCTEXT_NAMESPACE
