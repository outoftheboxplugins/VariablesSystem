// Copyright Out-of-the-Box Plugins 2018-2025. All Rights Reserved.
// GENERATED FILE DO NOT MODIFY DIRECTLY

#pragma once

#include "InstancedVariable.h"
#include "InstancedFVector2DArrayVariable.generated.h"

USTRUCT(BlueprintType)
struct FInstancedFVector2DArrayVariableType
{
    GENERATED_BODY();

public:
    UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "VariablesSystem")
    TArray<FVector2D> Value  = TArray<FVector2D>();
};

/**
 * Instanced FVector2DArrayVariable implementation of the BaseVariable
 */

UCLASS(BlueprintType)
class VARIABLESSYSTEM_API UInstancedFVector2DArrayVariable : public UInstancedVariable
{
	GENERATED_BODY()

// Global static calls
public:
	// Get the value of a InstancedFVector2DArrayVariable variable.
	UFUNCTION(BlueprintPure, Category = "VariablesSystem", meta = (BlueprintThreadSafe))
	static TArray<FVector2D> GetInstancedFVector2DArrayVariableValue(UObject* Owner, UInstancedFVector2DArrayVariable* Variable);

	// Get the reference of a InstancedFVector2DArrayVariable variable.
	UFUNCTION(BlueprintPure, Category = "VariablesSystem", meta = (BlueprintThreadSafe))
	static UInstancedFVector2DArrayVariable* GetInstancedMutableFVector2DArrayVariable(UInstancedFVector2DArrayVariable* Variable);

	// Set the value of a InstancedFVector2DArrayVariable variable.
	UFUNCTION(BlueprintCallable, Category = "VariablesSystem")
	static void SetInstancedFVector2DArrayVariableValue(UObject* Owner, UInstancedFVector2DArrayVariable* Variable, TArray<FVector2D> NewValue);
	
	// Copy the value of a InstancedFVector2DArrayVariable variable.
	UFUNCTION(BlueprintCallable, Category = "VariablesSystem")
	static void CopyInstancedFVector2DArrayVariableValue(UObject* Owner, UInstancedFVector2DArrayVariable* Variable, UObject* OtherOwner, UInstancedFVector2DArrayVariable* OtherVariable);

private:
	virtual void CleanupEntries() override;

private:
	// Internal getter or creater used to modify values.
	FInstancedFVector2DArrayVariableType& GetInstancedFVector2DArrayVariableRef(UObject* Owner);

// BaseVariable Debug Interface
private:
    virtual FString GetStringValue() const override;
	FString GetValueAsString(TArray<FVector2D> Value) const;

public:
    UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "VariablesSystem")
    TMap<UObject*, FInstancedFVector2DArrayVariableType> VariablesMap;
};

