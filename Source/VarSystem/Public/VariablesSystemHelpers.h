#include "Kismet/BlueprintFunctionLibrary.h"
#include "VarSystem/Generator/Generated/Node/IncludeAll.h"

#include "Modules/ModuleManager.h"
#include "AssetRegistryModule.h"

#include "VariablesSystemHelpers.generated.h"

UCLASS(meta = (BlueprintThreadSafe))
class VARSYSTEM_API UVariablesSystemHelpersBPLibrary : public UBlueprintFunctionLibrary
{
public:
    GENERATED_BODY()

    static TArray<UBaseVariable*> GetAllVariables();
    
    template<class T>
    static FORCEINLINE TArray<T*> GetAllAssetsOfType()
    {
        TArray<T*> Variables;

        if (FModuleManager::Get().IsModuleLoaded("AssetRegistry"))
        {
            FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
            TArray<FAssetData> AssetData;

            FARFilter SearchFilter;
            SearchFilter.ClassNames.Add(T::StaticClass()->GetFName());
            SearchFilter.bRecursiveClasses = true;

            AssetRegistryModule.Get().GetAssets(SearchFilter, AssetData);

            for (int i = 0; i < AssetData.Num(); i++) {
                T* VariableFound = Cast<T>(AssetData[i].GetAsset());
                if (VariableFound != NULL) {
                    Variables.Add(VariableFound);
                }
            }
        }

        return Variables;
    }
};