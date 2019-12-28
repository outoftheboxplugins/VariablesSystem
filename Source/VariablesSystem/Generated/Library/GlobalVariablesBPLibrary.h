#include "Kismet/BlueprintFunctionLibrary.h"
#include "VariablesSystem/Generated/Library/IncludeAll.h"
#include "GlobalVariablesBPLibrary.generated.h"

UCLASS(meta = (BlueprintThreadSafe))
class UGlobalVariablesBPLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

    UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Global ActorRefVariable Variable (Thread Safe)"), Category = "VariablesSystem")
    static AActor* GetGlobalActorRefVariableSafe(UGlobalActorRefVariable* variable);

    UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Global BoolVariable Variable (Thread Safe)"), Category = "VariablesSystem")
    static bool GetGlobalBoolVariableSafe(UGlobalBoolVariable* variable);

    UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Global IntVariable Variable (Thread Safe)"), Category = "VariablesSystem")
    static int32 GetGlobalIntVariableSafe(UGlobalIntVariable* variable);

    UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Global FloatVariable Variable (Thread Safe)"), Category = "VariablesSystem")
    static float GetGlobalFloatVariableSafe(UGlobalFloatVariable* variable);

    UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Global StringVariable Variable (Thread Safe)"), Category = "VariablesSystem")
    static FString GetGlobalStringVariableSafe(UGlobalStringVariable* variable);

    UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Global FRotatorVariable Variable (Thread Safe)"), Category = "VariablesSystem")
    static FRotator GetGlobalFRotatorVariableSafe(UGlobalFRotatorVariable* variable);

    UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Global FVectorVariable Variable (Thread Safe)"), Category = "VariablesSystem")
    static FVector GetGlobalFVectorVariableSafe(UGlobalFVectorVariable* variable);

    UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Global FVector2DVariable Variable (Thread Safe)"), Category = "VariablesSystem")
    static FVector2D GetGlobalFVector2DVariableSafe(UGlobalFVector2DVariable* variable);

};
