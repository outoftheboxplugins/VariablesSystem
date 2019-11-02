// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "VariablesSystemActions.h"

#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "BaseVariable.h"
#include "Styling/SlateStyle.h"

#include "VariablesSystemEditorToolkit.h"


#define LOCTEXT_NAMESPACE "AssetTypeActions"


/* FVariablesSystemActions constructors
 *****************************************************************************/

FVariablesSystemActions::FVariablesSystemActions(const TSharedRef<ISlateStyle>& InStyle)
	: Style(InStyle)
{ }


/* FAssetTypeActions_Base overrides
 *****************************************************************************/

bool FVariablesSystemActions::CanFilter()
{
	return true;
}


uint32 FVariablesSystemActions::GetCategories()
{
	return EAssetTypeCategories::Misc;
}


FText FVariablesSystemActions::GetName() const
{
	return NSLOCTEXT("AssetTypeActions", "AssetTypeActions_VariablesSystem", "Var System");
}


UClass* FVariablesSystemActions::GetSupportedClass() const
{
	return UBaseVariable::StaticClass();
}


FColor FVariablesSystemActions::GetTypeColor() const
{
	return FColor::Orange;
}

bool FVariablesSystemActions::HasActions(const TArray<UObject*>& InObjects) const
{
    return true;
}

void FVariablesSystemActions::GetActions(const TArray<UObject*>& InObjects, FMenuBuilder& MenuBuilder)
{
    FAssetTypeActions_Base::GetActions(InObjects, MenuBuilder);

    auto BaseVariables = GetTypedWeakObjectPtrs<UBaseVariable>(InObjects);

    MenuBuilder.AddMenuEntry(
        LOCTEXT("VariablesSystem_ReverseText", "Reverse Text"),
        LOCTEXT("VariablesSystem_ReverseTextToolTip", "Reverse the text stored in the selected text asset(s)."),
        FSlateIcon(),
        FUIAction(
            FExecuteAction::CreateLambda([=] {}),
            FCanExecuteAction::CreateLambda([=] { return true;}))
        );
}

void FVariablesSystemActions::OpenAssetEditor(const TArray<UObject*>& InObjects, TSharedPtr<IToolkitHost> EditWithinLevelEditor)
{
    EToolkitMode::Type Mode = EditWithinLevelEditor.IsValid()
        ? EToolkitMode::WorldCentric
        : EToolkitMode::Standalone;

    for (auto ObjIt = InObjects.CreateConstIterator(); ObjIt; ++ObjIt)
    {
        auto BaseVariable = Cast<UBaseVariable>(*ObjIt);

        if (BaseVariable != nullptr)
        {
            TSharedRef<FVariablesSystemEditorToolkit> EditorToolkit = MakeShareable(new FVariablesSystemEditorToolkit(Style));
            EditorToolkit->Initialize(BaseVariable, Mode, EditWithinLevelEditor);
        }
    }
}

#undef LOCTEXT_NAMESPACE
