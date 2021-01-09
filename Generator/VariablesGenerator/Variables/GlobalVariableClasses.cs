// Copyright Out-of-the-Box Plugins 2018-2021. All Rights Reserved.

public class BaseVariable { }

[GlobalVar("UObject*", "nullptr", "Object", "UObject::StaticClass()", "None", "Object")]
[DebugInfo("Item ? Item->GetName() : \"UNSET\"")]
public class ObjectRefVariable : BaseVariable { }

[GlobalVar("AActor*", "nullptr", "Object", "AActor::StaticClass()", "None", "SoftObject")]
[DebugInfo("Item ? Item->GetName() : \"UNSET\"")]
public class ActorRefVariable : BaseVariable { }

[GlobalVar("bool", "false", "Boolean", "", "None", "Boolean")]
[GenerateExtra(generateSaveLoad = true, generateArray = false)]
[DebugInfo("UKismetStringLibrary::Conv_BoolToString(Item)")]
public class BoolVariable : BaseVariable { }

[GlobalVar("int32", "0", "Int", "", "None", "Int")]
[GenerateExtra(generateSaveLoad = true, generateArray = false)]
[DebugInfo("UKismetStringLibrary::Conv_IntToString(Item)")]
public class IntVariable : BaseVariable { }

[GlobalVar("float", "0.0f", "Float", "", "None", "Float")]
[GenerateExtra(generateSaveLoad = true, generateArray = false)]
[DebugInfo("UKismetStringLibrary::Conv_FloatToString(Item)")]
public class FloatVariable : BaseVariable { }

[GlobalVar("FString", "\"\"", "String", "", "None", "String")]
[GenerateExtra(generateSaveLoad = true, generateArray = false)]
[DebugInfo("Item")]
public class StringVariable : BaseVariable { }

[GlobalVar("FRotator", "FRotator::ZeroRotator", "Struct", "TBaseStructure<FRotator>::Get()", "None", "Rotator")]
[GenerateExtra(generateSaveLoad = true, generateArray = false)]
[DebugInfo("UKismetStringLibrary::Conv_RotatorToString(Item)")]
public class FRotatorVariable : BaseVariable { }

[GlobalVar("FVector", "FVector::ZeroVector", "Struct", "TBaseStructure<FVector>::Get()", "None", "Vector")]
[GenerateExtra(generateSaveLoad = true, generateArray = false)]
[DebugInfo("UKismetStringLibrary::Conv_VectorToString(Item)")]
public class FVectorVariable : BaseVariable { }

[GlobalVar("FVector2D", "FVector2D::ZeroVector", "Struct", "TBaseStructure<FVector2D>::Get()", "None", "Vector")]
[GenerateExtra(generateSaveLoad = true, generateArray = false)]
[DebugInfo("UKismetStringLibrary::Conv_Vector2dToString(Item)")]
public class FVector2DVariable : BaseVariable { }

// Examples:
//[GlobalVariable("FGameplayTagContainer", "FGameplayTagContainer()", "Struct", "FGameplayTagContainer::StaticStruct()", "None")]
//[DebugInfo("Item.ToString()")]
//public class GameplayTagContainer : BaseVariable { }