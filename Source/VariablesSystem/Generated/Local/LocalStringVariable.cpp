// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#include "LocalStringVariable.h"
#include "Kismet/GameplayStatics.h"

//void UStringVariable::SetStringVariableValue(FString _value)
//{
//	SetStringVariableValue(this, _value);
//}
//

//
//void UStringVariable::CopyStringVariableValue(UStringVariable* other)
//{
//	CopyStringVariableValue(this, other);
//}
//


FString ULocalStringVariable::GetLocalStringVariable(UObject* owner, ULocalStringVariable* var)
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
		return var->GetLocalStringVariableRef(owner);
	}
}

FString& ULocalStringVariable::GetLocalStringVariableRef(UObject* owner)
{
	FString& value = variables.FindOrAdd(owner);
	return value;
}

void ULocalStringVariable::SetLocalStringVariableValue(UObject* owner, ULocalStringVariable* var, FString _value)
{

	if (!var)	return;
	if (!owner) return;

	FString& StringVariableRef = var->GetLocalStringVariableRef(owner);
	StringVariableRef = _value;
	var->dirty = true;
}

void ULocalStringVariable::CopyLocalStringVariableValue(UObject* owner, ULocalStringVariable* var, UObject* otherOwner, ULocalStringVariable* other)
{
	if (!var)	return;
	if (!owner) return;
	if (!otherOwner) return;
	if (!other) return;
	
	FString& StringVariableRef = var->GetLocalStringVariableRef(owner);
	FString& otherStringVariableRef = other->GetLocalStringVariableRef(otherOwner);

	StringVariableRef = otherStringVariableRef;
	var->dirty = true;
}

