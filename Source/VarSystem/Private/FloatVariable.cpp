// Fill out your copyright notice in the Description page of Project Settings.

#include "FloatVariable.h"




float UFloatVariable::GetValue(UFloatVariable* var)
{
	return var->value;
}

void UFloatVariable::SetValue(UFloatVariable* var, float _value)
{
	var->value = _value;
}

void UFloatVariable::CopyValue(UFloatVariable* var, UFloatVariable* other)
{
	var->value = other->value;
}

