// Copyright Out-of-the-Box Plugins 2018-2023. All Rights Reserved.include "GlobalCustomVariable.h"

#include "VSCustomActions.h"

#include "CustomVariableEditor.h"

#define LOCTEXT_NAMESPACE "VariablesSystem"

// TODO: Move these to shared category
namespace
{
FName CustomAssetCategoryRegisterName = FName(TEXT("OutOfTheBox"));
FText CustomAssetCategoryDisplayName = LOCTEXT("OutOfTheBoxCategory", "OutOfTheBox");
}	 // namespace

FVSCustomActions::FVSCustomActions()
{
	// TODO: Move these to shared category
	IAssetTools& AssetTools = FAssetToolsModule::GetModule().Get();
	AssetCategoryBit = AssetTools.RegisterAdvancedAssetCategory(CustomAssetCategoryRegisterName, CustomAssetCategoryDisplayName);
}

FText FVSCustomActions::GetName() const
{
	// Abstract function that must be implemented, but leaving it blank so autocomplete with type value.
	return LOCTEXT("EmptyText", "");
}

FColor FVSCustomActions::GetTypeColor() const
{
	// TODO: This should be changed to red now that we don't know what type of variable we are holding
	return FColor(183, 83, 183);
}

uint32 FVSCustomActions::GetCategories()
{
	// TODO: This should use our shared getter
	return AssetCategoryBit;
}

UClass* FVSCustomActions::GetSupportedClass() const
{
	// TODO: This should use the base class for Custom variables
	return UGlobalCustomVariable::StaticClass();
}

void FVSCustomActions::OpenAssetEditor(const TArray<UObject*>& InObjects, TSharedPtr<IToolkitHost> EditWithinLevelEditor)
{
	// TODO: Find out what the difference between those 2 are
	const EToolkitMode::Type Mode = EditWithinLevelEditor.IsValid() ? EToolkitMode::WorldCentric : EToolkitMode::Standalone;

	// open an individual editor for all the currently selected assets
	for (UObject* Object : InObjects)
	{
		if (UGlobalCustomVariable* CommandAsset = Cast<UGlobalCustomVariable>(Object))
		{
			const TSharedRef<FVsCustomVariableEditor> EditorToolkit = MakeShared<FVsCustomVariableEditor>();
			EditorToolkit->Initialize(CommandAsset, Mode, EditWithinLevelEditor);
		}
	}
}

#undef LOCTEXT_NAMESPACE
