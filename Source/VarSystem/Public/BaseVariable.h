// Copyright Alexandru pasotee Oprea 2018. All Rights Reserved.

#pragma once

#include "Internationalization/Text.h"
#include "UObject/Object.h"
#include "UObject/ObjectMacros.h"

#include "BaseVariable.generated.h"


/**
 * Implements an asset that can be used to store arbitrary text, such as notes
 * or documentation.
 */
UCLASS(BlueprintType, hidecategories=(Object))
class VARSYSTEM_API UBaseVariable
	: public UObject
{
	GENERATED_BODY()

public:

	/** Holds the stored text. */
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="VarSystem")
	FText Text;
};
