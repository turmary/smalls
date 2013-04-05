@echo off
echo /////////////////////////Compiling %1////////////////////////
if EXIST %1.ASM (
ml /c /coff /D "_CONSOLE" /D "WIN32" /nologo %1.asm
if NOT ERRORLEVEL 0 goto ERR
goto CLEND
)
REM /P
if EXIST %1.CPP (
cl /c /D "_CONSOLE" /D "WIN32" /nologo %1.CPP
if NOT ERRORLEVEL 0 goto ERR
goto CLEND 
)
REM /P
if EXIST %1.C (
cl /c /D "_CONSOLE" /D "WIN32" /nologo %1.C
if NOT ERRORLEVEL 0 goto ERR
goto CLEND
)
goto ERR
:CLEND

if EXIST %1.RC (
rc %1.RC
if NOT ERRORLEVEL 0 goto ERR
)

echo.
echo /////////////////////////Linking %1.Obj/////////////////////// 
if EXIST %1.EXE (
	del %1.EXE
)
rem no good for /subsystem:windows /subsystem:console
if EXIST %1.RES (
link /subsystem:windows /map:%1map.txt /nologo kernel32.lib shell32.lib user32.lib gdi32.lib %2 %1.obj %1.RES
goto LIKEND
)
link /subsystem:windows /map:%1map.txt /nologo kernel32.lib shell32.lib user32.lib gdi32.lib %2 %1.obj 

:LIKEND
if NOT ERRORLEVEL 0 goto ERR
echo.

echo /////////////////////////Running %1.EXE///////////////////////
%1
if NOT ERRORLEVEL 0 goto ERR
if "%2" == "/D" goto DODEL
if "%2" == "/d" goto DODEL
if "%3" == "/D" goto DODEL
if "%3" == "/d" goto DODEL
goto DONE

:DODEL
DEL %1map.txt
if NOT ERRORLEVEL 0 goto ERR
DEL %1.OBJ
if NOT ERRORLEVEL 0 goto ERR
DEL %1.EXE
if NOT ERRORLEVEL 0 goto ERR
DEL %1.RES
if NOT ERRORLEVEL 0 goto ERR
:DONE
goto :EOF

:ERR
echo error occured.....exit.....

:EOF
@echo on