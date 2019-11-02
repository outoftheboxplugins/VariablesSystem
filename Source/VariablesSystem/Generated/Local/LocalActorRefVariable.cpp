// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#include "LocalActorRefVariable.h"
#include "Kismet/GameplayStatics.h"

//void UActorRefVariable::SetActorRefValue(AActor* _value)
//{
//	SetActorRefValue(this, _value);
//}
//

//
//void UActorRefVariable::CopyActorRefValue(UActorRefVariable* other)
//{
//	CopyActorRefValue(this, other);
//}
//


AActor* ULocalActorRefVariable::GetLocalActorRef(UObject* owner, ULocalActorRefVariable* var)
{
	if (owner == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Missing owner"));
		return nullptr;
	}

	if (var == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Missing variable"));
		return nullptr;
	}
	else
	{
		return var->GetLocalActorRefRef(owner);
	}
}

AActor*& ULocalActorRefVariable::GetLocalActorRefRef(UObject* owner)
{
	AActor*& value = variables.FindOrAdd(owner);
	return value;
}

void ULocalActorRefVariable::SetLocalActorRefValue(UObject* owner, ULocalActorRefVariable* var, AActor* _value)
{

	if (!var)	return;
	if (!owner) return;

	AActor*& ActorRefRef = var->GetLocalActorRefRef(owner);
	ActorRefRef = _value;
	var->dirty = true;
}

void ULocalActorRefVariable::CopyLocalActorRefValue(UObject* owner, ULocalActorRefVariable* var, UObject* otherOwner, ULocalActorRefVariable* other)
{
	if (!var)	return;
	if (!owner) return;
	if (!otherOwner) return;
	if (!other) return;
	
	AActor*& ActorRefRef = var->GetLocalActorRefRef(owner);
	AActor*& otherActorRefRef = other->GetLocalActorRefRef(otherOwner);

	ActorRefRef = otherActorRefRef;
	var->dirty = true;
}

