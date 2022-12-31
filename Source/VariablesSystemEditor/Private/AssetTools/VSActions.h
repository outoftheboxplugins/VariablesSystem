// Copyright Out-of-the-Box Plugins 2018-2023. All Rights Reserved.
#pragma once

#include "AssetTypeActions_Base.h"

/**
 * Asset actions for UBaseVariables.
 */
class FVSActions : public FAssetTypeActions_Base
{
public:
	FVSActions();

// FAssetTypeActions_Base interface
private:
	virtual FText GetName() const override;
    virtual FColor GetTypeColor() const override;
    virtual uint32 GetCategories() override;
    
    virtual UClass* GetSupportedClass() const override;
	virtual TSharedPtr<SWidget> GetThumbnailOverlay(const FAssetData& AssetData) const override;

// Asset Actions
private:
    virtual bool HasActions(const TArray<UObject*>& InObjects) const override;
    virtual void GetActions(const TArray<UObject*>& InObjects, FMenuBuilder& MenuBuilder) override;

private:
	EAssetTypeCategories::Type AssetCategoryBit;
};
