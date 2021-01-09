// Copyright Out-of-the-Box Plugins 2018-2020. All Rights Reserved.

#include "BPNode_GenericVariablesSetValue.h"

#include "IncludeAll.h"

#define LOCTEXT_NAMESPACE "VariablesSystemEditor"

namespace
{
	const FName PN_InputValue = TEXT("InputValue");
	const FName VariableNewValueTextPin = TEXT("NewValue");
	const FName VariableInputValueTextPin = TEXT("InputValue");
}

//////////////////////////////////////////////////////////////////////////
//UEdGraphNode implementation
void UBPNode_GenericVariablesSetValue::AllocateDefaultPins()
{
	// Create Execute input pin
    CreatePin(EGPD_Input, UEdGraphSchema_K2::PC_Exec, UEdGraphSchema_K2::PN_Execute);
    
	// Create Execute output pin (Then)
	CreatePin(EGPD_Output, UEdGraphSchema_K2::PC_Exec, UEdGraphSchema_K2::PN_Then);

	// Create a pin for the input value, type will be determined later
    CreatePin(EGPD_Input, UEdGraphSchema_K2::PC_Wildcard, PN_InputValue);

    Super::AllocateDefaultPins();
}

FText UBPNode_GenericVariablesSetValue::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
    return LOCTEXT("SetVariableNodeName", "Set Generic Variable");
}

FText UBPNode_GenericVariablesSetValue::GetTooltipText() const
{
    return LOCTEXT("SetVariableNodetTooltip", "Sets the value of a Generic Variable");
}

bool UBPNode_GenericVariablesSetValue::AdditionalExpand(FKismetCompilerContext& CompilerContext, UK2Node_CallFunction* NodeFunction)
{
    bool bSucceeded = true;

    //connect exe
    {
        UEdGraphPin* SpawnExecPin = GetExecPin();
        UEdGraphPin* CallExecPin = NodeFunction->GetExecPin();
        bSucceeded &= SpawnExecPin && CallExecPin && CompilerContext.MovePinLinksToIntermediate(*SpawnExecPin, *CallExecPin).CanSafeConnect();
    }

    // connect then
    {
        UEdGraphPin* SpawnThenPin = GetThenPin();
        UEdGraphPin* CallThenPin = NodeFunction->GetThenPin();
        bSucceeded &= SpawnThenPin && CallThenPin && CompilerContext.MovePinLinksToIntermediate(*SpawnThenPin, *CallThenPin).CanSafeConnect();
    }

    return bSucceeded;
}

//////////////////////////////////////////////////////////////////////////
// Generic Overrides
UEdGraphPin* UBPNode_GenericVariablesSetValue::GetVariableValuePin() const
{
    UEdGraphPin* Pin = FindPinChecked(PN_InputValue);
    check(Pin->Direction == EGPD_Input);
    return Pin;
}

UK2Node_CallFunction* UBPNode_GenericVariablesSetValue::CreateSpecificNode(FName VariableClassName, FKismetCompilerContext& CompilerContext, UEdGraph* SourceGraph)
{
    UK2Node_CallFunction* ResultCreateNode = nullptr;
    ResultCreateNode = CompilerContext.SpawnIntermediateNode<UK2Node_CallFunction>(this, SourceGraph);

    #include "VariablesSystem/Generated/Node/CreateSpecificNodeSet.h"

    ResultCreateNode->AllocateDefaultPins();
    return ResultCreateNode;
}

UEdGraphPin* UBPNode_GenericVariablesSetValue::GetVariableLinkPin(UK2Node_CallFunction* NodeFunction) const
{
    return NodeFunction->FindPin(VariableNewValueTextPin);
}

//////////////////////////////////////////////////////////////////////////
// Internal helpers
UEdGraphPin* UBPNode_GenericVariablesSetValue::GetThenPin()const
{
    UEdGraphPin* Pin = FindPinChecked(UEdGraphSchema_K2::PN_Then);
    check(Pin->Direction == EGPD_Output);
    return Pin;
}

#undef LOCTEXT_NAMESPACE