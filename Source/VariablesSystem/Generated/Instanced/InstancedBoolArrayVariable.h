// Copyright Out-of-the-Box Plugins 2018-2023. All Rights Reserved.
// GENERATED FILE DO NOT MODIFY DIRECTLY

#pragma once

#include "InstancedVariable.h"
#include "InstancedBoolArrayVariable.generated.h"

USTRUCT(BlueprintType)
struct FInstancedBoolArrayVariableType
{
    GENERATED_BODY();

public:
    UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "VariablesSystem")
    TArray<bool> Value  = TArray<bool>();
};

/**
 * Instanced BoolArrayVariable implementation of the BaseVariable
 */

UCLASS(BlueprintType)
class VARIABLESSYSTEM_API UInstancedBoolArrayVariable : public UInstancedVariable
{
	GENERATED_BODY()

// Global static calls
public:
	// Get the value of a InstancedBoolArrayVariable variable.
	UFUNCTION(BlueprintPure, Category = "VariablesSystem", meta = (BlueprintThreadSafe))
	static TArray<bool> GetInstancedBoolArrayVariableValue(UObject* Owner, UInstancedBoolArrayVariable* Variable);

	// Get the reference of a InstancedBoolArrayVariable variable.
	UFUNCTION(BlueprintPure, Category = "VariablesSystem", meta = (BlueprintThreadSafe))
	static UInstancedBoolArrayVariable* GetInstancedMutableBoolArrayVariable(UInstancedBoolArrayVariable* Variable);

	// Set the value of a InstancedBoolArrayVariable variable.
	UFUNCTION(BlueprintCallable, Category = "VariablesSystem")
	static void SetInstancedBoolArrayVariableValue(UObject* Owner, UInstancedBoolArrayVariable* Variable, TArray<bool> NewValue);
	
	// Copy the value of a InstancedBoolArrayVariable variable.
	UFUNCTION(BlueprintCallable, Category = "VariablesSystem")
	static void CopyInstancedBoolArrayVariableValue(UObject* Owner, UInstancedBoolArrayVariable* Variable, UObject* OtherOwner, UInstancedBoolArrayVariable* OtherVariable);

private:
	virtual void CleanupEntries() override;

private:
	// Internal getter or creater used to modify values.
	FInstancedBoolArrayVariableType& GetInstancedBoolArrayVariableRef(UObject* Owner);

// BaseVariable Debug Interface
private:
    virtual FString GetStringValue() const override;
	FString GetValueAsString(TArray<bool> Value) const;

public:
    UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "VariablesSystem")
    TMap<UObject*, FInstancedBoolArrayVariableType> VariablesMap;
};

