using System;
using System.Linq;
using System.Collections.Generic;

public class VariableGenerator
{
    public static Dictionary<Type, GlobalVariable> GenerateAllVariables()
    {
        Dictionary<Type, GlobalVariable> result = new Dictionary<Type, GlobalVariable>();

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
				result.Add(variable, globalVariable);
			}

		}

        return result;
    }
}