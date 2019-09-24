#pragma once

#include "CoreMinimal.h"
#include "K2Node.h"
#include "BPNode_GenericVariablesBase.generated.h"

class FBlueprintActionDatabaseRegistrar;
class UEdGraphPin;
class UK2Node_CallFunction;
class UBaseVariable;

UCLASS(MinimalAPI, meta = (Keywords = "variable value"))
class UBPNode_GenericVariablesBase : public UK2Node
{
    GENERATED_BODY()
public:

    //UEdGraphNode implementation
    virtual void AllocateDefaultPins() override;
    //UEdGraphNode implementation

    //K2Node implementation
    virtual void GetMenuActions(FBlueprintActionDatabaseRegistrar& ActionRegistrar) const override;
    
    virtual void PostReconstructNode() override;
    virtual void NotifyPinConnectionListChanged(UEdGraphPin* Pin) override;
    virtual void PinDefaultValueChanged(UEdGraphPin* Pin) override;

    virtual void ExpandNode(class FKismetCompilerContext& CompilerContext, UEdGraph* SourceGraph) override;
    //K2Node implementation

private:
    // Nodes Detaisl
    virtual bool AdditionalExpand(FKismetCompilerContext& CompilerContext, UK2Node_CallFunction* nodeFunction) { return true; };

    //Generated Methods
    virtual UK2Node_CallFunction* CreateSpecificNode(FName VariableClassName, FKismetCompilerContext& CompilerContext, UEdGraph* SourceGraph);
    FEdGraphPinType GetPinTypeFromVariable();

    // Information about current node
    FName GetVariableNameToUse() const;
    void PropagatePinType(FEdGraphPinType& InType);

    // Pin Getter
    virtual UEdGraphPin* GetVariableValuePin() const;
    virtual UEdGraphPin* GetVariableLinkPin(UK2Node_CallFunction* nodeFunction) const;
    UEdGraphPin* GetVariablePin() const;
};
