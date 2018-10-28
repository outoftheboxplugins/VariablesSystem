// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Templates/SharedPointer.h"
#include "Widgets/DeclarativeSyntaxSupport.h"
#include "Widgets/SCompoundWidget.h"
#include "Widgets/Input/SMultiLineEditableTextBox.h"

class FText;
class ISlateStyle;
class UBaseVariable;


/**
 * Implements the UVarSystem asset editor widget.
 */
class SVarSystemEditor
	: public SCompoundWidget
{
public:

	SLATE_BEGIN_ARGS(SVarSystemEditor) { }
	SLATE_END_ARGS()

public:

	/** Virtual destructor. */
	virtual ~SVarSystemEditor();

	/**
	 * Construct this widget
	 *
	 * @param InArgs The declaration data for this widget.
	 * @param InVarSystem The UVarSystem asset to edit.
	 * @param InStyleSet The style set to use.
	 */
	void Construct(const FArguments& InArgs, UBaseVariable* InBaseVariable, const TSharedRef<ISlateStyle>& InStyle);

private:

	/** Callback for text changes in the editable text box. */
	void HandleEditableTextBoxTextChanged(const FText& NewText);

	/** Callback for committed text in the editable text box. */
	void HandleEditableTextBoxTextCommitted(const FText& Comment, ETextCommit::Type CommitType);

	/** Callback for property changes in the text asset. */
	void HandleVarSystemPropertyChanged(UObject* Object, FPropertyChangedEvent& PropertyChangedEvent);

private:

	/** Holds the editable text box widget. */
	TSharedPtr<SMultiLineEditableTextBox> EditableTextBox;

	/** Pointer to the text asset that is being edited. */
	UBaseVariable* BaseVariable;
};
