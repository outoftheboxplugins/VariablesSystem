// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

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


void FVarSystemActions::GetActions(const TArray<UObject*>& InObjects, FMenuBuilder& MenuBuilder)
{
	FAssetTypeActions_Base::GetActions(InObjects, MenuBuilder);

	auto BaseVariables = GetTypedWeakObjectPtrs<UBaseVariable>(InObjects);

	MenuBuilder.AddMenuEntry(
		LOCTEXT("VarSystem_ReverseText", "Reverse Text"),
		LOCTEXT("VarSystem_ReverseTextToolTip", "Reverse the text stored in the selected text asset(s)."),
		FSlateIcon(),
		FUIAction(
			FExecuteAction::CreateLambda([=]{
				for (auto& BaseVariable : BaseVariables)
				{
					if (BaseVariable.IsValid() && !BaseVariable->Text.IsEmpty())
					{
						BaseVariable->Text = FText::FromString(BaseVariable->Text.ToString().Reverse());
						BaseVariable->PostEditChange();
						BaseVariable->MarkPackageDirty();
					}
				}
			}),
			FCanExecuteAction::CreateLambda([=] {
				for (auto& BaseVariable : BaseVariables)
				{
					if (BaseVariable.IsValid() && !BaseVariable->Text.IsEmpty())
					{
						return true;
					}
				}
				return false;
			})
		)
	);
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
	return FColor::White;
}


bool FVarSystemActions::HasActions(const TArray<UObject*>& InObjects) const
{
	return true;
}


void FVarSystemActions::OpenAssetEditor(const TArray<UObject*>& InObjects, TSharedPtr<IToolkitHost> EditWithinLevelEditor)
{
	EToolkitMode::Type Mode = EditWithinLevelEditor.IsValid()
		? EToolkitMode::WorldCentric
		: EToolkitMode::Standalone;

	for (auto ObjIt = InObjects.CreateConstIterator(); ObjIt; ++ObjIt)
	{
		auto BaseVariable = Cast<UBaseVariable>(*ObjIt);

		if (BaseVariable != nullptr)
		{
			TSharedRef<FVarSystemEditorToolkit> EditorToolkit = MakeShareable(new FVarSystemEditorToolkit(Style));
			EditorToolkit->Initialize(BaseVariable, Mode, EditWithinLevelEditor);
		}
	}
}


#undef LOCTEXT_NAMESPACE
