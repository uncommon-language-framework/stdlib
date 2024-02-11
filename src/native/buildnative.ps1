using namespace System.Collections.Generic;

$files = Get-ChildItem System
$compile = [List[string]]::new()

foreach ($file in $files)
{
	if ($file.FullName.EndsWith(".cpp"))
	{
		$compile.Add($file.FullName);
	}
}

g++64 -c $compile "AssemblyInfo.cpp" "../../../ulr/ULR/Lib/Public/MethodInvokeImpl.cpp" -fpermissive -masm=intel -g -D DEBUG=true
g++64 -o "System.Runtime.Native.dll" *.o -shared

Remove-Item *.o