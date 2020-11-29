// Copyright Out-of-the-Box Plugins 2018-2020. All Rights Reserved.

#include "LocalActorRefVariable.h"
#include "Kismet/GameplayStatics.h"

AActor* ULocalActorRefVariable::GetLocalActorRefVariableValue(UObject* owner, ULocalActorRefVariable* var)
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
		return var->GetLocalActorRefVariableRef(owner);
	}
}

AActor*& ULocalActorRefVariable::GetLocalActorRefVariableRef(UObject* owner)
{
	AActor*& value = variables.FindOrAdd(owner);
	return value;
}

void ULocalActorRefVariable::SetLocalActorRefVariableValue(UObject* owner, ULocalActorRefVariable* var, AActor* _value)
{

	if (!var)	return;
	if (!owner) return;

	AActor*& ActorRefVariableRef = var->GetLocalActorRefVariableRef(owner);
	ActorRefVariableRef = _value;
	var->Dirty = true;
}

void ULocalActorRefVariable::CopyLocalActorRefVariableValue(UObject* owner, ULocalActorRefVariable* var, UObject* otherOwner, ULocalActorRefVariable* other)
{
	if (!var)	return;
	if (!owner) return;
	if (!otherOwner) return;
	if (!other) return;
	
	AActor*& ActorRefVariableRef = var->GetLocalActorRefVariableRef(owner);
	AActor*& otherActorRefVariableRef = other->GetLocalActorRefVariableRef(otherOwner);

	ActorRefVariableRef = otherActorRefVariableRef;
	var->Dirty = true;
}

void ULocalActorRefVariable::Save()
{
    TArray<UObject*> Keys;
    variables.GetKeys(Keys);

    for (UObject* Key : Keys)
    {
        variables.FindAndRemoveChecked(Key);
    }
}

void ULocalActorRefVariable::Load()
{
    TArray<UObject*> Keys;
    variables.GetKeys(Keys);

    for (UObject* Key : Keys)
    {
        variables.FindAndRemoveChecked(Key);
    }
}

FString ULocalActorRefVariable::GetStringValue() const
{
    FString lines;

    for (auto& var : variables)
    {
        const auto& value = var.Value;
        const auto& owner = var.Key;

        FString valueString = GetValueAsString(value);
        FString ownerString = owner ? owner->GetName() : FString("Owner destroyed");
        FString line = FString::Printf(TEXT("%s - %s \n"), *ownerString, *valueString);

        lines.Append(line);
    }

    lines.TrimEndInline();

    if (lines.IsEmpty())
    {
        lines = FString("No values set yet.");
    }

    return lines;
}

FString ULocalActorRefVariable::GetValueAsString(AActor* value) const
{
    const auto& item = value;
    return item->GetName();
}

