    if (VariableClassName == FName("GlobalObjectRefVariable"))
    {
        resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(UGlobalObjectRefVariable, GetGlobalObjectRefVariableValue), UGlobalObjectRefVariable::StaticClass());
    }
    if (VariableClassName == FName("InstancedObjectRefVariable"))
    {
        resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(UInstancedObjectRefVariable, GetInstancedObjectRefVariableValue), UInstancedObjectRefVariable::StaticClass());
    }
    if (VariableClassName == FName("GlobalActorRefVariable"))
    {
        resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(UGlobalActorRefVariable, GetGlobalActorRefVariableValue), UGlobalActorRefVariable::StaticClass());
    }
    if (VariableClassName == FName("InstancedActorRefVariable"))
    {
        resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(UInstancedActorRefVariable, GetInstancedActorRefVariableValue), UInstancedActorRefVariable::StaticClass());
    }
    if (VariableClassName == FName("GlobalBoolVariable"))
    {
        resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(UGlobalBoolVariable, GetGlobalBoolVariableValue), UGlobalBoolVariable::StaticClass());
    }
    if (VariableClassName == FName("InstancedBoolVariable"))
    {
        resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(UInstancedBoolVariable, GetInstancedBoolVariableValue), UInstancedBoolVariable::StaticClass());
    }
    if (VariableClassName == FName("GlobalIntVariable"))
    {
        resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(UGlobalIntVariable, GetGlobalIntVariableValue), UGlobalIntVariable::StaticClass());
    }
    if (VariableClassName == FName("InstancedIntVariable"))
    {
        resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(UInstancedIntVariable, GetInstancedIntVariableValue), UInstancedIntVariable::StaticClass());
    }
    if (VariableClassName == FName("GlobalFloatVariable"))
    {
        resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(UGlobalFloatVariable, GetGlobalFloatVariableValue), UGlobalFloatVariable::StaticClass());
    }
    if (VariableClassName == FName("InstancedFloatVariable"))
    {
        resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(UInstancedFloatVariable, GetInstancedFloatVariableValue), UInstancedFloatVariable::StaticClass());
    }
    if (VariableClassName == FName("GlobalStringVariable"))
    {
        resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(UGlobalStringVariable, GetGlobalStringVariableValue), UGlobalStringVariable::StaticClass());
    }
    if (VariableClassName == FName("InstancedStringVariable"))
    {
        resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(UInstancedStringVariable, GetInstancedStringVariableValue), UInstancedStringVariable::StaticClass());
    }
    if (VariableClassName == FName("GlobalFRotatorVariable"))
    {
        resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(UGlobalFRotatorVariable, GetGlobalFRotatorVariableValue), UGlobalFRotatorVariable::StaticClass());
    }
    if (VariableClassName == FName("InstancedFRotatorVariable"))
    {
        resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(UInstancedFRotatorVariable, GetInstancedFRotatorVariableValue), UInstancedFRotatorVariable::StaticClass());
    }
    if (VariableClassName == FName("GlobalFVectorVariable"))
    {
        resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(UGlobalFVectorVariable, GetGlobalFVectorVariableValue), UGlobalFVectorVariable::StaticClass());
    }
    if (VariableClassName == FName("InstancedFVectorVariable"))
    {
        resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(UInstancedFVectorVariable, GetInstancedFVectorVariableValue), UInstancedFVectorVariable::StaticClass());
    }
    if (VariableClassName == FName("GlobalFVector2DVariable"))
    {
        resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(UGlobalFVector2DVariable, GetGlobalFVector2DVariableValue), UGlobalFVector2DVariable::StaticClass());
    }
    if (VariableClassName == FName("InstancedFVector2DVariable"))
    {
        resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(UInstancedFVector2DVariable, GetInstancedFVector2DVariableValue), UInstancedFVector2DVariable::StaticClass());
    }
