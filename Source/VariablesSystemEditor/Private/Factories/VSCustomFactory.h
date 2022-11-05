// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "UObject/ObjectMacros.h"

#include "VSCustomFactory.generated.h"

class UGlobalCustomVariable;

UCLASS(hidecategories = Object)
class UVSCustomFactory : public UFactory
{
	GENERATED_UCLASS_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "Data Table Factory")
	TObjectPtr<const class UScriptStruct> Struct;

	//~ Begin UFactory Interface
	virtual bool ConfigureProperties() override;
	virtual UObject* FactoryCreateNew(
		UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
	//~ Begin UFactory Interface

protected:
	virtual UGlobalCustomVariable* MakeNewDataTable(UObject* InParent, FName Name, EObjectFlags Flags);
};
