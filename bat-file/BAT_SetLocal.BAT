@ECHO OFF
ECHO *******Begin Comment**************
ECHO This program starts the superapp batch program on the network,
ECHO directs the output to a file, and displays the file
ECHO in Notepad.
ECHO *******End Comment**************

ECHO @ECHO OFF

SETLOCAL
    SET PATH=%~dp0;%PATH%
    REM ECHO %~nx0
    CD /D %~dp0
    CALL %~0 2>superapp.out
ENDLOCAL

CD
ECHO PATH=%PATH%
REM notepad superapp.out
PAUSE
