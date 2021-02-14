// Copyright Out-of-the-Box Plugins 2018-2020. All Rights Reserved.

#pragma once

#include "BaseVariable.h"

#include "Engine/World.h"

#include "GlobalBaseVariable.generated.h"

/**
 * Global implementation of VS Variables
 */

// TOSOLVE: Make this a bitmap
UENUM(BlueprintType)
enum class EVSSaveType : uint8
{
	VSST_None                  UMETA(DisplayName = "None"),
	VSST_LoadOnStart 	       UMETA(DisplayName = "LoadOnStart"),
	VSST_SaveOnFinish 	       UMETA(DisplayName = "SaveOnFinish"),
	VSST_StartAndFinish	       UMETA(DisplayName = "StartAndFinish")
};

UCLASS(Abstract, BlueprintType, hidecategories=(Object)) 
class VARIABLESSYSTEM_API UGlobalBaseVariable : public UBaseVariable
{
	GENERATED_BODY()

public:
	UGlobalBaseVariable(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
	virtual ~UGlobalBaseVariable();

// Virtual functions for the derived variables to implement
public:
    // Returns the value of the variable as a string.
    virtual FString GetStringValue() const;

// Save & Load
public:
	// Saves the current data of a variable.
	virtual void Save() {};

	// Loads the data of a variable and assignees it.
	virtual void Load() {};

protected:
	// Returns the location where the variable should be saved.
	FString GetSaveLocation() const;

private:
	void SaveIfNeeded();
	void LoadIfNeeded();

// World Callbacks
private:
	virtual void OnWorldCreationEvent(const UWorld::FActorsInitializedParams& params) override;
	virtual void OnWorldDestructionEvent(UWorld* World, bool bSessionEnded, bool bCleanupResources) override;

protected:
    // Desired save-load behavior of the variable.
    UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "VariablesSystem")
    EVSSaveType SaveBehavior = EVSSaveType::VSST_StartAndFinish;

	// Unsaved changes done to this variable?
	bool Dirty = false;
};
