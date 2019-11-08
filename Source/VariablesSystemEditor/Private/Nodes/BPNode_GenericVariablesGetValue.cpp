#include "BPNode_GenericVariablesGetValue.h"

#include "VariablesSystem/Generated/Library/IncludeAll.h"
#include "K2Node_CallFunction.h"
#include "KismetCompiler.h"
#include "BlueprintActionDatabaseRegistrar.h"
#include "BlueprintNodeSpawner.h"
#include "Kismet2/BlueprintEditorUtils.h"

#define LOCTEXT_NAMESPACE "VariablesSystem"


//////////////////////////////////////////////////////////////////////////
void UBPNode_GenericVariablesGetValue::AllocateDefaultPins()
{
    const UEdGraphSchema_K2* K2Schema = GetDefault<UEdGraphSchema_K2>();

    UEdGraphPin* ResultPin = CreatePin(EGPD_Output, UEdGraphSchema_K2::PC_Wildcard, UEdGraphSchema_K2::PN_ReturnValue);

    Super::AllocateDefaultPins();
}

FText UBPNode_GenericVariablesGetValue::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
    return LOCTEXT("GetVariableValue", "GetVariableValue");
}

FText UBPNode_GenericVariablesGetValue::GetTooltipText() const
{
    return LOCTEXT("GetVariableValue_Tooltip", "Return the value of a Generic Variable");
}

//////////////////////////////////////////////////////////////////////////
FText UBPNode_GenericVariablesGetValue::GetMenuCategory() const
{
    return LOCTEXT("GetVariableValue_Category", "Variables System");
}

UEdGraphPin* UBPNode_GenericVariablesGetValue::GetVariableValuePin() const
{
    UEdGraphPin* Pin = FindPinChecked(UEdGraphSchema_K2::PN_ReturnValue);
    check(Pin->Direction == EGPD_Output);
    return Pin;
}

//////////////////////////////////////////////////////////////////////////
UK2Node_CallFunction* UBPNode_GenericVariablesGetValue::CreateSpecificNode(FName VariableClassName, FKismetCompilerContext& CompilerContext, UEdGraph* SourceGraph)
{
    UK2Node_CallFunction* resultCreateNode = nullptr;
    resultCreateNode = CompilerContext.SpawnIntermediateNode<UK2Node_CallFunction>(this, SourceGraph);

    #include "VariablesSystem/Generated/Node/CreateSpecificNodeGet.h"

    resultCreateNode->AllocateDefaultPins();
    return resultCreateNode;
}

UEdGraphPin* UBPNode_GenericVariablesGetValue::GetVariableLinkPin(UK2Node_CallFunction* nodeFunction) const
{
    return nodeFunction->GetReturnValuePin();
}

#undef LOCTEXT_NAMESPACE