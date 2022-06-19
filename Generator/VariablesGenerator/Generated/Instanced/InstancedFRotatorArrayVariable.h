// Copyright Out-of-the-Box Plugins 2018-2021. All Rights Reserved.
// GENERATED FILE DO NOT MODIFY DIRECTLY

#pragma once

#include "InstancedVariable.h"
#include "InstancedFRotatorArrayVariable.generated.h"

USTRUCT(BlueprintType)
struct FInstancedFRotatorArrayVariableType
{
    GENERATED_BODY();

public:
    UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "VariablesSystem")
    TArray<FRotator> Value  = TArray<FRotator>();
};

/**
 * Instanced FRotatorArrayVariable implementation of the BaseVariable
 */

UCLASS(BlueprintType)
class VARIABLESSYSTEM_API UInstancedFRotatorArrayVariable : public UInstancedVariable
{
	GENERATED_BODY()

// Global static calls
public:
	// Get the value of a InstancedFRotatorArrayVariable variable.
	UFUNCTION(BlueprintPure, Category = "VariablesSystem", meta = (BlueprintThreadSafe))
	static TArray<FRotator> GetInstancedFRotatorArrayVariableValue(UObject* Owner, UInstancedFRotatorArrayVariable* Variable);

	// Get the reference of a InstancedFRotatorArrayVariable variable.
	UFUNCTION(BlueprintPure, Category = "VariablesSystem", meta = (BlueprintThreadSafe))
	static UInstancedFRotatorArrayVariable* GetInstancedMutableFRotatorArrayVariable(UInstancedFRotatorArrayVariable* Variable);

	// Set the value of a InstancedFRotatorArrayVariable variable.
	UFUNCTION(BlueprintCallable, Category = "VariablesSystem")
	static void SetInstancedFRotatorArrayVariableValue(UObject* Owner, UInstancedFRotatorArrayVariable* Variable, TArray<FRotator> NewValue);
	
	// Copy the value of a InstancedFRotatorArrayVariable variable.
	UFUNCTION(BlueprintCallable, Category = "VariablesSystem")
	static void CopyInstancedFRotatorArrayVariableValue(UObject* Owner, UInstancedFRotatorArrayVariable* Variable, UObject* OtherOwner, UInstancedFRotatorArrayVariable* OtherVariable);

private:
	virtual void CleanupEntries() override;

private:
	// Internal getter or creater used to modify values.
	FInstancedFRotatorArrayVariableType& GetInstancedFRotatorArrayVariableRef(UObject* Owner);

// BaseVariable Debug Interface
private:
    virtual FString GetStringValue() const override;
	FString GetValueAsString(TArray<FRotator> Value) const;

public:
    UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "VariablesSystem")
    TMap<UObject*, FInstancedFRotatorArrayVariableType> VariablesMap;
};

