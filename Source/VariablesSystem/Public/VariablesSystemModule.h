// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#pragma once

#include "Modules/ModuleInterface.h"
#include "Engine/World.h"

/**
 * Implements the VariablesSystem module.
 */

class FVariablesSystemModule : public IModuleInterface
{

//IModuleInterface interface
public:
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;

// World Callbacks
private:
    void OnWorldCreationEvent(const UWorld::FActorsInitializedParams& params);
    void OnWorldDestructionEvent(UWorld* World, bool bSessionEnded, bool bCleanupResources);
};

IMPLEMENT_MODULE(FVariablesSystemModule, VariablesSystem);