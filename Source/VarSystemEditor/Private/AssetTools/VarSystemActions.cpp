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

//bool FVarSystemActions::HasActions(const TArray<UObject*>& InObjects) const
//{
//    return true;
//}
//
//void FVarSystemActions::GetActions(const TArray<UObject*>& InObjects, FMenuBuilder& MenuBuilder)
//{
//    FAssetTypeActions_Base::GetActions(InObjects, MenuBuilder);
//
//    auto BaseVariables = GetTypedWeakObjectPtrs<UBaseVariable>(InObjects);
//
//    MenuBuilder.AddMenuEntry(
//        LOCTEXT("VarSystem_ReverseText", "Reverse Text"),
//        LOCTEXT("VarSystem_ReverseTextToolTip", "Reverse the text stored in the selected text asset(s)."),
//        FSlateIcon(),
//        FUIAction(
//            FExecuteAction::CreateLambda([=] {}),
//            FCanExecuteAction::CreateLambda([=] { return true;}))
//        );
//}
//
//void FVarSystemActions::OpenAssetEditor(const TArray<UObject*>& InObjects, TSharedPtr<IToolkitHost> EditWithinLevelEditor)
//{
//    EToolkitMode::Type Mode = EditWithinLevelEditor.IsValid()
//        ? EToolkitMode::WorldCentric
//        : EToolkitMode::Standalone;
//
//    for (auto ObjIt = InObjects.CreateConstIterator(); ObjIt; ++ObjIt)
//    {
//        auto BaseVariable = Cast<UBaseVariable>(*ObjIt);
//
//        if (BaseVariable != nullptr)
//        {
//            TSharedRef<FVarSystemEditorToolkit> EditorToolkit = MakeShareable(new FVarSystemEditorToolkit(Style));
//            EditorToolkit->Initialize(BaseVariable, Mode, EditWithinLevelEditor);
//        }
//    }
//}

#undef LOCTEXT_NAMESPACE
