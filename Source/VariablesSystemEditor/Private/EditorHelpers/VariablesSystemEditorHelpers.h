// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "VariablesSystem/Generated/Library/IncludeAll.h"

#include "VariablesSystemEditorHelpers.generated.h"

/**
 * Various helpers to simply working with/within the Variables System.
 */

UCLASS(meta = (BlueprintThreadSafe))
class VARIABLESSYSTEMEDITOR_API UVariablesSystemEditorHelpersBPLibrary : public UBlueprintFunctionLibrary
{
public:
    GENERATED_BODY()

    static TSharedRef<class SDockTab> OpenOrAddVariablesToWatch(TArray<UBaseVariable*> Variables = TArray<UBaseVariable*>());
};