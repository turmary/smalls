
'On Error Resume Next
Dim bHas, bKill, fso, WsShell
Set fso = CreateObject("Scripting.FileSystemObject")
Set WsShell = CreateObject("WScript.Shell")


Function ShowDriveType(drvpath)
	Dim d, t

	Set d = fso.GetDrive(drvpath)
	Select Case d.DriveType
		Case 0: t = "未知"
		Case 1: t = "可移动"
		Case 2: t = "固定"
		Case 3: t = "网络"
		Case 4: t = "CD-ROM"
		Case 5: t = "RAM 磁盘"
	End Select
	'ShowDriveType = "驱动器 " & d.DriveLetter & ": - " & t
	ShowDriveType = t
End Function


Function ShowDriveList()
	Dim d, dc, s

	Set dc = fso.Drives
	For Each d in dc
		s = s & d.DriveLetter	' & " - " 
		s = s & ":^"
	Next
	ShowDriveList = Left(s, Len(s)-1)
End Function


Function TestDriveAuto(drv)
	Dim fileAuto, filespec

	filespec = drv & "\AUTORUN.INF"
	TestDriveAuto = fso.FileExists(filespec)
End Function


Function ReadAllTextFile(strFileName)
	On Error Resume Next
	Const ForReading = 1, ForWriting = 2
	Dim f

	Set f = fso.OpenTextFile(strFileName, ForReading, True, TristateUseDefault)
	ReadAllTextFile = f.ReadAll
End Function


'Content of file AUTORUN.INF such as 
'[AutoRun]
'OPEN=setup.exe
'shellexecute=setup.exe
'shell\Auto\command=setup.exe

Function GetVirusName(strAuto)
	Dim strNames, i, j, p1, p2
	Dim strAutoItems
	strAutoItems = Array("Open", "ShellExecute", "Shell\Auto\Command")

	strNames = Split(strAuto, vbCrLf, -1, 1)
	GetVirusName = ""
	For i = LBound(strNames) To UBound(strNames)
	If strNames(i) <> "" Then
		For j = LBound(strAutoItems) To UBound(strAutoItems)
			'MsgBox UCase(strNames(i)) & "," & strAutoItems(j)
			p1 = InStr(1, UCase(strNames(i)), strAutoItems(j), vbTextCompare)
			p2 = InStr(1, UCase(strNames(i)), "=", vbTextCompare)
			If (Not IsNull(p1) And Not IsNull(p2)) Then
			If (p1 <> 0 And p2 <> 0) Then
				GetVirusName = Trim(Right(strNames(i), Len(strNames(i))-p2))
				Exit Function
			End If
			End If
		Next
	End If
	Next
End Function


Function GetAttrStr(nAttrib)
	Dim i, nBit, sRet, sAttrItems

	sAttrItems = Array("只读", "隐藏", "系统", "卷标", "文件夹", "备份", "快捷方式", "压缩")
	
	If nAttrib = 0 Then
		GetAttribStr = "普通"
		Exit Function
	End If

	nBit = 1
	sRet = ""
	For i = 0 to 7
		If (nAttrib And nBit) Then sRet = sRet & sAttrItems(i) & vbCrLf
		nBit = nBit * 2
	Next
	GetAttrStr = Left(sRet, Len(sRet)-1)
End Function


Function ShowFileAccessInfo(filespec) 
	Dim f, s

	Set f = fso.GetFile(filespec)
	s = "名称: " & f.Path & vbCrLf
	s = s & "类型: " & f.Type & vbCrLf
	s = s & "大小: " & f.size & " 字节" & vbCrLf
	s = s & "属性位: " & GetAttrStr(f.Attributes) & vbCrLf
	s = s & "创建时间: " & f.DateCreated & vbCrLf
	s = s & "最后访问时间: " & f.DateLastAccessed & vbCrLf
	s = s & "最后修改时间: " & f.DateLastModified	
	ShowFileAccessInfo = s
End Function


Function KillVirus(drv)
	Dim fileAuto, filespec, strAutoFile, strVirusName

	KillVirus = True
	filespec = drv & "\AUTORUN.INF"
	strAutoFile = ReadAllTextFile(filespec)
	strVirusName = GetVirusName(strAutoFile)
	'Wscript.Echo "Virus Name=" & strVirusName
	If Left(strVirusName, 1) <> "\" Then strVirusName = "\" & strVirusName
	strVirusName = drv & strVirusName

	If Not fso.FileExists(strVirusName) Then Exit Function

	If MsgBox(ShowFileAccessInfo(strVirusName) & vbCrLf & vbCrLf & _
		"是否删除?", vbYesNo, "病毒信息") <> vbYes Then Exit Function

	Call fso.DeleteFile(strVirusName, True)
	Call fso.DeleteFile(filespec, True)
	KillVirus = Not fso.FileExists(filespec)
End Function


Private Sub NestDelete(ByRef folderspec, ByRef strFileName, ByRef nDelCnt)
	Dim f, f1, fc
	
	Set f = fso.GetFolder(folderspec)
			
	Set fc = f.SubFolders
	For Each f1 in fc
		NestDelete f1.Path, strFileName, nDelCnt
	Next

	f1 = folderspec
	If Right(f1, 1) <> "\" Then f1 = f1 & "\"
	f1 = f1 & strFileName
	If fso.FileExists(f1) Then
		nDelCnt = nDelCnt + 1
		'WScript.Echo f1
		fso.DeleteFile f1, True
	End If
End Sub


Sub Main()
	Dim DriveArr, i, nRet

	DriveArr = Split(ShowDriveList(), "^", -1, 1)
	bHas = False
	bKill = False

	For i = LBound(DriveArr) to UBound(DriveArr)
	If ShowDriveType(DriveArr(i)) = "可移动" Then
		'Wscript.Echo DriveArr(i) & " 是U盘或移动硬盘!"
		bHas = True
		If TestDriveAuto(DriveArr(i)) Then
			bKill = True
			nRet = MsgBox(DriveArr(i) & " 盘指定了自动播放" & _
				vbCrLf & "可能已被病毒感染" & _
				vbCrLf & "是否需要杀除?", vbYesNo, "安全警示")
			If (nRet = vbYes) Then
				bKill = True
				If KillVirus(DriveArr(i)) Then
					nRet = MsgBox(DriveArr(i) & " 盘" & _
						"杀毒成功!" & vbCrLf & "请放心使用!", vbOkOnly)
				Else
					nRet = MsgBox(DriveArr(i) & " 盘" & _
						"杀毒失败!" & vbCrLf & "请手工查杀!", vbOkOnly)				
				End If
			End If
		End If
		NestDelete DriveArr(i) & "\", "desktop.ini", nRet
		NestDelete DriveArr(i) & "\", "folder.htt", nRet
	End If
	Next

	If Not bHas Then
		nRet = MsgBox("没有U盘或移动硬盘设备", vbOkOnly)		
	ElseIf Not bKill Then
		nRet = MsgBox("你的U盘或移动硬盘" & vbCrLf & "可能没有病毒", vbOkOnly)
	End If

	'禁用自动播放
	WsShell.RegWrite "HKLM\SOFTWARE\Microsoft\" & _
		"Windows\CurrentVersion\policies\Explorer\NoDriveTypeAutoRun", &HFF, "REG_DWORD"
End Sub


Call Main()

