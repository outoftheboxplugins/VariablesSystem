// Copyright Out-of-the-Box Plugins 2018-2020. All Rights Reserved.

using System;
using System.Linq;
using System.Collections.Generic;

public class VariableGenerator
{
	public static KeyValuePair<string, GlobalVariable> GenerateArrayClass(KeyValuePair<string, GlobalVariable> variablePair)
	{
		GlobalVariable globalVariable = variablePair.Value;
		GlobalVariable globalArrayVariable = (GlobalVariable) globalVariable.Clone();
		
		// Prevent generating arrays based on arrays.
		globalArrayVariable.extraGeneration.generateArray = false;
		globalArrayVariable.globalVariable.ToArray();

		string newName = variablePair.Key.Replace("Variable", "ArrayVariable");

		return new KeyValuePair<string, GlobalVariable>(newName, globalArrayVariable);
	}

	public static Dictionary<string, GlobalVariable> GenerateAllVariables()
    {
        Dictionary<string, GlobalVariable> result = new Dictionary<string, GlobalVariable>();

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


		foreach(var pair in  result)
		{
			if(pair.Value.extraGeneration != null && pair.Value.extraGeneration.generateArray)
			{
				result.Append(GenerateArrayClass(pair));
			}
		}

        return result;
    }
}