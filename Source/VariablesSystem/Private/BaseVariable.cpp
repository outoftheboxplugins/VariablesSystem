// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#include "BaseVariable.h"

#include "VSLog.h"

UBaseVariable::UBaseVariable(const FObjectInitializer& ObjectInitializer /*= FObjectInitializer::Get()*/)
	: Super(ObjectInitializer)
{
	if (ShouldLoad())
	{
		Load();
	}

	FWorldDelegates::OnWorldInitializedActors.AddUObject(this, &UBaseVariable::OnWorldCreationEvent);
	FWorldDelegates::OnPostWorldCleanup.AddUObject(this, &UBaseVariable::OnWorldDestructionEvent);
}

UBaseVariable::~UBaseVariable()
{
	FWorldDelegates::OnWorldInitializedActors.RemoveAll(this);
	FWorldDelegates::OnPostWorldCleanup.RemoveAll(this);

	if (ShouldSave())
	{
		Save();
	}
}

void UBaseVariable::OnWorldCreationEvent(const UWorld::FActorsInitializedParams& params)
{
	if (ShouldLoad())
	{
		Load();
	}
}

void UBaseVariable::OnWorldDestructionEvent(UWorld* World, bool bSessionEnded, bool bCleanupResources)
{
	if (ShouldSave())
	{
		Save();
	}
}

FString UBaseVariable::GetSaveLocation() const
{
	FString SaveDestination;
	UObjectBaseUtility::GetName(SaveDestination);
	return SaveDestination;
}