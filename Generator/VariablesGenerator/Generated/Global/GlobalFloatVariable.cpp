// Copyright Out-of-the-Box Plugins 2018-2021. All Rights Reserved.
// GENERATED FILE DO NOT MODIFY DIRECTLY

#include "GlobalFloatVariable.h"

#include "VSLog.h"

#include "CoreMinimal.h"

#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetStringLibrary.h"

/* STATIC */ float UGlobalFloatVariable::GetGlobalFloatVariableValue(const UGlobalFloatVariable* Variable)
{
	if (Variable)
	{
		return Variable->Value;
	}
	else
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Cannot get value without a variable. Returning default value. Callstack below:"));
		PrintScriptCallstack();

		return 0.0f;
	}
}

/* STATIC */ void UGlobalFloatVariable::SetGlobalFloatVariableValue(UGlobalFloatVariable* Variable, float NewValue)
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

/* STATIC */ void UGlobalFloatVariable::CopyGlobalFloatVariableValue(UGlobalFloatVariable* Variable, UGlobalFloatVariable* OtherVariable)
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

FString UGlobalFloatVariable::GetStringValue() const
{
    const auto& Item = Value;
    return UKismetStringLibrary::Conv_FloatToString(Item);
}

void UGlobalFloatVariable::Save(bool bForce /* = false */)
{
	if (!bForce && !Dirty)
	{
		return;
	}

	UGameplayStatics::SaveGameToSlot(this, GetSaveLocation(), 0);
	Dirty = false;

	SavedValue = Value;
}

void UGlobalFloatVariable::Load(bool bUpdateValue /* = true */)
{
	if(UGameplayStatics::DoesSaveGameExist(GetSaveLocation(), 0))
	{
		if (UGlobalFloatVariable* LoadGameInstance = Cast<UGlobalFloatVariable>(UGameplayStatics::LoadGameFromSlot(GetSaveLocation(), 0)))
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

void UGlobalFloatVariable::PostEditChangeProperty(struct FPropertyChangedEvent& e)
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

