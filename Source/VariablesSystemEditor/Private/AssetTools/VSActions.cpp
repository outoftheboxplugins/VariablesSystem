// Copyright Out-of-the-Box Plugins 2018-2021. All Rights Reserved.
#include "VSActions.h"

#include "GraphEditorSettings.h"
#include "IncludeAll.h"
#include "LevelEditor.h"
#include "VariablesSystemEditorModule.h"

#define LOCTEXT_NAMESPACE "VariablesSystemEditor"

namespace
{
FColor EditorAssetBackgroundColor = FColor(77.0f, 77.0f, 77.0f);
uint32 ThumbnailSize = 72;

FName AssetCategoryRegisterName = FName(TEXT("OutOfTheBox"));
FText AssetCategoryDisplayName = LOCTEXT("OutOfTheBoxCategory", "OutOfTheBox");

FLinearColor GetAssetColorByVariable(const UBaseVariable* Variable)
{
	const UGraphEditorSettings* Settings = GetDefault<UGraphEditorSettings>();

	if (!Variable || !Settings)
	{
		return FLinearColor::White;
	}

#include "AssetColorByVariable.h"

	return Settings->WildcardPinTypeColor;
}
}	 // namespace

//////////////////////////////////////////////////////////////////////////
// FAssetTypeActions_Base interface
FVSActions::FVSActions()
{
	IAssetTools& AssetTools = FAssetToolsModule::GetModule().Get();
	AssetCategoryBit = AssetTools.RegisterAdvancedAssetCategory(AssetCategoryRegisterName, AssetCategoryDisplayName);
}

FText FVSActions::GetName() const
{
	// Abstract function that must be implemented, but leaving it blank so autocomplete with type value.
	return LOCTEXT("EmptyText", "");
}

FColor FVSActions::GetTypeColor() const
{
	return EditorAssetBackgroundColor;
}

uint32 FVSActions::GetCategories()
{
	return AssetCategoryBit;
}

UClass* FVSActions::GetSupportedClass() const
{
	return UBaseVariable::StaticClass();
}

TSharedPtr<SWidget> FVSActions::GetThumbnailOverlay(const FAssetData& AssetData) const
{
	FLevelEditorModule& LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");
	TSharedPtr<FAssetThumbnailPool> ThumbnailPool = LevelEditorModule.GetFirstLevelEditor()->GetThumbnailPool();

	TSharedRef<FAssetThumbnail> AssetThumbnail =
		MakeShared<FAssetThumbnail>(AssetData, ThumbnailSize, ThumbnailSize, ThumbnailPool);
	FAssetThumbnailConfig ThumbnailConfig;

	if (UBaseVariable* VariableAsset = Cast<UBaseVariable>(AssetData.GetAsset()))
	{
		ThumbnailConfig.AssetTypeColorOverride = GetAssetColorByVariable(VariableAsset);
	}

	return AssetThumbnail->MakeThumbnailWidget(ThumbnailConfig);
}

//////////////////////////////////////////////////////////////////////////
// Asset Actions
bool FVSActions::HasActions(const TArray<UObject*>& InObjects) const
{
	auto WeakVariables = GetTypedWeakObjectPtrs<UBaseVariable>(InObjects);
	TArray<UBaseVariable*> Variables;
	CopyFromWeakArray(Variables, WeakVariables);

	return Variables.Num() > 0;
}

void FVSActions::GetActions(const TArray<UObject*>& InObjects, FMenuBuilder& MenuBuilder)
{
	FAssetTypeActions_Base::GetActions(InObjects, MenuBuilder);

	auto WeakVariables = GetTypedWeakObjectPtrs<UBaseVariable>(InObjects);
	TArray<UBaseVariable*> Variables;
	CopyFromWeakArray(Variables, WeakVariables);

	MenuBuilder.AddMenuEntry(LOCTEXT("AddToWatchTitle", "Add to watch"),
		LOCTEXT("AddToWatchToolTip", "Add the selected variables to your watch window."), FSlateIcon(),
		FUIAction(FExecuteAction::CreateLambda(
			[=]() { FVariablesSystemEditorModule::GetModule().OpenOrAddVariablesToWatch(Variables); })));
}

#undef LOCTEXT_NAMESPACE
