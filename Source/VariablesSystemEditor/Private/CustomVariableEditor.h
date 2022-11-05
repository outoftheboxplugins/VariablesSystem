// Copyright Out-of-the-Box Plugins 2018-2021. All Rights Reserved.

#pragma once

#include "GlobalCustomVariable.h"
#include "Kismet2/StructureEditorUtils.h"

class SAwCommandArgumentsEditor;

class FVsCustomVariableEditor : public FAssetEditorToolkit, public FGCObject, public FStructureEditorUtils::INotifyOnStructChanged
{
public:
	void Initialize(
		UGlobalCustomVariable* InCommand, const EToolkitMode::Type InMode, const TSharedPtr<IToolkitHost>& InToolkitHost);

private:
	// FAssetEditorToolkit interface
	virtual void RegisterTabSpawners(const TSharedRef<FTabManager>& InTabManager) override;
	virtual void UnregisterTabSpawners(const TSharedRef<FTabManager>& InTabManager) override;

	// IToolkit interface
	virtual FText GetBaseToolkitName() const override;
	virtual FName GetToolkitFName() const override;
	virtual FLinearColor GetWorldCentricTabColorScale() const override;
	virtual FString GetWorldCentricTabPrefix() const override;

	// FGCObject interface
	virtual void AddReferencedObjects(FReferenceCollector& Collector) override;

	// INotifyOnStructChanged interface
	virtual void PreChange(const class UUserDefinedStruct* Struct, FStructureEditorUtils::EStructureEditorChangeInfo Info) override;
	virtual void PostChange(
		const class UUserDefinedStruct* Struct, FStructureEditorUtils::EStructureEditorChangeInfo Info) override;

	// Menu & Toolbar commands
	void RegisterToolBar();

	void OnSuggestionFromPanelSelected(const FString& Suggestion);

	// Callback for spawning the Properties tab.
	TSharedRef<SDockTab> SpawnTabCommandDetails(const FSpawnTabArgs& Args);

	void HandlePostChange();

private:
	// Command that is currently edited
	UGlobalCustomVariable* CommandAsset = nullptr;

	// Editor text widget where the arguments are edited
	TSharedPtr<SAwCommandArgumentsEditor> CommandEditorWidget;

	TSharedPtr<SDockTab> SpawnedTab;
};
