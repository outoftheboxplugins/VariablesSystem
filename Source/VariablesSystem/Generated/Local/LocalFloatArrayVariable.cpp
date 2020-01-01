// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#include "LocalFloatArrayVariable.h"
#include "Kismet/GameplayStatics.h"

TArray<float> ULocalFloatArrayVariable::GetLocalFloatArrayVariableValue(UObject* owner, ULocalFloatArrayVariable* var)
{
	if (owner == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Missing owner"));
		return TArray<float>();
	}

	if (var == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Missing variable"));
		return TArray<float>();
	}
	else
	{
		return var->GetLocalFloatArrayVariableRef(owner);
	}
}

TArray<float>& ULocalFloatArrayVariable::GetLocalFloatArrayVariableRef(UObject* owner)
{
	TArray<float>& value = variables.FindOrAdd(owner);
	return value;
}

void ULocalFloatArrayVariable::SetLocalFloatArrayVariableValue(UObject* owner, ULocalFloatArrayVariable* var, TArray<float> _value)
{

	if (!var)	return;
	if (!owner) return;

	TArray<float>& FloatArrayVariableRef = var->GetLocalFloatArrayVariableRef(owner);
	FloatArrayVariableRef = _value;
	var->dirty = true;
}

void ULocalFloatArrayVariable::CopyLocalFloatArrayVariableValue(UObject* owner, ULocalFloatArrayVariable* var, UObject* otherOwner, ULocalFloatArrayVariable* other)
{
	if (!var)	return;
	if (!owner) return;
	if (!otherOwner) return;
	if (!other) return;
	
	TArray<float>& FloatArrayVariableRef = var->GetLocalFloatArrayVariableRef(owner);
	TArray<float>& otherFloatArrayVariableRef = other->GetLocalFloatArrayVariableRef(otherOwner);

	FloatArrayVariableRef = otherFloatArrayVariableRef;
	var->dirty = true;
}

void ULocalFloatArrayVariable::Save()
{
    TArray<UObject*> Keys;
    variables.GetKeys(Keys);

    for (UObject* Key : Keys)
    {
        variables.FindAndRemoveChecked(Key);
    }
}

void ULocalFloatArrayVariable::Load()
{
    TArray<UObject*> Keys;
    variables.GetKeys(Keys);

    for (UObject* Key : Keys)
    {
        variables.FindAndRemoveChecked(Key);
    }
}

FString ULocalFloatArrayVariable::GetStringValue() const
{
    FString lines;

    for (auto& var : variables)
    {
        const auto& value = var.Value;
        const auto& owner = var.Key;

        FString valueString = GetValueAsString(value);
        FString ownerString = owner ? owner->GetName() : FString("Owner destroyed");
        FString line = FString::Printf(TEXT("%s - %s \n"), *ownerString, *valueString);

        lines.Append(line);
    }

    lines.TrimEndInline();

    if (lines.IsEmpty())
    {
        lines = FString("No values set yet.");
    }

    return lines;
}

FString ULocalFloatArrayVariable::GetValueAsString(TArray<float> value) const
{
    TArray<FString> StringValues;
    for(const auto& item : value)
    {
        StringValues.Add(UKismetStringLibrary::Conv_FloatToString(item));
    }

    return UKismetStringLibrary::JoinStringArray(StringValues);
}

