// Copyright Alexandru pasotee Oprea 2018. All Rights Reserved.

#pragma once

#include "SaveManager.h"

void USaveManager::SaveAllData(USaveManager* Manager)
{
	for (int32 i = 0; i < Manager->Variables.Num(); i++)
	{
		Manager->Variables[i]->Save();
	}
}

void USaveManager::LoadAllDaa(USaveManager* Manager)
{
	for (int32 i = 0; i < Manager->Variables.Num(); i++)
	{
		Manager->Variables[i]->Load();
	}
}
