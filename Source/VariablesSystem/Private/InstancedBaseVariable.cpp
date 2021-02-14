// Copyright Out-of-the-Box Plugins 2018-2020. All Rights Reserved.

#include "InstancedBaseVariable.h"

#include "VSLog.h"

FString UInstancedBaseVariable::GetStringValue() const
{
    return FString("Instanced - Invalid Value");
}

void UInstancedBaseVariable::OnWorldCreationEvent(const UWorld::FActorsInitializedParams& params)
{
	CleanupEntries();
}

void UInstancedBaseVariable::OnWorldDestructionEvent(UWorld* World, bool bSessionEnded, bool bCleanupResources)
{
	CleanupEntries();
}

void UInstancedBaseVariable::CleanupEntries()
{
	UE_LOG(LogVariablesSystem, Error, TEXT("UInstancedBaseVariable::CleanupEntries not implemented for this type."));
}
