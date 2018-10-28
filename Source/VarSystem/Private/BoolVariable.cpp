// Copyright Alexandru pasotee Oprea 2018. All Rights Reserved.

#include "BoolVariable.h"




bool UBoolVariable::GetBoolValue(UBoolVariable* var)
{
	return var->value;
}

void UBoolVariable::SetBoolValue(UBoolVariable* var, bool _value)
{
	var->value = _value;
}

void UBoolVariable::CopyBoolValue(UBoolVariable* var, UBoolVariable* other)
{
	var->value = other->value;
}

