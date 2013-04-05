@echo off
IF "%1" == "/s" goto sif1
IF "%1" == "/S" goto sif1
IF "%1" == "/c" goto sif2
If "%1" == "/C" goto sif2
goto usage

:sif2
rem combine file

IF EXIST %2 (DEL %2)
FOR %%i IN (SEP*.DAT) DO (
        IF NOT EXIST %2 (COPY /B %%i TEMP) ELSE (COPY /B %2+%%i TEMP)
	IF EXIST %2 (DEL %2)
	IF EXIST TEMP (REN TEMP %2)                       
)
goto finish

:sif1
rem separate file
L28 %2 %3
goto finish

:usage
echo.
echo USAGE:
echo 1. sep /s filename num
echo filename:  file to separate
echo num:       num of files after separate
echo 2. sep /c filename
echo filename:  filename after combine
echo .


:finish
@echo on


