// Fill out your copyright notice in the Description page of Project Settings.

#include "FloatVariable.h"




float UFloatVariable::GetFloatValue(UFloatVariable* var)
{
	return var->value;
}

void UFloatVariable::SetFloatValue(UFloatVariable* var, float _value)
{
	var->value = _value;
}

void UFloatVariable::CopyFloatValue(UFloatVariable* var, UFloatVariable* other)
{
	var->value = other->value;
}

