// Copyright Out-of-the-Box Plugins 2018-2020. All Rights Reserved.

#include "GlobalBaseVariable.h"

#include "VSLog.h"

UGlobalBaseVariable::UGlobalBaseVariable(const FObjectInitializer& ObjectInitializer /*= FObjectInitializer::Get()*/)
	: Super(ObjectInitializer)
{
	LoadIfNeeded();
}

UGlobalBaseVariable::~UGlobalBaseVariable()
{
	SaveIfNeeded();
}

FString UGlobalBaseVariable::GetStringValue() const
{
    return FString("Global - Invalid Value");
}

void UGlobalBaseVariable::SaveIfNeeded()
{
	if (HasAnyFlags(RF_ClassDefaultObject))
	{
		return;
	}

	if (SaveBehavior != EVSSaveType::VSST_SaveOnFinish && SaveBehavior != EVSSaveType::VSST_StartAndFinish)
	{
		return;
	}

	Save();
}

void UGlobalBaseVariable::LoadIfNeeded()
{
	if (HasAnyFlags(RF_ClassDefaultObject))
	{
		return;
	}

	if (SaveBehavior != EVSSaveType::VSST_LoadOnStart && SaveBehavior != EVSSaveType::VSST_StartAndFinish)
	{
		return;
	}

	Load();
}

void UGlobalBaseVariable::OnWorldCreationEvent(const UWorld::FActorsInitializedParams& params)
{
	LoadIfNeeded();
}

void UGlobalBaseVariable::OnWorldDestructionEvent(UWorld* World, bool bSessionEnded, bool bCleanupResources)
{
	SaveIfNeeded();
}

FString UGlobalBaseVariable::GetSaveLocation() const
{
	FString SaveDestination;
	UObjectBaseUtility::GetName(SaveDestination);
	return SaveDestination;
}