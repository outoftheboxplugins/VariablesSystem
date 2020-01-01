// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#include "LocalFVector2DVariable.h"
#include "Kismet/GameplayStatics.h"

FVector2D ULocalFVector2DVariable::GetLocalFVector2DVariableValue(UObject* owner, ULocalFVector2DVariable* var)
{
	if (owner == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Missing owner"));
		return FVector2D::ZeroVector;
	}

	if (var == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Missing variable"));
		return FVector2D::ZeroVector;
	}
	else
	{
		return var->GetLocalFVector2DVariableRef(owner);
	}
}

FVector2D& ULocalFVector2DVariable::GetLocalFVector2DVariableRef(UObject* owner)
{
	FVector2D& value = variables.FindOrAdd(owner);
	return value;
}

void ULocalFVector2DVariable::SetLocalFVector2DVariableValue(UObject* owner, ULocalFVector2DVariable* var, FVector2D _value)
{

	if (!var)	return;
	if (!owner) return;

	FVector2D& FVector2DVariableRef = var->GetLocalFVector2DVariableRef(owner);
	FVector2DVariableRef = _value;
	var->dirty = true;
}

void ULocalFVector2DVariable::CopyLocalFVector2DVariableValue(UObject* owner, ULocalFVector2DVariable* var, UObject* otherOwner, ULocalFVector2DVariable* other)
{
	if (!var)	return;
	if (!owner) return;
	if (!otherOwner) return;
	if (!other) return;
	
	FVector2D& FVector2DVariableRef = var->GetLocalFVector2DVariableRef(owner);
	FVector2D& otherFVector2DVariableRef = other->GetLocalFVector2DVariableRef(otherOwner);

	FVector2DVariableRef = otherFVector2DVariableRef;
	var->dirty = true;
}

void ULocalFVector2DVariable::Save()
{
    TArray<UObject*> Keys;
    variables.GetKeys(Keys);

    for (UObject* Key : Keys)
    {
        variables.FindAndRemoveChecked(Key);
    }
}

void ULocalFVector2DVariable::Load()
{
    TArray<UObject*> Keys;
    variables.GetKeys(Keys);

    for (UObject* Key : Keys)
    {
        variables.FindAndRemoveChecked(Key);
    }
}

FString ULocalFVector2DVariable::GetStringValue() const
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

FString ULocalFVector2DVariable::GetValueAsString(FVector2D value) const
{
    const auto& item = value;
    return UKismetStringLibrary::Conv_Vector2dToString(item);
}

