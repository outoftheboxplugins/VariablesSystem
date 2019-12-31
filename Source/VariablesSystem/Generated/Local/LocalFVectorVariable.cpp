// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#include "LocalFVectorVariable.h"
#include "Kismet/GameplayStatics.h"

FVector ULocalFVectorVariable::GetLocalFVectorVariableValue(UObject* owner, ULocalFVectorVariable* var)
{
	if (owner == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Missing owner"));
		return FVector::ZeroVector;
	}

	if (var == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Missing variable"));
		return FVector::ZeroVector;
	}
	else
	{
		return var->GetLocalFVectorVariableRef(owner);
	}
}

FVector& ULocalFVectorVariable::GetLocalFVectorVariableRef(UObject* owner)
{
	FVector& value = variables.FindOrAdd(owner);
	return value;
}

void ULocalFVectorVariable::SetLocalFVectorVariableValue(UObject* owner, ULocalFVectorVariable* var, FVector _value)
{

	if (!var)	return;
	if (!owner) return;

	FVector& FVectorVariableRef = var->GetLocalFVectorVariableRef(owner);
	FVectorVariableRef = _value;
	var->dirty = true;
}

void ULocalFVectorVariable::CopyLocalFVectorVariableValue(UObject* owner, ULocalFVectorVariable* var, UObject* otherOwner, ULocalFVectorVariable* other)
{
	if (!var)	return;
	if (!owner) return;
	if (!otherOwner) return;
	if (!other) return;
	
	FVector& FVectorVariableRef = var->GetLocalFVectorVariableRef(owner);
	FVector& otherFVectorVariableRef = other->GetLocalFVectorVariableRef(otherOwner);

	FVectorVariableRef = otherFVectorVariableRef;
	var->dirty = true;
}

void ULocalFVectorVariable::Save()
{
    //TODO cleanup
}

void ULocalFVectorVariable::Load()
{
    //TODO cleanup
}

FString ULocalFVectorVariable::GetStringValue() const
{
    FString lines;

    for (auto& var : variables)
    {
        const auto& value = var.Value;
        const auto& owner = var.Key;

        FString valueString = UKismetStringLibrary::Conv_VectorToString(value);
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

