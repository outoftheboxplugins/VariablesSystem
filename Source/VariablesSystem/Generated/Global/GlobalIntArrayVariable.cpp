// Copyright Out-of-the-Box Plugins 2018-2025. All Rights Reserved.
// GENERATED FILE DO NOT MODIFY DIRECTLY

#include "GlobalIntArrayVariable.h"

#include "VSLog.h"

#include "CoreMinimal.h"

#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetStringLibrary.h"

/* STATIC */ TArray<int32> UGlobalIntArrayVariable::GetGlobalIntArrayVariableValue(const UGlobalIntArrayVariable* Variable)
{
	if (Variable)
	{
		return Variable->Value;
	}
	else
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Cannot get value without a variable. Returning default value. Callstack below:"));
		PrintScriptCallstack();

		return TArray<int32>();
	}
}

/* STATIC */ UGlobalIntArrayVariable* UGlobalIntArrayVariable::GetGlobalMutableIntArrayVariable(UGlobalIntArrayVariable* Variable)
{
    return Variable;
}

/* STATIC */ void UGlobalIntArrayVariable::SetGlobalIntArrayVariableValue(UGlobalIntArrayVariable* Variable, TArray<int32> NewValue)
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

/* STATIC */ void UGlobalIntArrayVariable::CopyGlobalIntArrayVariableValue(UGlobalIntArrayVariable* Variable, UGlobalIntArrayVariable* OtherVariable)
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

FString UGlobalIntArrayVariable::GetStringValue() const
{
    TArray<FString> StringValues;
    for(const auto& Item : Value)
    {
        StringValues.Add(UKismetStringLibrary::Conv_IntToString(Item));
    }

    return UKismetStringLibrary::JoinStringArray(StringValues);
}

void UGlobalIntArrayVariable::Save(bool bForce /* = false */)
{
	if (GetOutermost() == GetTransientPackage() || (!Dirty && !bForce))
	{
		return;
	}

	UGameplayStatics::SaveGameToSlot(this, GetSaveLocation(), 0);
	Dirty = false;

	SavedValue = Value;
}

void UGlobalIntArrayVariable::Load(bool bUpdateValue /* = true */)
{
	if(UGameplayStatics::DoesSaveGameExist(GetSaveLocation(), 0))
	{
		if (UGlobalIntArrayVariable* LoadGameInstance = Cast<UGlobalIntArrayVariable>(UGameplayStatics::LoadGameFromSlot(GetSaveLocation(), 0)))
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

void UGlobalIntArrayVariable::PostEditChangeProperty(struct FPropertyChangedEvent& e)
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

