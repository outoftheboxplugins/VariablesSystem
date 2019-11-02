// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#include "LocalStringVariable.h"
#include "Kismet/GameplayStatics.h"

//void UStringVariable::SetStringValue(FString _value)
//{
//	SetStringValue(this, _value);
//}
//

//
//void UStringVariable::CopyStringValue(UStringVariable* other)
//{
//	CopyStringValue(this, other);
//}
//


FString ULocalStringVariable::GetLocalString(UObject* owner, ULocalStringVariable* var)
{
	if (owner == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Missing owner"));
		return "";
	}

	if (var == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Missing variable"));
		return "";
	}
	else
	{
		return var->GetLocalStringRef(owner);
	}
}

FString& ULocalStringVariable::GetLocalStringRef(UObject* owner)
{
	FString& value = variables.FindOrAdd(owner);
	return value;
}

void ULocalStringVariable::SetLocalStringValue(UObject* owner, ULocalStringVariable* var, FString _value)
{

	if (!var)	return;
	if (!owner) return;

	FString& StringRef = var->GetLocalStringRef(owner);
	StringRef = _value;
	var->dirty = true;
}

void ULocalStringVariable::CopyLocalStringValue(UObject* owner, ULocalStringVariable* var, UObject* otherOwner, ULocalStringVariable* other)
{
	if (!var)	return;
	if (!owner) return;
	if (!otherOwner) return;
	if (!other) return;
	
	FString& StringRef = var->GetLocalStringRef(owner);
	FString& otherStringRef = other->GetLocalStringRef(otherOwner);

	StringRef = otherStringRef;
	var->dirty = true;
}

