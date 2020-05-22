        if (VariableClassName == FName("GlobalActorRefVariable"))
        {
            resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(UGlobalActorRefVariable, SetGlobalActorRefVariableValue), UGlobalActorRefVariable::StaticClass());
        }

        if (VariableClassName == FName("LocalActorRefVariable"))
        {
            resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(ULocalActorRefVariable, SetLocalActorRefVariableValue), ULocalActorRefVariable::StaticClass());
        }
        if (VariableClassName == FName("GlobalBoolVariable"))
        {
            resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(UGlobalBoolVariable, SetGlobalBoolVariableValue), UGlobalBoolVariable::StaticClass());
        }

        if (VariableClassName == FName("LocalBoolVariable"))
        {
            resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(ULocalBoolVariable, SetLocalBoolVariableValue), ULocalBoolVariable::StaticClass());
        }
        if (VariableClassName == FName("GlobalIntVariable"))
        {
            resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(UGlobalIntVariable, SetGlobalIntVariableValue), UGlobalIntVariable::StaticClass());
        }

        if (VariableClassName == FName("LocalIntVariable"))
        {
            resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(ULocalIntVariable, SetLocalIntVariableValue), ULocalIntVariable::StaticClass());
        }
        if (VariableClassName == FName("GlobalFloatVariable"))
        {
            resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(UGlobalFloatVariable, SetGlobalFloatVariableValue), UGlobalFloatVariable::StaticClass());
        }

        if (VariableClassName == FName("LocalFloatVariable"))
        {
            resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(ULocalFloatVariable, SetLocalFloatVariableValue), ULocalFloatVariable::StaticClass());
        }
        if (VariableClassName == FName("GlobalStringVariable"))
        {
            resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(UGlobalStringVariable, SetGlobalStringVariableValue), UGlobalStringVariable::StaticClass());
        }

        if (VariableClassName == FName("LocalStringVariable"))
        {
            resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(ULocalStringVariable, SetLocalStringVariableValue), ULocalStringVariable::StaticClass());
        }
        if (VariableClassName == FName("GlobalFRotatorVariable"))
        {
            resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(UGlobalFRotatorVariable, SetGlobalFRotatorVariableValue), UGlobalFRotatorVariable::StaticClass());
        }

        if (VariableClassName == FName("LocalFRotatorVariable"))
        {
            resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(ULocalFRotatorVariable, SetLocalFRotatorVariableValue), ULocalFRotatorVariable::StaticClass());
        }
        if (VariableClassName == FName("GlobalFVectorVariable"))
        {
            resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(UGlobalFVectorVariable, SetGlobalFVectorVariableValue), UGlobalFVectorVariable::StaticClass());
        }

        if (VariableClassName == FName("LocalFVectorVariable"))
        {
            resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(ULocalFVectorVariable, SetLocalFVectorVariableValue), ULocalFVectorVariable::StaticClass());
        }
        if (VariableClassName == FName("GlobalFVector2DVariable"))
        {
            resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(UGlobalFVector2DVariable, SetGlobalFVector2DVariableValue), UGlobalFVector2DVariable::StaticClass());
        }

        if (VariableClassName == FName("LocalFVector2DVariable"))
        {
            resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(ULocalFVector2DVariable, SetLocalFVector2DVariableValue), ULocalFVector2DVariable::StaticClass());
        }
