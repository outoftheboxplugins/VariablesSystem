// Fill out your copyright notice in the Description page of Project Settings.

#include "StringVariable.h"




FString UStringVariable::GetStringValue(UStringVariable* var)
{
	return var->value;
}

void UStringVariable::SetStringValue(UStringVariable* var, FString _value)
{
	var->value = _value;
}

void UStringVariable::CopyStringValue(UStringVariable* var, UStringVariable* other)
{
	var->value = other->value;
}

