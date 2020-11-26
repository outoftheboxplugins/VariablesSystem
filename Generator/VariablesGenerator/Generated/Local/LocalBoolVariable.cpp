// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#include "LocalBoolVariable.h"
#include "Kismet/GameplayStatics.h"

bool ULocalBoolVariable::GetLocalBoolVariableValue(UObject* owner, ULocalBoolVariable* var)
{
	if (owner == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Missing owner"));
		return false;
	}

	if (var == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Missing variable"));
		return false;
	}
	else
	{
		return var->GetLocalBoolVariableRef(owner);
	}
}

bool& ULocalBoolVariable::GetLocalBoolVariableRef(UObject* owner)
{
	bool& value = variables.FindOrAdd(owner);
	return value;
}

void ULocalBoolVariable::SetLocalBoolVariableValue(UObject* owner, ULocalBoolVariable* var, bool _value)
{

	if (!var)	return;
	if (!owner) return;

	bool& BoolVariableRef = var->GetLocalBoolVariableRef(owner);
	BoolVariableRef = _value;
	var->dirty = true;
}

void ULocalBoolVariable::CopyLocalBoolVariableValue(UObject* owner, ULocalBoolVariable* var, UObject* otherOwner, ULocalBoolVariable* other)
{
	if (!var)	return;
	if (!owner) return;
	if (!otherOwner) return;
	if (!other) return;
	
	bool& BoolVariableRef = var->GetLocalBoolVariableRef(owner);
	bool& otherBoolVariableRef = other->GetLocalBoolVariableRef(otherOwner);

	BoolVariableRef = otherBoolVariableRef;
	var->dirty = true;
}

void ULocalBoolVariable::Save()
{
    TArray<UObject*> Keys;
    variables.GetKeys(Keys);

    for (UObject* Key : Keys)
    {
        variables.FindAndRemoveChecked(Key);
    }
}

void ULocalBoolVariable::Load()
{
    TArray<UObject*> Keys;
    variables.GetKeys(Keys);

    for (UObject* Key : Keys)
    {
        variables.FindAndRemoveChecked(Key);
    }
}

FString ULocalBoolVariable::GetStringValue() const
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

FString ULocalBoolVariable::GetValueAsString(bool value) const
{
    const auto& item = value;
    return UKismetStringLibrary::Conv_BoolToString(item);
}

