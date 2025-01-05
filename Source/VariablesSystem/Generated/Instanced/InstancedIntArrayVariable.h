// Copyright Out-of-the-Box Plugins 2018-2025. All Rights Reserved.
// GENERATED FILE DO NOT MODIFY DIRECTLY

#pragma once

#include "InstancedVariable.h"
#include "InstancedIntArrayVariable.generated.h"

USTRUCT(BlueprintType)
struct FInstancedIntArrayVariableType
{
    GENERATED_BODY();

public:
    UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "VariablesSystem")
    TArray<int32> Value  = TArray<int32>();
};

/**
 * Instanced IntArrayVariable implementation of the BaseVariable
 */

UCLASS(BlueprintType)
class VARIABLESSYSTEM_API UInstancedIntArrayVariable : public UInstancedVariable
{
	GENERATED_BODY()

// Global static calls
public:
	// Get the value of a InstancedIntArrayVariable variable.
	UFUNCTION(BlueprintPure, Category = "VariablesSystem", meta = (BlueprintThreadSafe))
	static TArray<int32> GetInstancedIntArrayVariableValue(UObject* Owner, UInstancedIntArrayVariable* Variable);

	// Get the reference of a InstancedIntArrayVariable variable.
	UFUNCTION(BlueprintPure, Category = "VariablesSystem", meta = (BlueprintThreadSafe))
	static UInstancedIntArrayVariable* GetInstancedMutableIntArrayVariable(UInstancedIntArrayVariable* Variable);

	// Set the value of a InstancedIntArrayVariable variable.
	UFUNCTION(BlueprintCallable, Category = "VariablesSystem")
	static void SetInstancedIntArrayVariableValue(UObject* Owner, UInstancedIntArrayVariable* Variable, TArray<int32> NewValue);
	
	// Copy the value of a InstancedIntArrayVariable variable.
	UFUNCTION(BlueprintCallable, Category = "VariablesSystem")
	static void CopyInstancedIntArrayVariableValue(UObject* Owner, UInstancedIntArrayVariable* Variable, UObject* OtherOwner, UInstancedIntArrayVariable* OtherVariable);

private:
	virtual void CleanupEntries() override;

private:
	// Internal getter or creater used to modify values.
	FInstancedIntArrayVariableType& GetInstancedIntArrayVariableRef(UObject* Owner);

// BaseVariable Debug Interface
private:
    virtual FString GetStringValue() const override;
	FString GetValueAsString(TArray<int32> Value) const;

public:
    UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "VariablesSystem")
    TMap<UObject*, FInstancedIntArrayVariableType> VariablesMap;
};

