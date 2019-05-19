// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#include "LocalBoolVariable.h"
#include "Kismet/GameplayStatics.h"

//void UBoolVariable::SetBoolValue(bool _value)
//{
//	SetBoolValue(this, _value);
//}
//

//
//void UBoolVariable::CopyBoolValue(UBoolVariable* other)
//{
//	CopyBoolValue(this, other);
//}
//


bool ULocalBoolVariable::GetLocalBool(UObject* owner, ULocalBoolVariable* var)
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
		return var->GetLocalBoolRef(owner);
	}
}

bool& ULocalBoolVariable::GetLocalBoolRef(UObject* owner)
{
	bool& value = variables.FindOrAdd(owner);
	return value;
}

void ULocalBoolVariable::SetLocalBoolValue(UObject* owner, ULocalBoolVariable* var, bool _value)
{

	if (!var)	return;
	if (!owner) return;

	bool& boolRef = var->GetLocalBoolRef(owner);
	boolRef = _value;
	var->dirty = true;
}

void ULocalBoolVariable::CopyLocalBoolValue(UObject* owner, ULocalBoolVariable* var, UObject* otherOwner, ULocalBoolVariable* other)
{
	if (!var)	return;
	if (!owner) return;
	if (!otherOwner) return;
	if (!other) return;
	
	bool& boolRef = var->GetLocalBoolRef(owner);
	bool& otherBoolRef = other->GetLocalBoolRef(otherOwner);

	boolRef = otherBoolRef;
	var->dirty = true;
}
