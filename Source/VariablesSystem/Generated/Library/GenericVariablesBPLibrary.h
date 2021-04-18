// Copyright Out-of-the-Box Plugins 2018-2021. All Rights Reserved.
// GENERATED FILE DO NOT MODIFY DIRECTLY

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"

#include "IncludeAll.h"

#include "GenericVariablesBPLibrary.generated.h"

UCLASS(meta = (BlueprintThreadSafe))
class VARIABLESSYSTEM_API UGenericVariablesBPLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Global ObjectRefVariable Variable (Thread Safe)"), Category = "VariablesSystem")
    static UObject* GetGlobalObjectRefVariableSafe(UGlobalObjectRefVariable* Variable);

    UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Instanced ObjectRefVariable Variable (Thread Safe)"), Category = "VariablesSystem")
    static UObject* GetInstancedObjectRefVariableSafe(UInstancedObjectRefVariable* Variable, UObject* Owner);

    UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Global ActorRefVariable Variable (Thread Safe)"), Category = "VariablesSystem")
    static AActor* GetGlobalActorRefVariableSafe(UGlobalActorRefVariable* Variable);

    UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Instanced ActorRefVariable Variable (Thread Safe)"), Category = "VariablesSystem")
    static AActor* GetInstancedActorRefVariableSafe(UInstancedActorRefVariable* Variable, UObject* Owner);

    UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Global BoolVariable Variable (Thread Safe)"), Category = "VariablesSystem")
    static bool GetGlobalBoolVariableSafe(UGlobalBoolVariable* Variable);

    UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Instanced BoolVariable Variable (Thread Safe)"), Category = "VariablesSystem")
    static bool GetInstancedBoolVariableSafe(UInstancedBoolVariable* Variable, UObject* Owner);

    UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Global IntVariable Variable (Thread Safe)"), Category = "VariablesSystem")
    static int32 GetGlobalIntVariableSafe(UGlobalIntVariable* Variable);

    UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Instanced IntVariable Variable (Thread Safe)"), Category = "VariablesSystem")
    static int32 GetInstancedIntVariableSafe(UInstancedIntVariable* Variable, UObject* Owner);

    UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Global FloatVariable Variable (Thread Safe)"), Category = "VariablesSystem")
    static float GetGlobalFloatVariableSafe(UGlobalFloatVariable* Variable);

    UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Instanced FloatVariable Variable (Thread Safe)"), Category = "VariablesSystem")
    static float GetInstancedFloatVariableSafe(UInstancedFloatVariable* Variable, UObject* Owner);

    UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Global StringVariable Variable (Thread Safe)"), Category = "VariablesSystem")
    static FString GetGlobalStringVariableSafe(UGlobalStringVariable* Variable);

    UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Instanced StringVariable Variable (Thread Safe)"), Category = "VariablesSystem")
    static FString GetInstancedStringVariableSafe(UInstancedStringVariable* Variable, UObject* Owner);

    UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Global FRotatorVariable Variable (Thread Safe)"), Category = "VariablesSystem")
    static FRotator GetGlobalFRotatorVariableSafe(UGlobalFRotatorVariable* Variable);

    UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Instanced FRotatorVariable Variable (Thread Safe)"), Category = "VariablesSystem")
    static FRotator GetInstancedFRotatorVariableSafe(UInstancedFRotatorVariable* Variable, UObject* Owner);

    UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Global FVectorVariable Variable (Thread Safe)"), Category = "VariablesSystem")
    static FVector GetGlobalFVectorVariableSafe(UGlobalFVectorVariable* Variable);

    UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Instanced FVectorVariable Variable (Thread Safe)"), Category = "VariablesSystem")
    static FVector GetInstancedFVectorVariableSafe(UInstancedFVectorVariable* Variable, UObject* Owner);

    UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Global FVector2DVariable Variable (Thread Safe)"), Category = "VariablesSystem")
    static FVector2D GetGlobalFVector2DVariableSafe(UGlobalFVector2DVariable* Variable);

    UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Instanced FVector2DVariable Variable (Thread Safe)"), Category = "VariablesSystem")
    static FVector2D GetInstancedFVector2DVariableSafe(UInstancedFVector2DVariable* Variable, UObject* Owner);

};
