// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#pragma once

#include "Templates/SharedPointer.h"
#include "Widgets/SCompoundWidget.h"
#include "Widgets/Views/SListView.h"

class UBaseVariable;

/**
 * Helper class to create a table row with multiple columns for a BaseVariable.
 */

class SVariableRowWidgetItem : public SMultiColumnTableRow< UBaseVariable* >
{
public:
    SLATE_BEGIN_ARGS(SVariableRowWidgetItem) {}
    SLATE_END_ARGS()

    void Construct(const FArguments& InArgs, const TSharedRef<STableViewBase>& InOwnerTable, UBaseVariable* InListItem);

private:
    TSharedRef<SWidget> GenerateWidgetForColumn(const FName& ColumnName);

private:
    UBaseVariable* Item;
};


/**
 * Creates a widgets to see multiple variables assets at the same time in an uniform list.
 */

class SVariablesWatchWidget : public SCompoundWidget
{
public:
    SLATE_BEGIN_ARGS(SVariablesWatchWidget) { }
    SLATE_END_ARGS()
    
    virtual ~SVariablesWatchWidget() { }

public:
    /**
     * Construct a watch to see the name and values of multiple variables at the same time.
     *
     * @param InArgs The declaration data for this widget.
     * @param Variables The variables we should use put inside the watch (Default = all)
     */
    void Construct(const FArguments& InArgs, TArray<UBaseVariable*> Variables = TArray<UBaseVariable*>());

    virtual void Tick(const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime) override;

private:
    // Creates a row for a variable from a table.
    TSharedRef<ITableRow> MakeVariableTableRow(UBaseVariable* InInfo, const TSharedRef<STableViewBase>& OwnerTable);
    
    // Handles selecting a variable from the table.
    void HandleVariableSelected(UBaseVariable* InItem);

private:
    // Slate widget displaying the list of variables.
    TSharedPtr<SListView<UBaseVariable*>> VariablesListView;
    
    // Reference to the variables currently inside the watch.
    TArray<UBaseVariable*> BaseVariables;
};
