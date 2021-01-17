// Copyright Out-of-the-Box Plugins 2018-2021. All Rights Reserved.

// GENERATED FILE DO NOT MODIFY DIRECTLY

#include "InstancedFVector2DVariable.h"

#include "VSLog.h"

/* STATIC */ FVector2D UInstancedFVector2DVariable::GetInstancedFVector2DVariableValue(UObject* Owner, UInstancedFVector2DVariable* Variable)
{
	if (!Owner)
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Cannot get instance value without an owner. Returning default value."));
		return FVector2D::ZeroVector;
	}

	if (!Variable)
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Cannot get instance value without a variable. Returning default value."));
		return FVector2D::ZeroVector;
	}
	else
	{
		return Variable->GetInstancedFVector2DVariableRef(Owner);
	}
}

/* STATIC */ void UInstancedFVector2DVariable::SetInstancedFVector2DVariableValue(UObject* Owner, UInstancedFVector2DVariable* Variable, FVector2D NewValue)
{
	if (!Owner)
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Cannot set instance value without an owner."));
	}
	else if (!Variable)
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Cannot set instance value without a variable."));
	}
	else
	{
		FVector2D& FVector2DVariableRef = Variable->GetInstancedFVector2DVariableRef(Owner);
		
		if(FVector2DVariableRef != NewValue)
		{
			FVector2DVariableRef = NewValue;
			Variable->Dirty = true;
		}
	}
}

/* STATIC */ void UInstancedFVector2DVariable::CopyInstancedFVector2DVariableValue(UObject* Owner, UInstancedFVector2DVariable* Variable, UObject* OtherOwner, UInstancedFVector2DVariable* OtherVariable)
{
	if (!Owner || !OtherOwner)
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Cannot copy instance value without an owner."));
	}
	else if (!Variable || !OtherVariable)
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Cannot copy instance value without a variable."));
	}
	else
	{
		FVector2D& FVector2DVariableRef = Variable->GetInstancedFVector2DVariableRef(Owner);
		FVector2D& otherFVector2DVariableRef = OtherVariable->GetInstancedFVector2DVariableRef(OtherOwner);

		if(FVector2DVariableRef != otherFVector2DVariableRef)
		{
			FVector2DVariableRef = otherFVector2DVariableRef;
			Variable->Dirty = true;
		}
	}
}

FVector2D& UInstancedFVector2DVariable::GetInstancedFVector2DVariableRef(UObject* Owner)
{
	return VariablesMap.FindOrAdd(Owner);;
}

FString UInstancedFVector2DVariable::GetStringValue() const
{
    FString Lines;

    for (auto& Variable : VariablesMap)
    {
        const auto& Value = Variable.Value;
        const auto& Owner = Variable.Key;

		FString ValueString = GetValueAsString(Value);
		FString OwnerString = Owner.IsValid() ? Owner.Get()->GetName() : FString("Invalid Owner");
		FString Line = FString::Printf(TEXT("%s - %s \n"), *OwnerString, *ValueString);

		Lines.Append(Line);
    }

    Lines.TrimEndInline();

    if (Lines.IsEmpty())
    {
        Lines = FString("No values set yet.");
    }

    return Lines;
}

FString UInstancedFVector2DVariable::GetValueAsString(FVector2D Value) const
{
    const auto& Item = Value;
    return UKismetStringLibrary::Conv_Vector2dToString(Item);
}

