// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#include "BPNode_GenericVariablesSetValue.h"

#include "BlueprintGraph/Classes/K2Node_CallFunction.h"
#include "BlueprintGraph/Public/BlueprintActionDatabaseRegistrar.h"
#include "BlueprintGraph/Public/BlueprintNodeSpawner.h"
#include "KismetCompiler/Public/KismetCompiler.h"
#include "VariablesSystem/Generated/Library/IncludeAll.h"

#define LOCTEXT_NAMESPACE "VariablesSystem"

const FName PN_InputValue(TEXT("InputValue"));

//////////////////////////////////////////////////////////////////////////
void UBPNode_GenericVariablesSetValue::AllocateDefaultPins()
{
    const UEdGraphSchema_K2* K2Schema = GetDefault<UEdGraphSchema_K2>();

    UEdGraphPin* InExec = CreatePin(EGPD_Input, UEdGraphSchema_K2::PC_Exec, UEdGraphSchema_K2::PN_Execute);
    UEdGraphPin* OutThen = CreatePin(EGPD_Output, UEdGraphSchema_K2::PC_Exec, UEdGraphSchema_K2::PN_Then);

    UEdGraphPin* ResultPin = CreatePin(EGPD_Input, UEdGraphSchema_K2::PC_Wildcard, PN_InputValue);

    Super::AllocateDefaultPins();
}

//////////////////////////////////////////////////////////////////////////
FText UBPNode_GenericVariablesSetValue::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
    return LOCTEXT("VariablesSystem_SetVariableNodeName", "Set Generic Variable");
}

//////////////////////////////////////////////////////////////////////////
FText UBPNode_GenericVariablesSetValue::GetTooltipText() const
{
    return LOCTEXT("VariablesSystem_SetVariableNodetTooltip", "Sets the value of a Generic Variable");
}

//////////////////////////////////////////////////////////////////////////
bool UBPNode_GenericVariablesSetValue::AdditionalExpand(FKismetCompilerContext& CompilerContext, UK2Node_CallFunction* nodeFunction)
{
    bool bSucceeded = true;
    //connect exe
    {
        UEdGraphPin* SpawnExecPin = GetExecPin();
        UEdGraphPin* CallExecPin = nodeFunction->GetExecPin();
        bSucceeded &= SpawnExecPin && CallExecPin && CompilerContext.MovePinLinksToIntermediate(*SpawnExecPin, *CallExecPin).CanSafeConnect();
    }

    // connect then
    {
        UEdGraphPin* SpawnThenPin = GetThenPin();
        UEdGraphPin* CallThenPin = nodeFunction->GetThenPin();
        bSucceeded &= SpawnThenPin && CallThenPin && CompilerContext.MovePinLinksToIntermediate(*SpawnThenPin, *CallThenPin).CanSafeConnect();
    }

    return bSucceeded;
}

//////////////////////////////////////////////////////////////////////////
UEdGraphPin* UBPNode_GenericVariablesSetValue::GetVariableValuePin() const
{
    UEdGraphPin* Pin = FindPinChecked(PN_InputValue);
    check(Pin->Direction == EGPD_Input);
    return Pin;
}

//////////////////////////////////////////////////////////////////////////
UK2Node_CallFunction* UBPNode_GenericVariablesSetValue::CreateSpecificNode(FName VariableClassName, FKismetCompilerContext& CompilerContext, UEdGraph* SourceGraph)
{
    UK2Node_CallFunction* resultCreateNode = nullptr;
    resultCreateNode = CompilerContext.SpawnIntermediateNode<UK2Node_CallFunction>(this, SourceGraph);

    #include "VariablesSystem/Generated/Node/CreateSpecificNodeSet.h"

    resultCreateNode->AllocateDefaultPins();
    return resultCreateNode;
}

//////////////////////////////////////////////////////////////////////////
UEdGraphPin* UBPNode_GenericVariablesSetValue::GetVariableLinkPin(UK2Node_CallFunction* nodeFunction) const
{
    return nodeFunction->FindPin(TEXT("_value"));
}

//////////////////////////////////////////////////////////////////////////
UEdGraphPin* UBPNode_GenericVariablesSetValue::GetThenPin()const
{
    UEdGraphPin* Pin = FindPinChecked(UEdGraphSchema_K2::PN_Then);
    check(Pin->Direction == EGPD_Output);
    return Pin;
}

#undef LOCTEXT_NAMESPACE