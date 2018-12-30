// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "SVarSystemEditor.h"

#include "Fonts/SlateFontInfo.h"
#include "Internationalization/Text.h"
#include "BaseVariable.h"
#include "UObject/Class.h"
#include "Widgets/SBoxPanel.h"
#include "Widgets/Input/SMultiLineEditableTextBox.h"

#include "VarSystemEditorSettings.h"


#define LOCTEXT_NAMESPACE "SVarSystemEditor"


/* SVarSystemEditor interface
 *****************************************************************************/

SVarSystemEditor::~SVarSystemEditor()
{
	FCoreUObjectDelegates::OnObjectPropertyChanged.RemoveAll(this);
}


void SVarSystemEditor::Construct(const FArguments& InArgs, UBaseVariable* InBaseVariable, const TSharedRef<ISlateStyle>& InStyle)
{
	BaseVariable = InBaseVariable;

	auto Settings = GetDefault<UVarSystemEditorSettings>();

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
					.OnTextChanged(this, &SVarSystemEditor::HandleEditableTextBoxTextChanged)
					.OnTextCommitted(this, &SVarSystemEditor::HandleEditableTextBoxTextCommitted)
					.Text(BaseVariable->VariableDescription)
			]
	];

	FCoreUObjectDelegates::OnObjectPropertyChanged.AddSP(this, &SVarSystemEditor::HandleVarSystemPropertyChanged);
}


/* SVarSystemEditor callbacks
 *****************************************************************************/

void SVarSystemEditor::HandleEditableTextBoxTextChanged(const FText& NewText)
{
	BaseVariable->MarkPackageDirty();
}


void SVarSystemEditor::HandleEditableTextBoxTextCommitted(const FText& Comment, ETextCommit::Type CommitType)
{
	BaseVariable->VariableDescription = EditableTextBox->GetText();
}


void SVarSystemEditor::HandleVarSystemPropertyChanged(UObject* Object, FPropertyChangedEvent& PropertyChangedEvent)
{
	if (Object == BaseVariable)
	{
		EditableTextBox->SetText(BaseVariable->VariableDescription);
	}
}


#undef LOCTEXT_NAMESPACE
