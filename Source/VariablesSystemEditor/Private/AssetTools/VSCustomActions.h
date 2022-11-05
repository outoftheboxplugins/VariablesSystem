// Copyright Out-of-the-Box Plugins 2018-2023. All Rights Reserved.include "GlobalCustomVariable.h"

#pragma once

#include <AssetTypeActions_Base.h>

/**
 * Asset actions for the custom variable assets
 */
class FVSCustomActions : public FAssetTypeActions_Base
{
public:
	FVSCustomActions();

private:
	// Begin FAssetTypeActions_Base interface
	virtual FText GetName() const override;
	virtual FColor GetTypeColor() const override;
	virtual uint32 GetCategories() override;
	virtual UClass* GetSupportedClass() const override;
	virtual void OpenAssetEditor(const TArray<UObject*>& InObjects, TSharedPtr<IToolkitHost> EditWithinLevelEditor) override;
	// End FAssetTypeActions_Base interface

private:
	EAssetTypeCategories::Type AssetCategoryBit;
};
