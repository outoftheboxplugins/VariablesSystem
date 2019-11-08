#include "BPNode_GenericVariablesBase.h"

#include "VariablesSystem/Generated/Library/IncludeAll.h"
#include "K2Node_CallFunction.h"
#include "KismetCompiler.h"
#include "BlueprintActionDatabaseRegistrar.h"
#include "BlueprintNodeSpawner.h"
#include "Kismet2/BlueprintEditorUtils.h"

#define LOCTEXT_NAMESPACE "VariablesSystem"


struct FGetPinName {
    static const FName& GetVariableTextPin() {
        static const FName VariableTextPin(TEXT("VariableToReference"));
        return VariableTextPin;
    }
};

//////////////////////////////////////////////////////////////////////////
void UBPNode_GenericVariablesBase::AllocateDefaultPins()
{
    const UEdGraphSchema_K2* K2Schema = GetDefault<UEdGraphSchema_K2>();
    
    UEdGraphPin* InVariablePin = CreatePin(EGPD_Input, UEdGraphSchema_K2::PC_Object, UBaseVariable::StaticClass(), FGetPinName::GetVariableTextPin());

    Super::AllocateDefaultPins();
}

void UBPNode_GenericVariablesBase::GetMenuActions(FBlueprintActionDatabaseRegistrar& ActionRegistrar) const
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
void UBPNode_GenericVariablesBase::PostReconstructNode()
{
    Super::PostReconstructNode();

    FEdGraphPinType pinType = GetPinTypeFromVariable();
    PropagatePinType(pinType);
}

void UBPNode_GenericVariablesBase::NotifyPinConnectionListChanged(UEdGraphPin* Pin)
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

void UBPNode_GenericVariablesBase::PinDefaultValueChanged(UEdGraphPin* Pin)
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
void UBPNode_GenericVariablesBase::ExpandNode(class FKismetCompilerContext& CompilerContext, UEdGraph* SourceGraph)
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
        UEdGraphPin* ResultPin = GetVariableValuePin();
        UEdGraphPin* ReturnPin = GetVariableLinkPin(CallCreateNode);
        bSucceeded &= ResultPin && ReturnPin && CompilerContext.MovePinLinksToIntermediate(*ResultPin, *ReturnPin).CanSafeConnect();
    }

    bSucceeded &= AdditionalExpand(CompilerContext, CallCreateNode);

    BreakAllNodeLinks();

    if (!bSucceeded)
    {
        CompilerContext.MessageLog.Error(*LOCTEXT("GetGenericVariable", "Get Generic Variable function expand failed.").ToString(), this);
    }
}

//////////////////////////////////////////////////////////////////////////
UK2Node_CallFunction* UBPNode_GenericVariablesBase::CreateSpecificNode(FName VariableClassName, FKismetCompilerContext& CompilerContext, UEdGraph* SourceGraph)
{
    return nullptr;
}

FEdGraphPinType UBPNode_GenericVariablesBase::GetPinTypeFromVariable()
{
    FName VariableClassName = GetVariableNameToUse();

    FEdGraphPinType ResultPinType;

    #include "VariablesSystem/Generated/Node/PinTypeFromVariable.h"

    return ResultPinType;
}

//////////////////////////////////////////////////////////////////////////
FName UBPNode_GenericVariablesBase::GetVariableNameToUse() const
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

void UBPNode_GenericVariablesBase::PropagatePinType(FEdGraphPinType& InType)
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

    UEdGraphPin* ResultPin = GetVariableValuePin();

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
UEdGraphPin* UBPNode_GenericVariablesBase::GetVariablePin() const
{
    UEdGraphPin* Pin = FindPin(FGetPinName::GetVariableTextPin());
    ensure(nullptr == Pin || Pin->Direction == EGPD_Input);
    return Pin;
}

UEdGraphPin* UBPNode_GenericVariablesBase::GetVariableValuePin() const
{
    return nullptr;
}

UEdGraphPin* UBPNode_GenericVariablesBase::GetVariableLinkPin(UK2Node_CallFunction* nodeFunction) const
{
    return nullptr;
}

#undef LOCTEXT_NAMESPACE