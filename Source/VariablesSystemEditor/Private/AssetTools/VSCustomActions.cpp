// Copyright Out-of-the-Box Plugins 2018-2021. All Rights Reserved.

#include "VSCustomActions.h"

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
	return LOCTEXT("AssetName", "Automation Command");
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

#undef LOCTEXT_NAMESPACE
