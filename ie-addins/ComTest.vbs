Set IEp = CreateObject("AddIEFun.IEContext")
If Err <> 0 Then
	MsgBox "Error!"
Else
	MsgBox "���潫�򿪼��±�!"
	Call IEp.AddContext()
End If
