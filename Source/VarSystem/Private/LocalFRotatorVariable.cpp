// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#include "LocalFRotatorVariable.h"
#include "Kismet/GameplayStatics.h"

//void UFRotatorVariable::SetFRotatorValue(FRotator _value)
//{
//	SetFRotatorValue(this, _value);
//}
//

//
//void UFRotatorVariable::CopyFRotatorValue(UFRotatorVariable* other)
//{
//	CopyFRotatorValue(this, other);
//}
//


FRotator ULocalFRotatorVariable::GetLocalFRotator(UObject* owner, ULocalFRotatorVariable* var)
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
		return var->GetLocalFRotatorRef(owner);
	}
}

FRotator& ULocalFRotatorVariable::GetLocalFRotatorRef(UObject* owner)
{
	FRotator& value = variables.FindOrAdd(owner);
	return value;
}

void ULocalFRotatorVariable::SetLocalFRotatorValue(UObject* owner, ULocalFRotatorVariable* var, FRotator _value)
{

	if (!var)	return;
	if (!owner) return;

	FRotator& FRotatorRef = var->GetLocalFRotatorRef(owner);
	FRotatorRef = _value;
	var->dirty = true;
}

void ULocalFRotatorVariable::CopyLocalFRotatorValue(UObject* owner, ULocalFRotatorVariable* var, UObject* otherOwner, ULocalFRotatorVariable* other)
{
	if (!var)	return;
	if (!owner) return;
	if (!otherOwner) return;
	if (!other) return;
	
	FRotator& FRotatorRef = var->GetLocalFRotatorRef(owner);
	FRotator& otherFRotatorRef = other->GetLocalFRotatorRef(otherOwner);

	FRotatorRef = otherFRotatorRef;
	var->dirty = true;
}
