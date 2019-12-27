// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#include "VariablesWatchWidget.h"

#include "AssetRegistry/Public/AssetData.h"
#include "AssetRegistry/Public/AssetRegistryModule.h"
#include "Slate/Public/Framework/MultiBox/MultiBoxBuilder.h"
#include "Slate/Public/Widgets/Layout/SSpacer.h"
#include "UnrealEd/Public/DragAndDrop/AssetDragDropOp.h"
#include "UnrealEd/Public/Toolkits/AssetEditorManager.h"
#include "VariablesSystem/Generated/Library/IncludeAll.h"
#include "VariablesSystem/Public/BaseVariable.h"
#include "VariablesSystem/Public/VariablesSystemHelpers.h"

const FName ColumnVariableName = FName("Name");
const FName ColumnVariableValue = FName("Value");

#define LOCTEXT_NAMESPACE "VariablesSystem"

void SVariableRowWidgetItem::Construct(const FArguments& InArgs, const TSharedRef<STableViewBase>& InOwnerTable, UBaseVariable* InListItem)
{
    Item = InListItem;

    SMultiColumnTableRow< UBaseVariable* >::Construct(FSuperRowType::FArguments(), InOwnerTable);
}

TSharedRef<SWidget> SVariableRowWidgetItem::GenerateWidgetForColumn(const FName& ColumnName)
{
    if (ColumnName == ColumnVariableName)
    {
        return
            SNew(STextBlock)
            .Text(FText::FromName(Item->GetFName()));
    }
    else if (ColumnName == ColumnVariableValue)
    {
        return 
            SNew(STextBlock)
            .Text(FText::FromString(Item->GetStringValue()));
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("Could not identify this column, please contact the developer"));
        return SNew(STextBlock).Text(LOCTEXT("VariablesSystem_WatchUnkownColumn", "Unknown Column"));
    }
}


void SVariablesWatchWidget::Construct(const FArguments& InArgs)
{
    ChildSlot
    [
        SNew(SVerticalBox)

        + SVerticalBox::Slot()
        .FillHeight(1.0f)
        [
            SAssignNew(VariablesListView, SListView<UBaseVariable*>)
            .ListItemsSource(&BaseVariables)
            .OnGenerateRow(this, &SVariablesWatchWidget::MakeVariableTableRow)
            .OnMouseButtonDoubleClick(this, &SVariablesWatchWidget::HandleVariableSelected)
            .OnContextMenuOpening(FOnContextMenuOpening::CreateSP(this, &SVariablesWatchWidget::CreateContextMenu))
            .HeaderRow(
                SNew(SHeaderRow)
                + SHeaderRow::Column(ColumnVariableName).DefaultLabel(LOCTEXT("VariablesSystem_WatchNameColumn", "Name"))
                + SHeaderRow::Column(ColumnVariableValue).DefaultLabel(LOCTEXT("VariablesSystem_WatchNameValue", "Value"))
            )
        ]
        + SVerticalBox::Slot()
        .AutoHeight()
        [
            SNew(SHorizontalBox)

            + SHorizontalBox::Slot()
            [
                SNew(SSpacer)
            ]

            + SHorizontalBox::Slot()
            .AutoWidth()
            .Padding(.5f)
            .VAlign(VAlign_Center)
            .HAlign(HAlign_Center)
            [
                SNew(SButton)
                .HAlign(HAlign_Center)
                .Text(LOCTEXT("VariablesSystem_WatchAddAllTitle", "Add All"))
                .ToolTipText(LOCTEXT("VariablesSystem_WatchAddAllTooltip", "Add all Variables to the watch."))
                .OnClicked(this, &SVariablesWatchWidget::OnAddButtonClicked)
            ]

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
                .OnClicked(this, &SVariablesWatchWidget::OnRemoveButtonClicked)
            ]

            + SHorizontalBox::Slot()
            [
                SNew(SSpacer)
            ]
        ]
    ];
}


void SVariablesWatchWidget::Tick(const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime)
{
    SCompoundWidget::Tick(AllottedGeometry, InCurrentTime, InDeltaTime);
    
    VariablesListView->RebuildList();
}

FReply SVariablesWatchWidget::OnDrop(const FGeometry& MyGeometry, const FDragDropEvent& DragDropEvent)
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

TSharedRef<ITableRow> SVariablesWatchWidget::MakeVariableTableRow(UBaseVariable* InInfo, const TSharedRef<STableViewBase>& OwnerTable)
{
    return SNew(SVariableRowWidgetItem, OwnerTable, InInfo);
}

TSharedPtr< SWidget > SVariablesWatchWidget::CreateContextMenu()
{
    TArray< UBaseVariable*>SelectedVariables;
    int32 VariablesCount = VariablesListView->GetSelectedItems(SelectedVariables);

    FMenuBuilder MenuBuilder(true, nullptr);

    MenuBuilder.BeginSection("Variables System");
    {
        MenuBuilder.AddMenuEntry(
            LOCTEXT("VariablesSystem_WatchMenuOpenTitle", "Open Variables"),
            LOCTEXT("VariablesSystem_WatchMenuOpenTooltip", "Open the selected variable assets."),
            FSlateIcon(),
            FUIAction(FExecuteAction::CreateSP(this, &SVariablesWatchWidget::OpenVariables, SelectedVariables))
        );

        MenuBuilder.AddMenuEntry(
            LOCTEXT("VariablesSystem_WatchMenuRemoveTitle", "Remove Variables"),
            LOCTEXT("VariablesSystem_WatchMenuRemoveTooltip", "Remove the selected variable assets."),
            FSlateIcon(),
            FUIAction(FExecuteAction::CreateSP(this, &SVariablesWatchWidget::RemoveVariables, SelectedVariables))
        );
    }
    MenuBuilder.EndSection();

    return MenuBuilder.MakeWidget();
}

void SVariablesWatchWidget::HandleVariableSelected(UBaseVariable* InItem)
{
    FAssetEditorManager::Get().OpenEditorForAsset(InItem);
}

void SVariablesWatchWidget::AddAllVariables()
{
    BaseVariables = UVariablesSystemHelpersBPLibrary::GetAllVariables();
}

void SVariablesWatchWidget::RemoveAllVariables()
{
    BaseVariables.Empty();
}

void SVariablesWatchWidget::AddVariables(TArray<UBaseVariable*> selected)
{
    for (auto variable : selected)
    {
        BaseVariables.AddUnique(variable);
    }
}

void SVariablesWatchWidget::OpenVariables(TArray<UBaseVariable*> selected)
{
    for (auto variable : selected)
    {
        HandleVariableSelected(variable);
    }
}

void SVariablesWatchWidget::RemoveVariables(TArray<UBaseVariable*> selected)
{
    for (auto variable : selected)
    {
        BaseVariables.RemoveSwap(variable);
    }
}

FReply SVariablesWatchWidget::OnAddButtonClicked()
{
    AddAllVariables();
    return FReply::Handled();
}

FReply SVariablesWatchWidget::OnRemoveButtonClicked()
{
    RemoveAllVariables();
    return FReply::Handled();
}

#undef LOCTEXT_NAMESPACE
