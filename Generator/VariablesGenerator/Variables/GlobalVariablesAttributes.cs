// Copyright Out-of-the-Box Plugins 2018-2021. All Rights Reserved.
using System;

#pragma warning disable CS1717 // Assignment made to same variable

public class GlobalVariable : ICloneable
{
	public DebugInfoAttribute debugInfo;
	public GlobalVarAttribute globalVariable;
	public GenerateExtraAttribute extraGeneration;
	public ExtraIncludeAttribute extraInclude;

	public object Clone()
	{
		GlobalVariable globalVariableClone = (GlobalVariable) MemberwiseClone();

		globalVariableClone.debugInfo		= (DebugInfoAttribute)		debugInfo.Clone();
		globalVariableClone.globalVariable	= (GlobalVarAttribute)		globalVariable.Clone();
		globalVariableClone.extraGeneration = (GenerateExtraAttribute)	extraGeneration.Clone();
		globalVariableClone.extraInclude	= (ExtraIncludeAttribute)	extraInclude.Clone();

		return globalVariableClone;
	}
}

[AttributeUsage(AttributeTargets.Class)]  
public class GlobalVarAttribute : Attribute, ICloneable
{
	const string DefaultNodeSubType = "::StaticClass()";

    public string valueType;
    public string defaultValue;
    public string nodeType;
    public string nodeSubType;
    public string nodeContainer;
	public string assetColor;

	public GlobalVarAttribute(string valueType,
		string defaultValue = "0", 
		string nodeType = "Object", 
		string nodeSubType = DefaultNodeSubType, 
		string nodeContainer = "None",
		string assetColor = "Wildcard")
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
		this.assetColor = assetColor;
    }

	public void ToArray()
	{
		valueType = "TArray<" + valueType + ">";	// FString	-> TArray<FString>
		defaultValue = valueType + "()";            // ""		-> TArray<FString>()

		nodeType = nodeType;                        // String	-> String
		nodeSubType = nodeSubType;                  // ""		-> ""

		nodeContainer = "Array";					// None		-> Array
	}

	public object Clone()
	{
		return MemberwiseClone();
	}
}

[AttributeUsage(AttributeTargets.Class)]
public class GenerateExtraAttribute : Attribute, ICloneable
{
	public bool generateSaveLoad = true;
	public bool generateArray = true;

	public GenerateExtraAttribute(bool implementSaveLoad = true, bool generateArray = false)
	{
		this.generateSaveLoad = implementSaveLoad;
		this.generateArray = generateArray;
	}

	public object Clone()
	{
		return MemberwiseClone();
	}
}

[AttributeUsage(AttributeTargets.Class)]
public class DebugInfoAttribute : Attribute, ICloneable
{
    public string toStringFunction;

	public DebugInfoAttribute(string toStringFunction)
	{
		this.toStringFunction = toStringFunction;
	}

	public object Clone()
	{
		return MemberwiseClone();
	}
}

[AttributeUsage(AttributeTargets.Class)]
public class ExtraIncludeAttribute : Attribute, ICloneable
{
	public string includePath;

	public ExtraIncludeAttribute(string includePath)
	{
		this.includePath = includePath;
	}

	public object Clone()
	{
		return MemberwiseClone();
	}
}