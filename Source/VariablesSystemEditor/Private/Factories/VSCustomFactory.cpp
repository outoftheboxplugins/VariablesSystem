// Copyright Epic Games, Inc. All Rights Reserved.

#include "Factories/VSCustomFactory.h"

#include "DataTableEditorUtils.h"
#include "Editor.h"
#include "EditorStyleSet.h"
#include "Engine/DataTable.h"
#include "GlobalCustomVariable.h"
#include "Input/Reply.h"
#include "Modules/ModuleManager.h"
#include "StructViewerFilter.h"
#include "StructViewerModule.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Input/SComboButton.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/SWindow.h"
#include "Widgets/Text/STextBlock.h"

#define LOCTEXT_NAMESPACE "VSCustomFactory"

UVSCustomFactory::UVSCustomFactory(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	SupportedClass = UGlobalCustomVariable::StaticClass();
	bCreateNew = true;
	bEditAfterNew = true;
}

bool UVSCustomFactory::ConfigureProperties()
{
	class FDataTableStructFilter : public IStructViewerFilter
	{
	public:
		virtual bool IsStructAllowed(const FStructViewerInitializationOptions& InInitOptions, const UScriptStruct* InStruct,
			TSharedRef<FStructViewerFilterFuncs> InFilterFuncs) override
		{
			return FDataTableEditorUtils::IsValidTableStruct(InStruct);
		}

		virtual bool IsUnloadedStructAllowed(const FStructViewerInitializationOptions& InInitOptions, const FName InStructPath,
			TSharedRef<FStructViewerFilterFuncs> InFilterFuncs) override
		{
			// Unloaded structs are always User Defined Structs, and User Defined Structs are always allowed
			// They will be re-validated by IsStructAllowed once loaded during the pick
			return true;
		}
	};

	class FVSCustomFactoryUI : public TSharedFromThis<FVSCustomFactoryUI>
	{
	public:
		FReply OnCreate()
		{
			check(ResultStruct);
			if (PickerWindow.IsValid())
			{
				PickerWindow->RequestDestroyWindow();
			}
			return FReply::Handled();
		}

		FReply OnCancel()
		{
			ResultStruct = nullptr;
			if (PickerWindow.IsValid())
			{
				PickerWindow->RequestDestroyWindow();
			}
			return FReply::Handled();
		}

		bool IsStructSelected() const
		{
			return ResultStruct != nullptr;
		}

		void OnPickedStruct(const UScriptStruct* ChosenStruct)
		{
			ResultStruct = ChosenStruct;
			StructPickerAnchor->SetIsOpen(false);
		}

		FText OnGetComboTextValue() const
		{
			return ResultStruct ? FText::AsCultureInvariant(ResultStruct->GetName()) : LOCTEXT("None", "None");
		}

		TSharedRef<SWidget> GenerateStructPicker()
		{
			FStructViewerModule& StructViewerModule = FModuleManager::LoadModuleChecked<FStructViewerModule>("StructViewer");

			// Fill in options
			FStructViewerInitializationOptions Options;
			Options.Mode = EStructViewerMode::StructPicker;
			Options.StructFilter = MakeShared<FDataTableStructFilter>();

			return SNew(SBox).WidthOverride(
				330)[SNew(SVerticalBox)

					 + SVerticalBox::Slot().FillHeight(1.0f).MaxHeight(500)[SNew(SBorder).Padding(4).BorderImage(
						   FEditorStyle::GetBrush("ToolPanel.GroupBorder"))[StructViewerModule.CreateStructViewer(
						   Options, FOnStructPicked::CreateSP(this, &FVSCustomFactoryUI::OnPickedStruct))]]];
		}

		const UScriptStruct* OpenStructSelector()
		{
			FStructViewerModule& StructViewerModule = FModuleManager::LoadModuleChecked<FStructViewerModule>("StructViewer");
			ResultStruct = nullptr;

			// Fill in options
			FStructViewerInitializationOptions Options;
			Options.Mode = EStructViewerMode::StructPicker;
			Options.StructFilter = MakeShared<FDataTableStructFilter>();

			// clang-format off
			PickerWindow = SNew(SWindow)
				.Title(LOCTEXT("VSCustomFactoryOptions", "Pick Row Structure"))
				.ClientSize(FVector2D(350, 100))
				.SupportsMinimize(false)
				.SupportsMaximize(false)
				[
					SNew(SBorder)
					.BorderImage(FEditorStyle::GetBrush("Menu.Background"))
					.Padding(10)
					[
						SNew(SVerticalBox)
						+SVerticalBox::Slot()
						.AutoHeight()
						[
							SAssignNew(StructPickerAnchor, SComboButton)
							.ContentPadding(FMargin(2,2,2,1))
							.MenuPlacement(MenuPlacement_BelowAnchor)
							.ButtonContent()
							[
								SNew(STextBlock)
								.Text(this, &FVSCustomFactoryUI::OnGetComboTextValue)
							]
							.OnGetMenuContent(this, &FVSCustomFactoryUI::GenerateStructPicker)
						]
						+SVerticalBox::Slot()
						.HAlign(HAlign_Right)
						.AutoHeight()
						[
							SNew(SHorizontalBox)
							+SHorizontalBox::Slot()
							.AutoWidth()
							[
								SNew(SButton)
								.Text(LOCTEXT("OK", "OK"))
								.IsEnabled(this, &FVSCustomFactoryUI::IsStructSelected)
								.OnClicked(this, &FVSCustomFactoryUI::OnCreate)
							]
							+SHorizontalBox::Slot()
							.AutoWidth()
							[
								SNew(SButton)
								.Text(LOCTEXT("Cancel", "Cancel"))
								.OnClicked(this, &FVSCustomFactoryUI::OnCancel)
							]
						]
					]
				];
			// clang-format on

			GEditor->EditorAddModalWindow(PickerWindow.ToSharedRef());
			PickerWindow.Reset();

			return ResultStruct;
		}

	private:
		TSharedPtr<SWindow> PickerWindow;
		TSharedPtr<SComboButton> StructPickerAnchor;
		const UScriptStruct* ResultStruct = nullptr;
	};

	TSharedRef<FVSCustomFactoryUI> StructSelector = MakeShareable(new FVSCustomFactoryUI());
	Struct = StructSelector->OpenStructSelector();

	return Struct != nullptr;
}

UObject* UVSCustomFactory::FactoryCreateNew(
	UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	UGlobalCustomVariable* DataTable = nullptr;
	if (Struct && ensure(SupportedClass == Class))
	{
		ensure(0 != (RF_Public & Flags));
		DataTable = MakeNewDataTable(InParent, Name, Flags);
		if (DataTable)
		{
			DataTable->StructType = const_cast<UScriptStruct*>(ToRawPtr(Struct));
			DataTable->StructData.SetNumZeroed(DataTable->StructType->GetStructureSize());
			DataTable->StructType->InitializeStruct(DataTable->StructData.GetData());
		}
	}
	return DataTable;
}

UGlobalCustomVariable* UVSCustomFactory::MakeNewDataTable(UObject* InParent, FName Name, EObjectFlags Flags)
{
	return NewObject<UGlobalCustomVariable>(InParent, Name, Flags);
}

#undef LOCTEXT_NAMESPACE	// "VSCustomFactory"
