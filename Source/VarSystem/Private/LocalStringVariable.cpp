// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#include "LocalStringVariable.h"
#include "Kismet/GameplayStatics.h"

//void UFStringVariable::SetFStringValue(FString _value)
//{
//	SetFStringValue(this, _value);
//}
//

//
//void UFStringVariable::CopyFStringValue(UFStringVariable* other)
//{
//	CopyFStringValue(this, other);
//}
//


FString ULocalFStringVariable::GetLocalFString(UObject* owner, ULocalFStringVariable* var)
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
		return var->GetLocalFStringRef(owner);
	}
}

FString& ULocalFStringVariable::GetLocalFStringRef(UObject* owner)
{
	FString& value = variables.FindOrAdd(owner);
	return value;
}

void ULocalFStringVariable::SetLocalFStringValue(UObject* owner, ULocalFStringVariable* var, FString _value)
{

	if (!var)	return;
	if (!owner) return;

	FString& FStringRef = var->GetLocalFStringRef(owner);
	FStringRef = _value;
	var->dirty = true;
}

void ULocalFStringVariable::CopyLocalFStringValue(UObject* owner, ULocalFStringVariable* var, UObject* otherOwner, ULocalFStringVariable* other)
{
	if (!var)	return;
	if (!owner) return;
	if (!otherOwner) return;
	if (!other) return;
	
	FString& FStringRef = var->GetLocalFStringRef(owner);
	FString& otherFStringRef = other->GetLocalFStringRef(otherOwner);

	FStringRef = otherFStringRef;
	var->dirty = true;
}
