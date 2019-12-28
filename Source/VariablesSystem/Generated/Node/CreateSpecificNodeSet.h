        if (VariableClassName == FName("GlobalActorRefVariable"))
        {
            resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(UGlobalActorRefVariable, SetGlobalActorRefVariableValue), UGlobalActorRefVariable::StaticClass());
        }
                if (VariableClassName == FName("GlobalBoolVariable"))
        {
            resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(UGlobalBoolVariable, SetGlobalBoolVariableValue), UGlobalBoolVariable::StaticClass());
        }
                if (VariableClassName == FName("GlobalIntVariable"))
        {
            resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(UGlobalIntVariable, SetGlobalIntVariableValue), UGlobalIntVariable::StaticClass());
        }
                if (VariableClassName == FName("GlobalFloatVariable"))
        {
            resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(UGlobalFloatVariable, SetGlobalFloatVariableValue), UGlobalFloatVariable::StaticClass());
        }
                if (VariableClassName == FName("GlobalStringVariable"))
        {
            resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(UGlobalStringVariable, SetGlobalStringVariableValue), UGlobalStringVariable::StaticClass());
        }
                if (VariableClassName == FName("GlobalFRotatorVariable"))
        {
            resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(UGlobalFRotatorVariable, SetGlobalFRotatorVariableValue), UGlobalFRotatorVariable::StaticClass());
        }
                if (VariableClassName == FName("GlobalFVectorVariable"))
        {
            resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(UGlobalFVectorVariable, SetGlobalFVectorVariableValue), UGlobalFVectorVariable::StaticClass());
        }
                if (VariableClassName == FName("GlobalFVector2DVariable"))
        {
            resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(UGlobalFVector2DVariable, SetGlobalFVector2DVariableValue), UGlobalFVector2DVariable::StaticClass());
        }
        