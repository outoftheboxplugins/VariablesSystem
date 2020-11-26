using System;
using System.Linq;
using System.Collections.Generic;

public class VariableGenerator
{
    public static Dictionary<System.Type, GlobalVariable> GenerateAllVariables()
    {
        Dictionary<System.Type, GlobalVariable> result = new Dictionary<Type, GlobalVariable>();

        Type[] variablesTypesList = (from domainAssembly in AppDomain.CurrentDomain.GetAssemblies()
                                            from assemblyType in domainAssembly.GetTypes()
                                            where typeof(BaseVariable).IsAssignableFrom(assemblyType)
                                            select assemblyType).ToArray();

        foreach (Type variable in variablesTypesList)
        {
            Attribute[] attrs = Attribute.GetCustomAttributes(variable);

            foreach (Attribute attr in attrs)
            {
                if (attr is GlobalVariable)
                {
                    GlobalVariable globalVariableAttribute = attr as GlobalVariable;
                    result.Add(variable, globalVariableAttribute);
                }
            }
        }

        return result;
    }
}