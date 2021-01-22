// Copyright Out-of-the-Box Plugins 2018-2020. All Rights Reserved.

#include "BaseVariable.h"

#include "VSLog.h"

UBaseVariable::UBaseVariable(const FObjectInitializer& ObjectInitializer /*= FObjectInitializer::Get()*/)
	: Super(ObjectInitializer)
{
	//TOSOLVE: Check if this makes any sense at all for packed games.
	LoadIfNeeded();

	FWorldDelegates::OnWorldInitializedActors.AddUObject(this, &UBaseVariable::OnWorldCreationEvent);
	FWorldDelegates::OnPostWorldCleanup.AddUObject(this, &UBaseVariable::OnWorldDestructionEvent);
}

UBaseVariable::~UBaseVariable()
{
	FWorldDelegates::OnWorldInitializedActors.RemoveAll(this);
	FWorldDelegates::OnPostWorldCleanup.RemoveAll(this);

	//TOSOLVE: Check if this makes any sense at all for packed games.
	SaveIfNeeded();
}

FString UBaseVariable::GetStringValue() const
{
    return FString("Invalid Value");
}

void UBaseVariable::SaveIfNeeded()
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

void UBaseVariable::LoadIfNeeded()
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

void UBaseVariable::OnWorldCreationEvent(const UWorld::FActorsInitializedParams& params)
{
	LoadIfNeeded();
}

void UBaseVariable::OnWorldDestructionEvent(UWorld* World, bool bSessionEnded, bool bCleanupResources)
{
	SaveIfNeeded();
}

FString UBaseVariable::GetSaveLocation() const
{
	FString SaveDestination;
	UObjectBaseUtility::GetName(SaveDestination);
	return SaveDestination;
}