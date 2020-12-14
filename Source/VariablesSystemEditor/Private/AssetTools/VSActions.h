// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#pragma once

#include "AssetTools/Public/AssetTypeActions_Base.h"

class ISlateStyle;

/**
 * Implements actions for Global Variables assets.
 */
class FVSActions : public FAssetTypeActions_Base
{
//FAssetTypeActions_Base overrides
public:
    virtual bool CanFilter() override;
    virtual uint32 GetCategories() override;
    virtual FText GetName() const override;
    virtual UClass* GetSupportedClass() const override;
    virtual FColor GetTypeColor() const override;

public:
    virtual void GetActions(const TArray<UObject*>& InObjects, FMenuBuilder& MenuBuilder) override;
    virtual bool HasActions(const TArray<UObject*>& InObjects) const override;
};
