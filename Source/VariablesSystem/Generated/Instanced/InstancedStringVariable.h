// Copyright Out-of-the-Box Plugins 2018-2021. All Rights Reserved.
// GENERATED FILE DO NOT MODIFY DIRECTLY

#pragma once

#include "InstancedVariable.h"
#include "InstancedStringVariable.generated.h"

USTRUCT(BlueprintType)
struct FInstancedStringVariableType
{
    GENERATED_BODY();

public:
    UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "VariablesSystem")
    FString Value  = "";
};

/**
 * Instanced StringVariable implementation of the BaseVariable
 */

UCLASS(BlueprintType)
class VARIABLESSYSTEM_API UInstancedStringVariable : public UInstancedVariable
{
	GENERATED_BODY()

// Global static calls
public:
	// Get the value of a InstancedStringVariable variable.
	UFUNCTION(BlueprintPure, Category = "VariablesSystem", meta = (BlueprintThreadSafe))
	static FString GetInstancedStringVariableValue(UObject* Owner, UInstancedStringVariable* Variable);

	// Get the reference of a InstancedStringVariable variable.
	UFUNCTION(BlueprintPure, Category = "VariablesSystem", meta = (BlueprintThreadSafe))
	static UInstancedStringVariable* GetInstancedMutableStringVariable(UInstancedStringVariable* Variable);

	// Set the value of a InstancedStringVariable variable.
	UFUNCTION(BlueprintCallable, Category = "VariablesSystem")
	static void SetInstancedStringVariableValue(UObject* Owner, UInstancedStringVariable* Variable, FString NewValue);
	
	// Copy the value of a InstancedStringVariable variable.
	UFUNCTION(BlueprintCallable, Category = "VariablesSystem")
	static void CopyInstancedStringVariableValue(UObject* Owner, UInstancedStringVariable* Variable, UObject* OtherOwner, UInstancedStringVariable* OtherVariable);

private:
	virtual void CleanupEntries() override;

private:
	// Internal getter or creater used to modify values.
	FInstancedStringVariableType& GetInstancedStringVariableRef(UObject* Owner);

// BaseVariable Debug Interface
private:
    virtual FString GetStringValue() const override;
	FString GetValueAsString(FString Value) const;

public:
    UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "VariablesSystem")
    TMap<UObject*, FInstancedStringVariableType> VariablesMap;
};

