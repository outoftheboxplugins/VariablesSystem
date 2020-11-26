using System;

[System.AttributeUsage(System.AttributeTargets.Class)]  
public class GlobalVariable  : System.Attribute  
{  
    public string valueType;
    public string defaultValue;
    public string nodeType;
    public string nodeSubType;
    public string nodeContainer;
    public string toStringFunction;
  
    public GlobalVariable(string valueType, string defaultValue, string nodeType, string nodeSubType, string nodeContainer, string toStringFunction)
    {
        this.valueType = valueType;
        this.defaultValue = defaultValue;
        this.nodeType = nodeType;
        this.nodeSubType = nodeSubType;
        this.nodeContainer = nodeContainer;
        this.toStringFunction = toStringFunction;
    }

    public override string ToString()
    {
        return base.ToString() + " - " + valueType + " " + defaultValue + " " + nodeType + " " + nodeSubType + " " + toStringFunction;
    }
}  