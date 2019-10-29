#include "VarSystemModule.h"

#define LOCTEXT_NAMESPACE "VariablesSystem"


void FVarSystemModule::StartupModule()
{
    FWorldDelegates::OnWorldInitializedActors.AddRaw(this, &FVarSystemModule::OnWorldCreationEvent);
    FWorldDelegates::OnPostWorldCleanup.AddRaw(this, &FVarSystemModule::OnWorldDestructionEvent);

    // Register main menu dropdown entry
    TSharedPtr<FExtender> MenuExtender = MakeShareable(new FExtender);
    MenuExtender->AddMenuExtension("MainMenuEntryVarSystem", EExtensionHook::After, nullptr, FMenuExtensionDelegate::CreateRaw(this, &FVarSystemModule::CreateDepenCheckerMainMenuEntry));
}

void FVarSystemModule::ShutdownModule()
{
    FWorldDelegates::OnWorldInitializedActors.RemoveAll(this);
    FWorldDelegates::OnPostWorldCleanup.RemoveAll(this);
}

bool FVarSystemModule::SupportsDynamicReloading()
{
    return true;
}

TArray<UBaseVariable*> FVarSystemModule::GetAllVariables()
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

void FVarSystemModule::OnWorldCreationEvent(const UWorld::FActorsInitializedParams& params)
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

void FVarSystemModule::OnWorldDestructionEvent(UWorld* World, bool bSessionEnded, bool bCleanupResources)
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

void FVarSystemModule::CreateDepenCheckerMainMenuEntry(FMenuBuilder& MenuBuilder)
{
    MenuBuilder.BeginSection("VariablesSystem", LOCTEXT("WatchWindow", "WatchWindow"));
    MenuBuilder.AddMenuEntry(
        FText(LOCTEXT("VariablesWatch", "Variables Watch")),
        LOCTEXT("VariablesWatchTooltip", "Show all the variables inside a watch"),
        FSlateIcon(FEditorStyle::GetStyleSetName(), "DeveloperTools.MenuIcon"),
        FUIAction(FExecuteAction::CreateRaw(this, &FVarSystemModule::OnExtendMainMenu)));
    MenuBuilder.EndSection();
}

void FVarSystemModule::OnExtendMainMenu()
{

}

#undef LOCTEXT_NAMESPACE
