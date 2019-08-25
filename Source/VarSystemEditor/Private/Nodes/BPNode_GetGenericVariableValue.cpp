#include "BPNode_GetGenericVariableValue.h"

#include "Generator/Generated/Node/IncludeAll.h"
#include "K2Node_CallFunction.h"
#include "KismetCompiler.h"
#include "BlueprintActionDatabaseRegistrar.h"
#include "BlueprintNodeSpawner.h"
#include "BlueprintEditorUtils.h"

#define LOCTEXT_NAMESPACE "K2Node_GenericVariableValue"

struct FGetPinName {
    static const FName& GetVariableTextPin() {
        static const FName VariableTextPin(TEXT("VariableToReference"));
        return VariableTextPin;
    }
};

//////////////////////////////////////////////////////////////////////////
void UBPNode_GetGenericVariableValue::AllocateDefaultPins()
{
    const UEdGraphSchema_K2* K2Schema = GetDefault<UEdGraphSchema_K2>();
    
    UEdGraphPin* InVariablePin = CreatePin(EGPD_Input, UEdGraphSchema_K2::PC_Object, UBaseVariable::StaticClass(), FGetPinName::GetVariableTextPin());
    UEdGraphPin* ResultPin = CreatePin(EGPD_Output, UEdGraphSchema_K2::PC_Wildcard, UEdGraphSchema_K2::PN_ReturnValue);

    Super::AllocateDefaultPins();
}

FText UBPNode_GetGenericVariableValue::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
    return LOCTEXT("GetVariableValue", "GetVariableValue");
}

FText UBPNode_GetGenericVariableValue::GetTooltipText() const
{
    return LOCTEXT("GetVariableValue_Tooltip", "Return the value of a Generic Variable");
}

//////////////////////////////////////////////////////////////////////////
FText UBPNode_GetGenericVariableValue::GetMenuCategory() const
{
    return LOCTEXT("GetVariableValue_Category", "Variables System");
}

void UBPNode_GetGenericVariableValue::GetMenuActions(FBlueprintActionDatabaseRegistrar& ActionRegistrar) const
{
    Super::GetMenuActions(ActionRegistrar);

    UClass* Action = GetClass();

    if (ActionRegistrar.IsOpenForRegistration(Action)) {
        UBlueprintNodeSpawner* Spawner = UBlueprintNodeSpawner::Create(GetClass());
        check(Spawner != nullptr);

        ActionRegistrar.AddBlueprintAction(Action, Spawner);
    }
}

//////////////////////////////////////////////////////////////////////////
void UBPNode_GetGenericVariableValue::PostReconstructNode()
{
    Super::PostReconstructNode();

    FEdGraphPinType pinType = GetPinTypeFromVariable();
    PropagatePinType(pinType);
}

void UBPNode_GetGenericVariableValue::NotifyPinConnectionListChanged(UEdGraphPin* Pin)
{
    Super::NotifyPinConnectionListChanged(Pin);

    if (Pin->ParentPin == nullptr)
    {
        UEdGraphPin* VariablePin = GetVariablePin();

        if (VariablePin == Pin)
        {
            FEdGraphPinType pinType = GetPinTypeFromVariable();
            PropagatePinType(pinType);
        }
    }
}

void UBPNode_GetGenericVariableValue::PinDefaultValueChanged(UEdGraphPin* Pin)
{
    Super::PinDefaultValueChanged(Pin);

    if (Pin->ParentPin == nullptr)
    {
        UEdGraphPin* VariablePin = GetVariablePin();

        if (VariablePin == Pin)
        {
            FEdGraphPinType pinType = GetPinTypeFromVariable();
            PropagatePinType(pinType);
        }
    }
}

//////////////////////////////////////////////////////////////////////////
void UBPNode_GetGenericVariableValue::ExpandNode(class FKismetCompilerContext& CompilerContext, UEdGraph* SourceGraph)
{
    Super::ExpandNode(CompilerContext, SourceGraph);

    // Create the specific function node to the variable.
    FName VariableName = GetVariableNameToUse();
    UK2Node_CallFunction* CallCreateNode = CreateSpecificNode(VariableName, CompilerContext, SourceGraph);

    bool bSucceeded = true;

    if (CallCreateNode == nullptr)
    {
        bSucceeded = false;
    }

    else
    {
        // Connect Class pin.
        UEdGraphPin* ClassPin = GetVariablePin();
        UEdGraphPin* VariableInput = CallCreateNode->FindPin(TEXT("var"));
        bSucceeded &= ClassPin && VariableInput && CompilerContext.CopyPinLinksToIntermediate(*ClassPin, *VariableInput).CanSafeConnect();

        // Connect Result pin.
        UEdGraphPin* ResultPin = GetResultPin();
        UEdGraphPin* ReturnPin = CallCreateNode->GetReturnValuePin();
        bSucceeded &= ResultPin && ReturnPin && CompilerContext.MovePinLinksToIntermediate(*ResultPin, *ReturnPin).CanSafeConnect();
    }

    BreakAllNodeLinks();

    if (!bSucceeded)
    {
        CompilerContext.MessageLog.Error(*LOCTEXT("GetGenericVariable", "Get Generic Variable function expand failed.").ToString(), this);
    }
}


//TODO: Not sure we need this.
/*
void UBPNode_GetGenericVariableValue::PinTypeChanged(UEdGraphPin* Pin)
{
    const UEdGraphSchema_K2* Schema = GetDefault<UEdGraphSchema_K2>();

    {
        // Set the return value
        UEdGraphPin* ReturnPin = GetResultPin();
        if (ReturnPin->PinType != Pin->PinType)
        {
            // Recombine the sub pins back into the ReturnPin
            if (ReturnPin->SubPins.Num() > 0)
            {
                Schema->RecombinePin(ReturnPin->SubPins[0]);
            }
            ReturnPin->PinType = Pin->PinType;
            Schema->SetPinAutogeneratedDefaultValueBasedOnType(ReturnPin);
        }
    }

    // Let the graph know to refresh
    GetGraph()->NotifyGraphChanged();

    UBlueprint* Blueprint = GetBlueprint();
    if (!Blueprint->bBeingCompiled)
    {
        FBlueprintEditorUtils::MarkBlueprintAsModified(Blueprint);
        Blueprint->BroadcastChanged();
    }
}
*/

//////////////////////////////////////////////////////////////////////////
UK2Node_CallFunction* UBPNode_GetGenericVariableValue::CreateSpecificNode(FName VariableClassName, FKismetCompilerContext& CompilerContext, UEdGraph* SourceGraph)
{
    UK2Node_CallFunction* resultCreateNode = nullptr;
    resultCreateNode = CompilerContext.SpawnIntermediateNode<UK2Node_CallFunction>(this, SourceGraph);

    #include "Generator/Generated/Node/CreateSpecificNode.h"

    resultCreateNode->AllocateDefaultPins();
    return resultCreateNode;
}

FEdGraphPinType UBPNode_GetGenericVariableValue::GetPinTypeFromVariable()
{
    FName VariableClassName = GetVariableNameToUse();

    FEdGraphPinType ResultPinType;

#include "Generator/Generated/Node/PinTypeFromVariable.h"

    return ResultPinType;
}

//////////////////////////////////////////////////////////////////////////
FName UBPNode_GetGenericVariableValue::GetVariableNameToUse() const
{
    FName VariableClassName;
    UEdGraphPin* ClassPin = GetVariablePin();

    if (ClassPin && ClassPin->DefaultObject && ClassPin->LinkedTo.Num() == 0)
    {
        VariableClassName = ClassPin->DefaultObject->GetClass()->GetFName();
    }
    else if (ClassPin && ClassPin->LinkedTo.Num())
    {
        UEdGraphPin* ClassSource = ClassPin->LinkedTo[0];
        VariableClassName = ClassSource->PinType.PinSubCategoryObject->GetFName();
    }

    return VariableClassName;
}

void UBPNode_GetGenericVariableValue::PropagatePinType(FEdGraphPinType& InType)
{
    UClass const* CallingContext = NULL;
    if (UBlueprint const* Blueprint = GetBlueprint())
    {
        CallingContext = Blueprint->GeneratedClass;
        if (CallingContext == NULL)
        {
            CallingContext = Blueprint->ParentClass;
        }
    }

    UEdGraphPin* ResultPin = GetResultPin();

    ResultPin->PinType = InType;
    ResultPin->PinType.ContainerType = EPinContainerType::None;
    ResultPin->PinType.bIsReference = false;

    const UEdGraphSchema_K2* Schema = GetDefault<UEdGraphSchema_K2>();

    // Verify that all previous connections to this pin are still valid with the new type
    for (TArray<UEdGraphPin*>::TIterator ConnectionIt(ResultPin->LinkedTo); ConnectionIt; ++ConnectionIt)
    {
        UEdGraphPin* ConnectedPin = *ConnectionIt;
        if (!Schema->ArePinsCompatible(ResultPin, ConnectedPin, CallingContext))
        {
            ResultPin->BreakLinkTo(ConnectedPin);
        }
    }
}

//////////////////////////////////////////////////////////////////////////
UEdGraphPin* UBPNode_GetGenericVariableValue::GetVariablePin() const
{
    UEdGraphPin* Pin = FindPin(FGetPinName::GetVariableTextPin());
    ensure(nullptr == Pin || Pin->Direction == EGPD_Input);
    return Pin;
}

UEdGraphPin* UBPNode_GetGenericVariableValue::GetResultPin() const
{
    UEdGraphPin* Pin = FindPinChecked(UEdGraphSchema_K2::PN_ReturnValue);
    check(Pin->Direction == EGPD_Output);
    return Pin;
}

#undef LOCTEXT_NAMESPACE