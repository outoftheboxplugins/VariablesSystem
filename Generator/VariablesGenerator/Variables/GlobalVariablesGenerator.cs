// Copyright Out-of-the-Box Plugins 2018-2021. All Rights Reserved.

using System;
using System.Linq;

using VariableEntry = System.Collections.Generic.KeyValuePair<string, GlobalVariable>;
using VariableList = System.Collections.Generic.Dictionary<string, GlobalVariable>;

public class VariableGenerator
{
	public static VariableEntry GenerateArrayClass(VariableEntry variablePair)
	{
		GlobalVariable globalVariable = variablePair.Value;
		GlobalVariable globalArrayVariable = (GlobalVariable) globalVariable.Clone();
		
		// Prevent generating arrays based on arrays.
		globalArrayVariable.extraGeneration.generateArray = false;
		globalArrayVariable.globalVariable.ToArray();

		string newName = variablePair.Key.Replace("Variable", "ArrayVariable");

		return new VariableEntry(newName, globalArrayVariable);
	}

	public static VariableList GetArrayVariable(VariableList keyValuePairs)
	{
		VariableList arrayVariables = new VariableList();
		foreach (var pair in keyValuePairs)
		{
			if (pair.Value.extraGeneration != null && pair.Value.extraGeneration.generateArray)
			{
				VariableEntry arrayVariable = GenerateArrayClass(pair);
				arrayVariables.Add(arrayVariable.Key, arrayVariable.Value);
			}
		}

		return arrayVariables;
	}

	public static VariableList GenerateAllVariables()
    {
        VariableList result = new VariableList();

        Type[] variablesTypesList = (from domainAssembly in AppDomain.CurrentDomain.GetAssemblies()
                                            from assemblyType in domainAssembly.GetTypes()
                                            where typeof(BaseVariable).IsAssignableFrom(assemblyType)
                                            select assemblyType).ToArray();

        
		foreach (Type variable in variablesTypesList)
        {
			GlobalVariable globalVariable = new GlobalVariable();

            Attribute[] attrs = Attribute.GetCustomAttributes(variable);

			foreach (Attribute attr in attrs)
            {
				if (attr is GlobalVarAttribute)
                {
					globalVariable.globalVariable = attr as GlobalVarAttribute;
                }

				if(attr is GenerateExtraAttribute)
				{
					globalVariable.extraGeneration = attr as GenerateExtraAttribute;
				}

				if(attr is DebugInfoAttribute)
				{
					globalVariable.debugInfo = attr as DebugInfoAttribute;
				}
            }

			if(globalVariable.globalVariable != null)
			{
				result.Add(variable.Name, globalVariable);
			}
		}

		VariableList arrayVariablesList = GetArrayVariable(result);

		foreach(VariableEntry arrayEntry in arrayVariablesList)
		{
			result.Add(arrayEntry.Key, arrayEntry.Value);
		}

		return result;
	}
}