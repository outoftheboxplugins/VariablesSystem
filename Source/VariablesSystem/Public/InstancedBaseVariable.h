// Copyright Out-of-the-Box Plugins 2018-2020. All Rights Reserved.

#pragma once

#include "BaseVariable.h"

#include "InstancedBaseVariable.generated.h"

/**
 * Instanced implementation of VS Variables
 */

UCLASS(Abstract, BlueprintType, hidecategories=(Object)) 
class VARIABLESSYSTEM_API UInstancedBaseVariable : public UBaseVariable
{
	GENERATED_BODY()

// Virtual functions for the derived variables to implement
public:
    // Returns the value of the variable as a string.
    virtual FString GetStringValue() const;
};
