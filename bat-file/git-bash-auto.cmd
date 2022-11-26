::::::::::::::::::::::::::::::::::::::::::::
:: Automatically check & get admin rights
:: see "https://stackoverflow.com/a/12264592/1016343" for description
::::::::::::::::::::::::::::::::::::::::::::
@setlocal enabledelayedexpansion enableextensions
@echo off

:: Admin check
rem :: (echo !_!)&
fltmc >nul 2>nul || set _=^"set _ELEV=1^& cd /d "%cd%"^& "%~f0" %* ^"&&((if "%_ELEV%"=="" (echo Requesting administrator privileges...&((powershell -nop -c start cmd -args '/d/x/s/r',$env:_ -verb runas -windowstyle hidden >nul 2>nul) || (mshta vbscript:execute^("createobject(""shell.application"").shellexecute(""cmd"",""/d/x/s/v:off/r ""&createobject(""WScript.Shell"").Environment(""PROCESS"")(""_""),,""runas"",1)(window.close)"^) >nul 2>nul))) else (echo This script requires administrator privileges.& pause))& exit /b)

:: echo Has admin permissions& echo Working dir: "%cd%"& echo Script dir: "%~dp0"& echo Script path: "%~f0"& echo Args: %*& pause

 ::::::::::::::::::::::::::::
 ::START
 ::::::::::::::::::::::::::::
 REM begin real part with administrator privilege

:: Open PDF with SumatraPDF
:: assoc .pdf=SumatraPDF
:: ftype SumatraPDF=F:\TaryInst\SumatraPDF-3.4.6-64.exe %1 %*

cd /d %HOMEDRIVE%%HOMEPATH%
start d:\TaryInst\Git\git-bash.exe --cd-to-home
call :sleep 10
:: workaround mintty/mingw64 problem:
::   CTRL+C close background process group
::
:: ** taskkill require administrator privilege **
taskkill /f /im mintty.exe
start d:\TaryInst\Git\git-bash.exe --cd-to-home
exit



:sleep seconds -- waits some seconds before returning
::             -- seconds [in]  - number of seconds to wait
:$created 20060101 :$changed 20080219
:$source https://www.dostips.com
FOR /l %%a in (%~1,-1,1) do (ping -n 2 -w 1 127.0.0.1>NUL)
EXIT /b
