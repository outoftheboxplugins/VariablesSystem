// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#pragma once

#include "VariablesSystemSaver.h"

void UVariablesSystemSaver::SaveAllData(UVariablesSystemSaver* Manager)
{
	if (!Manager)
	{
		return;
	}

	for (int32 i = 0; i < Manager->Variables.Num(); i++)
	{
		if (UBaseVariable* current = Manager->Variables[i])
		{
			current->Save();
		}
	}
}

void UVariablesSystemSaver::LoadAllDaa(UVariablesSystemSaver* Manager)
{
	if (!Manager)
	{
		return;
	}

	for (int32 i = 0; i < Manager->Variables.Num(); i++)
	{
		if (UBaseVariable* current = Manager->Variables[i])
		{
			current->Load();
		}
	}
}
