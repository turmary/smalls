@ECHO oFF
:-  ���������ڽ���һ��Visual C++�������б��뻷��
:-  �����Visual C++�İ�װλ���޸ı���MSVS
:-  Ĭ���������C:\Program Files\Microsoft Visual Studio
:-  ���������һ����ϵİ�װ�ļ���
SET MSVS=F:\TaryInstalled\Microsoft Visual Studio

:-  �����벻Ҫ�Ķ�
IF NOT EXIST "%MSVS%\VC98\BIN\VCVARS32.BAT" (
	ECHO.
	ECHO ���޸ı��ļ��е��¾�Ⱥ��ұ�Ϊ�ʵ�ֵ
	ECHO SET MSVS=%MSVS%
	ECHO ����ָ��Visual C++�İ�װ�ļ���
	ECHO.
	PAUSE ��������˳�
	GOTO :EOF
)
CHCP 936
SET VCBIN=%MSVS%\VC98\BIN
PATH=%VCBIN%;%PATH% && CALL VCVARS32.BAT
:-  START
cmd.exe /E:ON /T:1A /V:ON /K "CLS"
:-  ���

@ECHO ON
