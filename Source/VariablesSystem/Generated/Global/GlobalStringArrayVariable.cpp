// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#include "GlobalStringArrayVariable.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetStringLibrary.h"
#include "CoreMinimal.h"

TArray<FString> UGlobalStringArrayVariable::GetGlobalStringArrayVariableValue(UGlobalStringArrayVariable* var)
{
	if (var == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Missing variable"));
		return TArray<FString>();
	}
	else
	{
		return var->value;
	}
}

TArray<FString> UGlobalStringArrayVariable::GetGlobalInternalStringArrayVariableValue()
{
	return GetGlobalStringArrayVariableValue(this);
}

void UGlobalStringArrayVariable::SetGlobalStringArrayVariableValue(UGlobalStringArrayVariable* var, TArray<FString> _value)
{
	if (!var) return;

	var->value = _value;
	var->dirty = true;
}

void UGlobalStringArrayVariable::SetGlobalInternalStringArrayVariableValue(TArray<FString> _value)
{
	SetGlobalStringArrayVariableValue(this, _value);
}

void UGlobalStringArrayVariable::CopyGlobalStringArrayVariableValue(UGlobalStringArrayVariable* var, UGlobalStringArrayVariable* other)
{
	if (!var) return;

	var->value = other->value;
	var->dirty = true;
}

void UGlobalStringArrayVariable::CopyGlobalInternalStringArrayVariableValue(UGlobalStringArrayVariable* other)
{
	CopyGlobalStringArrayVariableValue(this, other);
}

void UGlobalStringArrayVariable::Save()
{
	if (dirty == false)
	{
		return;
	}

	UGameplayStatics::SaveGameToSlot(this, GetSaveLocation(), 0);
	dirty = false;
}

void UGlobalStringArrayVariable::Load()
{
	UGlobalStringArrayVariable* LoadGameInstance = Cast<UGlobalStringArrayVariable>(UGameplayStatics::CreateSaveGameObject(UGlobalStringArrayVariable::StaticClass()));
	LoadGameInstance = Cast<UGlobalStringArrayVariable>(UGameplayStatics::LoadGameFromSlot(GetSaveLocation(), 0));
	
	if (LoadGameInstance != nullptr)
	{
		this->value = LoadGameInstance->value;
	}
}


FString UGlobalStringArrayVariable::GetStringValue() const
{
    TArray<FString> StringValues;
    for(const auto& item : value)
    {
        StringValues.Add(item);
    }

    return UKismetStringLibrary::JoinStringArray(StringValues);
}

