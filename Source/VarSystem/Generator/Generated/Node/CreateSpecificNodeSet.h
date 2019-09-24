        if (VariableClassName == FName("GlobalActorRefVariable"))
        {
            resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(UGlobalActorRefVariable, SetGlobalActorRefValue), UGlobalActorRefVariable::StaticClass());
        }
                if (VariableClassName == FName("GlobalBoolVariable"))
        {
            resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(UGlobalBoolVariable, SetGlobalBoolValue), UGlobalBoolVariable::StaticClass());
        }
                if (VariableClassName == FName("GlobalIntVariable"))
        {
            resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(UGlobalIntVariable, SetGlobalIntValue), UGlobalIntVariable::StaticClass());
        }
                if (VariableClassName == FName("GlobalFloatVariable"))
        {
            resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(UGlobalFloatVariable, SetGlobalFloatValue), UGlobalFloatVariable::StaticClass());
        }
                if (VariableClassName == FName("GlobalFRotatorVariable"))
        {
            resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(UGlobalFRotatorVariable, SetGlobalFRotatorValue), UGlobalFRotatorVariable::StaticClass());
        }
                if (VariableClassName == FName("GlobalFVectorVariable"))
        {
            resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(UGlobalFVectorVariable, SetGlobalFVectorValue), UGlobalFVectorVariable::StaticClass());
        }
                if (VariableClassName == FName("GlobalStringVariable"))
        {
            resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(UGlobalStringVariable, SetGlobalStringValue), UGlobalStringVariable::StaticClass());
        }
                if (VariableClassName == FName("GlobalFVector2DVariable"))
        {
            resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(UGlobalFVector2DVariable, SetGlobalFVector2DValue), UGlobalFVector2DVariable::StaticClass());
        }
        