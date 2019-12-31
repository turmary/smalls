Dim WsShell, objArgs

mgmt_path = "HKCR\CLSID\{20D04FE0-3AEA-1069-A2D8-08002B30309D}\shell\Manage\command\"

Function ShortCreate()
	On Error Resume Next
	WsShell.RegWrite "HKCR\InternetShortcut\IsShortcut", "","REG_SZ"
	WsShell.RegWrite "HKCR\lnkfile\IsShortcut", "","REG_SZ"
	WsShell.RegWrite "HKCR\piffile\IsShortcut", "","REG_SZ"
	mgmt_val = "%SystemRoot%\system32\CompMgmtLauncher.exe"
	WsShell.RegWrite mgmt_path, mgmt_val, "REG_EXPAND_SZ"
	WScript.Echo "显示成功"
End Function

Function ShortDelete()
	On Error Resume Next
	WsShell.RegDelete "HKCR\InternetShortcut\IsShortcut"
	WsShell.RegDelete "HKCR\lnkfile\IsShortcut"
	WsShell.RegDelete "HKCR\piffile\IsShortcut"
	mgmt_val = "mmc.exe %windir%\system32\compmgmt.msc"
	WsShell.RegWrite mgmt_path, mgmt_val, "REG_EXPAND_SZ"
	WScript.Echo "删除成功"
End Function

Function InitVars()
	On Error Resume Next

	Err.Clear
	Set WsShell = CreateObject("WScript.Shell")
	Set objArgs = Wscript.Arguments
End Function

Function ResetExplorer()
	Const SW_HIDE = 0

	WsShell.Run "taskkill /f /im explorer.exe", SW_HIDE, True
	WsShell.Run "explorer.exe"
	WsShell.Run "explorer.exe " & Left(Wscript.ScriptFullName, _
	Len(Wscript.ScriptFullName)-Len(Wscript.ScriptName)-1)
End Function

Sub Main()
	InitVars()
	If objArgs.count > 0 Then
		If LCase(objArgs(0)) = "show" Then
			ShortCreate()
		End If
		If LCase(objArgs(0)) = "delete" Or LCase(objArgs(0)) = "del" Then
			ShortDelete()
		End If
	Else
		ShortDelete()
	End If
	ResetExplorer()
End Sub

Main()