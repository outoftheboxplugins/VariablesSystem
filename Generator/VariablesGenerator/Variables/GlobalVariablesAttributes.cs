using System;

public class GlobalVariable
{
	public DebugInfoAttribute debugInfo;
	public GlobalVarAttribute globalVariable;
	public GenerateExtraAttribute extraGeneration;
}

[AttributeUsage(AttributeTargets.Class)]  
public class GlobalVarAttribute : Attribute
{
	const string DefaultNodeSubType = "::StaticClass()";

    public string valueType;
    public string defaultValue;
    public string nodeType;
    public string nodeSubType;
    public string nodeContainer;

	public GlobalVarAttribute(string valueType,
		string defaultValue = "0", 
		string nodeType = "Object", 
		string nodeSubType = DefaultNodeSubType, 
		string nodeContainer = "None")
    {
		if(nodeSubType == DefaultNodeSubType)
		{
			nodeSubType = valueType + nodeSubType;
		}

        this.valueType = valueType;
        this.defaultValue = defaultValue;
        this.nodeType = nodeType;
        this.nodeSubType = nodeSubType;
        this.nodeContainer = nodeContainer;
    }
}

[AttributeUsage(AttributeTargets.Class)]
public class GenerateExtraAttribute : Attribute
{
	public bool generateSaveLoad = true;
	public bool generateArray = true;

	public GenerateExtraAttribute(bool implementSaveLoad = true, bool generateArray = false)
	{
		this.generateSaveLoad = implementSaveLoad;
		this.generateArray = generateArray;
	}
}

[AttributeUsage(AttributeTargets.Class)]
public class DebugInfoAttribute : Attribute
{
    public string toStringFunction;

	public DebugInfoAttribute(string toStringFunction = "Item->GetName()")
	{
		this.toStringFunction = toStringFunction;
	}
}