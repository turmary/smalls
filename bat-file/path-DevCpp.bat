@ECHO OFF
@REM ����Dev-Cpp �Ļ���·��

@IF NOT "%DEVCPPROOT%" == "" GOTO END
@SET DEVCPPROOT=F:\TaryInstalled\Dev-Cpp
@SET PATH=%DEVCPPROOT%\bin;%DEVCPPROOT%\mingw32\bin;%PATH%

:END
@ECHO ON

