// Copyright Out-of-the-Box Plugins 2018-2023. All Rights Reserved.
// GENERATED FILE DO NOT MODIFY DIRECTLY

#pragma once

#include "InstancedVariable.h"
#include "InstancedFloatArrayVariable.generated.h"

USTRUCT(BlueprintType)
struct FInstancedFloatArrayVariableType
{
    GENERATED_BODY();

public:
    UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "VariablesSystem")
    TArray<float> Value  = TArray<float>();
};

/**
 * Instanced FloatArrayVariable implementation of the BaseVariable
 */

UCLASS(BlueprintType)
class VARIABLESSYSTEM_API UInstancedFloatArrayVariable : public UInstancedVariable
{
	GENERATED_BODY()

// Global static calls
public:
	// Get the value of a InstancedFloatArrayVariable variable.
	UFUNCTION(BlueprintPure, Category = "VariablesSystem", meta = (BlueprintThreadSafe))
	static TArray<float> GetInstancedFloatArrayVariableValue(UObject* Owner, UInstancedFloatArrayVariable* Variable);

	// Get the reference of a InstancedFloatArrayVariable variable.
	UFUNCTION(BlueprintPure, Category = "VariablesSystem", meta = (BlueprintThreadSafe))
	static UInstancedFloatArrayVariable* GetInstancedMutableFloatArrayVariable(UInstancedFloatArrayVariable* Variable);

	// Set the value of a InstancedFloatArrayVariable variable.
	UFUNCTION(BlueprintCallable, Category = "VariablesSystem")
	static void SetInstancedFloatArrayVariableValue(UObject* Owner, UInstancedFloatArrayVariable* Variable, TArray<float> NewValue);
	
	// Copy the value of a InstancedFloatArrayVariable variable.
	UFUNCTION(BlueprintCallable, Category = "VariablesSystem")
	static void CopyInstancedFloatArrayVariableValue(UObject* Owner, UInstancedFloatArrayVariable* Variable, UObject* OtherOwner, UInstancedFloatArrayVariable* OtherVariable);

private:
	virtual void CleanupEntries() override;

private:
	// Internal getter or creater used to modify values.
	FInstancedFloatArrayVariableType& GetInstancedFloatArrayVariableRef(UObject* Owner);

// BaseVariable Debug Interface
private:
    virtual FString GetStringValue() const override;
	FString GetValueAsString(TArray<float> Value) const;

public:
    UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "VariablesSystem")
    TMap<UObject*, FInstancedFloatArrayVariableType> VariablesMap;
};

