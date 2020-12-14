// Copyright Out-of-the-Box Plugins 2018-2020. All Rights Reserved.

#include "VSActions.h"

#include "BaseVariable.h"
#include "VariablesSystemEditorModule.h"

#define LOCTEXT_NAMESPACE "VariablesSystemEditor"

namespace
{
	FName AssetCategoryRegisterName = FName(TEXT("OutOfTheBox"));
	FText AssetCategoryDisplayName = LOCTEXT("OutOfTheBoxCategory", "OutOfTheBox");
}

//////////////////////////////////////////////////////////////////////////
// FAssetTypeActions_Base interface
FVSActions::FVSActions()
{
	IAssetTools& AssetTools = FAssetToolsModule::GetModule().Get();
	AssetCategoryBit = AssetTools.RegisterAdvancedAssetCategory(AssetCategoryRegisterName, AssetCategoryDisplayName);
}

FText FVSActions::GetName() const
{
	return LOCTEXT("AssetName", "Variable");
}

FColor FVSActions::GetTypeColor() const
{
	return FColor(240.0f, 10.0f, 11.0f);
}

uint32 FVSActions::GetCategories()
{
	return AssetCategoryBit;
}

UClass* FVSActions::GetSupportedClass() const
{
	return UBaseVariable::StaticClass();
}

//////////////////////////////////////////////////////////////////////////
// Asset Actions
bool FVSActions::HasActions(const TArray<UObject*>& InObjects) const
{
	auto WeakVariables = GetTypedWeakObjectPtrs<UBaseVariable>(InObjects);
	TArray<UBaseVariable*> Variables;
	CopyFromWeakArray(Variables, WeakVariables);

	return Variables.Num() > 0;
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
            FExecuteAction::CreateLambda([=]() 
				{ 
					FVariablesSystemEditorModule::GetModule().OpenOrAddVariablesToWatch(Variables);
				})
        )
    );
}

#undef LOCTEXT_NAMESPACE
