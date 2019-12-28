// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#include "LocalFloatVariable.h"
#include "Kismet/GameplayStatics.h"

//void UFloatVariable::SetFloatVariableValue(float _value)
//{
//	SetFloatVariableValue(this, _value);
//}
//

//
//void UFloatVariable::CopyFloatVariableValue(UFloatVariable* other)
//{
//	CopyFloatVariableValue(this, other);
//}
//


float ULocalFloatVariable::GetLocalFloatVariable(UObject* owner, ULocalFloatVariable* var)
{
	if (owner == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Missing owner"));
		return 0.0f;
	}

	if (var == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Missing variable"));
		return 0.0f;
	}
	else
	{
		return var->GetLocalFloatVariableRef(owner);
	}
}

float& ULocalFloatVariable::GetLocalFloatVariableRef(UObject* owner)
{
	float& value = variables.FindOrAdd(owner);
	return value;
}

void ULocalFloatVariable::SetLocalFloatVariableValue(UObject* owner, ULocalFloatVariable* var, float _value)
{

	if (!var)	return;
	if (!owner) return;

	float& FloatVariableRef = var->GetLocalFloatVariableRef(owner);
	FloatVariableRef = _value;
	var->dirty = true;
}

void ULocalFloatVariable::CopyLocalFloatVariableValue(UObject* owner, ULocalFloatVariable* var, UObject* otherOwner, ULocalFloatVariable* other)
{
	if (!var)	return;
	if (!owner) return;
	if (!otherOwner) return;
	if (!other) return;
	
	float& FloatVariableRef = var->GetLocalFloatVariableRef(owner);
	float& otherFloatVariableRef = other->GetLocalFloatVariableRef(otherOwner);

	FloatVariableRef = otherFloatVariableRef;
	var->dirty = true;
}

