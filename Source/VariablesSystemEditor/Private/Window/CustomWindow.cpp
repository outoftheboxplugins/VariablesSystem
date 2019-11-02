// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "CustomWindow.h"

#include "VariablesSystemHelpers.h"

#include "Fonts/SlateFontInfo.h"
#include "Internationalization/Text.h"
#include "BaseVariable.h"
#include "UObject/Class.h"
#include "Widgets/SBoxPanel.h"
#include "Widgets/Input/SMultiLineEditableTextBox.h"

#include "VariablesSystemEditorSettings.h"
#include "Framework/Views/ITypedTableView.h"

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"
#include "Templates/SharedPointer.h"
#include "Framework/MultiBox/MultiBoxExtender.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "Containers/Array.h"
#include "AssetData.h"
#include "AssetRegistryModule.h"

#include "VariablesSystem/Generated/Library/IncludeAll.h"
#include "AssetEditorManager.h"

#define LOCTEXT_NAMESPACE "SVarEditorWindow"

/* SVarEditorWindow interface
 *****************************************************************************/

SVarEditorWindow::~SVarEditorWindow()
{
    //FCoreUObjectDelegates::OnObjectPropertyChanged.RemoveAll(this);
}

void SVarEditorWindow::Construct(const FArguments& InArgs, TArray<UBaseVariable*> InBaseVariables, const TSharedRef<ISlateStyle>& InStyle)
{
    InBaseVariables = UVariablesSystemHelpersBPLibrary::GetAllVariables();

    for (auto& variable : InBaseVariables)
    {
        BaseVariables.Push(variable);
    }

    ChildSlot
    [ 
        SAssignNew(SubjectsListView, SListView<UBaseVariable*>)
        .ListItemsSource(&BaseVariables)
        .OnGenerateRow(this, &SVarEditorWindow::MakeTreeRowWidget)
        .OnMouseButtonDoubleClick(this, &SVarEditorWindow::HandleSelectionChanged)
        .HeaderRow(
            SNew(SHeaderRow)
            + SHeaderRow::Column("Name").DefaultLabel(LOCTEXT("Name", "Name"))
            + SHeaderRow::Column("Value").DefaultLabel(LOCTEXT("Value", "Value"))
        )
    ];

    //FCoreUObjectDelegates::OnObjectPropertyChanged.AddSP(this, &SVarEditorWindow::HandleVariablesSystemPropertyChanged);
}


/* SVarEditorWindow callbacks
 *****************************************************************************/

void SVarEditorWindow::HandleEditableTextBoxTextChanged(const FText& NewText)
{
    BaseVariables[0]->MarkPackageDirty();
}


void SVarEditorWindow::HandleEditableTextBoxTextCommitted(const FText& Comment, ETextCommit::Type CommitType)
{
    BaseVariables[0]->GetDescription() = EditableTextBox->GetText();
}


void SVarEditorWindow::HandleVariablesSystemPropertyChanged(UObject* Object, FPropertyChangedEvent& PropertyChangedEvent)
{
    if (Object == BaseVariables[0])
    {
        EditableTextBox->SetText(BaseVariables[0]->GetDescription());
    }
}

TSharedRef<ITableRow> SVarEditorWindow::MakeTreeRowWidget(UBaseVariable* InInfo, const TSharedRef<STableViewBase>& OwnerTable)
{
    auto Settings = GetDefault<UVariablesSystemEditorSettings>();

    FString variableName;
    InInfo->GetName(variableName);

    class SModuleItemWidget : public SMultiColumnTableRow< UBaseVariable* >
    {
    public:
        SLATE_BEGIN_ARGS(SModuleItemWidget) {}
        SLATE_END_ARGS()

            void Construct(const FArguments& InArgs, const TSharedRef<STableViewBase>& InOwnerTable, UBaseVariable* InListItem)
        {
            Item = InListItem;

            SMultiColumnTableRow< UBaseVariable* >::Construct(FSuperRowType::FArguments(), InOwnerTable);
        }

        TSharedRef<SWidget> GenerateWidgetForColumn(const FName& ColumnName)
        {
            if (ColumnName == "Name")
            {
                return
                    SNew(STextBlock)
                    .Text(FText::FromName(Item->GetFName()));
            }
            else if (ColumnName == "Value")
            {
                return
                    SNew(STextBlock)
                    .Text(FText::FromString(Item->GetStringValue()));
            }
            else
            {
                return SNew(STextBlock).Text(LOCTEXT("UnknownColumn", "Unknown Column"));
            }

        }

        UBaseVariable* Item;
    };

    return SNew(SModuleItemWidget, OwnerTable, InInfo);
     
    //FString rowText = FString::Printf(L"%s - %s", *variableName, *variableValue);
    //
    //return
    //    SNew(STableRow< UBaseVariable* >, OwnerTable)
    //    .ShowSelection(true)
    //    [
    //        SNew(SBox)
    //        .Padding(1.f)
    //    [
    //        SNew(STextBlock)
    //        .Text(rowText)
    //    ]
    //    ];
}

void SVarEditorWindow::HandleSelectionChanged(UBaseVariable* InItem)
{
    FAssetEditorManager::Get().OpenEditorForAsset(InItem);
}

#undef LOCTEXT_NAMESPACE
