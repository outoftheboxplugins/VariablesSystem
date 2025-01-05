// Copyright Out-of-the-Box Plugins 2018-2025. All Rights Reserved.
// GENERATED FILE DO NOT MODIFY DIRECTLY

#pragma once

#include "InstancedVariable.h"
#include "InstancedFVectorArrayVariable.generated.h"

USTRUCT(BlueprintType)
struct FInstancedFVectorArrayVariableType
{
    GENERATED_BODY();

public:
    UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "VariablesSystem")
    TArray<FVector> Value  = TArray<FVector>();
};

/**
 * Instanced FVectorArrayVariable implementation of the BaseVariable
 */

UCLASS(BlueprintType)
class VARIABLESSYSTEM_API UInstancedFVectorArrayVariable : public UInstancedVariable
{
	GENERATED_BODY()

// Global static calls
public:
	// Get the value of a InstancedFVectorArrayVariable variable.
	UFUNCTION(BlueprintPure, Category = "VariablesSystem", meta = (BlueprintThreadSafe))
	static TArray<FVector> GetInstancedFVectorArrayVariableValue(UObject* Owner, UInstancedFVectorArrayVariable* Variable);

	// Get the reference of a InstancedFVectorArrayVariable variable.
	UFUNCTION(BlueprintPure, Category = "VariablesSystem", meta = (BlueprintThreadSafe))
	static UInstancedFVectorArrayVariable* GetInstancedMutableFVectorArrayVariable(UInstancedFVectorArrayVariable* Variable);

	// Set the value of a InstancedFVectorArrayVariable variable.
	UFUNCTION(BlueprintCallable, Category = "VariablesSystem")
	static void SetInstancedFVectorArrayVariableValue(UObject* Owner, UInstancedFVectorArrayVariable* Variable, TArray<FVector> NewValue);
	
	// Copy the value of a InstancedFVectorArrayVariable variable.
	UFUNCTION(BlueprintCallable, Category = "VariablesSystem")
	static void CopyInstancedFVectorArrayVariableValue(UObject* Owner, UInstancedFVectorArrayVariable* Variable, UObject* OtherOwner, UInstancedFVectorArrayVariable* OtherVariable);

private:
	virtual void CleanupEntries() override;

private:
	// Internal getter or creater used to modify values.
	FInstancedFVectorArrayVariableType& GetInstancedFVectorArrayVariableRef(UObject* Owner);

// BaseVariable Debug Interface
private:
    virtual FString GetStringValue() const override;
	FString GetValueAsString(TArray<FVector> Value) const;

public:
    UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "VariablesSystem")
    TMap<UObject*, FInstancedFVectorArrayVariableType> VariablesMap;
};

