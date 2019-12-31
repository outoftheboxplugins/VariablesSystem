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

