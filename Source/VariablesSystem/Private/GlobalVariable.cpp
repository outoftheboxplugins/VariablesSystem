// Copyright Out-of-the-Box Plugins 2018-2023. All Rights Reserved.
#include "GlobalVariable.h"

#include "VSLog.h"

UGlobalVariable::UGlobalVariable(const FObjectInitializer& ObjectInitializer /*= FObjectInitializer::Get()*/)
	: Super(ObjectInitializer)
{
	LoadIfNeeded();
}

UGlobalVariable::~UGlobalVariable()
{
	SaveIfNeeded();
}

FString UGlobalVariable::GetStringValue() const
{
    return FString("Global - Invalid Value");
}

void UGlobalVariable::SaveIfNeeded()
{
	if (HasAnyFlags(RF_ClassDefaultObject))
	{
		return;
	}

	if (SaveBehavior != EVSSaveType::VSST_SaveOnFinish && SaveBehavior != EVSSaveType::VSST_StartAndFinish)
	{
		return;
	}

	Save(true);
}

void UGlobalVariable::LoadIfNeeded()
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

void UGlobalVariable::OnWorldCreationEvent(const UWorld::FActorsInitializedParams& params)
{
	if(params.World && params.World->IsGameWorld())
	{
		LoadIfNeeded();
	}
}

void UGlobalVariable::OnWorldDestructionEvent(UWorld* World, bool bSessionEnded, bool bCleanupResources)
{
	if(World && World->IsGameWorld())
	{
		SaveIfNeeded();
	}
}

FString UGlobalVariable::GetSaveLocation() const
{
	FString SaveDestination;
	UObjectBaseUtility::GetName(SaveDestination);
	return SaveDestination;
}
