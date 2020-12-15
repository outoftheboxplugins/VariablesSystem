// Copyright Out-of-the-Box Plugins 2018-2020. All Rights Reserved.

#include "VariablesWatchWidget.h"

#include "BaseVariable.h"
#include "VSLog.h"
#include "VariablesSystemHelpers.h"

#include "DragAndDrop/AssetDragDropOp.h"

#define LOCTEXT_NAMESPACE "VariablesSystemEditor"

namespace
{
	const FName ColumnVariableName = FName("Name");
	const FName ColumnVariableValue = FName("Value");
}

//////////////////////////////////////////////////////////////////////////
// SVSVariableRow
void SVSVariableRow::Construct(const FArguments& InArgs, const TSharedRef<STableViewBase>& InOwnerTable, UBaseVariable* InListItem)
{
	FSuperRowType::Construct(InArgs, InOwnerTable);

    Item = InListItem;
}

TSharedRef<SWidget> SVSVariableRow::GenerateWidgetForColumn(const FName& ColumnName)
{
    if (ColumnName == ColumnVariableName)
    {
        return SNew(STextBlock)
            .Text(FText::FromName(Item->GetFName()));
    }
    else if (ColumnName == ColumnVariableValue)
    {
        return SNew(STextBlock)
            .Text(FText::FromString(Item->GetStringValue()));
    }
    else
    {
        UE_LOG(LogVariablesSystem, Error, TEXT("Could not identify column based on name."));
        return SNew(STextBlock).Text(LOCTEXT("WatchUnkownColumn", "Unknown Column"));
    }
}

//////////////////////////////////////////////////////////////////////////
// SVSWatchWidget
void SVSWatchWidget::Construct(const FArguments& InArgs)
{
    ChildSlot
    [
        SNew(SVerticalBox)

		// Create a variable list to display each variable on row
        + SVerticalBox::Slot()
        .FillHeight(1.0f)
        [
            SAssignNew(VariablesListView, SListView<UBaseVariable*>)
            .ListItemsSource(&BaseVariables)
            .OnGenerateRow(this, &SVSWatchWidget::MakeVariableTableRow)
            .OnMouseButtonDoubleClick(this, &SVSWatchWidget::HandleVariableSelected)
            .OnContextMenuOpening(FOnContextMenuOpening::CreateSP(this, &SVSWatchWidget::CreateContextMenu))
            .HeaderRow(
                SNew(SHeaderRow)
                + SHeaderRow::Column(ColumnVariableName).DefaultLabel(LOCTEXT("WatchNameColumn", "Name"))
                + SHeaderRow::Column(ColumnVariableValue).DefaultLabel(LOCTEXT("WatchNameValue", "Value"))
            )
        ]
        + SVerticalBox::Slot()
        .AutoHeight()
        [
            SNew(SHorizontalBox)

			// Center content
            + SHorizontalBox::Slot()
            [
                SNew(SSpacer)
            ]

			// Button to add all the variables to the watch
            + SHorizontalBox::Slot()
            .AutoWidth()
            .Padding(.5f)
            .VAlign(VAlign_Center)
            .HAlign(HAlign_Center)
            [
                SNew(SButton)
                .HAlign(HAlign_Center)
                .Text(LOCTEXT("WatchAddAllTitle", "Add All"))
                .ToolTipText(LOCTEXT("WatchAddAllTooltip", "Add all Variables to the watch."))
				.OnClicked_Lambda([this]()
					{
						AddAllVariables();
						return FReply::Handled();
					})
            ]

			// Button to remove all the variables from the watch
            + SHorizontalBox::Slot()
            .AutoWidth()
            .Padding(.5f)
            .VAlign(VAlign_Center)
            .HAlign(HAlign_Right)
            [
                SNew(SButton)
                .HAlign(HAlign_Center)
                .Text(LOCTEXT("VariablesSystem_WatchRemoveAllTitle", "Remove All"))
                .ToolTipText(LOCTEXT("VariablesSystem_WatchRemoveAllTooltip", "Remove all Variables from the watch."))
				.OnClicked_Lambda([this]()
					{
						RemoveAllVariables();
						return FReply::Handled();
					})
            ]

			// Center content
            + SHorizontalBox::Slot()
            [
                SNew(SSpacer)
            ]
        ]
    ];
}

//////////////////////////////////////////////////////////////////////////
// Public calls
void SVSWatchWidget::AddVariables(TArray<UBaseVariable*> VariablesToAdd)
{
    for (auto Variable : VariablesToAdd)
    {
        BaseVariables.AddUnique(Variable);
    }
}

//////////////////////////////////////////////////////////////////////////
//SCompoundWidget interface
void SVSWatchWidget::Tick(const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime)
{
    SCompoundWidget::Tick(AllottedGeometry, InCurrentTime, InDeltaTime);
    
    VariablesListView->RebuildList();
}

FReply SVSWatchWidget::OnDrop(const FGeometry& MyGeometry, const FDragDropEvent& DragDropEvent)
{
    if (TSharedPtr<FDragDropOperation> DragDropOp = DragDropEvent.GetOperation())
    {
        if (TSharedPtr<FAssetDragDropOp> AssetDragDropOp = DragDropEvent.GetOperationAs<FAssetDragDropOp>())
        {
            TArray<UBaseVariable*> VariablesDropped;

            for (const FAssetData& AssetData : AssetDragDropOp->GetAssets())
            {
                if (UBaseVariable* VariableAsset = Cast<UBaseVariable>(AssetData.GetAsset()))
                {
                    VariablesDropped.Add(VariableAsset);
                }
            }

            AddVariables(VariablesDropped);

            if (VariablesDropped.Num() > 0)
            {
                return FReply::Handled();
            }
        }
    }

    return FReply::Unhandled();
}

//////////////////////////////////////////////////////////////////////////
// Callbacks
TSharedRef<ITableRow> SVSWatchWidget::MakeVariableTableRow(UBaseVariable* InInfo, const TSharedRef<STableViewBase>& OwnerTable)
{
    return SNew(SVSVariableRow, OwnerTable, InInfo);
}

TSharedPtr< SWidget > SVSWatchWidget::CreateContextMenu()
{
    TArray< UBaseVariable*>SelectedVariables;
    VariablesListView->GetSelectedItems(SelectedVariables);

    FMenuBuilder MenuBuilder(/*bInShouldCloseWindowAfterMenuSelection = */true, nullptr);
    MenuBuilder.BeginSection("Variables System");
    {
        MenuBuilder.AddMenuEntry(
            LOCTEXT("WatchMenuOpenTitle",	"Open Variables"),
            LOCTEXT("WatchMenuOpenTooltip", "Open the selected variable assets."),
            FSlateIcon(),
            FUIAction(FExecuteAction::CreateSP(this, &SVSWatchWidget::OpenVariables, SelectedVariables))
        );
        MenuBuilder.AddMenuEntry(
            LOCTEXT("WatchMenuRemoveTitle",		"Remove Variables"),
            LOCTEXT("WatchMenuRemoveTooltip",	"Remove the selected variable assets."),
            FSlateIcon(),
            FUIAction(FExecuteAction::CreateSP(this, &SVSWatchWidget::RemoveVariables, SelectedVariables))
        );
    }

    MenuBuilder.EndSection();

    return MenuBuilder.MakeWidget();
}

void SVSWatchWidget::HandleVariableSelected(UBaseVariable* InItem)
{
	GEditor->GetEditorSubsystem<UAssetEditorSubsystem>()->OpenEditorForAsset(InItem);
}

//////////////////////////////////////////////////////////////////////////
// Internal functionality
void SVSWatchWidget::AddAllVariables()
{
	TArray<UBaseVariable*> AllVariables = UVariablesSystemHelpersBPLibrary::GetAllVariables();
	AddVariables(AllVariables);
}

void SVSWatchWidget::RemoveAllVariables()
{
	BaseVariables.Empty();
}

void SVSWatchWidget::OpenVariables(TArray<UBaseVariable*> SelectedVariable)
{
	for (auto Variable : SelectedVariable)
	{
		HandleVariableSelected(Variable);
	}
}

void SVSWatchWidget::RemoveVariables(TArray<UBaseVariable*> SelectedVariable)
{
	for (auto Variable : SelectedVariable)
	{
		BaseVariables.RemoveSwap(Variable);
	}
}

#undef LOCTEXT_NAMESPACE