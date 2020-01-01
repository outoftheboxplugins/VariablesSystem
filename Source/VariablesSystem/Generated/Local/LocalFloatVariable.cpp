// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#include "LocalFloatVariable.h"
#include "Kismet/GameplayStatics.h"

float ULocalFloatVariable::GetLocalFloatVariableValue(UObject* owner, ULocalFloatVariable* var)
{
	if (owner == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Missing owner"));
		return 0.0f;
	}

	if (var == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Missing variable"));
		return 0.0f;
	}
	else
	{
		return var->GetLocalFloatVariableRef(owner);
	}
}

float& ULocalFloatVariable::GetLocalFloatVariableRef(UObject* owner)
{
	float& value = variables.FindOrAdd(owner);
	return value;
}

void ULocalFloatVariable::SetLocalFloatVariableValue(UObject* owner, ULocalFloatVariable* var, float _value)
{

	if (!var)	return;
	if (!owner) return;

	float& FloatVariableRef = var->GetLocalFloatVariableRef(owner);
	FloatVariableRef = _value;
	var->dirty = true;
}

void ULocalFloatVariable::CopyLocalFloatVariableValue(UObject* owner, ULocalFloatVariable* var, UObject* otherOwner, ULocalFloatVariable* other)
{
	if (!var)	return;
	if (!owner) return;
	if (!otherOwner) return;
	if (!other) return;
	
	float& FloatVariableRef = var->GetLocalFloatVariableRef(owner);
	float& otherFloatVariableRef = other->GetLocalFloatVariableRef(otherOwner);

	FloatVariableRef = otherFloatVariableRef;
	var->dirty = true;
}

void ULocalFloatVariable::Save()
{
    TArray<UObject*> Keys;
    variables.GetKeys(Keys);

    for (UObject* Key : Keys)
    {
        variables.FindAndRemoveChecked(Key);
    }
}

void ULocalFloatVariable::Load()
{
    TArray<UObject*> Keys;
    variables.GetKeys(Keys);

    for (UObject* Key : Keys)
    {
        variables.FindAndRemoveChecked(Key);
    }
}

FString ULocalFloatVariable::GetStringValue() const
{
    FString lines;

    for (auto& var : variables)
    {
        const auto& value = var.Value;
        const auto& owner = var.Key;

        FString valueString = UKismetStringLibrary::Conv_FloatToString(value);
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

