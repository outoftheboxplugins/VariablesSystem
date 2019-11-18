// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#pragma once 

#include "AssetRegistryModule.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Modules/ModuleManager.h"
#include "VariablesSystem/Generated/Library/IncludeAll.h"

#include "VariablesSystemHelpers.generated.h"

/**
 * Various helpers to simply working with/within the Variables System.
 */

UCLASS(meta = (BlueprintThreadSafe))
class VARIABLESSYSTEM_API UVariablesSystemHelpersBPLibrary : public UBlueprintFunctionLibrary
{
public:
    GENERATED_BODY()

    // Returns all the variables (UObjects) assets from the content browser.
    static TArray<UBaseVariable*> GetAllVariables();
    
    // Returns all assets of a certain type from the content browser.
    template<class T>
    static TArray<T*> GetAllAssetsOfType();
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

    return Assets;
}
