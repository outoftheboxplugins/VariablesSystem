// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "SVarSystemEditor.h"

#include "Fonts/SlateFontInfo.h"
#include "Internationalization/Text.h"
#include "VarSystem.h"
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


void SVarSystemEditor::Construct(const FArguments& InArgs, UVarSystem* InVarSystem, const TSharedRef<ISlateStyle>& InStyle)
{
	VarSystem = InVarSystem;

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
					.Text(VarSystem->Text)
			]
	];

	FCoreUObjectDelegates::OnObjectPropertyChanged.AddSP(this, &SVarSystemEditor::HandleVarSystemPropertyChanged);
}


/* SVarSystemEditor callbacks
 *****************************************************************************/

void SVarSystemEditor::HandleEditableTextBoxTextChanged(const FText& NewText)
{
	VarSystem->MarkPackageDirty();
}


void SVarSystemEditor::HandleEditableTextBoxTextCommitted(const FText& Comment, ETextCommit::Type CommitType)
{
	VarSystem->Text = EditableTextBox->GetText();
}


void SVarSystemEditor::HandleVarSystemPropertyChanged(UObject* Object, FPropertyChangedEvent& PropertyChangedEvent)
{
	if (Object == VarSystem)
	{
		EditableTextBox->SetText(VarSystem->Text);
	}
}


#undef LOCTEXT_NAMESPACE
