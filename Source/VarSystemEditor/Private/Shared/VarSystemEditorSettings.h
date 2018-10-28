// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
#pragma once

#include "Fonts/SlateFontInfo.h"
#include "Styling/SlateColor.h"
#include "UObject/ObjectMacros.h"

#include "VarSystemEditorSettings.generated.h"


UCLASS(config=Editor)
class VARSYSTEMEDITOR_API UVarSystemEditorSettings
	: public UObject
{
	GENERATED_BODY()

public:

	/** Color of the VarSystem editor's background. */
	UPROPERTY(config, EditAnywhere, Category=Appearance)
	FSlateColor BackgroundColor;

	/** Color of the VarSystem editor's text. */
	UPROPERTY(config, EditAnywhere, Category=Appearance)
	FSlateColor ForegroundColor;

	/** The font to use in the VarSystem editor window. */
	UPROPERTY(config, EditAnywhere, Category=Appearance)
	FSlateFontInfo Font;

	/** The margin around the VarSystem editor window (in pixels). */
	UPROPERTY(config, EditAnywhere, Category=Appearance)
	float Margin;

public:

	/** Default constructor. */
	UVarSystemEditorSettings();
};
