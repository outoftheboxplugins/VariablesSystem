// Copyright Out-of-the-Box Plugins 2018-2020. All Rights Reserved.

#include "BPNode_GenericVariablesGetValue.h"

#include "GenericVariablesBPLibrary.h"

#define LOCTEXT_NAMESPACE "VariablesSystemEditor"

//////////////////////////////////////////////////////////////////////////
//UEdGraphNode implementation
void UBPNode_GenericVariablesGetValue::AllocateDefaultPins()
{
	// Create a pin for the return value, type will be determined later
    CreatePin(EGPD_Output, UEdGraphSchema_K2::PC_Wildcard, UEdGraphSchema_K2::PN_ReturnValue);

    Super::AllocateDefaultPins();
}

FText UBPNode_GenericVariablesGetValue::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
    return LOCTEXT("GetVariableNodeName", "Get Generic Variable");
}

FText UBPNode_GenericVariablesGetValue::GetTooltipText() const
{
    return LOCTEXT("GetVariableNodetTooltip", "Returns the value of a Generic Variable");
}

//////////////////////////////////////////////////////////////////////////
// Generic Overrides
UEdGraphPin* UBPNode_GenericVariablesGetValue::GetVariableValuePin() const
{
    UEdGraphPin* Pin = FindPinChecked(UEdGraphSchema_K2::PN_ReturnValue);
    check(Pin->Direction == EGPD_Output);
    return Pin;
}

UEdGraphPin* UBPNode_GenericVariablesGetValue::GetVariableLinkPin(UK2Node_CallFunction* NodeFunction) const
{
	return NodeFunction->GetReturnValuePin();
}

UK2Node_CallFunction* UBPNode_GenericVariablesGetValue::CreateSpecificNode(FName VariableClassName, FKismetCompilerContext& CompilerContext, UEdGraph* SourceGraph)
{
    UK2Node_CallFunction* ResultCreateNode = nullptr;
    ResultCreateNode = CompilerContext.SpawnIntermediateNode<UK2Node_CallFunction>(this, SourceGraph);

    #include "VariablesSystem/Generated/Node/CreateSpecificNodeGet.h"

    ResultCreateNode->AllocateDefaultPins();
    return ResultCreateNode;
}

#undef LOCTEXT_NAMESPACE