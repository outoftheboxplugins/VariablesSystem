// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#include "VariablesSystemSaver.h"

void UVariablesSystemSaver::SaveAllData(UVariablesSystemSaver* Manager)
{
	if (!Manager) { return; }

    for (auto& variable : Manager->Variables)
    {
        variable->Save();
    }
}

void UVariablesSystemSaver::LoadAllData(UVariablesSystemSaver* Manager)
{
    if (!Manager) { return; }

    for (auto& variable : Manager->Variables)
    {
        variable->Load();
    }
}