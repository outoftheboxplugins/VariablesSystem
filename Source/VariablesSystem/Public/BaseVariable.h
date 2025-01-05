// Copyright Out-of-the-Box Plugins 2018-2025. All Rights Reserved.
#pragma once

#include "GameFramework/SaveGame.h"

#include "Engine/World.h"

#include "BaseVariable.generated.h"

/**
 * Implements an asset that can store specific types of variables.
 */

UCLASS(Abstract, BlueprintType, hidecategories=(Object)) 
class VARIABLESSYSTEM_API UBaseVariable : public USaveGame
{
	GENERATED_BODY()

public:
	UBaseVariable(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
	virtual ~UBaseVariable();

// Virtual functions for the derived variables to implement
public:
    // Returns the value of the variable as a string.
    virtual FString GetStringValue() const;

// World Callbacks
private:
	virtual void OnWorldCreationEvent(const UWorld::FActorsInitializedParams& params) { } 
	virtual void OnWorldDestructionEvent(UWorld* World, bool bSessionEnded, bool bCleanupResources) { }

protected:
    // Full description of the variable usage.
    UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "VariablesSystem")
    FString Description = "Say something about your variable.";
};
