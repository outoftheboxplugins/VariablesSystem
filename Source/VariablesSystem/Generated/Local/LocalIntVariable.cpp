// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#include "LocalIntVariable.h"
#include "Kismet/GameplayStatics.h"

//void UIntVariable::SetIntValue(int32 _value)
//{
//	SetIntValue(this, _value);
//}
//

//
//void UIntVariable::CopyIntValue(UIntVariable* other)
//{
//	CopyIntValue(this, other);
//}
//


int32 ULocalIntVariable::GetLocalInt(UObject* owner, ULocalIntVariable* var)
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
		return var->GetLocalIntRef(owner);
	}
}

int32& ULocalIntVariable::GetLocalIntRef(UObject* owner)
{
	int32& value = variables.FindOrAdd(owner);
	return value;
}

void ULocalIntVariable::SetLocalIntValue(UObject* owner, ULocalIntVariable* var, int32 _value)
{

	if (!var)	return;
	if (!owner) return;

	int32& IntRef = var->GetLocalIntRef(owner);
	IntRef = _value;
	var->dirty = true;
}

void ULocalIntVariable::CopyLocalIntValue(UObject* owner, ULocalIntVariable* var, UObject* otherOwner, ULocalIntVariable* other)
{
	if (!var)	return;
	if (!owner) return;
	if (!otherOwner) return;
	if (!other) return;
	
	int32& IntRef = var->GetLocalIntRef(owner);
	int32& otherIntRef = other->GetLocalIntRef(otherOwner);

	IntRef = otherIntRef;
	var->dirty = true;
}

