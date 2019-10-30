// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "CustomWindow.h"

#include "Fonts/SlateFontInfo.h"
#include "Internationalization/Text.h"
#include "BaseVariable.h"
#include "UObject/Class.h"
#include "Widgets/SBoxPanel.h"
#include "Widgets/Input/SMultiLineEditableTextBox.h"

#include "VarSystemEditorSettings.h"
#include "Framework/Views/ITypedTableView.h"

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"
#include "Templates/SharedPointer.h"
#include "Framework/MultiBox/MultiBoxExtender.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "Containers/Array.h"
#include "AssetData.h"
#include "AssetRegistryModule.h"

#include "VarSystem/Generator/Generated/Node/IncludeAll.h"

#define LOCTEXT_NAMESPACE "SVarEditorWindow"

/* SVarEditorWindow interface
 *****************************************************************************/

SVarEditorWindow::~SVarEditorWindow()
{
    //FCoreUObjectDelegates::OnObjectPropertyChanged.RemoveAll(this);
}

void SVarEditorWindow::Construct(const FArguments& InArgs, TArray<UBaseVariable*> InBaseVariables, const TSharedRef<ISlateStyle>& InStyle)
{
    if (FModuleManager::Get().IsModuleLoaded("AssetRegistry"))
    {
        FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
        TArray<FAssetData> AssetData;
        AssetRegistryModule.Get().GetAssetsByClass(UGlobalBoolVariable::StaticClass()->GetFName(), AssetData);
        for (int i = 0; i < AssetData.Num(); i++) {
            UBaseVariable* VariableFound = Cast<UBaseVariable>(AssetData[i].GetAsset());
            if (VariableFound != NULL) {
                InBaseVariables.Add(VariableFound);
            }
        }
    }

    for (auto& variable : InBaseVariables)
    {
        BaseVariables.Push(variable);
    }

    ChildSlot
    [ 
        SAssignNew(SubjectsListView, SListView<UBaseVariable*>)
        .ListItemsSource(&BaseVariables)
        .OnGenerateRow(this, &SVarEditorWindow::MakeTreeRowWidget)
    ];

    //FCoreUObjectDelegates::OnObjectPropertyChanged.AddSP(this, &SVarEditorWindow::HandleVarSystemPropertyChanged);
}


/* SVarEditorWindow callbacks
 *****************************************************************************/

void SVarEditorWindow::HandleEditableTextBoxTextChanged(const FText& NewText)
{
    BaseVariables[0]->MarkPackageDirty();
}


void SVarEditorWindow::HandleEditableTextBoxTextCommitted(const FText& Comment, ETextCommit::Type CommitType)
{
    BaseVariables[0]->VariableDescription = EditableTextBox->GetText();
}


void SVarEditorWindow::HandleVarSystemPropertyChanged(UObject* Object, FPropertyChangedEvent& PropertyChangedEvent)
{
    if (Object == BaseVariables[0])
    {
        EditableTextBox->SetText(BaseVariables[0]->VariableDescription);
    }
}

TSharedRef<ITableRow> SVarEditorWindow::MakeTreeRowWidget(UBaseVariable* InInfo, const TSharedRef<STableViewBase>& OwnerTable)
{
    auto Settings = GetDefault<UVarSystemEditorSettings>();

    return
        SNew(STableRow< TSharedPtr<FString> >, OwnerTable)
        .ShowSelection(true)
        [
            SNew(SBox)
            .Padding(1.f)
        [
            SNew(STextBlock)
            .Text(FText::FromString(FString::FString("da")))
        ]
        ];

    //return SNew(SVerticalBox)
    //    + SVerticalBox::Slot()
    //    .FillHeight(1.0f)
    //    [
    //        SAssignNew(EditableTextBox, SMultiLineEditableTextBox)
    //        .BackgroundColor((Settings != nullptr) ? Settings->BackgroundColor : FLinearColor::White)
    //    .Font((Settings != nullptr) ? Settings->Font : FSlateFontInfo())
    //    .ForegroundColor((Settings != nullptr) ? Settings->ForegroundColor : FLinearColor::Black)
    //    .Margin((Settings != nullptr) ? Settings->Margin : 4.0f)
    //    .OnTextChanged(this, &SVarEditorWindow::HandleEditableTextBoxTextChanged)
    //    .OnTextCommitted(this, &SVarEditorWindow::HandleEditableTextBoxTextCommitted)
    //    .Text(/*BaseVariables[0]->VariableDescription*/ FText::FromString("da"))
    //    ];
    //        
    //
    // SNew(SLiveLinkClientPanelSubjectRow, OwnerTable)
    //    .Entry(InInfo);
}

#undef LOCTEXT_NAMESPACE
