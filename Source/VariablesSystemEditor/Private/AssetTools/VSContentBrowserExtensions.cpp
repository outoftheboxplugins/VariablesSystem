// Copyright Out-of-the-Box Plugins 2018-2023. All Rights Reserved.

#include "VSContentBrowserExtensions.h"

#include "AssetToolsModule.h"
#include "ContentBrowserDataMenuContexts.h"
#include "ContentBrowserDataSubsystem.h"
#include "ToolMenus.h"
#include "VSFactory.h"
#include "VariablesSystem/Generated/Global/GlobalIntVariable.h"
#include "HAL/PlatformApplicationMisc.h"

#define LOCTEXT_NAMESPACE "VariablesSystemEditor"

static const TCHAR* VAR_PREFIX = TEXT("BPVar");

void FVSContentBrowserExtensions::Register()
{
	UToolMenu* ContextMenu = UToolMenus::Get()->ExtendMenu("ContentBrowser.AddNewContextMenu");
	FToolMenuSection& ContextMenuSection =
		ContextMenu->AddSection("OutOfTheBox", LOCTEXT("OutOfTheBoxActions", "Out-Of-The-Box Plugins"));

	ContextMenuSection.AddDynamicEntry(
		"PasteVariables", FNewToolMenuSectionDelegate::CreateSP(this, &FVSContentBrowserExtensions::RegisterDynamicMenuEntry));
}

void FVSContentBrowserExtensions::Unregister()
{
}

void FVSContentBrowserExtensions::RegisterDynamicMenuEntry(FToolMenuSection& Section)
{
	UContentBrowserDataMenuContext_AddNewMenu* AddNewMenuContext = Section.FindContext<UContentBrowserDataMenuContext_AddNewMenu>();
	if (AddNewMenuContext && AddNewMenuContext->bCanBeModified && AddNewMenuContext->bContainsValidPackagePath)
	{
		TArray<FName> SelectedPaths = AddNewMenuContext->SelectedPaths;

		Section.AddMenuEntry("PasteVariables", LOCTEXT("PasteVariables", "Convert clipboard to Global Variable"),
			LOCTEXT("PasteVariablesTooltip", "Transforms the currently copied blueprint variable to a Global Variable asset"),
			FSlateIcon(),
			FUIAction(FExecuteAction::CreateLambda(
						  [=]()
						  {
							  const FString SelectedPath = SelectedPaths[0].ToString();
							  OnPasteVariables(SelectedPath);
						  }),
				FCanExecuteAction::CreateLambda(
					[=]()
					{
						const bool bCanPaste = SelectedPaths.Num() > 0 && CanPasteVariable();
						return bCanPaste;
					})));
	}
}

bool FVSContentBrowserExtensions::CanPasteVariable() const
{
	FString ClipboardText;
	FPlatformApplicationMisc::ClipboardPaste(ClipboardText);
	return ClipboardText.StartsWith(VAR_PREFIX, ESearchCase::CaseSensitive);
}

void FVSContentBrowserExtensions::OnPasteVariables(const FString& Path)
{
	if (!CanPasteVariable())
	{
		return;
	}

	FString ClipboardText;
	FPlatformApplicationMisc::ClipboardPaste(ClipboardText);

	UContentBrowserDataSubsystem* ContentBrowserDataSubsystem = GEditor->GetEditorSubsystem<UContentBrowserDataSubsystem>();
	FString PackagePath;
	ContentBrowserDataSubsystem->TryConvertVirtualPath(Path, PackagePath);

	FBPVariableDescription Description;
	FStringOutputDevice Errors;
	const TCHAR* Import = ClipboardText.GetCharArray().GetData() + FCString::Strlen(VAR_PREFIX);
	FBPVariableDescription::StaticStruct()->ImportText(
		Import, &Description, nullptr, 0, &Errors, FBPVariableDescription::StaticStruct()->GetName());
	if (Errors.IsEmpty())
	{
		if (Description.VarType.PinCategory == UEdGraphSchema_K2::PC_Int)
		{
			FAssetToolsModule& AssetToolsModule = FAssetToolsModule::GetModule();
			FString NewPackageName;
			FString NewAssetName;
			FString DefaultName = FString::Printf(TEXT("%s/%s"), *PackagePath, *Description.VarName.ToString());
			// Sequences created in VR editor will have a sequential VRSequencer00X naming scheme and be stored in Game/Sequences
			AssetToolsModule.Get().CreateUniqueAssetName(DefaultName, TEXT(""), NewPackageName, NewAssetName);

			UVSGlobalFactory* Factory = NewObject<UVSGlobalFactory>();
			UClass* TargetClass = UGlobalIntVariable::StaticClass();
			Factory->ChoosenVariableType = TargetClass;
			AssetToolsModule.Get().CreateAsset(NewAssetName, PackagePath, TargetClass, Factory);
		}
	}
}

#undef LOCTEXT_NAMESPACE
