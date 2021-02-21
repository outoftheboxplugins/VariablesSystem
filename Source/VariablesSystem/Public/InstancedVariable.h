// Copyright Out-of-the-Box Plugins 2018-2020. All Rights Reserved.

#pragma once

#include "BaseVariable.h"

#include "InstancedVariable.generated.h"

/**
 * Instanced implementation of VS Variables
 */

UCLASS(Abstract, BlueprintType, hidecategories=(Object)) 
class VARIABLESSYSTEM_API UInstancedVariable : public UBaseVariable
{
	GENERATED_BODY()

// Virtual functions for the derived variables to implement
public:
    // Returns the value of the variable as a string.
    virtual FString GetStringValue() const;

	// World Callbacks
private:
	virtual void OnWorldCreationEvent(const UWorld::FActorsInitializedParams& params) override;
	virtual void OnWorldDestructionEvent(UWorld* World, bool bSessionEnded, bool bCleanupResources) override;

protected:
	virtual void CleanupEntries() { }
};
