cl /c First_DLL.C
Link /subsystem:windows /Dll /Def:First_DLL.def First_Dll.obj User32.lib