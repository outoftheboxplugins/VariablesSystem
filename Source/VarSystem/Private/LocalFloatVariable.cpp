// Copyright Alexandru pasotee Oprea 2018. All Rights Reserved.

#include "LocalFloatVariable.h"
#include "Kismet/GameplayStatics.h"

//void UFloatVariable::SetFloatValue(float _value)
//{
//	SetFloatValue(this, _value);
//}
//

//
//void UFloatVariable::CopyFloatValue(UFloatVariable* other)
//{
//	CopyFloatValue(this, other);
//}
//


float ULocalFloatVariable::GetLocalFloat(UObject* owner, ULocalFloatVariable* var)
{
	if (owner == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Missing owner"));
		return false;
	}

	if (var == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Missing variable"));
		return false;
	}
	else
	{
		return var->GetLocalFloatRef(owner);
	}
}

float& ULocalFloatVariable::GetLocalFloatRef(UObject* owner)
{
	float& value = variables.FindOrAdd(owner);
	return value;
}

void ULocalFloatVariable::SetLocalFloatValue(UObject* owner, ULocalFloatVariable* var, float _value)
{

	if (!var)	return;
	if (!owner) return;

	float& floatRef = var->GetLocalFloatRef(owner);
	floatRef = _value;
	var->dirty = true;
}

void ULocalFloatVariable::CopyLocalFloatValue(UObject* owner, ULocalFloatVariable* var, UObject* otherOwner, ULocalFloatVariable* other)
{
	if (!var)	return;
	if (!owner) return;
	if (!otherOwner) return;
	if (!other) return;
	
	float& floatRef = var->GetLocalFloatRef(owner);
	float& otherFloatRef = other->GetLocalFloatRef(otherOwner);

	floatRef = otherFloatRef;
	var->dirty = true;
}
