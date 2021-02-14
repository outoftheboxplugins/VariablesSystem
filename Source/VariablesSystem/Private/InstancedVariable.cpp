// Copyright Out-of-the-Box Plugins 2018-2020. All Rights Reserved.

#include "InstancedVariable.h"

#include "VSLog.h"

FString UInstancedVariable::GetStringValue() const
{
    return FString("Instanced - Invalid Value");
}

void UInstancedVariable::OnWorldCreationEvent(const UWorld::FActorsInitializedParams& params)
{
	CleanupEntries();
}

void UInstancedVariable::OnWorldDestructionEvent(UWorld* World, bool bSessionEnded, bool bCleanupResources)
{
	CleanupEntries();
}

void UInstancedVariable::CleanupEntries()
{
	UE_LOG(LogVariablesSystem, Error, TEXT("UInstancedVariable::CleanupEntries not implemented for this type."));
}
