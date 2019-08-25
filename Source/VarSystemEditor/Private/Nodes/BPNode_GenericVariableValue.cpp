#include "BPNode_GenericVariableValue.h"

#include "KismetCompiler.h"
#include "BlueprintActionDatabaseRegistrar.h"
#include "BlueprintNodeSpawner.h"
#include "K2Node_CallFunction.h"

#include "BPNode_GenericVariableValue.h"
#include "EdGraph/EdGraphPin.h"
#include "GraphEditorSettings.h"
#include "EdGraphSchema_K2.h"
#include "EdGraphUtilities.h"
#include "KismetCompilerMisc.h"
#include "KismetCompiler.h"
#include "BlueprintNodeSpawner.h"
#include "EditorCategoryUtils.h"
#include "BlueprintActionDatabaseRegistrar.h"
#include "VarSystem\Public\BaseVariable.h"
#include "KismetCompiler.h"
#include "BlueprintActionDatabaseRegistrar.h"
#include "BlueprintNodeSpawner.h"
#include "K2Node_CallFunction.h"
#include "Kismet2/BlueprintEditorUtils.h"
#include "Misc/AssertionMacros.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/UObjectGlobals.h"

#include"Generator/Generated/Node/IncludeAll.h"

#pragma optimize("", off)

#define LOCTEXT_NAMESPACE "K2Node_Tutorial"

struct FGetPinName {
    static const FName& GetVariableTextPin() {
        static const FName VariableTextPin(TEXT("VariableToReference"));
        return VariableTextPin;
    }
};

void UBPNode_GenericVariableValue::AllocateDefaultPins()
{
    const UEdGraphSchema_K2* K2Schema = GetDefault<UEdGraphSchema_K2>();
    
    UEdGraphPin* InVariablePin = CreatePin(EGPD_Input, UEdGraphSchema_K2::PC_Object, UBaseVariable::StaticClass(), FGetPinName::GetVariableTextPin());
    UEdGraphPin* ResultPin = CreatePin(EGPD_Output, UEdGraphSchema_K2::PC_Wildcard, UEdGraphSchema_K2::PN_ReturnValue);

    Super::AllocateDefaultPins();
}

FText UBPNode_GenericVariableValue::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
    return LOCTEXT("GetVariableValue", "GetVariableValue");
}

FText UBPNode_GenericVariableValue::GetTooltipText() const
{
    return LOCTEXT("GetVariableValue_Tooltip", "Return the value of a Generic Variable");
}

FText UBPNode_GenericVariableValue::GetMenuCategory() const
{
    return LOCTEXT("GetVariableValue_Category", "Variables System");
}

void UBPNode_GenericVariableValue::ExpandNode(class FKismetCompilerContext& CompilerContext, UEdGraph* SourceGraph)
{
    Super::ExpandNode(CompilerContext, SourceGraph);


    // Create the specific function node to the variable.
    FName VariableName = GetVariableNameToUse();
    UK2Node_CallFunction* CallCreateNode = CreateSpecificNode(VariableName, CompilerContext, SourceGraph);

    if (CallCreateNode == nullptr)
    {
        return;
    }

    bool bSucceeded = true;

    {
        UEdGraphPin* SpawnClassPin = GetClassPin();
        UEdGraphPin* CallClassPin = CallCreateNode->FindPin(TEXT("var"));
        bSucceeded &= SpawnClassPin && CallClassPin && CompilerContext.CopyPinLinksToIntermediate(*SpawnClassPin, *CallClassPin).CanSafeConnect();
    }

    {
        UEdGraphPin* ResultPin = GetResultPin();
        UEdGraphPin* ReturnPin = CallCreateNode->GetReturnValuePin();
        bSucceeded &= ResultPin && ReturnPin && CompilerContext.MovePinLinksToIntermediate(*ResultPin, *ReturnPin).CanSafeConnect();
    }

    BreakAllNodeLinks();

    if (!bSucceeded)
    {
        CompilerContext.MessageLog.Error(*LOCTEXT("GenericCreateObject_Error", "ICE: GenericCreateObject error @@").ToString(), this);
    }
}

UK2Node_CallFunction* UBPNode_GenericVariableValue::CreateSpecificNode(FName VariableClassName, FKismetCompilerContext& CompilerContext, UEdGraph* SourceGraph)
{
    UK2Node_CallFunction* resultCreateNode = nullptr;
    resultCreateNode = CompilerContext.SpawnIntermediateNode<UK2Node_CallFunction>(this, SourceGraph);

    #include"Generator/Generated/Node/CreateSpecificNode.h"

    resultCreateNode->AllocateDefaultPins();
    return resultCreateNode;
}

//This method adds our node to the context menu
void UBPNode_GenericVariableValue::GetMenuActions(FBlueprintActionDatabaseRegistrar& ActionRegistrar) const
{
    Super::GetMenuActions(ActionRegistrar);

    UClass* Action = GetClass();

    if (ActionRegistrar.IsOpenForRegistration(Action)) {
        UBlueprintNodeSpawner* Spawner = UBlueprintNodeSpawner::Create(GetClass());
        check(Spawner != nullptr);

        ActionRegistrar.AddBlueprintAction(Action, Spawner);
    }
}

UEdGraphPin* UBPNode_GenericVariableValue::GetVariablePin() const
{
    UEdGraphPin* Pin = FindPin(FGetPinName::GetVariableTextPin());
    ensure(nullptr == Pin || Pin->Direction == EGPD_Input);
    return Pin;
}

UBaseVariable* UBPNode_GenericVariableValue::GetVariableToUse(const TArray<UEdGraphPin*>* InPinsToSearch /*=NULL*/) const
{
    UBaseVariable* VariableToSpawn = nullptr;
    const TArray<UEdGraphPin*>* PinsToSearch = InPinsToSearch ? InPinsToSearch : &Pins;

    UEdGraphPin* ClassPin = GetClassPin(PinsToSearch);
    if (ClassPin && ClassPin->DefaultObject && ClassPin->LinkedTo.Num() == 0)
    {
        VariableToSpawn = CastChecked<UBaseVariable>(ClassPin->DefaultObject);
    }
    else if (ClassPin && ClassPin->LinkedTo.Num())
    {
        UEdGraphPin* ClassSource = ClassPin->LinkedTo[0];
        VariableToSpawn = ClassSource ? Cast<UBaseVariable>(ClassSource->PinType.PinSubCategoryObject.Get()) : nullptr;
    }

    return VariableToSpawn;
}

FName UBPNode_GenericVariableValue::GetVariableNameToUse() const 
{
    FName VariableClassName;
    UEdGraphPin* ClassPin = GetClassPin(&Pins);

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

UEdGraphPin* UBPNode_GenericVariableValue::GetClassPin(const TArray<UEdGraphPin*>* InPinsToSearch /*= NULL*/) const
{
    const TArray<UEdGraphPin*>* PinsToSearch = InPinsToSearch ? InPinsToSearch : &Pins;

    UEdGraphPin* Pin = nullptr;
    for (UEdGraphPin* TestPin : *PinsToSearch)
    {
        if (TestPin && TestPin->PinName == FGetPinName::GetVariableTextPin())
        {
            Pin = TestPin;
            break;
        }
    }
    check(Pin == nullptr || Pin->Direction == EGPD_Input);
    return Pin;
}

UEdGraphPin* UBPNode_GenericVariableValue::GetResultPin() const
{
    UEdGraphPin* Pin = FindPinChecked(UEdGraphSchema_K2::PN_ReturnValue);
    check(Pin->Direction == EGPD_Output);
    return Pin;
}

void UBPNode_GenericVariableValue::PostReconstructNode()
{
    //TODO: we need to call this method with the node pin type we want.

    PropagatePinType(GetResultPin()->PinType);
}

FEdGraphPinType UBPNode_GenericVariableValue::GetPinTypeFromVariable()
{
    FName VariableClassName = GetVariableNameToUse();

    FEdGraphPinType ResultPinType;

    #include"Generator/Generated/Node/PinTypeFromVariable.h"

    return ResultPinType;
}

/** Determine if any pins are connected, if so make all the other pins the same type, if not, make sure pins are switched back to wildcards */
void UBPNode_GenericVariableValue::NotifyPinConnectionListChanged(UEdGraphPin* Pin)
{
    Super::NotifyPinConnectionListChanged(Pin);

    if (Pin->ParentPin == nullptr)
    {
        UEdGraphPin* ResultPin = GetVariablePin();

        if (ResultPin == Pin)
        {
            FEdGraphPinType pinType = GetPinTypeFromVariable();
            PropagatePinType(pinType);
        }
    }
}

void UBPNode_GenericVariableValue::PinDefaultValueChanged(UEdGraphPin* Pin)
{
    Super::PinDefaultValueChanged(Pin);

    if (Pin->ParentPin == nullptr)
    {
        UEdGraphPin* ResultPin = GetVariablePin();

        if (ResultPin == Pin)
        {
            FEdGraphPinType pinType = GetPinTypeFromVariable();
            PropagatePinType(pinType);
        }
    }
}

void UBPNode_GenericVariableValue::PinTypeChanged(UEdGraphPin* Pin)
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

void UBPNode_GenericVariableValue::PropagatePinType(FEdGraphPinType& InType)
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

#undef LOCTEXT_NAMESPACE

#pragma optimize("", on)
