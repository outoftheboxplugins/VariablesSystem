rmdir "Generated/" /s /q

mkdir "Generated"

"D:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\TextTransform.exe" "E:\projects\CodePlugins\Plugins\VarSystem\Source\VarSystem\Generator\GenericVariableGenerator.tt"

"D:/Program Files/Epic Games/UE_4.22/Engine/Binaries/DotNET/UnrealBuildTool.exe"  -projectfiles -project="E:/projects/CodePlugins/CodePlugins.uproject" -game -rocket -progress

pause