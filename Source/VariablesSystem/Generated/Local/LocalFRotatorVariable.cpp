// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#include "LocalFRotatorVariable.h"
#include "Kismet/GameplayStatics.h"

FRotator ULocalFRotatorVariable::GetLocalFRotatorVariableValue(UObject* owner, ULocalFRotatorVariable* var)
{
	if (owner == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Missing owner"));
		return FRotator::ZeroRotator;
	}

	if (var == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Missing variable"));
		return FRotator::ZeroRotator;
	}
	else
	{
		return var->GetLocalFRotatorVariableRef(owner);
	}
}

FRotator& ULocalFRotatorVariable::GetLocalFRotatorVariableRef(UObject* owner)
{
	FRotator& value = variables.FindOrAdd(owner);
	return value;
}

void ULocalFRotatorVariable::SetLocalFRotatorVariableValue(UObject* owner, ULocalFRotatorVariable* var, FRotator _value)
{

	if (!var)	return;
	if (!owner) return;

	FRotator& FRotatorVariableRef = var->GetLocalFRotatorVariableRef(owner);
	FRotatorVariableRef = _value;
	var->dirty = true;
}

void ULocalFRotatorVariable::CopyLocalFRotatorVariableValue(UObject* owner, ULocalFRotatorVariable* var, UObject* otherOwner, ULocalFRotatorVariable* other)
{
	if (!var)	return;
	if (!owner) return;
	if (!otherOwner) return;
	if (!other) return;
	
	FRotator& FRotatorVariableRef = var->GetLocalFRotatorVariableRef(owner);
	FRotator& otherFRotatorVariableRef = other->GetLocalFRotatorVariableRef(otherOwner);

	FRotatorVariableRef = otherFRotatorVariableRef;
	var->dirty = true;
}

void ULocalFRotatorVariable::Save()
{
    variables
}

void ULocalFRotatorVariable::Load()
{
    variables.
}

FString ULocalFRotatorVariable::GetStringValue() const
{
    FString lines;

    for (auto& var : variables)
    {
        const auto& value = var.Value;
        const auto& owner = var.Key;

        FString valueString = UKismetStringLibrary::Conv_RotatorToString(value);
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

