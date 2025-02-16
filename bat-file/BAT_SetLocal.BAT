@echo off
:- *******begin comment**************
echo this program starts the superapp batch program on the network,
echo directs the output to a file, and displays the file
echo in notepad.
:- *******end comment**************

echo @echo off

setlocal
    set path=%~dp0;%path%
    set public=%~dp0;%public%
    if defined level (set /a level=%level% + 1) else (set level=0)
    rem echo %~nx0
    cd /d %~dp0
    call %~0 >superapp%level%.out 2>&1
endlocal

cd
echo public=%public%
echo.
echo.
rem notepad superapp.out
pause
