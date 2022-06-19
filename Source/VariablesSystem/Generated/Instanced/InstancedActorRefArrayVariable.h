// Copyright Out-of-the-Box Plugins 2018-2021. All Rights Reserved.
// GENERATED FILE DO NOT MODIFY DIRECTLY

#pragma once

#include "InstancedVariable.h"
#include "InstancedActorRefArrayVariable.generated.h"

USTRUCT(BlueprintType)
struct FInstancedActorRefArrayVariableType
{
    GENERATED_BODY();

public:
    UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "VariablesSystem")
    TArray<AActor*> Value  = TArray<AActor*>();
};

/**
 * Instanced ActorRefArrayVariable implementation of the BaseVariable
 */

UCLASS(BlueprintType)
class VARIABLESSYSTEM_API UInstancedActorRefArrayVariable : public UInstancedVariable
{
	GENERATED_BODY()

// Global static calls
public:
	// Get the value of a InstancedActorRefArrayVariable variable.
	UFUNCTION(BlueprintPure, Category = "VariablesSystem", meta = (BlueprintThreadSafe))
	static TArray<AActor*> GetInstancedActorRefArrayVariableValue(UObject* Owner, UInstancedActorRefArrayVariable* Variable);

	// Get the reference of a InstancedActorRefArrayVariable variable.
	UFUNCTION(BlueprintPure, Category = "VariablesSystem", meta = (BlueprintThreadSafe))
	static UInstancedActorRefArrayVariable* GetInstancedMutableActorRefArrayVariable(UInstancedActorRefArrayVariable* Variable);

	// Set the value of a InstancedActorRefArrayVariable variable.
	UFUNCTION(BlueprintCallable, Category = "VariablesSystem")
	static void SetInstancedActorRefArrayVariableValue(UObject* Owner, UInstancedActorRefArrayVariable* Variable, TArray<AActor*> NewValue);
	
	// Copy the value of a InstancedActorRefArrayVariable variable.
	UFUNCTION(BlueprintCallable, Category = "VariablesSystem")
	static void CopyInstancedActorRefArrayVariableValue(UObject* Owner, UInstancedActorRefArrayVariable* Variable, UObject* OtherOwner, UInstancedActorRefArrayVariable* OtherVariable);

private:
	virtual void CleanupEntries() override;

private:
	// Internal getter or creater used to modify values.
	FInstancedActorRefArrayVariableType& GetInstancedActorRefArrayVariableRef(UObject* Owner);

// BaseVariable Debug Interface
private:
    virtual FString GetStringValue() const override;
	FString GetValueAsString(TArray<AActor*> Value) const;

public:
    UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "VariablesSystem")
    TMap<UObject*, FInstancedActorRefArrayVariableType> VariablesMap;
};

