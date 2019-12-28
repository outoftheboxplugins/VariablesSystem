@ECHO OFF
rmdir "../Generated/" /s /q

mkdir "../Generated"

mkdir "../Generated/Node"

mkdir "../Generated/Library"

mkdir "../Generated/Local"

mkdir "../Generated/Global"

"D:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\TextTransform.exe" "E:\CodePlugins\Plugins\VariablesSystem\Source\VariablesSystem\Generator\GenericVariableGenerator.tt"

rem "D:/Program Files/Epic Games/UE_4.22/Engine/Binaries/DotNET/UnrealBuildTool.exe"  -projectfiles -project="E:/CodePlugins/CodePlugins.uproject" -game -rocket -progress

pause