// Copyright Out-of-the-Box Plugins 2018-2023. All Rights Reserved.

#pragma once

class FVSContentBrowserExtensions : public TSharedFromThis<FVSContentBrowserExtensions>
{
public:
	void Register();
	void Unregister();

private:
	void RegisterDynamicMenuEntry(FToolMenuSection& Section);

	bool CanPasteVariable() const;
	void OnPasteVariables(const FString& Path);
};
