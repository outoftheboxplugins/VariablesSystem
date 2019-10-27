#include "Kismet/BlueprintFunctionLibrary.h"
#include "VarSystem/Generator/Generated/Node/IncludeAll.h"
#include "GlobalVariablesBPLibrary.generated.h"

UCLASS(meta = (BlueprintThreadSafe))
class UGlobalVariablesBPLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

    UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Global ActorRef Variable (Thread Safe)"), Category = "VarSystem")
    static AActor* GetGlobalActorRefVariableSafe(UGlobalActorRefVariable* variable);

    UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Global Bool Variable (Thread Safe)"), Category = "VarSystem")
    static bool GetGlobalBoolVariableSafe(UGlobalBoolVariable* variable);

    UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Global Int Variable (Thread Safe)"), Category = "VarSystem")
    static int32 GetGlobalIntVariableSafe(UGlobalIntVariable* variable);

    UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Global Float Variable (Thread Safe)"), Category = "VarSystem")
    static float GetGlobalFloatVariableSafe(UGlobalFloatVariable* variable);

    UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Global FRotator Variable (Thread Safe)"), Category = "VarSystem")
    static FRotator GetGlobalFRotatorVariableSafe(UGlobalFRotatorVariable* variable);

    UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Global FVector Variable (Thread Safe)"), Category = "VarSystem")
    static FVector GetGlobalFVectorVariableSafe(UGlobalFVectorVariable* variable);

    UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Global String Variable (Thread Safe)"), Category = "VarSystem")
    static FString GetGlobalStringVariableSafe(UGlobalStringVariable* variable);

    UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Global FVector2D Variable (Thread Safe)"), Category = "VarSystem")
    static FVector2D GetGlobalFVector2DVariableSafe(UGlobalFVector2DVariable* variable);

};
