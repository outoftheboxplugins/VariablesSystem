// Copyright Out-of-the-Box Plugins 2018-2025. All Rights Reserved.
#include "VariablesSystemModule.h"

#include "VSLog.h"

void FVariablesSystemModule::StartupModule()
{
	LOG_TRACE();
}

void FVariablesSystemModule::ShutdownModule()
{
	LOG_TRACE();
}

IMPLEMENT_MODULE(FVariablesSystemModule, VariablesSystem);
