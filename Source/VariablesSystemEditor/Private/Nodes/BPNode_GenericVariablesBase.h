// Copyright Out-of-the-Box Plugins 2018-2021. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "K2Node.h"

#include "BPNode_GenericVariablesBase.generated.h"

class FBlueprintActionDatabaseRegistrar;
class UEdGraphPin;
class UK2Node_CallFunction;

UCLASS(Abstract)
class UBPNode_GenericVariablesBase : public UK2Node
{
    GENERATED_BODY()

//UEdGraphNode implementation
protected:
    virtual void AllocateDefaultPins() override;
	virtual void GetMenuActions(FBlueprintActionDatabaseRegistrar& ActionRegistrar) const override;

//K2Node implementation
private:
    virtual void PostReconstructNode() override;
    virtual void PinDefaultValueChanged(UEdGraphPin* Pin) override;
    virtual void NotifyPinConnectionListChanged(UEdGraphPin* Pin) override;
    virtual void ExpandNode(class FKismetCompilerContext& CompilerContext, UEdGraph* SourceGraph) override;

    virtual FText GetMenuCategory() const override;
    
// Virtuals for specific behavior (Get/Set)
protected:
	virtual bool AdditionalExpand(FKismetCompilerContext& CompilerContext, UK2Node_CallFunction* nodeFunction) { return true; }
	virtual UK2Node_CallFunction* CreateSpecificNode(FName VariableClassName, FKismetCompilerContext& CompilerContext, UEdGraph* SourceGraph) { return nullptr; }

	virtual UEdGraphPin* GetVariableValuePin() const { return nullptr; }
	virtual UEdGraphPin* GetVariableLinkPin(UK2Node_CallFunction* nodeFunction) const { return nullptr; }

//Generated Methods
private:
    void UpdatePinTypeFromVariable();

// Utility functionality
private:
    FName GetVariableNameToUse() const;

	bool IsGlobalVariable(FName VariableName) const;
	bool IsInstancedVariable(FName VariableName) const;

    UEdGraphPin* GetVariablePin() const;
    UEdGraphPin* GetVariableOwnerPin() const;

    void PropagatePinType(FEdGraphPinType& InType, EPinContainerType containerType);
    bool CheckForCompilationErrors(FName VariableClassName, FKismetCompilerContext& CompilerContext) const;
};
