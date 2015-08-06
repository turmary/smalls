Set IEp = CreateObject("AddIEFun.IEContext")
If Err <> 0 Then
	MsgBox "Error!"
Else
	MsgBox "下面将打开记事本!"
	Call IEp.AddContext()
End If
