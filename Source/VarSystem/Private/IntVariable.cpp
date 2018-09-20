// Fill out your copyright notice in the Description page of Project Settings.

#include "IntVariable.h"




int32 UIntVariable::GetValue(UIntVariable* var)
{
	return var->value;
}

void UIntVariable::SetValue(UIntVariable* var, int32 _value)
{
	var->value = _value;
}

void UIntVariable::CopyValue(UIntVariable* var, UIntVariable* other)
{
	var->value = other->value;
}

