// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#include "LocalFVector2DVariable.h"
#include "Kismet/GameplayStatics.h"

//void UFVector2DVariable::SetFVector2DValue(FVector2D _value)
//{
//	SetFVector2DValue(this, _value);
//}
//

//
//void UFVector2DVariable::CopyFVector2DValue(UFVector2DVariable* other)
//{
//	CopyFVector2DValue(this, other);
//}
//


FVector2D ULocalFVector2DVariable::GetLocalFVector2D(UObject* owner, ULocalFVector2DVariable* var)
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
		return var->GetLocalFVector2DRef(owner);
	}
}

FVector2D& ULocalFVector2DVariable::GetLocalFVector2DRef(UObject* owner)
{
	FVector2D& value = variables.FindOrAdd(owner);
	return value;
}

void ULocalFVector2DVariable::SetLocalFVector2DValue(UObject* owner, ULocalFVector2DVariable* var, FVector2D _value)
{

	if (!var)	return;
	if (!owner) return;

	FVector2D& FVector2DRef = var->GetLocalFVector2DRef(owner);
	FVector2DRef = _value;
	var->dirty = true;
}

void ULocalFVector2DVariable::CopyLocalFVector2DValue(UObject* owner, ULocalFVector2DVariable* var, UObject* otherOwner, ULocalFVector2DVariable* other)
{
	if (!var)	return;
	if (!owner) return;
	if (!otherOwner) return;
	if (!other) return;
	
	FVector2D& FVector2DRef = var->GetLocalFVector2DRef(owner);
	FVector2D& otherFVector2DRef = other->GetLocalFVector2DRef(otherOwner);

	FVector2DRef = otherFVector2DRef;
	var->dirty = true;
}

