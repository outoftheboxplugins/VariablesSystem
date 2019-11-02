// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
#pragma once

#include "Fonts/SlateFontInfo.h"
#include "Styling/SlateColor.h"
#include "UObject/ObjectMacros.h"

#include "VariablesSystemEditorSettings.generated.h"


UCLASS(config=Editor)
class VARIABLESSYSTEMEDITOR_API UVariablesSystemEditorSettings
	: public UObject
{
	GENERATED_BODY()

public:

	/** Color of the VariablesSystem editor's background. */
	UPROPERTY(config, EditAnywhere, Category=Appearance)
	FSlateColor BackgroundColor;

	/** Color of the VariablesSystem editor's text. */
	UPROPERTY(config, EditAnywhere, Category=Appearance)
	FSlateColor ForegroundColor;

	/** The font to use in the VariablesSystem editor window. */
	UPROPERTY(config, EditAnywhere, Category=Appearance)
	FSlateFontInfo Font;

	/** The margin around the VariablesSystem editor window (in pixels). */
	UPROPERTY(config, EditAnywhere, Category=Appearance)
	float Margin;

public:

	/** Default constructor. */
	UVariablesSystemEditorSettings();
};
