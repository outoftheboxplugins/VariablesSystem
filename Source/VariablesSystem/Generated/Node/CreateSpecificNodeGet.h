    if (VariableClassName == FName("GlobalActorRefVariable"))
    {
        resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(UGlobalActorRefVariable, GetGlobalActorRefVariableValue), UGlobalActorRefVariable::StaticClass());
    }
    if (VariableClassName == FName("LocalActorRefVariable"))
    {
        resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(ULocalActorRefVariable, GetLocalActorRefVariableValue), ULocalActorRefVariable::StaticClass());
    }
    if (VariableClassName == FName("GlobalBoolVariable"))
    {
        resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(UGlobalBoolVariable, GetGlobalBoolVariableValue), UGlobalBoolVariable::StaticClass());
    }
    if (VariableClassName == FName("LocalBoolVariable"))
    {
        resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(ULocalBoolVariable, GetLocalBoolVariableValue), ULocalBoolVariable::StaticClass());
    }
    if (VariableClassName == FName("GlobalIntVariable"))
    {
        resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(UGlobalIntVariable, GetGlobalIntVariableValue), UGlobalIntVariable::StaticClass());
    }
    if (VariableClassName == FName("LocalIntVariable"))
    {
        resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(ULocalIntVariable, GetLocalIntVariableValue), ULocalIntVariable::StaticClass());
    }
    if (VariableClassName == FName("GlobalFloatVariable"))
    {
        resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(UGlobalFloatVariable, GetGlobalFloatVariableValue), UGlobalFloatVariable::StaticClass());
    }
    if (VariableClassName == FName("LocalFloatVariable"))
    {
        resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(ULocalFloatVariable, GetLocalFloatVariableValue), ULocalFloatVariable::StaticClass());
    }
    if (VariableClassName == FName("GlobalStringVariable"))
    {
        resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(UGlobalStringVariable, GetGlobalStringVariableValue), UGlobalStringVariable::StaticClass());
    }
    if (VariableClassName == FName("LocalStringVariable"))
    {
        resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(ULocalStringVariable, GetLocalStringVariableValue), ULocalStringVariable::StaticClass());
    }
    if (VariableClassName == FName("GlobalFRotatorVariable"))
    {
        resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(UGlobalFRotatorVariable, GetGlobalFRotatorVariableValue), UGlobalFRotatorVariable::StaticClass());
    }
    if (VariableClassName == FName("LocalFRotatorVariable"))
    {
        resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(ULocalFRotatorVariable, GetLocalFRotatorVariableValue), ULocalFRotatorVariable::StaticClass());
    }
    if (VariableClassName == FName("GlobalFVectorVariable"))
    {
        resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(UGlobalFVectorVariable, GetGlobalFVectorVariableValue), UGlobalFVectorVariable::StaticClass());
    }
    if (VariableClassName == FName("LocalFVectorVariable"))
    {
        resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(ULocalFVectorVariable, GetLocalFVectorVariableValue), ULocalFVectorVariable::StaticClass());
    }
    if (VariableClassName == FName("GlobalFVector2DVariable"))
    {
        resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(UGlobalFVector2DVariable, GetGlobalFVector2DVariableValue), UGlobalFVector2DVariable::StaticClass());
    }
    if (VariableClassName == FName("LocalFVector2DVariable"))
    {
        resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(ULocalFVector2DVariable, GetLocalFVector2DVariableValue), ULocalFVector2DVariable::StaticClass());
    }
    if (VariableClassName == FName("GlobalStringArrayVariable"))
    {
        resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(UGlobalStringArrayVariable, GetGlobalStringArrayVariableValue), UGlobalStringArrayVariable::StaticClass());
    }
    if (VariableClassName == FName("LocalStringArrayVariable"))
    {
        resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(ULocalStringArrayVariable, GetLocalStringArrayVariableValue), ULocalStringArrayVariable::StaticClass());
    }
    if (VariableClassName == FName("GlobalGameplayTagContainer"))
    {
        resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(UGlobalGameplayTagContainer, GetGlobalGameplayTagContainerValue), UGlobalGameplayTagContainer::StaticClass());
    }
    if (VariableClassName == FName("LocalGameplayTagContainer"))
    {
        resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(ULocalGameplayTagContainer, GetLocalGameplayTagContainerValue), ULocalGameplayTagContainer::StaticClass());
    }
