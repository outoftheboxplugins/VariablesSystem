// Copyright Out-of-the-Box Plugins 2018-2020. All Rights Reserved.

// GENERATED FILE DO NOT MODIFY DIRECTLY

#include "InstancedFVectorVariable.h"

#include "VSLog.h"

/* STATIC */ FVector UInstancedFVectorVariable::GetInstancedFVectorVariableValue(UObject* Owner, UInstancedFVectorVariable* Variable)
{
	if (!Owner)
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Cannot get instance value without an owner. Returning default value."));
		return FVector::ZeroVector;
	}

	if (!Variable)
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Cannot get instance value without a variable. Returning default value."));
		return FVector::ZeroVector;
	}
	else
	{
		return Variable->GetInstancedFVectorVariableRef(Owner);
	}
}

/* STATIC */ void UInstancedFVectorVariable::SetInstancedFVectorVariableValue(UObject* Owner, UInstancedFVectorVariable* Variable, FVector NewValue)
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
		FVector& FVectorVariableRef = Variable->GetInstancedFVectorVariableRef(Owner);
		
		if(FVectorVariableRef != NewValue)
		{
			FVectorVariableRef = NewValue;
			Variable->Dirty = true;
		}
	}
}

/* STATIC */ void UInstancedFVectorVariable::CopyInstancedFVectorVariableValue(UObject* Owner, UInstancedFVectorVariable* Variable, UObject* OtherOwner, UInstancedFVectorVariable* OtherVariable)
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
		FVector& FVectorVariableRef = Variable->GetInstancedFVectorVariableRef(Owner);
		FVector& otherFVectorVariableRef = OtherVariable->GetInstancedFVectorVariableRef(OtherOwner);

		if(FVectorVariableRef != otherFVectorVariableRef)
		{
			FVectorVariableRef = otherFVectorVariableRef;
			Variable->Dirty = true;
		}
	}
}

FVector& UInstancedFVectorVariable::GetInstancedFVectorVariableRef(UObject* Owner)
{
	return VariablesMap.FindOrAdd(Owner);;
}

FString UInstancedFVectorVariable::GetStringValue() const
{
    FString Lines;

    for (auto& Variable : VariablesMap)
    {
        const auto& Value = Variable.Value;
        const auto& Owner = Variable.Key;

        FString ValueString = GetValueAsString(Value);
        FString OwnerString = Owner ? Owner->GetName() : FString("Invalid Owner");
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

FString UInstancedFVectorVariable::GetValueAsString(FVector Value) const
{
    const auto& Item = Value;
    return UKismetStringLibrary::Conv_VectorToString(Item);
}

