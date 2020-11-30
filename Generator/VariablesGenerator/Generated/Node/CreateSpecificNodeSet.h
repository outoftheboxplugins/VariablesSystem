        if (VariableClassName == FName("GlobalObjectRefVariable"))
        {
            resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(UGlobalObjectRefVariable, SetGlobalObjectRefVariableValue), UGlobalObjectRefVariable::StaticClass());
        }

        if (VariableClassName == FName("InstancedObjectRefVariable"))
        {
            resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(UInstancedObjectRefVariable, SetInstancedObjectRefVariableValue), UInstancedObjectRefVariable::StaticClass());
        }
        if (VariableClassName == FName("GlobalActorRefVariable"))
        {
            resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(UGlobalActorRefVariable, SetGlobalActorRefVariableValue), UGlobalActorRefVariable::StaticClass());
        }

        if (VariableClassName == FName("InstancedActorRefVariable"))
        {
            resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(UInstancedActorRefVariable, SetInstancedActorRefVariableValue), UInstancedActorRefVariable::StaticClass());
        }
        if (VariableClassName == FName("GlobalBoolVariable"))
        {
            resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(UGlobalBoolVariable, SetGlobalBoolVariableValue), UGlobalBoolVariable::StaticClass());
        }

        if (VariableClassName == FName("InstancedBoolVariable"))
        {
            resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(UInstancedBoolVariable, SetInstancedBoolVariableValue), UInstancedBoolVariable::StaticClass());
        }
        if (VariableClassName == FName("GlobalIntVariable"))
        {
            resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(UGlobalIntVariable, SetGlobalIntVariableValue), UGlobalIntVariable::StaticClass());
        }

        if (VariableClassName == FName("InstancedIntVariable"))
        {
            resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(UInstancedIntVariable, SetInstancedIntVariableValue), UInstancedIntVariable::StaticClass());
        }
        if (VariableClassName == FName("GlobalFloatVariable"))
        {
            resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(UGlobalFloatVariable, SetGlobalFloatVariableValue), UGlobalFloatVariable::StaticClass());
        }

        if (VariableClassName == FName("InstancedFloatVariable"))
        {
            resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(UInstancedFloatVariable, SetInstancedFloatVariableValue), UInstancedFloatVariable::StaticClass());
        }
        if (VariableClassName == FName("GlobalStringVariable"))
        {
            resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(UGlobalStringVariable, SetGlobalStringVariableValue), UGlobalStringVariable::StaticClass());
        }

        if (VariableClassName == FName("InstancedStringVariable"))
        {
            resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(UInstancedStringVariable, SetInstancedStringVariableValue), UInstancedStringVariable::StaticClass());
        }
        if (VariableClassName == FName("GlobalFRotatorVariable"))
        {
            resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(UGlobalFRotatorVariable, SetGlobalFRotatorVariableValue), UGlobalFRotatorVariable::StaticClass());
        }

        if (VariableClassName == FName("InstancedFRotatorVariable"))
        {
            resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(UInstancedFRotatorVariable, SetInstancedFRotatorVariableValue), UInstancedFRotatorVariable::StaticClass());
        }
        if (VariableClassName == FName("GlobalFVectorVariable"))
        {
            resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(UGlobalFVectorVariable, SetGlobalFVectorVariableValue), UGlobalFVectorVariable::StaticClass());
        }

        if (VariableClassName == FName("InstancedFVectorVariable"))
        {
            resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(UInstancedFVectorVariable, SetInstancedFVectorVariableValue), UInstancedFVectorVariable::StaticClass());
        }
        if (VariableClassName == FName("GlobalFVector2DVariable"))
        {
            resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(UGlobalFVector2DVariable, SetGlobalFVector2DVariableValue), UGlobalFVector2DVariable::StaticClass());
        }

        if (VariableClassName == FName("InstancedFVector2DVariable"))
        {
            resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(UInstancedFVector2DVariable, SetInstancedFVector2DVariableValue), UInstancedFVector2DVariable::StaticClass());
        }
