// Copyright Out-of-the-Box Plugins 2018-2021. All Rights Reserved.
#pragma once 

#include "Kismet/BlueprintFunctionLibrary.h"

#include "AssetRegistry/Public/AssetRegistryModule.h"
#include "Core/Public/Modules/ModuleManager.h"

#include "VSLog.h"

#include "VariablesSystemHelpers.generated.h"

class UBaseVariable;

/**
 * Various helpers to simply working with VS Variables.
 */

UCLASS(meta = (BlueprintThreadSafe))
class VARIABLESSYSTEM_API UVariablesSystemHelpersBPLibrary : public UBlueprintFunctionLibrary
{
public:
    GENERATED_BODY()

	// Returns all assets of a certain type from the content browser.
	template<class T>
	static TArray<T*> GetAllAssetsOfType();

    // Returns all the variables (UObjects) assets from the content browser.
    static TArray<UBaseVariable*> GetAllVariables();

	// Returns all the variables (UObjects) assets from the content browser.
	static TArray<UGlobalVariable*> GetAllGlobalVariables();
    
	// Triggers a Save operation on all the Variable Assets
	UFUNCTION(BlueprintCallable, Category = "VariablesSystem")
	static void SaveAllVariables();

	// Triggers a Load operation on all the Variable Assets
	UFUNCTION(BlueprintCallable, Category = "VariablesSystem")
	static void LoadAllVariables();
};

template<class T>
TArray<T*> UVariablesSystemHelpersBPLibrary::GetAllAssetsOfType()
{
    TArray<T*> Assets;

    if (FModuleManager::Get().IsModuleLoaded("AssetRegistry"))
    {
        FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
        TArray<FAssetData> assetDatas;

        FARFilter SearchFilter;
        SearchFilter.ClassNames.Add(T::StaticClass()->GetFName());
        SearchFilter.bRecursiveClasses = true;

        AssetRegistryModule.Get().GetAssets(SearchFilter, assetDatas);

        for (auto& assetData : assetDatas)
        {
            T* VariableFound = Cast<T>(assetData.GetAsset());
            if (VariableFound != NULL) {
                Assets.Add(VariableFound);
            }
        }
    }
	else
	{
		UE_LOG(LogVariablesSystem, Error, TEXT("AssetRegistry Module not loaded!"));
	}

    return Assets;
}
