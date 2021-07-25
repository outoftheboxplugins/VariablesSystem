// Copyright Out-of-the-Box Plugins 2018-2021. All Rights Reserved.
// GENERATED FILE DO NOT MODIFY DIRECTLY

#pragma once

#include "InstancedVariable.h"
#include "InstancedObjectRefArrayVariable.generated.h"

USTRUCT(BlueprintType)
struct FInstancedObjectRefArrayVariableType
{
    GENERATED_USTRUCT_BODY();

public:
    UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "VariablesSystem")
    TArray<UObject*> Value;
};

/**
 * Instanced ObjectRefArrayVariable implementation of the BaseVariable
 */

UCLASS(BlueprintType)
class VARIABLESSYSTEM_API UInstancedObjectRefArrayVariable : public UInstancedVariable
{
	GENERATED_BODY()

// Global static calls
public:
	// Get the value of a InstancedObjectRefArrayVariable variable.
	UFUNCTION(BlueprintPure, Category = "VariablesSystem", meta = (BlueprintThreadSafe))
	static TArray<UObject*> GetInstancedObjectRefArrayVariableValue(UObject* Owner, UInstancedObjectRefArrayVariable* Variable);

	// Get the reference of a InstancedObjectRefArrayVariable variable.
	UFUNCTION(BlueprintPure, Category = "VariablesSystem", meta = (BlueprintThreadSafe))
	static UInstancedObjectRefArrayVariable* GetInstancedMutableObjectRefArrayVariable(UInstancedObjectRefArrayVariable* Variable);

	// Set the value of a InstancedObjectRefArrayVariable variable.
	UFUNCTION(BlueprintCallable, Category = "VariablesSystem")
	static void SetInstancedObjectRefArrayVariableValue(UObject* Owner, UInstancedObjectRefArrayVariable* Variable, TArray<UObject*> NewValue);
	
	// Copy the value of a InstancedObjectRefArrayVariable variable.
	UFUNCTION(BlueprintCallable, Category = "VariablesSystem")
	static void CopyInstancedObjectRefArrayVariableValue(UObject* Owner, UInstancedObjectRefArrayVariable* Variable, UObject* OtherOwner, UInstancedObjectRefArrayVariable* OtherVariable);

private:
	virtual void CleanupEntries() override;

private:
	// Internal getter or creater used to modify values.
	FInstancedObjectRefArrayVariableType& GetInstancedObjectRefArrayVariableRef(UObject* Owner);

// BaseVariable Debug Interface
private:
    virtual FString GetStringValue() const override;
	FString GetValueAsString(TArray<UObject*> Value) const;

public:
    UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "VariablesSystem")
    TMap<UObject*, FInstancedObjectRefArrayVariableType> VariablesMap;
};

