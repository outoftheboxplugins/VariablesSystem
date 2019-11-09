// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#pragma once

#include "ClassViewerFilter.h"
#include "CoreMinimal.h"

/**
 * Filter used for the Class picker dialog. Allows for filtering by class type and class flags.
 */

class FVariablesSystemCreateNewFilter : public IClassViewerFilter
{
public:
    FVariablesSystemCreateNewFilter();

    // IClassViewerFilter interface
public:
    virtual bool IsClassAllowed(const FClassViewerInitializationOptions& InInitOptions, const UClass* InClass, TSharedRef< FClassViewerFilterFuncs > InFilterFuncs) override;
    virtual bool IsUnloadedClassAllowed(const FClassViewerInitializationOptions& InInitOptions, const TSharedRef< const IUnloadedBlueprintData > InUnloadedClassData, TSharedRef< FClassViewerFilterFuncs > InFilterFuncs) override;

    // Filter properties
public:
    // Allowed types of classes (including children) 
    TSet< const UClass* > AllowedChildrenOfClasses;

    // Disallowed class flags.
    EClassFlags DisallowedClassFlags;
};