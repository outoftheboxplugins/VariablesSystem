// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "VarSystemActions.h"

#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "BaseVariable.h"
#include "Styling/SlateStyle.h"

#include "VarSystemEditorToolkit.h"


#define LOCTEXT_NAMESPACE "AssetTypeActions"


/* FVarSystemActions constructors
 *****************************************************************************/

FVarSystemActions::FVarSystemActions(const TSharedRef<ISlateStyle>& InStyle)
	: Style(InStyle)
{ }


/* FAssetTypeActions_Base overrides
 *****************************************************************************/

bool FVarSystemActions::CanFilter()
{
	return true;
}


uint32 FVarSystemActions::GetCategories()
{
	return EAssetTypeCategories::Misc;
}


FText FVarSystemActions::GetName() const
{
	return NSLOCTEXT("AssetTypeActions", "AssetTypeActions_VarSystem", "Var System");
}


UClass* FVarSystemActions::GetSupportedClass() const
{
	return UBaseVariable::StaticClass();
}


FColor FVarSystemActions::GetTypeColor() const
{
	return FColor::Orange;
}

#undef LOCTEXT_NAMESPACE
