public class BaseVariable
{
}

[GlobalVariable("UObject*", "nullptr", "Object", "UObject::StaticClass()", "None", "item->GetName()")]
public class ObjectRefVariable : BaseVariable
{

}

[GlobalVariable("AActor*", "nullptr", "Object", "AActor::StaticClass()", "None", "item->GetName()")]
public class ActorRefVariable : BaseVariable
{

}

[GlobalVariable("bool", "false", "Boolean", "", "None", "UKismetStringLibrary::Conv_BoolToString(item)")]
public class BoolVariable : BaseVariable
{

}

[GlobalVariable("int32", "0", "Int", "", "None", "UKismetStringLibrary::Conv_IntToString(item)")]
public class IntVariable : BaseVariable
{

}

[GlobalVariable("float", "0.0f", "Float", "", "None", "UKismetStringLibrary::Conv_FloatToString(item)")]
public class FloatVariable : BaseVariable
{

}

[GlobalVariable("FString", "\"\"", "String", "", "None", "item")]
public class StringVariable : BaseVariable
{
}

[GlobalVariable("FRotator", "FRotator::ZeroRotator", "Struct", "TBaseStructure<FRotator>::Get()", "None", "UKismetStringLibrary::Conv_RotatorToString(item)")]
public class FRotatorVariable : BaseVariable
{

}

[GlobalVariable("FVector", "FVector::ZeroVector", "Struct", "TBaseStructure<FVector>::Get()", "None", "UKismetStringLibrary::Conv_VectorToString(item)")]
public class FVectorVariable : BaseVariable
{

}

[GlobalVariable("FVector2D", "FVector2D::ZeroVector", "Struct", "TBaseStructure<FVector2D>::Get()", "None", "UKismetStringLibrary::Conv_Vector2dToString(item)")]
public class FVector2DVariable : BaseVariable
{

}

// Examples:
// 
//[GlobalVariable("TArray<FString>", "TArray<FString>()", "String", "", "Array", "item")]
//public class StringArrayVariable : BaseVariable
//{
//
//}
//
//[GlobalVariable("FGameplayTagContainer", "FGameplayTagContainer()", "Struct", "FGameplayTagContainer::StaticStruct()", "None", "item.ToString()")]
//public class GameplayTagContainer : BaseVariable
//{
//
//}
