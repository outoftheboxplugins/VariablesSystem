// Copyright Out-of-the-Box Plugins 2018-2020. All Rights Reserved.

#pragma once

#include "BPNode_GenericVariablesBase.h"

#include "BPNode_GenericVariablesGetValue.generated.h"

UCLASS(MinimalAPI, meta = (Keywords = "variable value global instanced get"))
class UBPNode_GenericVariablesGetValue : public UBPNode_GenericVariablesBase
{
    GENERATED_BODY()

//UEdGraphNode implementation
public:    
    virtual void AllocateDefaultPins() override;
    virtual FText GetNodeTitle(ENodeTitleType::Type TitleType) const override;
    virtual FText GetTooltipText() const override;

// Generic Overrides
private:
    virtual UEdGraphPin* GetVariableValuePin() const override;
    virtual UEdGraphPin* GetVariableLinkPin(UK2Node_CallFunction* nodeFunction) const override;

    virtual UK2Node_CallFunction* CreateSpecificNode(FName VariableClassName, FKismetCompilerContext& CompilerContext, UEdGraph* SourceGraph) override;
    
//K2Node implementation
public:
    virtual bool IsNodePure() const override { return true; }
    
};