// Copyright Out-of-the-Box Plugins 2018-2025. All Rights Reserved.
#pragma once

#include "ClassViewerFilter.h"
#include "Factories/Factory.h"

#include "VSFactory.generated.h"

// Filter class for variables factory
class FVSFactoryFilter : public IClassViewerFilter
{
public:
	TSet<const UClass*> AllowedChildrenOfClasses;
	EClassFlags DisallowedClassFlags;

private:
	virtual bool IsClassAllowed(const FClassViewerInitializationOptions& InInitOptions, const UClass* InClass,
		TSharedRef<class FClassViewerFilterFuncs> InFilterFuncs) override;

	virtual bool IsUnloadedClassAllowed(const FClassViewerInitializationOptions& InInitOptions,
		const TSharedRef<const class IUnloadedBlueprintData> InUnloadedClassData,
		TSharedRef<class FClassViewerFilterFuncs> InFilterFuncs) override;
};

/**
 * Factory responsible for creating Variable assets.
 */

UCLASS(abstract)
class UVSFactory : public UFactory
{
	GENERATED_UCLASS_BODY()

	// UFactory interface
private:
	virtual bool ConfigureProperties() override;
	virtual bool CanCreateNew() const override
	{
		return true;
	}
	virtual bool ShouldShowInNewMenu() const override
	{
		return true;
	}

	virtual UObject* FactoryCreateNew(
		UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;

public:
	TSubclassOf<class UBaseVariable> ChoosenVariableType;

private:
	virtual bool ConfigureVariableProperties(UClass*& OutChosenClass)
	{
		return false;
	}
};

UCLASS()
class UVSInstancedFactory : public UVSFactory
{
	GENERATED_UCLASS_BODY()

	virtual bool ConfigureVariableProperties(UClass*& OutChosenClass) override;
};

UCLASS()
class UVSGlobalFactory : public UVSFactory
{
	GENERATED_UCLASS_BODY()

	virtual bool ConfigureVariableProperties(UClass*& OutChosenClass) override;
};
