    if (VariableClassName == FName("GlobalActorRefVariable"))
    {
        resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(UGlobalActorRefVariable, GetGlobalActorRefVariableValue), UGlobalActorRefVariable::StaticClass());
    }
    if (VariableClassName == FName("GlobalBoolVariable"))
    {
        resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(UGlobalBoolVariable, GetGlobalBoolVariableValue), UGlobalBoolVariable::StaticClass());
    }
    if (VariableClassName == FName("GlobalIntVariable"))
    {
        resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(UGlobalIntVariable, GetGlobalIntVariableValue), UGlobalIntVariable::StaticClass());
    }
    if (VariableClassName == FName("GlobalFloatVariable"))
    {
        resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(UGlobalFloatVariable, GetGlobalFloatVariableValue), UGlobalFloatVariable::StaticClass());
    }
    if (VariableClassName == FName("GlobalStringVariable"))
    {
        resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(UGlobalStringVariable, GetGlobalStringVariableValue), UGlobalStringVariable::StaticClass());
    }
    if (VariableClassName == FName("GlobalFRotatorVariable"))
    {
        resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(UGlobalFRotatorVariable, GetGlobalFRotatorVariableValue), UGlobalFRotatorVariable::StaticClass());
    }
    if (VariableClassName == FName("GlobalFVectorVariable"))
    {
        resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(UGlobalFVectorVariable, GetGlobalFVectorVariableValue), UGlobalFVectorVariable::StaticClass());
    }
    if (VariableClassName == FName("GlobalFVector2DVariable"))
    {
        resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(UGlobalFVector2DVariable, GetGlobalFVector2DVariableValue), UGlobalFVector2DVariable::StaticClass());
    }
