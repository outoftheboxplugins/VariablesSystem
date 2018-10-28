// Copyright Alexandru pasotee Oprea 2018. All Rights Reserved.

#include "FRotatorVariable.h"




FRotator UFRotatorVariable::GetFRotatorValue(UFRotatorVariable* var)
{
	return var->value;
}

void UFRotatorVariable::SetFRotatorValue(UFRotatorVariable* var, FRotator _value)
{
	var->value = _value;
}

void UFRotatorVariable::CopyFRotatorValue(UFRotatorVariable* var, UFRotatorVariable* other)
{
	var->value = other->value;
}

