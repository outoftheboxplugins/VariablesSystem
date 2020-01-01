    if (VariableClassName == FName("GlobalActorRefVariable"))
    {
        ResultPinType.PinCategory = UEdGraphSchema_K2::PC_Object;
        ResultContainerType = EPinContainerType::None;
        ResultPinType.PinSubCategoryObject = AActor::StaticClass();
    }
    if (VariableClassName == FName("LocalActorRefVariable"))
    {
        ResultPinType.PinCategory = UEdGraphSchema_K2::PC_Object;
        ResultContainerType = EPinContainerType::None;
        ResultPinType.PinSubCategoryObject = AActor::StaticClass();
    }
    if (VariableClassName == FName("GlobalBoolVariable"))
    {
        ResultPinType.PinCategory = UEdGraphSchema_K2::PC_Boolean;
        ResultContainerType = EPinContainerType::None;
    }
    if (VariableClassName == FName("LocalBoolVariable"))
    {
        ResultPinType.PinCategory = UEdGraphSchema_K2::PC_Boolean;
        ResultContainerType = EPinContainerType::None;
    }
    if (VariableClassName == FName("GlobalIntVariable"))
    {
        ResultPinType.PinCategory = UEdGraphSchema_K2::PC_Int;
        ResultContainerType = EPinContainerType::None;
    }
    if (VariableClassName == FName("LocalIntVariable"))
    {
        ResultPinType.PinCategory = UEdGraphSchema_K2::PC_Int;
        ResultContainerType = EPinContainerType::None;
    }
    if (VariableClassName == FName("GlobalFloatVariable"))
    {
        ResultPinType.PinCategory = UEdGraphSchema_K2::PC_Float;
        ResultContainerType = EPinContainerType::None;
    }
    if (VariableClassName == FName("LocalFloatVariable"))
    {
        ResultPinType.PinCategory = UEdGraphSchema_K2::PC_Float;
        ResultContainerType = EPinContainerType::None;
    }
    if (VariableClassName == FName("GlobalStringVariable"))
    {
        ResultPinType.PinCategory = UEdGraphSchema_K2::PC_String;
        ResultContainerType = EPinContainerType::None;
    }
    if (VariableClassName == FName("LocalStringVariable"))
    {
        ResultPinType.PinCategory = UEdGraphSchema_K2::PC_String;
        ResultContainerType = EPinContainerType::None;
    }
    if (VariableClassName == FName("GlobalFRotatorVariable"))
    {
        ResultPinType.PinCategory = UEdGraphSchema_K2::PC_Struct;
        ResultContainerType = EPinContainerType::None;
        ResultPinType.PinSubCategoryObject = TBaseStructure<FRotator>::Get();
    }
    if (VariableClassName == FName("LocalFRotatorVariable"))
    {
        ResultPinType.PinCategory = UEdGraphSchema_K2::PC_Struct;
        ResultContainerType = EPinContainerType::None;
        ResultPinType.PinSubCategoryObject = TBaseStructure<FRotator>::Get();
    }
    if (VariableClassName == FName("GlobalFVectorVariable"))
    {
        ResultPinType.PinCategory = UEdGraphSchema_K2::PC_Struct;
        ResultContainerType = EPinContainerType::None;
        ResultPinType.PinSubCategoryObject = TBaseStructure<FVector>::Get();
    }
    if (VariableClassName == FName("LocalFVectorVariable"))
    {
        ResultPinType.PinCategory = UEdGraphSchema_K2::PC_Struct;
        ResultContainerType = EPinContainerType::None;
        ResultPinType.PinSubCategoryObject = TBaseStructure<FVector>::Get();
    }
    if (VariableClassName == FName("GlobalFVector2DVariable"))
    {
        ResultPinType.PinCategory = UEdGraphSchema_K2::PC_Struct;
        ResultContainerType = EPinContainerType::None;
        ResultPinType.PinSubCategoryObject = TBaseStructure<FVector2D>::Get();
    }
    if (VariableClassName == FName("LocalFVector2DVariable"))
    {
        ResultPinType.PinCategory = UEdGraphSchema_K2::PC_Struct;
        ResultContainerType = EPinContainerType::None;
        ResultPinType.PinSubCategoryObject = TBaseStructure<FVector2D>::Get();
    }
