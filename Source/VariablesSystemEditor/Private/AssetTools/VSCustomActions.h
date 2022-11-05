#pragma once

#include "AssetTypeActions_Base.h"

/**
 * Asset actions for UAwCommands.
 */

class FVSCustomActions : public FAssetTypeActions_Base
{
public:
	FVSCustomActions();

	// FAssetTypeActions_Base interface
private:
	virtual FText GetName() const override;
	virtual FColor GetTypeColor() const override;
	virtual uint32 GetCategories() override;
	virtual UClass* GetSupportedClass() const override;

	virtual void OpenAssetEditor(const TArray<UObject*>& InObjects, TSharedPtr<IToolkitHost> EditWithinLevelEditor) override;

private:
	EAssetTypeCategories::Type AssetCategoryBit;
};
