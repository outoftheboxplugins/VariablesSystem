// Copyright Out-of-the-Box Plugins 2018-2020. All Rights Reserved.

#pragma once

#include "Factories/Factory.h"

#include "ClassViewerFilter.h"

#include "VSFactory.generated.h"

// Filter class for variables factory
class FVSFactoryFilter : public IClassViewerFilter
{
public:
	TSet<const UClass*> AllowedChildrenOfClasses;
	EClassFlags DisallowedClassFlags;

private:
	virtual bool IsClassAllowed(const FClassViewerInitializationOptions& InInitOptions, const UClass* InClass, TSharedRef<class FClassViewerFilterFuncs> InFilterFuncs) override;

	virtual bool IsUnloadedClassAllowed(const FClassViewerInitializationOptions& InInitOptions, const TSharedRef<const class IUnloadedBlueprintData> InUnloadedClassData, TSharedRef<class FClassViewerFilterFuncs> InFilterFuncs) override;
};

/**
 * Factory responsible for creating Variable assets.
 */

UCLASS()
class UVSFactory : public UFactory
{
    GENERATED_UCLASS_BODY()

// UFactory interface
private:
    virtual bool ShouldShowInNewMenu() const override;
    virtual bool ConfigureProperties() override;

    virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;

private:
    TSubclassOf<class UBaseVariable> ChoosenVariableType;
};
