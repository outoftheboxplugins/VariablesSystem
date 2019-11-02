// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "SVariablesSystemEditor.h"

#include "Fonts/SlateFontInfo.h"
#include "Internationalization/Text.h"
#include "BaseVariable.h"
#include "UObject/Class.h"
#include "Widgets/SBoxPanel.h"
#include "Widgets/Input/SMultiLineEditableTextBox.h"

#include "VariablesSystemEditorSettings.h"


#define LOCTEXT_NAMESPACE "SVariablesSystemEditor"


/* SVariablesSystemEditor interface
 *****************************************************************************/

SVariablesSystemEditor::~SVariablesSystemEditor()
{
	FCoreUObjectDelegates::OnObjectPropertyChanged.RemoveAll(this);
}


void SVariablesSystemEditor::Construct(const FArguments& InArgs, UBaseVariable* InBaseVariable, const TSharedRef<ISlateStyle>& InStyle)
{
	BaseVariable = InBaseVariable;

	auto Settings = GetDefault<UVariablesSystemEditorSettings>();

	ChildSlot
	[
		SNew(SVerticalBox)

		+ SVerticalBox::Slot()
			.FillHeight(1.0f)
			[
				SAssignNew(EditableTextBox, SMultiLineEditableTextBox)
					.BackgroundColor((Settings != nullptr) ? Settings->BackgroundColor : FLinearColor::White)
					.Font((Settings != nullptr) ? Settings->Font : FSlateFontInfo())
					.ForegroundColor((Settings != nullptr) ? Settings->ForegroundColor : FLinearColor::Black)
					.Margin((Settings != nullptr) ? Settings->Margin : 4.0f)
					.OnTextChanged(this, &SVariablesSystemEditor::HandleEditableTextBoxTextChanged)
					.OnTextCommitted(this, &SVariablesSystemEditor::HandleEditableTextBoxTextCommitted)
					.Text(BaseVariable->GetDescription())
			]
	];

	FCoreUObjectDelegates::OnObjectPropertyChanged.AddSP(this, &SVariablesSystemEditor::HandleVariablesSystemPropertyChanged);
}


/* SVariablesSystemEditor callbacks
 *****************************************************************************/

void SVariablesSystemEditor::HandleEditableTextBoxTextChanged(const FText& NewText)
{
	BaseVariable->MarkPackageDirty();
}


void SVariablesSystemEditor::HandleEditableTextBoxTextCommitted(const FText& Comment, ETextCommit::Type CommitType)
{
	BaseVariable->GetDescription() = EditableTextBox->GetText();
}


void SVariablesSystemEditor::HandleVariablesSystemPropertyChanged(UObject* Object, FPropertyChangedEvent& PropertyChangedEvent)
{
	if (Object == BaseVariable)
	{
		EditableTextBox->SetText(BaseVariable->GetDescription());
	}
}


#undef LOCTEXT_NAMESPACE
