// Copyright Out-of-the-Box Plugins 2018-2021. All Rights Reserved.
// GENERATED FILE DO NOT MODIFY DIRECTLY

#pragma once

#include "InstancedVariable.h"
#include "InstancedFVectorVariable.generated.h"

USTRUCT(BlueprintType)
struct FInstancedFVectorVariableType
{
    GENERATED_USTRUCT_BODY();

public:
    UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "VariablesSystem")
    FVector Value;
};

/**
 * Instanced FVectorVariable implementation of the BaseVariable
 */

UCLASS(BlueprintType)
class VARIABLESSYSTEM_API UInstancedFVectorVariable : public UInstancedVariable
{
	GENERATED_BODY()

// Global static calls
public:
	// Get the value of a InstancedFVectorVariable variable.
	UFUNCTION(BlueprintPure, Category = "VariablesSystem", meta = (BlueprintThreadSafe))
	static FVector GetInstancedFVectorVariableValue(UObject* Owner, UInstancedFVectorVariable* Variable);

	// Get the reference of a InstancedFVectorVariable variable.
	UFUNCTION(BlueprintPure, Category = "VariablesSystem", meta = (BlueprintThreadSafe))
	static UInstancedFVectorVariable* GetInstancedMutableFVectorVariable(UInstancedFVectorVariable* Variable);

	// Set the value of a InstancedFVectorVariable variable.
	UFUNCTION(BlueprintCallable, Category = "VariablesSystem")
	static void SetInstancedFVectorVariableValue(UObject* Owner, UInstancedFVectorVariable* Variable, FVector NewValue);
	
	// Copy the value of a InstancedFVectorVariable variable.
	UFUNCTION(BlueprintCallable, Category = "VariablesSystem")
	static void CopyInstancedFVectorVariableValue(UObject* Owner, UInstancedFVectorVariable* Variable, UObject* OtherOwner, UInstancedFVectorVariable* OtherVariable);

private:
	virtual void CleanupEntries() override;

private:
	// Internal getter or creater used to modify values.
	FInstancedFVectorVariableType& GetInstancedFVectorVariableRef(UObject* Owner);

// BaseVariable Debug Interface
private:
    virtual FString GetStringValue() const override;
	FString GetValueAsString(FVector Value) const;

public:
    UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "VariablesSystem")
    TMap<UObject*, FInstancedFVectorVariableType> VariablesMap;
};

