// Copyright Alexandru pasotee Oprea 2018. All Rights Reserved.

#include "IntVariable.h"




int32 UIntVariable::GetIntValue(UIntVariable* var)
{
	return var->value;
}

void UIntVariable::SetIntValue(UIntVariable* var, int32 _value)
{
	var->value = _value;
}

void UIntVariable::CopyIntValue(UIntVariable* var, UIntVariable* other)
{
	var->value = other->value;
}

