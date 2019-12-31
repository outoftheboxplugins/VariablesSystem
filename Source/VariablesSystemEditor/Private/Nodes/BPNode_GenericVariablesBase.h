// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

#pragma once

#include "Core/Public/CoreMinimal.h"
#include "BlueprintGraph/Classes/K2Node.h"

#include "BPNode_GenericVariablesBase.generated.h"

class FBlueprintActionDatabaseRegistrar;
class UEdGraphPin;
class UK2Node_CallFunction;

UCLASS(MinimalAPI, meta = (Keywords = "variable value global"))
class UBPNode_GenericVariablesBase : public UK2Node
{
    GENERATED_BODY()

//UEdGraphNode implementation
public:
    virtual void AllocateDefaultPins() override;

//K2Node implementation
public:
    virtual void GetMenuActions(FBlueprintActionDatabaseRegistrar& ActionRegistrar) const override;
    virtual FText GetMenuCategory() const override;
    
    virtual void PostReconstructNode() override;
    virtual void NotifyPinConnectionListChanged(UEdGraphPin* Pin) override;
    virtual void PinDefaultValueChanged(UEdGraphPin* Pin) override;

    virtual void ExpandNode(class FKismetCompilerContext& CompilerContext, UEdGraph* SourceGraph) override;
    
// Virtuals for specific behavior (Get/Set)
protected:
    // Nodes Details
    virtual bool AdditionalExpand(FKismetCompilerContext& CompilerContext, UK2Node_CallFunction* nodeFunction) { return true; };

    //Generated Methods
    virtual UK2Node_CallFunction* CreateSpecificNode(FName VariableClassName, FKismetCompilerContext& CompilerContext, UEdGraph* SourceGraph);
    FEdGraphPinType GetPinTypeFromVariable();

// Current node utility
private:
    // Information about current node
    FName GetVariableNameToUse() const;
    void PropagatePinType(FEdGraphPinType& InType);

    // Pin Getter
    virtual UEdGraphPin* GetVariableValuePin() const;
    virtual UEdGraphPin* GetVariableLinkPin(UK2Node_CallFunction* nodeFunction) const;

    enum EGenericVariablesNodeError
    {
        None,
        UnkownType,
        GlobalHasOwner,
        LocalMissingOwner,

    };

    EGenericVariablesNodeError CompileVariablesCompatbility(FName VariableClassName) const;

    UEdGraphPin* GetVariablePin() const;
    UEdGraphPin* GetVariableOwnerPin() const;
};
