// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#include "VariablesSystemCreateNewFilter.h"

FVariablesSystemCreateNewFilter::FVariablesSystemCreateNewFilter()
    : DisallowedClassFlags(CLASS_None) { }

bool FVariablesSystemCreateNewFilter::IsClassAllowed(const FClassViewerInitializationOptions& InInitOptions, const UClass* InClass, TSharedRef< FClassViewerFilterFuncs > InFilterFuncs)
{
    bool bAllowed = !InClass->HasAnyClassFlags(DisallowedClassFlags) && InFilterFuncs->IfInChildOfClassesSet(AllowedChildrenOfClasses, InClass) != EFilterReturn::Failed;

    return bAllowed;
}

bool FVariablesSystemCreateNewFilter::IsUnloadedClassAllowed(const FClassViewerInitializationOptions& InInitOptions, const TSharedRef< const IUnloadedBlueprintData > InUnloadedClassData, TSharedRef< FClassViewerFilterFuncs > InFilterFuncs)
{
    //For now we don not accept accept blueprint based classes.
    return false;
}
