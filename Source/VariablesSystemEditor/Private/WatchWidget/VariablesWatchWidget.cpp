// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#include "VariablesWatchWidget.h"

#include "AssetData.h"
#include "AssetRegistryModule.h"
#include "BaseVariable.h"
#include "Toolkits/AssetEditorManager.h"
#include "VariablesSystem/Generated/Library/IncludeAll.h"
#include "VariablesSystemHelpers.h"

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


void SVariablesWatchWidget::Construct(const FArguments& InArgs, TArray<UBaseVariable*> Variables /* = TArray<UBaseVariable*>() */)
{
    if (Variables.Num() == 0)
    {
        BaseVariables = UVariablesSystemHelpersBPLibrary::GetAllVariables();
    }
    else
    {
        //TODO: Test if this works when we implement the variables actions to add/remove variables.
        BaseVariables = std::move(Variables);
    }

    ChildSlot
    [ 
        SAssignNew(VariablesListView, SListView<UBaseVariable*>)
        .ListItemsSource(&BaseVariables)
        .OnGenerateRow(this, &SVariablesWatchWidget::MakeVariableTableRow)
        .OnMouseButtonDoubleClick(this, &SVariablesWatchWidget::HandleVariableSelected)
        .HeaderRow(
            SNew(SHeaderRow)
            + SHeaderRow::Column(ColumnVariableName).DefaultLabel(LOCTEXT("VariablesSystem_WatchNameColumn", "Name"))
            + SHeaderRow::Column(ColumnVariableValue).DefaultLabel(LOCTEXT("VariablesSystem_WatchNameValue", "Value"))
        )
    ];
}


void SVariablesWatchWidget::Tick(const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime)
{
    SCompoundWidget::Tick(AllottedGeometry, InCurrentTime, InDeltaTime);
    
    VariablesListView->RebuildList();
}


TSharedRef<ITableRow> SVariablesWatchWidget::MakeVariableTableRow(UBaseVariable* InInfo, const TSharedRef<STableViewBase>& OwnerTable)
{
    return SNew(SVariableRowWidgetItem, OwnerTable, InInfo);
}

void SVariablesWatchWidget::HandleVariableSelected(UBaseVariable* InItem)
{
    FAssetEditorManager::Get().OpenEditorForAsset(InItem);
}

#undef LOCTEXT_NAMESPACE
