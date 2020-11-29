// Copyright Out-of-the-Box Plugins 2018-2020. All Rights Reserved.

#include "LocalStringVariable.h"
#include "Kismet/GameplayStatics.h"

FString ULocalStringVariable::GetLocalStringVariableValue(UObject* owner, ULocalStringVariable* var)
{
	if (owner == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Missing owner"));
		return "";
	}

	if (var == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Missing variable"));
		return "";
	}
	else
	{
		return var->GetLocalStringVariableRef(owner);
	}
}

FString& ULocalStringVariable::GetLocalStringVariableRef(UObject* owner)
{
	FString& value = variables.FindOrAdd(owner);
	return value;
}

void ULocalStringVariable::SetLocalStringVariableValue(UObject* owner, ULocalStringVariable* var, FString _value)
{

	if (!var)	return;
	if (!owner) return;

	FString& StringVariableRef = var->GetLocalStringVariableRef(owner);
	StringVariableRef = _value;
	var->Dirty = true;
}

void ULocalStringVariable::CopyLocalStringVariableValue(UObject* owner, ULocalStringVariable* var, UObject* otherOwner, ULocalStringVariable* other)
{
	if (!var)	return;
	if (!owner) return;
	if (!otherOwner) return;
	if (!other) return;
	
	FString& StringVariableRef = var->GetLocalStringVariableRef(owner);
	FString& otherStringVariableRef = other->GetLocalStringVariableRef(otherOwner);

	StringVariableRef = otherStringVariableRef;
	var->Dirty = true;
}

void ULocalStringVariable::Save()
{
    TArray<UObject*> Keys;
    variables.GetKeys(Keys);

    for (UObject* Key : Keys)
    {
        variables.FindAndRemoveChecked(Key);
    }
}

void ULocalStringVariable::Load()
{
    TArray<UObject*> Keys;
    variables.GetKeys(Keys);

    for (UObject* Key : Keys)
    {
        variables.FindAndRemoveChecked(Key);
    }
}

FString ULocalStringVariable::GetStringValue() const
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

FString ULocalStringVariable::GetValueAsString(FString value) const
{
    const auto& item = value;
    return item;
}

