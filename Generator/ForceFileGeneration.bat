@echo off

echo [VariablesSystem] Updating VariablesSystemGenerator
where msbuild /Q
if %ERRORLEVEL% NEQ 0 (
echo [VariablesSystem] msbuild was not found
exit /b
)

msbuild %~dp0VariablesGenerator.sln /target:Rebuild /verbosity:minimal /nologo