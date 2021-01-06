// Copyright Out-of-the-Box Plugins 2018-2020. All Rights Reserved.

// GENERATED FILE DO NOT MODIFY DIRECTLY

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"

#include "VariablesSystem/Generated/Library/IncludeAll.h"

#include "GenericVariablesBPLibrary.generated.h"

UCLASS(meta = (BlueprintThreadSafe))
class UGenericVariablesBPLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Global ObjectRefVariable Variable (Thread Safe)"), Category = "VariablesSystem")
    static UObject* GetGlobalObjectRefVariableSafe(UGlobalObjectRefVariable* variable);

    UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Instanced ObjectRefVariable Variable (Thread Safe)"), Category = "VariablesSystem")
    static UObject* GetInstancedObjectRefVariableSafe(UInstancedObjectRefVariable* variable, UObject* owner);

    UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Global ActorRefVariable Variable (Thread Safe)"), Category = "VariablesSystem")
    static AActor* GetGlobalActorRefVariableSafe(UGlobalActorRefVariable* variable);

    UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Instanced ActorRefVariable Variable (Thread Safe)"), Category = "VariablesSystem")
    static AActor* GetInstancedActorRefVariableSafe(UInstancedActorRefVariable* variable, UObject* owner);

    UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Global BoolVariable Variable (Thread Safe)"), Category = "VariablesSystem")
    static bool GetGlobalBoolVariableSafe(UGlobalBoolVariable* variable);

    UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Instanced BoolVariable Variable (Thread Safe)"), Category = "VariablesSystem")
    static bool GetInstancedBoolVariableSafe(UInstancedBoolVariable* variable, UObject* owner);

    UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Global IntVariable Variable (Thread Safe)"), Category = "VariablesSystem")
    static int32 GetGlobalIntVariableSafe(UGlobalIntVariable* variable);

    UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Instanced IntVariable Variable (Thread Safe)"), Category = "VariablesSystem")
    static int32 GetInstancedIntVariableSafe(UInstancedIntVariable* variable, UObject* owner);

    UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Global FloatVariable Variable (Thread Safe)"), Category = "VariablesSystem")
    static float GetGlobalFloatVariableSafe(UGlobalFloatVariable* variable);

    UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Instanced FloatVariable Variable (Thread Safe)"), Category = "VariablesSystem")
    static float GetInstancedFloatVariableSafe(UInstancedFloatVariable* variable, UObject* owner);

    UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Global StringVariable Variable (Thread Safe)"), Category = "VariablesSystem")
    static FString GetGlobalStringVariableSafe(UGlobalStringVariable* variable);

    UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Instanced StringVariable Variable (Thread Safe)"), Category = "VariablesSystem")
    static FString GetInstancedStringVariableSafe(UInstancedStringVariable* variable, UObject* owner);

    UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Global FRotatorVariable Variable (Thread Safe)"), Category = "VariablesSystem")
    static FRotator GetGlobalFRotatorVariableSafe(UGlobalFRotatorVariable* variable);

    UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Instanced FRotatorVariable Variable (Thread Safe)"), Category = "VariablesSystem")
    static FRotator GetInstancedFRotatorVariableSafe(UInstancedFRotatorVariable* variable, UObject* owner);

    UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Global FVectorVariable Variable (Thread Safe)"), Category = "VariablesSystem")
    static FVector GetGlobalFVectorVariableSafe(UGlobalFVectorVariable* variable);

    UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Instanced FVectorVariable Variable (Thread Safe)"), Category = "VariablesSystem")
    static FVector GetInstancedFVectorVariableSafe(UInstancedFVectorVariable* variable, UObject* owner);

    UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Global FVector2DVariable Variable (Thread Safe)"), Category = "VariablesSystem")
    static FVector2D GetGlobalFVector2DVariableSafe(UGlobalFVector2DVariable* variable);

    UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Instanced FVector2DVariable Variable (Thread Safe)"), Category = "VariablesSystem")
    static FVector2D GetInstancedFVector2DVariableSafe(UInstancedFVector2DVariable* variable, UObject* owner);

};
