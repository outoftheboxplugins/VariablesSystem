// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#include "LocalIntVariable.h"
#include "Kismet/GameplayStatics.h"

int32 ULocalIntVariable::GetLocalIntVariableValue(UObject* owner, ULocalIntVariable* var)
{
	if (owner == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Missing owner"));
		return 0;
	}

	if (var == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Missing variable"));
		return 0;
	}
	else
	{
		return var->GetLocalIntVariableRef(owner);
	}
}

int32& ULocalIntVariable::GetLocalIntVariableRef(UObject* owner)
{
	int32& value = variables.FindOrAdd(owner);
	return value;
}

void ULocalIntVariable::SetLocalIntVariableValue(UObject* owner, ULocalIntVariable* var, int32 _value)
{

	if (!var)	return;
	if (!owner) return;

	int32& IntVariableRef = var->GetLocalIntVariableRef(owner);
	IntVariableRef = _value;
	var->dirty = true;
}

void ULocalIntVariable::CopyLocalIntVariableValue(UObject* owner, ULocalIntVariable* var, UObject* otherOwner, ULocalIntVariable* other)
{
	if (!var)	return;
	if (!owner) return;
	if (!otherOwner) return;
	if (!other) return;
	
	int32& IntVariableRef = var->GetLocalIntVariableRef(owner);
	int32& otherIntVariableRef = other->GetLocalIntVariableRef(otherOwner);

	IntVariableRef = otherIntVariableRef;
	var->dirty = true;
}

