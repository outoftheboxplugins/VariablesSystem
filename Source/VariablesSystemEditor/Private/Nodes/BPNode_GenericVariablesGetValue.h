// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "VariablesSystemEditor/Private/Nodes/BPNode_GenericVariablesBase.h"

#include "BPNode_GenericVariablesGetValue.generated.h"

class UEdGraphPin;
class UK2Node_CallFunction;

UCLASS(MinimalAPI, meta = (Keywords = "variable value global get"))
class UBPNode_GenericVariablesGetValue : public UBPNode_GenericVariablesBase
{
    GENERATED_BODY()

//UEdGraphNode implementation
public:    
    virtual void AllocateDefaultPins() override;
    virtual FText GetNodeTitle(ENodeTitleType::Type TitleType) const override;
    virtual FText GetTooltipText() const override;
    
//K2Node implementation
public:
    virtual bool IsNodePure() const override { return true; }
    
// Generic Overrides
private:
    virtual UEdGraphPin* GetVariableValuePin() const override;
    virtual UEdGraphPin* GetVariableLinkPin(UK2Node_CallFunction* nodeFunction) const override;

    virtual UK2Node_CallFunction* CreateSpecificNode(FName VariableClassName, FKismetCompilerContext& CompilerContext, UEdGraph* SourceGraph) override;
};