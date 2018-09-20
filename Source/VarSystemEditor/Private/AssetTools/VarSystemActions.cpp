// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "VarSystemActions.h"

#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "VarSystem.h"
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

	auto VarSystems = GetTypedWeakObjectPtrs<UVarSystem>(InObjects);

	MenuBuilder.AddMenuEntry(
		LOCTEXT("VarSystem_ReverseText", "Reverse Text"),
		LOCTEXT("VarSystem_ReverseTextToolTip", "Reverse the text stored in the selected text asset(s)."),
		FSlateIcon(),
		FUIAction(
			FExecuteAction::CreateLambda([=]{
				for (auto& VarSystem : VarSystems)
				{
					if (VarSystem.IsValid() && !VarSystem->Text.IsEmpty())
					{
						VarSystem->Text = FText::FromString(VarSystem->Text.ToString().Reverse());
						VarSystem->PostEditChange();
						VarSystem->MarkPackageDirty();
					}
				}
			}),
			FCanExecuteAction::CreateLambda([=] {
				for (auto& VarSystem : VarSystems)
				{
					if (VarSystem.IsValid() && !VarSystem->Text.IsEmpty())
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
	return UVarSystem::StaticClass();
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
		auto VarSystem = Cast<UVarSystem>(*ObjIt);

		if (VarSystem != nullptr)
		{
			TSharedRef<FVarSystemEditorToolkit> EditorToolkit = MakeShareable(new FVarSystemEditorToolkit(Style));
			EditorToolkit->Initialize(VarSystem, Mode, EditWithinLevelEditor);
		}
	}
}


#undef LOCTEXT_NAMESPACE
