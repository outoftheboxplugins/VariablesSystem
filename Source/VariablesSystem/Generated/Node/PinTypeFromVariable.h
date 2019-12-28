    if (VariableClassName == FName("GlobalActorRefVariable"))
    {
        ResultPinType.PinCategory = UEdGraphSchema_K2::PC_Object;
        ResultPinType.PinSubCategoryObject = AActor::StaticClass();
    }
    if (VariableClassName == FName("GlobalBoolVariable"))
    {
        ResultPinType.PinCategory = UEdGraphSchema_K2::PC_Boolean;
    }
    if (VariableClassName == FName("GlobalIntVariable"))
    {
        ResultPinType.PinCategory = UEdGraphSchema_K2::PC_Int;
    }
    if (VariableClassName == FName("GlobalFloatVariable"))
    {
        ResultPinType.PinCategory = UEdGraphSchema_K2::PC_Float;
    }
    if (VariableClassName == FName("GlobalStringVariable"))
    {
        ResultPinType.PinCategory = UEdGraphSchema_K2::PC_String;
    }
    if (VariableClassName == FName("GlobalFRotatorVariable"))
    {
        ResultPinType.PinCategory = UEdGraphSchema_K2::PC_Struct;
        ResultPinType.PinSubCategoryObject = TBaseStructure<FRotator>::Get();
    }
    if (VariableClassName == FName("GlobalFVectorVariable"))
    {
        ResultPinType.PinCategory = UEdGraphSchema_K2::PC_Struct;
        ResultPinType.PinSubCategoryObject = TBaseStructure<FVector>::Get();
    }
    if (VariableClassName == FName("GlobalFVector2DVariable"))
    {
        ResultPinType.PinCategory = UEdGraphSchema_K2::PC_Struct;
        ResultPinType.PinSubCategoryObject = TBaseStructure<FVector2D>::Get();
    }
