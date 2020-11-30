// Copyright Out-of-the-Box Plugins 2018-2020. All Rights Reserved.

// GENERATED FILE DO NOT MODIFY DIRECTLY

#include "InstancedFloatVariable.h"

#include "VSLog.h"

/* STATIC */ float UInstancedFloatVariable::GetInstancedFloatVariableValue(UObject* Owner, UInstancedFloatVariable* Variable)
{
	if (!Owner)
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Cannot get instance value without an owner. Returning default value."));
		return 0.0f;
	}

	if (!Variable)
	{
		UE_LOG(LogVariablesSystem, Warning, TEXT("Cannot get instance value without a variable. Returning default value."));
		return 0.0f;
	}
	else
	{
		return Variable->GetInstancedFloatVariableRef(Owner);
	}
}

/* STATIC */ void UInstancedFloatVariable::SetInstancedFloatVariableValue(UObject* Owner, UInstancedFloatVariable* Variable, float NewValue)
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
		float& FloatVariableRef = Variable->GetInstancedFloatVariableRef(Owner);
		
		if(FloatVariableRef != NewValue)
		{
			FloatVariableRef = NewValue;
			Variable->Dirty = true;
		}
	}
}

/* STATIC */ void UInstancedFloatVariable::CopyInstancedFloatVariableValue(UObject* Owner, UInstancedFloatVariable* Variable, UObject* OtherOwner, UInstancedFloatVariable* OtherVariable)
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
		float& FloatVariableRef = Variable->GetInstancedFloatVariableRef(Owner);
		float& otherFloatVariableRef = OtherVariable->GetInstancedFloatVariableRef(OtherOwner);

		if(FloatVariableRef != otherFloatVariableRef)
		{
			FloatVariableRef = otherFloatVariableRef;
			Variable->Dirty = true;
		}
	}
}

float& UInstancedFloatVariable::GetInstancedFloatVariableRef(UObject* Owner)
{
	return VariablesMap.FindOrAdd(Owner);;
}

FString UInstancedFloatVariable::GetStringValue() const
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

FString UInstancedFloatVariable::GetValueAsString(float Value) const
{
    const auto& Item = Value;
    return UKismetStringLibrary::Conv_FloatToString(Item);
}

