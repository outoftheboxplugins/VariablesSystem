// Copyright Out-of-the-Box Plugins 2018-2020. All Rights Reserved.

#pragma once

VARIABLESSYSTEM_API DECLARE_LOG_CATEGORY_EXTERN(LogVariablesSystem, Log, All);

#define LOG_TRACE() UE_LOG(LogVariablesSystem, Log, TEXT("%s"), TEXT(__FUNCTION__))