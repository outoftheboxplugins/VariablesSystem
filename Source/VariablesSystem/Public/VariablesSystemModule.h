// Copyright Out-of-the-Box Plugins 2018-2023. All Rights Reserved.
#pragma once

#include "Modules/ModuleInterface.h"
#include "Modules/ModuleManager.h"

/**
 * Implements the VariablesSystem module.
 */

class FVariablesSystemModule : public IModuleInterface
{
//IModuleInterface interface
public:
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;
};
