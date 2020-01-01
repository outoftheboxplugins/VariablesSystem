// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#include "GlobalFloatArrayVariable.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetStringLibrary.h"
#include "CoreMinimal.h"

TArray<float> UGlobalFloatArrayVariable::GetGlobalFloatArrayVariableValue(UGlobalFloatArrayVariable* var)
{
	if (var == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Missing variable"));
		return TArray<float>();
	}
	else
	{
		return var->value;
	}
}

TArray<float> UGlobalFloatArrayVariable::GetGlobalInternalFloatArrayVariableValue()
{
	return GetGlobalFloatArrayVariableValue(this);
}

void UGlobalFloatArrayVariable::SetGlobalFloatArrayVariableValue(UGlobalFloatArrayVariable* var, TArray<float> _value)
{
	if (!var) return;

	var->value = _value;
	var->dirty = true;
}

void UGlobalFloatArrayVariable::SetGlobalInternalFloatArrayVariableValue(TArray<float> _value)
{
	SetGlobalFloatArrayVariableValue(this, _value);
}

void UGlobalFloatArrayVariable::CopyGlobalFloatArrayVariableValue(UGlobalFloatArrayVariable* var, UGlobalFloatArrayVariable* other)
{
	if (!var) return;

	var->value = other->value;
	var->dirty = true;
}

void UGlobalFloatArrayVariable::CopyGlobalInternalFloatArrayVariableValue(UGlobalFloatArrayVariable* other)
{
	CopyGlobalFloatArrayVariableValue(this, other);
}

void UGlobalFloatArrayVariable::Save()
{
	if (dirty == false)
	{
		return;
	}

	UGameplayStatics::SaveGameToSlot(this, GetSaveLocation(), 0);
	dirty = false;
}

void UGlobalFloatArrayVariable::Load()
{
	UGlobalFloatArrayVariable* LoadGameInstance = Cast<UGlobalFloatArrayVariable>(UGameplayStatics::CreateSaveGameObject(UGlobalFloatArrayVariable::StaticClass()));
	LoadGameInstance = Cast<UGlobalFloatArrayVariable>(UGameplayStatics::LoadGameFromSlot(GetSaveLocation(), 0));
	
	if (LoadGameInstance != nullptr)
	{
		this->value = LoadGameInstance->value;
	}
}


FString UGlobalFloatArrayVariable::GetStringValue() const
{
    TArray<FString> StringValues;
    for(const auto& item : value)
    {
        StringValues.Add(UKismetStringLibrary::Conv_FloatToString(item));
    }

    return UKismetStringLibrary::JoinStringArray(StringValues);
}

