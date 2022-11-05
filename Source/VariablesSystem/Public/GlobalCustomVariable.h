// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"

#include "GlobalCustomVariable.generated.h"

/**
 *
 */
UCLASS(abstract, Blueprintable)
class VARIABLESSYSTEM_API UGlobalCustomVariable : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, Category = DataTable, meta = (DisplayThumbnail = "false"))
	TObjectPtr<UScriptStruct> RowStruct;
};
