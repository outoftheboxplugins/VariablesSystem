// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#include "LocalGameplayTagContainer.h"
#include "Kismet/GameplayStatics.h"

FGameplayTagContainer ULocalGameplayTagContainer::GetLocalGameplayTagContainerValue(UObject* owner, ULocalGameplayTagContainer* var)
{
	if (owner == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Missing owner"));
		return FGameplayTagContainer();
	}

	if (var == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Missing variable"));
		return FGameplayTagContainer();
	}
	else
	{
		return var->GetLocalGameplayTagContainerRef(owner);
	}
}

FGameplayTagContainer& ULocalGameplayTagContainer::GetLocalGameplayTagContainerRef(UObject* owner)
{
	FGameplayTagContainer& value = variables.FindOrAdd(owner);
	return value;
}

void ULocalGameplayTagContainer::SetLocalGameplayTagContainerValue(UObject* owner, ULocalGameplayTagContainer* var, FGameplayTagContainer _value)
{

	if (!var)	return;
	if (!owner) return;

	FGameplayTagContainer& GameplayTagContainerRef = var->GetLocalGameplayTagContainerRef(owner);
	GameplayTagContainerRef = _value;
	var->dirty = true;
}

void ULocalGameplayTagContainer::CopyLocalGameplayTagContainerValue(UObject* owner, ULocalGameplayTagContainer* var, UObject* otherOwner, ULocalGameplayTagContainer* other)
{
	if (!var)	return;
	if (!owner) return;
	if (!otherOwner) return;
	if (!other) return;
	
	FGameplayTagContainer& GameplayTagContainerRef = var->GetLocalGameplayTagContainerRef(owner);
	FGameplayTagContainer& otherGameplayTagContainerRef = other->GetLocalGameplayTagContainerRef(otherOwner);

	GameplayTagContainerRef = otherGameplayTagContainerRef;
	var->dirty = true;
}

void ULocalGameplayTagContainer::Save()
{
    TArray<UObject*> Keys;
    variables.GetKeys(Keys);

    for (UObject* Key : Keys)
    {
        variables.FindAndRemoveChecked(Key);
    }
}

void ULocalGameplayTagContainer::Load()
{
    TArray<UObject*> Keys;
    variables.GetKeys(Keys);

    for (UObject* Key : Keys)
    {
        variables.FindAndRemoveChecked(Key);
    }
}

FString ULocalGameplayTagContainer::GetStringValue() const
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

FString ULocalGameplayTagContainer::GetValueAsString(FGameplayTagContainer value) const
{
    const auto& item = value;
    return item.ToString();
}

