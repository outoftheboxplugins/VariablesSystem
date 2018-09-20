// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "VarSystemFactoryNew.h"

#include "VarSystem.h"


/* UVarSystemFactoryNew structors
 *****************************************************************************/

UVarSystemFactoryNew::UVarSystemFactoryNew(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	SupportedClass = UVarSystem::StaticClass();
	bCreateNew = true;
	bEditAfterNew = true;
}


/* UFactory overrides
 *****************************************************************************/

UObject* UVarSystemFactoryNew::FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	return NewObject<UVarSystem>(InParent, InClass, InName, Flags);
}


bool UVarSystemFactoryNew::ShouldShowInNewMenu() const
{
	return true;
}
