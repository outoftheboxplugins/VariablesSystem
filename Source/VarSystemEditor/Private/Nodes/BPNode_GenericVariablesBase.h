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
    virtual FText GetNodeTitle(ENodeTitleType::Type TitleType) const override;
    virtual FText GetTooltipText() const override;
    //UEdGraphNode implementation

    //K2Node implementation
    virtual FText GetMenuCategory() const override;
    virtual void GetMenuActions(FBlueprintActionDatabaseRegistrar& ActionRegistrar) const override;
    
    virtual void PostReconstructNode() override;
    virtual void NotifyPinConnectionListChanged(UEdGraphPin* Pin) override;
    virtual void PinDefaultValueChanged(UEdGraphPin* Pin) override;

    virtual bool IsNodePure() const override { return true; }
    virtual void ExpandNode(class FKismetCompilerContext& CompilerContext, UEdGraph* SourceGraph) override;
    /*virtual void PinTypeChanged(UEdGraphPin* Pin) override;*/
    //K2Node implementation

private:
    //Generated Methods
    UK2Node_CallFunction* CreateSpecificNode(FName VariableClassName, FKismetCompilerContext& CompilerContext, UEdGraph* SourceGraph);
    FEdGraphPinType GetPinTypeFromVariable();

    // Information about current node
    FName GetVariableNameToUse() const;
    void PropagatePinType(FEdGraphPinType& InType);

    // Pin Getter
    UEdGraphPin* GetVariablePin() const;
    UEdGraphPin* GetResultPin() const;

};