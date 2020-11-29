// Copyright Out-of-the-Box Plugins 2018-2020. All Rights Reserved.

#include "LocalObjectRefVariable.h"
#include "Kismet/GameplayStatics.h"

UObject* ULocalObjectRefVariable::GetLocalObjectRefVariableValue(UObject* owner, ULocalObjectRefVariable* var)
{
	if (owner == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Missing owner"));
		return nullptr;
	}

	if (var == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Missing variable"));
		return nullptr;
	}
	else
	{
		return var->GetLocalObjectRefVariableRef(owner);
	}
}

UObject*& ULocalObjectRefVariable::GetLocalObjectRefVariableRef(UObject* owner)
{
	UObject*& value = variables.FindOrAdd(owner);
	return value;
}

void ULocalObjectRefVariable::SetLocalObjectRefVariableValue(UObject* owner, ULocalObjectRefVariable* var, UObject* _value)
{

	if (!var)	return;
	if (!owner) return;

	UObject*& ObjectRefVariableRef = var->GetLocalObjectRefVariableRef(owner);
	ObjectRefVariableRef = _value;
	var->Dirty = true;
}

void ULocalObjectRefVariable::CopyLocalObjectRefVariableValue(UObject* owner, ULocalObjectRefVariable* var, UObject* otherOwner, ULocalObjectRefVariable* other)
{
	if (!var)	return;
	if (!owner) return;
	if (!otherOwner) return;
	if (!other) return;
	
	UObject*& ObjectRefVariableRef = var->GetLocalObjectRefVariableRef(owner);
	UObject*& otherObjectRefVariableRef = other->GetLocalObjectRefVariableRef(otherOwner);

	ObjectRefVariableRef = otherObjectRefVariableRef;
	var->Dirty = true;
}

void ULocalObjectRefVariable::Save()
{
    TArray<UObject*> Keys;
    variables.GetKeys(Keys);

    for (UObject* Key : Keys)
    {
        variables.FindAndRemoveChecked(Key);
    }
}

void ULocalObjectRefVariable::Load()
{
    TArray<UObject*> Keys;
    variables.GetKeys(Keys);

    for (UObject* Key : Keys)
    {
        variables.FindAndRemoveChecked(Key);
    }
}

FString ULocalObjectRefVariable::GetStringValue() const
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

FString ULocalObjectRefVariable::GetValueAsString(UObject* value) const
{
    const auto& item = value;
    return item->GetName();
}

