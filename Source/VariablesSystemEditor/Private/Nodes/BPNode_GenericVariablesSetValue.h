// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "VariablesSystemEditor/Private/Nodes/BPNode_GenericVariablesBase.h"

#include "BPNode_GenericVariablesSetValue.generated.h"

class UEdGraphPin;
class UK2Node_CallFunction;

UCLASS(MinimalAPI, meta = (Keywords = "variable value global get"))
class UBPNode_GenericVariablesSetValue : public UBPNode_GenericVariablesBase
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

    virtual bool AdditionalExpand(FKismetCompilerContext& CompilerContext, UK2Node_CallFunction* nodeFunction) override;
    virtual UK2Node_CallFunction* CreateSpecificNode(FName VariableClassName, FKismetCompilerContext& CompilerContext, UEdGraph* SourceGraph) override;

// Internal helpers
private:
    UEdGraphPin* GetThenPin() const;
};