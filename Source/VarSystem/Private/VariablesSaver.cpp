// Copyright Alexandru pasotee Oprea 2018. All Rights Reserved.

#pragma once

#include "VariablesSaver.h"

void UVariablesSaver::SaveAllData(UVariablesSaver* Manager)
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

void UVariablesSaver::LoadAllDaa(UVariablesSaver* Manager)
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
