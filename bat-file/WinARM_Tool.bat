@ECHO OFF
:-  ���������ڽ���һ��WinARM�������б��뻷��
:-  �����WinARM�İ�װλ���޸ı���WINARM
:-  Ĭ���������F:\WinARM
SET WINARM=C:\WinARM

:-  �����벻Ҫ�Ķ�
IF NOT EXIST "%WINARM%\bin\arm-elf-gcc.exe" (
	ECHO.
	ECHO ���޸ı��ļ��е��¾�Ⱥ��ұ�Ϊ�ʵ�ֵ
	ECHO SET WinARM=%WINARM%
	ECHO ����ָ��WinARM�İ�װ�ļ���
	ECHO.
	PAUSE ��������˳�
	GOTO :EOF
)
CHCP 936
PATH=%WINARM%\bin;%WINARM%\utils\bin;C:\MinGW\bin;%PATH%
:-  START
TITLE WinARM Environment
COLOR 2E
CMD.EXE /E:ON /V:ON /K "CD /D D:\lpc2131\svn\trunk\02_Project && CLS"
:-  ���

@ECHO ON
