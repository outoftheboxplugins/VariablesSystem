public class BaseVariable { }

[GlobalVar("UObject*", "nullptr", "Object", "UObject::StaticClass()", "None")]
[DebugInfo()]
public class ObjectRefVariable : BaseVariable { }

[GlobalVar("AActor*", "nullptr", "Object", "AActor::StaticClass()", "None")]
[DebugInfo()]
public class ActorRefVariable : BaseVariable { }

[GlobalVar("bool", "false", "Boolean", "", "None")]
[GenerateExtra(generateSaveLoad = true, generateArray = false)]
[DebugInfo("UKismetStringLibrary::Conv_BoolToString(Item)")]
public class BoolVariable : BaseVariable { }

[GlobalVar("int32", "0", "Int", "", "None")]
[GenerateExtra(generateSaveLoad = true, generateArray = false)]
[DebugInfo("UKismetStringLibrary::Conv_IntToString(Item)")]
public class IntVariable : BaseVariable { }

[GlobalVar("float", "0.0f", "Float", "", "None")]
[GenerateExtra(generateSaveLoad = true, generateArray = false)]
[DebugInfo("UKismetStringLibrary::Conv_FloatToString(Item)")]
public class FloatVariable : BaseVariable { }

[GlobalVar("FString", "\"\"", "String", "", "None")]
[GenerateExtra(generateSaveLoad = true, generateArray = false)]
[DebugInfo("Item")]
public class StringVariable : BaseVariable { }

[GlobalVar("FRotator", "FRotator::ZeroRotator", "Struct", "TBaseStructure<FRotator>::Get()", "None")]
[GenerateExtra(generateSaveLoad = true, generateArray = false)]
[DebugInfo("UKismetStringLibrary::Conv_RotatorToString(Item)")]
public class FRotatorVariable : BaseVariable { }

[GlobalVar("FVector", "FVector::ZeroVector", "Struct", "TBaseStructure<FVector>::Get()", "None")]
[GenerateExtra(generateSaveLoad = true, generateArray = false)]
[DebugInfo("UKismetStringLibrary::Conv_VectorToString(Item)")]
public class FVectorVariable : BaseVariable { }

[GlobalVar("FVector2D", "FVector2D::ZeroVector", "Struct", "TBaseStructure<FVector2D>::Get()", "None")]
[GenerateExtra(generateSaveLoad = true, generateArray = false)]
[DebugInfo("UKismetStringLibrary::Conv_Vector2dToString(Item)")]
public class FVector2DVariable : BaseVariable { }

// Examples:
// 
//[GlobalVariable("TArray<FString>", "TArray<FString>()", "String", "", "Array")]
//[GenerateExtra(generateSaveLoad = true, generateArray = false)]
//[DebugInfo("Item")]
//public class StringArrayVariable : BaseVariable { }

//[GlobalVariable("FGameplayTagContainer", "FGameplayTagContainer()", "Struct", "FGameplayTagContainer::StaticStruct()", "None")]
//[DebugInfo("Item.ToString()")]
//public class GameplayTagContainer : BaseVariable { }