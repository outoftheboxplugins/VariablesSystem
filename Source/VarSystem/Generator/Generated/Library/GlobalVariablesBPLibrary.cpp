#include "GlobalVariablesBPLibrary.h"

    /* STATIC */ AActor* UGlobalVariablesBPLibrary::GetGlobalActorRefVariableSafe(UGlobalActorRefVariable* variable)
    {
        return UGlobalActorRefVariable::GetGlobalActorRefValue(variable);
    }

    /* STATIC */ bool UGlobalVariablesBPLibrary::GetGlobalBoolVariableSafe(UGlobalBoolVariable* variable)
    {
        return UGlobalBoolVariable::GetGlobalBoolValue(variable);
    }

    /* STATIC */ int32 UGlobalVariablesBPLibrary::GetGlobalIntVariableSafe(UGlobalIntVariable* variable)
    {
        return UGlobalIntVariable::GetGlobalIntValue(variable);
    }

    /* STATIC */ float UGlobalVariablesBPLibrary::GetGlobalFloatVariableSafe(UGlobalFloatVariable* variable)
    {
        return UGlobalFloatVariable::GetGlobalFloatValue(variable);
    }

    /* STATIC */ FRotator UGlobalVariablesBPLibrary::GetGlobalFRotatorVariableSafe(UGlobalFRotatorVariable* variable)
    {
        return UGlobalFRotatorVariable::GetGlobalFRotatorValue(variable);
    }

    /* STATIC */ FVector UGlobalVariablesBPLibrary::GetGlobalFVectorVariableSafe(UGlobalFVectorVariable* variable)
    {
        return UGlobalFVectorVariable::GetGlobalFVectorValue(variable);
    }

    /* STATIC */ FString UGlobalVariablesBPLibrary::GetGlobalStringVariableSafe(UGlobalStringVariable* variable)
    {
        return UGlobalStringVariable::GetGlobalStringValue(variable);
    }

    /* STATIC */ FVector2D UGlobalVariablesBPLibrary::GetGlobalFVector2DVariableSafe(UGlobalFVector2DVariable* variable)
    {
        return UGlobalFVector2DVariable::GetGlobalFVector2DValue(variable);
    }

