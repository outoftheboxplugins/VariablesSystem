// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#pragma once

#include "AssetTypeActions_Base.h"

class ISlateStyle;

/**
 * Implements actions for Global Variables assets.
 */
class FVariablesSystemActions : public FAssetTypeActions_Base
{
//FAssetTypeActions_Base overrides
public:
	virtual bool CanFilter() override;
	virtual uint32 GetCategories() override;
	virtual FText GetName() const override;
	virtual UClass* GetSupportedClass() const override;
	virtual FColor GetTypeColor() const override;
};
