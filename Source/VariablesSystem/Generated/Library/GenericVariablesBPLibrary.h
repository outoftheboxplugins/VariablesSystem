#include "Kismet/BlueprintFunctionLibrary.h"
#include "VariablesSystem/Generated/Library/IncludeAll.h"
#include "GenericVariablesBPLibrary.generated.h"

UCLASS(meta = (BlueprintThreadSafe))
class UGenericVariablesBPLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

    UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Global ActorRefVariable Variable (Thread Safe)"), Category = "VariablesSystem")
    static AActor* GetGlobalActorRefVariableSafe(UGlobalActorRefVariable* variable);

    UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Local ActorRefVariable Variable (Thread Safe)"), Category = "VariablesSystem")
    static AActor* GetLocalActorRefVariableSafe(ULocalActorRefVariable* variable, UObject* owner);

    UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Global BoolVariable Variable (Thread Safe)"), Category = "VariablesSystem")
    static bool GetGlobalBoolVariableSafe(UGlobalBoolVariable* variable);

    UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Local BoolVariable Variable (Thread Safe)"), Category = "VariablesSystem")
    static bool GetLocalBoolVariableSafe(ULocalBoolVariable* variable, UObject* owner);

    UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Global IntVariable Variable (Thread Safe)"), Category = "VariablesSystem")
    static int32 GetGlobalIntVariableSafe(UGlobalIntVariable* variable);

    UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Local IntVariable Variable (Thread Safe)"), Category = "VariablesSystem")
    static int32 GetLocalIntVariableSafe(ULocalIntVariable* variable, UObject* owner);

    UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Global FloatVariable Variable (Thread Safe)"), Category = "VariablesSystem")
    static float GetGlobalFloatVariableSafe(UGlobalFloatVariable* variable);

    UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Local FloatVariable Variable (Thread Safe)"), Category = "VariablesSystem")
    static float GetLocalFloatVariableSafe(ULocalFloatVariable* variable, UObject* owner);

    UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Global StringVariable Variable (Thread Safe)"), Category = "VariablesSystem")
    static FString GetGlobalStringVariableSafe(UGlobalStringVariable* variable);

    UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Local StringVariable Variable (Thread Safe)"), Category = "VariablesSystem")
    static FString GetLocalStringVariableSafe(ULocalStringVariable* variable, UObject* owner);

    UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Global FRotatorVariable Variable (Thread Safe)"), Category = "VariablesSystem")
    static FRotator GetGlobalFRotatorVariableSafe(UGlobalFRotatorVariable* variable);

    UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Local FRotatorVariable Variable (Thread Safe)"), Category = "VariablesSystem")
    static FRotator GetLocalFRotatorVariableSafe(ULocalFRotatorVariable* variable, UObject* owner);

    UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Global FVectorVariable Variable (Thread Safe)"), Category = "VariablesSystem")
    static FVector GetGlobalFVectorVariableSafe(UGlobalFVectorVariable* variable);

    UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Local FVectorVariable Variable (Thread Safe)"), Category = "VariablesSystem")
    static FVector GetLocalFVectorVariableSafe(ULocalFVectorVariable* variable, UObject* owner);

    UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Global FVector2DVariable Variable (Thread Safe)"), Category = "VariablesSystem")
    static FVector2D GetGlobalFVector2DVariableSafe(UGlobalFVector2DVariable* variable);

    UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Local FVector2DVariable Variable (Thread Safe)"), Category = "VariablesSystem")
    static FVector2D GetLocalFVector2DVariableSafe(ULocalFVector2DVariable* variable, UObject* owner);

    UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Global FloatArrayVariable Variable (Thread Safe)"), Category = "VariablesSystem")
    static TArray<float> GetGlobalFloatArrayVariableSafe(UGlobalFloatArrayVariable* variable);

    UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Local FloatArrayVariable Variable (Thread Safe)"), Category = "VariablesSystem")
    static TArray<float> GetLocalFloatArrayVariableSafe(ULocalFloatArrayVariable* variable, UObject* owner);

};
