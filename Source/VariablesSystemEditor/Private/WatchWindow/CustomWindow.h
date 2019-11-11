// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Templates/SharedPointer.h"
#include "Widgets/DeclarativeSyntaxSupport.h"
#include "Widgets/SCompoundWidget.h"
#include "Widgets/Input/SMultiLineEditableTextBox.h"
#include "Widgets/Views/STreeView.h"

class FText;
class ISlateStyle;
class UBaseVariable;


/**
 * Implements the UVariablesSystem asset editor widget.
 */

class SVarEditorWindow
    : public SCompoundWidget
{
public:

    SLATE_BEGIN_ARGS(SVarEditorWindow) { }
    SLATE_END_ARGS()

public:

    /** Virtual destructor. */
    virtual ~SVarEditorWindow();

    /**
     * Construct this widget
     *
     * @param InArgs The declaration data for this widget.
     * @param InVariablesSystem The UVariablesSystem asset to edit.
     * @param InStyleSet The style set to use.
     */
    void Construct(const FArguments& InArgs);

    virtual void Tick(const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime) override;

private:

    /** Callback for text changes in the editable text box. */
    void HandleEditableTextBoxTextChanged(const FText& NewText);

    /** Callback for committed text in the editable text box. */
    void HandleEditableTextBoxTextCommitted(const FText& Comment, ETextCommit::Type CommitType);

    /** Callback for property changes in the text asset. */
    void HandleVariablesSystemPropertyChanged(UObject* Object, FPropertyChangedEvent& PropertyChangedEvent);

    // Helper functions for building the subject tree UI
    TSharedRef<ITableRow> MakeTreeRowWidget(UBaseVariable* InInfo, const TSharedRef<STableViewBase>& OwnerTable);
    
    /** Callback for selecting an activity in the list view. */
    void HandleSelectionChanged(UBaseVariable* InItem);


private:

    // Subject tree widget
    TSharedPtr< SListView< UBaseVariable* > > SubjectsListView;

    /** Holds the editable text box widget. */
    TSharedPtr<SMultiLineEditableTextBox> EditableTextBox;

    /** Pointer to the text asset that is being edited. */
    TArray<UBaseVariable*> BaseVariables;
};
