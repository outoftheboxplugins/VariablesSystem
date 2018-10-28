// Copyright Alexandru pasotee Oprea 2018. All Rights Reserved.

#include "FVectorVariable.h"




FVector UFVectorVariable::GetFVectorValue(UFVectorVariable* var)
{
	return var->value;
}

void UFVectorVariable::SetFVectorValue(UFVectorVariable* var, FVector _value)
{
	var->value = _value;
}

void UFVectorVariable::CopyFVectorValue(UFVectorVariable* var, UFVectorVariable* other)
{
	var->value = other->value;
}

