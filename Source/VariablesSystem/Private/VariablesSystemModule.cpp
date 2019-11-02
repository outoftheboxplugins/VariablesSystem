#include "VariablesSystemModule.h"

#define LOCTEXT_NAMESPACE "VariablesSystem"


void FVariablesSystemModule::StartupModule()
{
    FWorldDelegates::OnWorldInitializedActors.AddRaw(this, &FVariablesSystemModule::OnWorldCreationEvent);
    FWorldDelegates::OnPostWorldCleanup.AddRaw(this, &FVariablesSystemModule::OnWorldDestructionEvent);

    // Register main menu dropdown entry
    TSharedPtr<FExtender> MenuExtender = MakeShareable(new FExtender);
    MenuExtender->AddMenuExtension("MainMenuEntryVariablesSystem", EExtensionHook::After, nullptr, FMenuExtensionDelegate::CreateRaw(this, &FVariablesSystemModule::CreateDepenCheckerMainMenuEntry));
}

void FVariablesSystemModule::ShutdownModule()
{
    FWorldDelegates::OnWorldInitializedActors.RemoveAll(this);
    FWorldDelegates::OnPostWorldCleanup.RemoveAll(this);
}

bool FVariablesSystemModule::SupportsDynamicReloading()
{
    return true;
}

TArray<UBaseVariable*> FVariablesSystemModule::GetAllVariables()
{
    TArray<UBaseVariable*> Variables;

    if (FModuleManager::Get().IsModuleLoaded("AssetRegistry"))
    {
        FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
        TArray<FAssetData> AssetData;

        FARFilter SearchFilter;
        SearchFilter.ClassNames.Add(UBaseVariable::StaticClass()->GetFName());
        SearchFilter.bRecursiveClasses = true;

        AssetRegistryModule.Get().GetAssets(SearchFilter, AssetData);

        for (int i = 0; i < AssetData.Num(); i++) {
            UBaseVariable* VariableFound = Cast<UBaseVariable>(AssetData[i].GetAsset());
            if (VariableFound != NULL) {
                Variables.Add(VariableFound);
            }
        }
    }

    return Variables;
}

void FVariablesSystemModule::OnWorldCreationEvent(const UWorld::FActorsInitializedParams& params)
{
    TArray<UBaseVariable*> variables = GetAllVariables();
    for (UBaseVariable* variable : variables)
    {
        if (variable->ShouldLoad())
        {
            variable->Load();
        }
    }
}

void FVariablesSystemModule::OnWorldDestructionEvent(UWorld* World, bool bSessionEnded, bool bCleanupResources)
{
    TArray<UBaseVariable*> variables = GetAllVariables();
    for (UBaseVariable* variable : variables)
    {
        if (variable->ShouldSave())
        {
            variable->Save();
        }
    }
}

void FVariablesSystemModule::CreateDepenCheckerMainMenuEntry(FMenuBuilder& MenuBuilder)
{
    MenuBuilder.BeginSection("VariablesSystem", LOCTEXT("WatchWindow", "WatchWindow"));
    MenuBuilder.AddMenuEntry(
        FText(LOCTEXT("VariablesWatch", "Variables Watch")),
        LOCTEXT("VariablesWatchTooltip", "Show all the variables inside a watch"),
        FSlateIcon(FEditorStyle::GetStyleSetName(), "DeveloperTools.MenuIcon"),
        FUIAction(FExecuteAction::CreateRaw(this, &FVariablesSystemModule::OnExtendMainMenu)));
    MenuBuilder.EndSection();
}

void FVariablesSystemModule::OnExtendMainMenu()
{

}

#undef LOCTEXT_NAMESPACE
