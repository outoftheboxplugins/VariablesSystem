// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#include "VariablesSystemActions.h"

#include "VariablesSystem/Public/BaseVariable.h"

#define VARIABLESSYSTEM_COLOR FColor(224.0f, 20.0f, 23.0f)

#define LOCTEXT_NAMESPACE "VariablesSystem"

/* FAssetTypeActions_Base overrides
 *****************************************************************************/

bool FVariablesSystemActions::CanFilter()
{
	return true;
}

uint32 FVariablesSystemActions::GetCategories()
{
    //TODO: We should move this to our own category really soon.
	return EAssetTypeCategories::Misc;
}

FText FVariablesSystemActions::GetName() const
{
	return LOCTEXT("VariablesSystem_AssetName", "Variable");
}

UClass* FVariablesSystemActions::GetSupportedClass() const
{
	return UBaseVariable::StaticClass();
}

FColor FVariablesSystemActions::GetTypeColor() const
{
	return VARIABLESSYSTEM_COLOR;
}

#undef LOCTEXT_NAMESPACE
