// Copyright Out-of-the-Box Plugins 2018-2025. All Rights Reserved.
// GENERATED FILE DO NOT MODIFY DIRECTLY

#pragma once

#include "InstancedVariable.h"
#include "InstancedFloatVariable.generated.h"

USTRUCT(BlueprintType)
struct FInstancedFloatVariableType
{
    GENERATED_BODY();

public:
    UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "VariablesSystem")
    float Value  = 0.0f;
};

/**
 * Instanced FloatVariable implementation of the BaseVariable
 */

UCLASS(BlueprintType)
class VARIABLESSYSTEM_API UInstancedFloatVariable : public UInstancedVariable
{
	GENERATED_BODY()

// Global static calls
public:
	// Get the value of a InstancedFloatVariable variable.
	UFUNCTION(BlueprintPure, Category = "VariablesSystem", meta = (BlueprintThreadSafe))
	static float GetInstancedFloatVariableValue(UObject* Owner, UInstancedFloatVariable* Variable);

	// Get the reference of a InstancedFloatVariable variable.
	UFUNCTION(BlueprintPure, Category = "VariablesSystem", meta = (BlueprintThreadSafe))
	static UInstancedFloatVariable* GetInstancedMutableFloatVariable(UInstancedFloatVariable* Variable);

	// Set the value of a InstancedFloatVariable variable.
	UFUNCTION(BlueprintCallable, Category = "VariablesSystem")
	static void SetInstancedFloatVariableValue(UObject* Owner, UInstancedFloatVariable* Variable, float NewValue);
	
	// Copy the value of a InstancedFloatVariable variable.
	UFUNCTION(BlueprintCallable, Category = "VariablesSystem")
	static void CopyInstancedFloatVariableValue(UObject* Owner, UInstancedFloatVariable* Variable, UObject* OtherOwner, UInstancedFloatVariable* OtherVariable);

private:
	virtual void CleanupEntries() override;

private:
	// Internal getter or creater used to modify values.
	FInstancedFloatVariableType& GetInstancedFloatVariableRef(UObject* Owner);

// BaseVariable Debug Interface
private:
    virtual FString GetStringValue() const override;
	FString GetValueAsString(float Value) const;

public:
    UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "VariablesSystem")
    TMap<UObject*, FInstancedFloatVariableType> VariablesMap;
};

