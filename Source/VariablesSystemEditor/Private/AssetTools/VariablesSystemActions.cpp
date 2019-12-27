// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#include "VariablesSystemActions.h"

#include "Slate/Public/Framework/MultiBox/MultiBoxBuilder.h"
#include "VariablesSystem/Public/BaseVariable.h"
#include "VariablesSystemEditor/Private/EditorHelpers/VariablesSystemEditorHelpers.h"

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

void FVariablesSystemActions::GetActions(const TArray<UObject*>& InObjects, FMenuBuilder& MenuBuilder)
{
    FAssetTypeActions_Base::GetActions(InObjects, MenuBuilder);

    auto WeakVariables = GetTypedWeakObjectPtrs<UBaseVariable>(InObjects);
    TArray<UBaseVariable*> Variables;
    CopyFromWeakArray(Variables, WeakVariables);

    MenuBuilder.AddMenuEntry(
        LOCTEXT("VariablesSystem_AddToWatchTitle", "Add to watch"),
        LOCTEXT("VariablesSystem_AddToWatchToolTip", "Add the selected variables to your watch window."),
        FSlateIcon(),
        FUIAction(
            FExecuteAction::CreateLambda([=] { UVariablesSystemEditorHelpersBPLibrary::OpenOrAddVariablesToWatch(Variables); }),
            FCanExecuteAction::CreateLambda([=] { return Variables.Num() > 0; })
        )
    );
}

bool FVariablesSystemActions::HasActions(const TArray<UObject*>& InObjects) const
{
    return true;
}

#undef LOCTEXT_NAMESPACE
