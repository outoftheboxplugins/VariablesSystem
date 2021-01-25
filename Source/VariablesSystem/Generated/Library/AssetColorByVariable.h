
// Copyright Out-of-the-Box Plugins 2018-2021. All Rights Reserved.

// GENERATED FILE DO NOT MODIFY DIRECTLY

	if (Variable->IsA<UGlobalObjectRefVariable>() || Variable->IsA<UInstancedObjectRefVariable>())
	{
		return Settings->ObjectPinTypeColor;
	}
	if (Variable->IsA<UGlobalActorRefVariable>() || Variable->IsA<UInstancedActorRefVariable>())
	{
		return Settings->SoftObjectPinTypeColor;
	}
	if (Variable->IsA<UGlobalBoolVariable>() || Variable->IsA<UInstancedBoolVariable>())
	{
		return Settings->BooleanPinTypeColor;
	}
	if (Variable->IsA<UGlobalIntVariable>() || Variable->IsA<UInstancedIntVariable>())
	{
		return Settings->IntPinTypeColor;
	}
	if (Variable->IsA<UGlobalFloatVariable>() || Variable->IsA<UInstancedFloatVariable>())
	{
		return Settings->FloatPinTypeColor;
	}
	if (Variable->IsA<UGlobalStringVariable>() || Variable->IsA<UInstancedStringVariable>())
	{
		return Settings->StringPinTypeColor;
	}
	if (Variable->IsA<UGlobalFRotatorVariable>() || Variable->IsA<UInstancedFRotatorVariable>())
	{
		return Settings->RotatorPinTypeColor;
	}
	if (Variable->IsA<UGlobalFVectorVariable>() || Variable->IsA<UInstancedFVectorVariable>())
	{
		return Settings->VectorPinTypeColor;
	}
	if (Variable->IsA<UGlobalFVector2DVariable>() || Variable->IsA<UInstancedFVector2DVariable>())
	{
		return Settings->VectorPinTypeColor;
	}
	if (Variable->IsA<UGlobalGameplayTagContainer>() || Variable->IsA<UInstancedGameplayTagContainer>())
	{
		return Settings->StructPinTypeColor;
	}
