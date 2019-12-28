'���������ڴ�IE���渴�Ƶ��ļ�����
'    ȥ���ļ����е�[1]�Ȳ���
'On Error Resume Next
Dim bHas, bKill, fso, WsShell
Set fso = CreateObject("Scripting.FileSystemObject")


Function IsRenameFile(strName)
	Dim strRet, bValid, ch

	strRet = ""
	If 0 = InStr(1, strName, "[", vbTextCompare) Then
		Exit Function
	End If

	bValid = 1
	For i = 1 To Len(strName)
		ch = Mid(strName, i, 1)
		If  ch = "[" Then
			bValid = 0
		ElseIf ch = "]" Then
			bValid = 1
		ElseIf bValid Then
			strRet = strRet + ch
		End If
	Next
	IsRenameFile = strRet
End Function


Private Sub NestRename(ByVal folderspec, ByRef nRenCnt)
	Dim fold, subfolds, subfiles, fitem, fname
	
	Set fold = fso.GetFolder(folderspec)
		
	Set subfolds = fold.SubFolders
	For Each fitem In subfolds
		NestRename fitem.Path, nRenCnt
	Next

	Set subfiles = fold.Files
	For each fitem In subfiles
		fname = IsRenameFile(fso.GetFileName(fitem.Path))
		If (fname <> "") Then
			Wscript.Echo fso.GetParentFolderName(fitem.Path) & "\" & fname
			fso.MoveFile fitem.Path, fso.GetParentFolderName(fitem.Path) & "\" & fname
			nRenCnt = nRenCnt + 1
		End If
	Next
End Sub

Sub Main()
	Dim nCount

	' Display the first command-line parameters
	Set objArgs = Wscript.Arguments
	If objArgs.Count = 0 Then
		Wscript.Echo "���������ڴ�IE���渴�Ƶ��ļ�����" & _
		  Chr(13) & Chr(10) & "  ʹ�÷��� HtmlRename.vbs <Path>"
		Wscript.Quit(1)
	End If
	nCount = 0
	Call NestRename(objArgs(0), nCount)
	Wscript.Echo "�������ļ�" & nCount & "��!"
End Sub

Call Main()

