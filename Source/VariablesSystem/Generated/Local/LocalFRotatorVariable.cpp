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

