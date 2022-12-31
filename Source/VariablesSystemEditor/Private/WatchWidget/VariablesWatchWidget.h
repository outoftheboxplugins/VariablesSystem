// Copyright Out-of-the-Box Plugins 2018-2023. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"

#include "Widgets/SCompoundWidget.h"
#include "Widgets/Views/SListView.h"

class UBaseVariable;

/**
 * Helper class to create a table row with multiple columns for a BaseVariable.
 */

class SVSVariableRow : public SMultiColumnTableRow<UBaseVariable*>
{
public:
    void Construct(const FArguments& InArgs, const TSharedRef<STableViewBase>& InOwnerTable, UBaseVariable* InListItem);

private:
	virtual TSharedRef<SWidget> GenerateWidgetForColumn(const FName& ColumnName) override;

private:
    UBaseVariable* Item;
};

/**
 * Construct a watch to see the name and values of multiple variables at the same time.
 */

class SVSWatchWidget : public SCompoundWidget
{
public:
    SLATE_BEGIN_ARGS(SVSWatchWidget) { }
    SLATE_END_ARGS()

    void Construct(const FArguments& InArgs);
    
// Public calls
public:
    void AddVariables(TArray<UBaseVariable*> VariablesToAdd);

//SCompoundWidget interface
private:
    virtual void Tick(const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime) override;
    virtual FReply OnDrop(const FGeometry& MyGeometry, const FDragDropEvent& DragDropEvent) override;

// Callbacks
private:
    TSharedRef<ITableRow> MakeVariableTableRow(UBaseVariable* InInfo, const TSharedRef<STableViewBase>& OwnerTable);
    TSharedPtr<SWidget> CreateContextMenu();

    void HandleVariableSelected(UBaseVariable* InItem);

// Internal functionality
private:
    void AddAllVariables();
    void RemoveAllVariables();

    void OpenVariables(TArray<UBaseVariable*> SelectedVariable);
    void RemoveVariables(TArray<UBaseVariable*> SelectedVariable);

private:
    TSharedPtr<SListView<UBaseVariable*>> VariablesListView;
    
    TArray<UBaseVariable*> BaseVariables;
};
