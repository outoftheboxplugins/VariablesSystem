// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#include "VariablesSystemEditor/Private/EditorHelpers/VariablesSystemEditorHelpers.h"

#include "Slate/Public/Framework/Docking/TabManager.h"
#include "VariablesSystemEditor/Private/Module/VariablesSystemEditorModule.h"
#include "VariablesSystemEditor/Private/WatchWidget/VariablesWatchWidget.h"
#include "VariablesSystemEditorHelpers.h"
#include "Widgets/Docking/SDockTab.h"

TSharedRef<SDockTab> UVariablesSystemEditorHelpersBPLibrary::OpenOrAddVariablesToWatch(TArray<UBaseVariable*> Variables /*= TArray<UBaseVariable*>()*/)
{
    TSharedRef<SDockTab> WatchTab = FGlobalTabmanager::Get()->InvokeTab(FVariablesSystemEditorModule::VariablesWatchTabName);
    TSharedRef<SVariablesWatchWidget> VariablesWatch = StaticCastSharedRef<SVariablesWatchWidget>(WatchTab->GetContent());

    VariablesWatch->AddVariables(Variables);

    return WatchTab;
}
