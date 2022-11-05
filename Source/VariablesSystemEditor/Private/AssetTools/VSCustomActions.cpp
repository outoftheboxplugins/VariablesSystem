// Copyright Out-of-the-Box Plugins 2018-2021. All Rights Reserved.

#include "VSCustomActions.h"

#include "CustomVariableEditor.h"
#include "GlobalCustomVariable.h"

#define LOCTEXT_NAMESPACE "AutomationWizard"

namespace
{
FName CustomAssetCategoryRegisterName = FName(TEXT("OutOfTheBox"));
FText CustomAssetCategoryDisplayName = LOCTEXT("OutOfTheBoxCategory", "OutOfTheBox");
}	 // namespace

FVSCustomActions::FVSCustomActions()
{
	IAssetTools& AssetTools = FAssetToolsModule::GetModule().Get();
	AssetCategoryBit = AssetTools.RegisterAdvancedAssetCategory(CustomAssetCategoryRegisterName, CustomAssetCategoryDisplayName);
}

FText FVSCustomActions::GetName() const
{
	return LOCTEXT("AssetName", "Automation Command 2");
}

FColor FVSCustomActions::GetTypeColor() const
{
	return FColor(183, 83, 183);
}

uint32 FVSCustomActions::GetCategories()
{
	return AssetCategoryBit;
}

UClass* FVSCustomActions::GetSupportedClass() const
{
	return UGlobalCustomVariable::StaticClass();
}

void FVSCustomActions::OpenAssetEditor(const TArray<UObject*>& InObjects, TSharedPtr<IToolkitHost> EditWithinLevelEditor)
{
	const EToolkitMode::Type Mode = EditWithinLevelEditor.IsValid() ? EToolkitMode::WorldCentric : EToolkitMode::Standalone;

	for (auto ObjIt = InObjects.CreateConstIterator(); ObjIt; ++ObjIt)
	{
		const auto CommandAsset = Cast<UGlobalCustomVariable>(*ObjIt);
		if (CommandAsset != nullptr)
		{
			TSharedRef<FVsCustomVariableEditor> EditorToolkit = MakeShared<FVsCustomVariableEditor>();
			EditorToolkit->Initialize(CommandAsset, Mode, EditWithinLevelEditor);
		}
	}
}

#undef LOCTEXT_NAMESPACE
