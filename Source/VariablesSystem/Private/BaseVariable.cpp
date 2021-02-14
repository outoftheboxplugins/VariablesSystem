// Copyright Out-of-the-Box Plugins 2018-2020. All Rights Reserved.

#include "BaseVariable.h"

UBaseVariable::UBaseVariable(const FObjectInitializer& ObjectInitializer /*= FObjectInitializer::Get()*/)
	: Super(ObjectInitializer)
{
	FWorldDelegates::OnWorldInitializedActors.AddUObject(this, &UBaseVariable::OnWorldCreationEvent);
	FWorldDelegates::OnPostWorldCleanup.AddUObject(this, &UBaseVariable::OnWorldDestructionEvent);
}
UBaseVariable::~UBaseVariable()
{
	FWorldDelegates::OnWorldInitializedActors.RemoveAll(this);
	FWorldDelegates::OnPostWorldCleanup.RemoveAll(this);
}
FString UBaseVariable::GetStringValue() const
{
    return FString("Invalid Value");
}