#pragma once

#include "CoreMinimal.h"
#include "VariablesSystemEditor/Private/Nodes/BPNode_GenericVariablesBase.h"

#include "BPNode_GenericVariablesGetValue.generated.h"

class FBlueprintActionDatabaseRegistrar;
class UEdGraphPin;
class UK2Node_CallFunction;
class UBaseVariable;

UCLASS(MinimalAPI, meta = (Keywords = "variable value"))
class UBPNode_GenericVariablesGetValue : public UBPNode_GenericVariablesBase
{
    GENERATED_BODY()
public:

    //UEdGraphNode implementation
    virtual void AllocateDefaultPins() override;
    virtual FText GetNodeTitle(ENodeTitleType::Type TitleType) const override;
    virtual FText GetTooltipText() const override;
    //UEdGraphNode implementation

    //K2Node implementation
    virtual bool IsNodePure() const override { return true; }
    virtual FText GetMenuCategory() const override;
    //K2Node implementation

private:
    virtual UEdGraphPin* GetVariableValuePin() const override;

    virtual UK2Node_CallFunction* CreateSpecificNode(FName VariableClassName, FKismetCompilerContext& CompilerContext, UEdGraph* SourceGraph) override;
    virtual UEdGraphPin* GetVariableLinkPin(UK2Node_CallFunction* nodeFunction) const override;
};