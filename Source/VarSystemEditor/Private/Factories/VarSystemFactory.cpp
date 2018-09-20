// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "VarSystemFactory.h"

#include "Containers/UnrealString.h"
#include "VarSystem.h"
#include "Misc/FileHelper.h"


/* UVarSystemFactory structors
 *****************************************************************************/

UVarSystemFactory::UVarSystemFactory( const FObjectInitializer& ObjectInitializer )
	: Super(ObjectInitializer)
{
	Formats.Add(FString(TEXT("txt;")) + NSLOCTEXT("UVarSystemFactory", "FormatTxt", "Text File").ToString());
	SupportedClass = UVarSystem::StaticClass();
	bCreateNew = false;
	bEditorImport = true;
}


/* UFactory overrides
 *****************************************************************************/

/* This is the old API (only for demonstration purposes)
UObject* UVarSystemFactory::FactoryCreateBinary(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, const TCHAR* Type, const uint8*& Buffer, const uint8* BufferEnd, FFeedbackContext* Warn)
{
	UVarSystem* VarSystem = nullptr;
	FString TextString;

	if (FFileHelper::LoadFileToString(TextString, *CurrentFilename))
	{
		VarSystem = NewObject<UVarSystem>(InParent, Class, Name, Flags);
		VarSystem->Text = FText::FromString(TextString);
	}

	return VarSystem;
}*/


UObject* UVarSystemFactory::FactoryCreateFile(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, const FString& Filename, const TCHAR* Parms, FFeedbackContext* Warn, bool& bOutOperationCanceled)
{
	UVarSystem* VarSystem = nullptr;
	FString TextString;

	if (FFileHelper::LoadFileToString(TextString, *Filename))
	{
		VarSystem = NewObject<UVarSystem>(InParent, InClass, InName, Flags);
		VarSystem->Text = FText::FromString(TextString);
	}

	bOutOperationCanceled = false;

	return VarSystem;
}
