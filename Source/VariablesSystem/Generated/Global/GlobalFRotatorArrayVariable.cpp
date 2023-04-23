// Copyright Out-of-the-Box Plugins 2018-2023. All Rights Reserved.
// GENERATED FILE DO NOT MODIFY DIRECTLY

#include "GlobalFRotatorArrayVariable.h"

#include "VSLog.h"

#include "CoreMinimal.h"

#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetStringLibrary.h"

/* STATIC */ TArray<FRotator> UGlobalFRotatorArrayVariable::GetGlobalFRotatorArrayVariableValue(const UGlobalFRotatorArrayVariable* Variable)
{
	if (Variable)
	{
		return Variable->Value;
	}
	else
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Cannot get value without a variable. Returning default value. Callstack below:"));
		PrintScriptCallstack();

		return TArray<FRotator>();
	}
}

/* STATIC */ UGlobalFRotatorArrayVariable* UGlobalFRotatorArrayVariable::GetGlobalMutableFRotatorArrayVariable(UGlobalFRotatorArrayVariable* Variable)
{
    return Variable;
}

/* STATIC */ void UGlobalFRotatorArrayVariable::SetGlobalFRotatorArrayVariableValue(UGlobalFRotatorArrayVariable* Variable, TArray<FRotator> NewValue)
{
	if (Variable && Variable->Value != NewValue)
	{
		Variable->Value = NewValue;
		Variable->Dirty = true;
	}
	else if(!Variable)
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Cannot set value without a variable. Callstack below:"));
		PrintScriptCallstack();
	}
}

/* STATIC */ void UGlobalFRotatorArrayVariable::CopyGlobalFRotatorArrayVariableValue(UGlobalFRotatorArrayVariable* Variable, UGlobalFRotatorArrayVariable* OtherVariable)
{
	if (Variable && OtherVariable && Variable->Value != OtherVariable->Value)
	{
		Variable->Value = OtherVariable->Value;
		Variable->Dirty = true;
	}
	else if(!Variable)
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Cannot copy a value without a variable. Callstack below:"));
		PrintScriptCallstack();
	}
	else if(!OtherVariable)
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Cannot copy a value without an other variable. Callstack below:"));
		PrintScriptCallstack();
	}
}

FString UGlobalFRotatorArrayVariable::GetStringValue() const
{
    TArray<FString> StringValues;
    for(const auto& Item : Value)
    {
        StringValues.Add(UKismetStringLibrary::Conv_RotatorToString(Item));
    }

    return UKismetStringLibrary::JoinStringArray(StringValues);
}

void UGlobalFRotatorArrayVariable::Save(bool bForce /* = false */)
{
	if (GetOutermost() == GetTransientPackage() || (!Dirty && !bForce))
	{
		return;
	}

	UGameplayStatics::SaveGameToSlot(this, GetSaveLocation(), 0);
	Dirty = false;

	SavedValue = Value;
}

void UGlobalFRotatorArrayVariable::Load(bool bUpdateValue /* = true */)
{
	if(UGameplayStatics::DoesSaveGameExist(GetSaveLocation(), 0))
	{
		if (UGlobalFRotatorArrayVariable* LoadGameInstance = Cast<UGlobalFRotatorArrayVariable>(UGameplayStatics::LoadGameFromSlot(GetSaveLocation(), 0)))
		{
			SavedValue = LoadGameInstance->Value;

			if(bUpdateValue)
			{
				Value = SavedValue;
			}

		}
	}

}

#if WITH_EDITOR

void UGlobalFRotatorArrayVariable::PostEditChangeProperty(struct FPropertyChangedEvent& e)
{
	const bool bShouldLoad = SaveBehavior == EVSSaveType::VSST_LoadOnStart || SaveBehavior == EVSSaveType::VSST_StartAndFinish;

	 if (!bShouldLoad)
	 {
		 SavedValue = Value;
	 }
	 else
	 {
		 Load(false);
	 }

     Super::PostEditChangeProperty(e);
}

#endif

