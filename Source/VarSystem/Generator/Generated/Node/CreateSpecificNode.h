	if (VariableClassName == FName("GlobalActorRefVariable"))
	{
		resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(UGlobalActorRefVariable, GetGlobalActorRefValue), UGlobalActorRefVariable::StaticClass());
	}
	if (VariableClassName == FName("GlobalBoolVariable"))
	{
		resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(UGlobalBoolVariable, GetGlobalBoolValue), UGlobalBoolVariable::StaticClass());
	}
	if (VariableClassName == FName("GlobalIntVariable"))
	{
		resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(UGlobalIntVariable, GetGlobalIntValue), UGlobalIntVariable::StaticClass());
	}
	if (VariableClassName == FName("GlobalFloatVariable"))
	{
		resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(UGlobalFloatVariable, GetGlobalFloatValue), UGlobalFloatVariable::StaticClass());
	}
	if (VariableClassName == FName("GlobalFRotatorVariable"))
	{
		resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(UGlobalFRotatorVariable, GetGlobalFRotatorValue), UGlobalFRotatorVariable::StaticClass());
	}
	if (VariableClassName == FName("GlobalFVectorVariable"))
	{
		resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(UGlobalFVectorVariable, GetGlobalFVectorValue), UGlobalFVectorVariable::StaticClass());
	}
	if (VariableClassName == FName("GlobalStringVariable"))
	{
		resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(UGlobalStringVariable, GetGlobalStringValue), UGlobalStringVariable::StaticClass());
	}
	if (VariableClassName == FName("GlobalFVector2DVariable"))
	{
		resultCreateNode->FunctionReference.SetExternalMember(GET_FUNCTION_NAME_CHECKED(UGlobalFVector2DVariable, GetGlobalFVector2DValue), UGlobalFVector2DVariable::StaticClass());
	}
