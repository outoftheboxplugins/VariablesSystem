// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#include "VariablesSystemActions.h"

#include "Slate/Public/Framework/MultiBox/MultiBoxBuilder.h"
#include "VariablesSystem/Public/BaseVariable.h"
#include "VariablesSystemEditor/Private/EditorHelpers/VariablesSystemEditorHelpers.h"

#define VARIABLESSYSTEM_COLOR FColor(224.0f, 20.0f, 23.0f)

#define LOCTEXT_NAMESPACE "VariablesSystem"

/* FAssetTypeActions_Base overrides
 *****************************************************************************/

bool FVSActions::CanFilter()
{
	return true;
}

uint32 FVSActions::GetCategories()
{
    //TODO: We should move this to our own category really soon.
	return EAssetTypeCategories::Misc;
}

FText FVSActions::GetName() const
{
	return LOCTEXT("VariablesSystem_AssetName", "Variable");
}

UClass* FVSActions::GetSupportedClass() const
{
	return UBaseVariable::StaticClass();
}

FColor FVSActions::GetTypeColor() const
{
	return VARIABLESSYSTEM_COLOR;
}

void FVSActions::GetActions(const TArray<UObject*>& InObjects, FMenuBuilder& MenuBuilder)
{
    FAssetTypeActions_Base::GetActions(InObjects, MenuBuilder);

    auto WeakVariables = GetTypedWeakObjectPtrs<UBaseVariable>(InObjects);
    TArray<UBaseVariable*> Variables;
    CopyFromWeakArray(Variables, WeakVariables);

    MenuBuilder.AddMenuEntry(
        LOCTEXT("AddToWatchTitle", "Add to watch"),
        LOCTEXT("AddToWatchToolTip", "Add the selected variables to your watch window."),
        FSlateIcon(),
        FUIAction(
            FExecuteAction::CreateLambda([=] { /*UVariablesSystemEditorHelpersBPLibrary::OpenOrAddVariablesToWatch(Variables);*/ }),
            FCanExecuteAction::CreateLambda([=] { return Variables.Num() > 0; })
        )
    );
}

bool FVSActions::HasActions(const TArray<UObject*>& InObjects) const
{
    return true;
}

#undef LOCTEXT_NAMESPACE
