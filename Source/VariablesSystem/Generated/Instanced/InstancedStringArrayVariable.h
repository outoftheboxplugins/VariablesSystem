// Copyright Out-of-the-Box Plugins 2018-2021. All Rights Reserved.
// GENERATED FILE DO NOT MODIFY DIRECTLY

#pragma once

#include "InstancedVariable.h"
#include "InstancedStringArrayVariable.generated.h"

USTRUCT(BlueprintType)
struct FInstancedStringArrayVariableType
{
    GENERATED_BODY();

public:
    UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "VariablesSystem")
    TArray<FString> Value  = TArray<FString>();
};

/**
 * Instanced StringArrayVariable implementation of the BaseVariable
 */

UCLASS(BlueprintType)
class VARIABLESSYSTEM_API UInstancedStringArrayVariable : public UInstancedVariable
{
	GENERATED_BODY()

// Global static calls
public:
	// Get the value of a InstancedStringArrayVariable variable.
	UFUNCTION(BlueprintPure, Category = "VariablesSystem", meta = (BlueprintThreadSafe))
	static TArray<FString> GetInstancedStringArrayVariableValue(UObject* Owner, UInstancedStringArrayVariable* Variable);

	// Get the reference of a InstancedStringArrayVariable variable.
	UFUNCTION(BlueprintPure, Category = "VariablesSystem", meta = (BlueprintThreadSafe))
	static UInstancedStringArrayVariable* GetInstancedMutableStringArrayVariable(UInstancedStringArrayVariable* Variable);

	// Set the value of a InstancedStringArrayVariable variable.
	UFUNCTION(BlueprintCallable, Category = "VariablesSystem")
	static void SetInstancedStringArrayVariableValue(UObject* Owner, UInstancedStringArrayVariable* Variable, TArray<FString> NewValue);
	
	// Copy the value of a InstancedStringArrayVariable variable.
	UFUNCTION(BlueprintCallable, Category = "VariablesSystem")
	static void CopyInstancedStringArrayVariableValue(UObject* Owner, UInstancedStringArrayVariable* Variable, UObject* OtherOwner, UInstancedStringArrayVariable* OtherVariable);

private:
	virtual void CleanupEntries() override;

private:
	// Internal getter or creater used to modify values.
	FInstancedStringArrayVariableType& GetInstancedStringArrayVariableRef(UObject* Owner);

// BaseVariable Debug Interface
private:
    virtual FString GetStringValue() const override;
	FString GetValueAsString(TArray<FString> Value) const;

public:
    UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "VariablesSystem")
    TMap<UObject*, FInstancedStringArrayVariableType> VariablesMap;
};

