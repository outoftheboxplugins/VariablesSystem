#include "GlobalVariablesBPLibrary.h"

    /* STATIC */ AActor* UGlobalVariablesBPLibrary::GetGlobalActorRefVariableSafe(UGlobalActorRefVariable* variable)
    {
        return UGlobalActorRefVariable::GetGlobalActorRefVariableValue(variable);
    }

    /* STATIC */ bool UGlobalVariablesBPLibrary::GetGlobalBoolVariableSafe(UGlobalBoolVariable* variable)
    {
        return UGlobalBoolVariable::GetGlobalBoolVariableValue(variable);
    }

    /* STATIC */ int32 UGlobalVariablesBPLibrary::GetGlobalIntVariableSafe(UGlobalIntVariable* variable)
    {
        return UGlobalIntVariable::GetGlobalIntVariableValue(variable);
    }

    /* STATIC */ float UGlobalVariablesBPLibrary::GetGlobalFloatVariableSafe(UGlobalFloatVariable* variable)
    {
        return UGlobalFloatVariable::GetGlobalFloatVariableValue(variable);
    }

    /* STATIC */ FString UGlobalVariablesBPLibrary::GetGlobalStringVariableSafe(UGlobalStringVariable* variable)
    {
        return UGlobalStringVariable::GetGlobalStringVariableValue(variable);
    }

    /* STATIC */ FRotator UGlobalVariablesBPLibrary::GetGlobalFRotatorVariableSafe(UGlobalFRotatorVariable* variable)
    {
        return UGlobalFRotatorVariable::GetGlobalFRotatorVariableValue(variable);
    }

    /* STATIC */ FVector UGlobalVariablesBPLibrary::GetGlobalFVectorVariableSafe(UGlobalFVectorVariable* variable)
    {
        return UGlobalFVectorVariable::GetGlobalFVectorVariableValue(variable);
    }

    /* STATIC */ FVector2D UGlobalVariablesBPLibrary::GetGlobalFVector2DVariableSafe(UGlobalFVector2DVariable* variable)
    {
        return UGlobalFVector2DVariable::GetGlobalFVector2DVariableValue(variable);
    }

