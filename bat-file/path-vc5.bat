REM @ECHO OFF
REM ����Visual C++ 5.0 �Ļ���·��
REM ���б��ļ���,ʹ�����·�������FILE.C�ļ�
REM CL ^<FILE.C^>

IF NOT "%INCLUDE%" == "" GOTO BEND
SET VCBASE=D:\DEVSTU~1\VC
SET PATH=%VCBASE%\BIN;D:\DEVSTU~1\Shared~1\bin;%PATH%
SET INCLUDE=%VCBASE%\INCLUDE;%VCBASE%\MFC\INCLUDE
SET LIB=%VCBASE%\LIB;%VCBASE%\MFC\LIB
ECHO Visual C++ 5.0 Environment Set OK
ECHO You can use nmake and cl to compile programs now.

:BEND
@ECHO ON
