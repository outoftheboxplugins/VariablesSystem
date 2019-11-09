// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#pragma once

#include "Factories/Factory.h"
#include "CoreMinimal.h"

#include "VariablesSystemFactory.generated.h"

/**
 * Implements a factory for UVariablesSystem to create Global & Local variables in form of assets..
 */

class UBaseVariable;

UCLASS()
class UVariablesSystemFactory : public UFactory
{
    GENERATED_UCLASS_BODY()

// UFactory Interface
public:
    virtual bool ShouldShowInNewMenu() const override;
    virtual bool ConfigureProperties() override;

    //TODO: We might want to import variables from .variable files as well.
    virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;

private:
    TSubclassOf<UBaseVariable> ChoosenVariableType;
};
