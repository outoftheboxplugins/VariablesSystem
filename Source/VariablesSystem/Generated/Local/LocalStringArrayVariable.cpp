// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#include "LocalStringArrayVariable.h"
#include "Kismet/GameplayStatics.h"

TArray<FString> ULocalStringArrayVariable::GetLocalStringArrayVariableValue(UObject* owner, ULocalStringArrayVariable* var)
{
	if (owner == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Missing owner"));
		return TArray<FString>();
	}

	if (var == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Missing variable"));
		return TArray<FString>();
	}
	else
	{
		return var->GetLocalStringArrayVariableRef(owner);
	}
}

TArray<FString>& ULocalStringArrayVariable::GetLocalStringArrayVariableRef(UObject* owner)
{
	TArray<FString>& value = variables.FindOrAdd(owner);
	return value;
}

void ULocalStringArrayVariable::SetLocalStringArrayVariableValue(UObject* owner, ULocalStringArrayVariable* var, TArray<FString> _value)
{

	if (!var)	return;
	if (!owner) return;

	TArray<FString>& StringArrayVariableRef = var->GetLocalStringArrayVariableRef(owner);
	StringArrayVariableRef = _value;
	var->dirty = true;
}

void ULocalStringArrayVariable::CopyLocalStringArrayVariableValue(UObject* owner, ULocalStringArrayVariable* var, UObject* otherOwner, ULocalStringArrayVariable* other)
{
	if (!var)	return;
	if (!owner) return;
	if (!otherOwner) return;
	if (!other) return;
	
	TArray<FString>& StringArrayVariableRef = var->GetLocalStringArrayVariableRef(owner);
	TArray<FString>& otherStringArrayVariableRef = other->GetLocalStringArrayVariableRef(otherOwner);

	StringArrayVariableRef = otherStringArrayVariableRef;
	var->dirty = true;
}

void ULocalStringArrayVariable::Save()
{
    TArray<UObject*> Keys;
    variables.GetKeys(Keys);

    for (UObject* Key : Keys)
    {
        variables.FindAndRemoveChecked(Key);
    }
}

void ULocalStringArrayVariable::Load()
{
    TArray<UObject*> Keys;
    variables.GetKeys(Keys);

    for (UObject* Key : Keys)
    {
        variables.FindAndRemoveChecked(Key);
    }
}

FString ULocalStringArrayVariable::GetStringValue() const
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

FString ULocalStringArrayVariable::GetValueAsString(TArray<FString> value) const
{
    TArray<FString> StringValues;
    for(const auto& item : value)
    {
        StringValues.Add(item);
    }

    return UKismetStringLibrary::JoinStringArray(StringValues);
}

