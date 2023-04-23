// Copyright Out-of-the-Box Plugins 2018-2023. All Rights Reserved.
// GENERATED FILE DO NOT MODIFY DIRECTLY

#include "GlobalBoolArrayVariable.h"

#include "VSLog.h"

#include "CoreMinimal.h"

#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetStringLibrary.h"

/* STATIC */ TArray<bool> UGlobalBoolArrayVariable::GetGlobalBoolArrayVariableValue(const UGlobalBoolArrayVariable* Variable)
{
	if (Variable)
	{
		return Variable->Value;
	}
	else
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Cannot get value without a variable. Returning default value. Callstack below:"));
		PrintScriptCallstack();

		return TArray<bool>();
	}
}

/* STATIC */ UGlobalBoolArrayVariable* UGlobalBoolArrayVariable::GetGlobalMutableBoolArrayVariable(UGlobalBoolArrayVariable* Variable)
{
    return Variable;
}

/* STATIC */ void UGlobalBoolArrayVariable::SetGlobalBoolArrayVariableValue(UGlobalBoolArrayVariable* Variable, TArray<bool> NewValue)
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

/* STATIC */ void UGlobalBoolArrayVariable::CopyGlobalBoolArrayVariableValue(UGlobalBoolArrayVariable* Variable, UGlobalBoolArrayVariable* OtherVariable)
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

FString UGlobalBoolArrayVariable::GetStringValue() const
{
    TArray<FString> StringValues;
    for(const auto& Item : Value)
    {
        StringValues.Add(UKismetStringLibrary::Conv_BoolToString(Item));
    }

    return UKismetStringLibrary::JoinStringArray(StringValues);
}

void UGlobalBoolArrayVariable::Save(bool bForce /* = false */)
{
	if (GetOutermost() == GetTransientPackage() || (!Dirty && !bForce))
	{
		return;
	}

	UGameplayStatics::SaveGameToSlot(this, GetSaveLocation(), 0);
	Dirty = false;

	SavedValue = Value;
}

void UGlobalBoolArrayVariable::Load(bool bUpdateValue /* = true */)
{
	if(UGameplayStatics::DoesSaveGameExist(GetSaveLocation(), 0))
	{
		if (UGlobalBoolArrayVariable* LoadGameInstance = Cast<UGlobalBoolArrayVariable>(UGameplayStatics::LoadGameFromSlot(GetSaveLocation(), 0)))
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

void UGlobalBoolArrayVariable::PostEditChangeProperty(struct FPropertyChangedEvent& e)
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

