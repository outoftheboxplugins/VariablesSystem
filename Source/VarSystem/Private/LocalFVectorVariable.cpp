// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#include "LocalFVectorVariable.h"
#include "Kismet/GameplayStatics.h"

//void UFVectorVariable::SetFVectorValue(FVector _value)
//{
//	SetFVectorValue(this, _value);
//}
//

//
//void UFVectorVariable::CopyFVectorValue(UFVectorVariable* other)
//{
//	CopyFVectorValue(this, other);
//}
//


FVector ULocalFVectorVariable::GetLocalFVector(UObject* owner, ULocalFVectorVariable* var)
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
		return var->GetLocalFVectorRef(owner);
	}
}

FVector& ULocalFVectorVariable::GetLocalFVectorRef(UObject* owner)
{
	FVector& value = variables.FindOrAdd(owner);
	return value;
}

void ULocalFVectorVariable::SetLocalFVectorValue(UObject* owner, ULocalFVectorVariable* var, FVector _value)
{

	if (!var)	return;
	if (!owner) return;

	FVector& FVectorRef = var->GetLocalFVectorRef(owner);
	FVectorRef = _value;
	var->dirty = true;
}

void ULocalFVectorVariable::CopyLocalFVectorValue(UObject* owner, ULocalFVectorVariable* var, UObject* otherOwner, ULocalFVectorVariable* other)
{
	if (!var)	return;
	if (!owner) return;
	if (!otherOwner) return;
	if (!other) return;
	
	FVector& FVectorRef = var->GetLocalFVectorRef(owner);
	FVector& otherFVectorRef = other->GetLocalFVectorRef(otherOwner);

	FVectorRef = otherFVectorRef;
	var->dirty = true;
}
