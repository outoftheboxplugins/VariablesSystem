// Copyright Alexandru pasotee Oprea 2018. All Rights Reserved.

#pragma once

#include "VariablesSaver.h"

void UVariablesSaver::SaveAllData(UVariablesSaver* Manager)
{
	for (int32 i = 0; i < Manager->Variables.Num(); i++)
	{
		Manager->Variables[i]->Save();
	}
}

void UVariablesSaver::LoadAllDaa(UVariablesSaver* Manager)
{
	for (int32 i = 0; i < Manager->Variables.Num(); i++)
	{
		Manager->Variables[i]->Load();
	}
}
