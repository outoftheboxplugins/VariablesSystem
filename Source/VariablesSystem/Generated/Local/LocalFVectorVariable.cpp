// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#include "LocalFVectorVariable.h"
#include "Kismet/GameplayStatics.h"

//void UFVectorVariable::SetFVectorVariableValue(FVector _value)
//{
//	SetFVectorVariableValue(this, _value);
//}
//

//
//void UFVectorVariable::CopyFVectorVariableValue(UFVectorVariable* other)
//{
//	CopyFVectorVariableValue(this, other);
//}
//


FVector ULocalFVectorVariable::GetLocalFVectorVariable(UObject* owner, ULocalFVectorVariable* var)
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

