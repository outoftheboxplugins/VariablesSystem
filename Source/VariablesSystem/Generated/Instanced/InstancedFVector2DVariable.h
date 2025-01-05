// Copyright Out-of-the-Box Plugins 2018-2025. All Rights Reserved.
// GENERATED FILE DO NOT MODIFY DIRECTLY

#pragma once

#include "InstancedVariable.h"
#include "InstancedFVector2DVariable.generated.h"

USTRUCT(BlueprintType)
struct FInstancedFVector2DVariableType
{
    GENERATED_BODY();

public:
    UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "VariablesSystem")
    FVector2D Value  = FVector2D::ZeroVector;
};

/**
 * Instanced FVector2DVariable implementation of the BaseVariable
 */

UCLASS(BlueprintType)
class VARIABLESSYSTEM_API UInstancedFVector2DVariable : public UInstancedVariable
{
	GENERATED_BODY()

// Global static calls
public:
	// Get the value of a InstancedFVector2DVariable variable.
	UFUNCTION(BlueprintPure, Category = "VariablesSystem", meta = (BlueprintThreadSafe))
	static FVector2D GetInstancedFVector2DVariableValue(UObject* Owner, UInstancedFVector2DVariable* Variable);

	// Get the reference of a InstancedFVector2DVariable variable.
	UFUNCTION(BlueprintPure, Category = "VariablesSystem", meta = (BlueprintThreadSafe))
	static UInstancedFVector2DVariable* GetInstancedMutableFVector2DVariable(UInstancedFVector2DVariable* Variable);

	// Set the value of a InstancedFVector2DVariable variable.
	UFUNCTION(BlueprintCallable, Category = "VariablesSystem")
	static void SetInstancedFVector2DVariableValue(UObject* Owner, UInstancedFVector2DVariable* Variable, FVector2D NewValue);
	
	// Copy the value of a InstancedFVector2DVariable variable.
	UFUNCTION(BlueprintCallable, Category = "VariablesSystem")
	static void CopyInstancedFVector2DVariableValue(UObject* Owner, UInstancedFVector2DVariable* Variable, UObject* OtherOwner, UInstancedFVector2DVariable* OtherVariable);

private:
	virtual void CleanupEntries() override;

private:
	// Internal getter or creater used to modify values.
	FInstancedFVector2DVariableType& GetInstancedFVector2DVariableRef(UObject* Owner);

// BaseVariable Debug Interface
private:
    virtual FString GetStringValue() const override;
	FString GetValueAsString(FVector2D Value) const;

public:
    UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "VariablesSystem")
    TMap<UObject*, FInstancedFVector2DVariableType> VariablesMap;
};

