// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#include "Modules/ModuleInterface.h"
#include "Modules/ModuleManager.h"
#include "Engine/World.h"
#include "BaseVariable.h"
#include "AssetRegistryModule.h"

#include "Containers/Array.h"
#include "ISettingsModule.h"
#include "ISettingsSection.h"
#include "Modules/ModuleInterface.h"
#include "Modules/ModuleManager.h"
#include "Templates/SharedPointer.h"
#include "Toolkits/AssetEditorToolkit.h"

#include "ContentBrowserModule.h"
#include "Editor/LevelEditor/Public/LevelEditor.h"
#include "Developer/AssetTools/Public/IAssetTools.h"
#include "Developer/AssetTools/Public/AssetToolsModule.h"
#include "Misc/ScopedSlowTask.h"
#include "AssetRegistryModule.h"
#include "Misc/MessageDialog.h"
#include "EngineUtils.h"
#include "UnrealEd/Public/ObjectTools.h"
#include "EditorStyleSet.h"
#include "Engine/World.h"
#include "AssetTools/Private/SPackageReportDialog.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"
#include "Templates/SharedPointer.h"
#include "Framework/MultiBox/MultiBoxExtender.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "Containers/Array.h"
#include "AssetData.h"

#define LOCTEXT_NAMESPACE "VariablesSystem"


/**
 * Implements the VarSystem module.
 */
class FVarSystemModule
    : public IModuleInterface
{
public:

    //~ IModuleInterface interface

    virtual void StartupModule() override;
    virtual void ShutdownModule() override;

    virtual bool SupportsDynamicReloading() override;

    static TArray<UBaseVariable*> GetAllVariables();

private:
    
    void OnWorldCreationEvent(const UWorld::FActorsInitializedParams& params);

    void OnWorldDestructionEvent(UWorld* World, bool bSessionEnded, bool bCleanupResources);

    // Extend main menu for to add depend checker delegate
    void CreateDepenCheckerMainMenuEntry(FMenuBuilder& MenuBuilder);

    void OnExtendMainMenu();
};

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FVarSystemModule, VarSystem);
