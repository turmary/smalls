@echo off
echo *******Begin Comment**************
echo This program starts the superapp batch program on the network,
echo directs the output to a file, and displays the file
echo in Notepad.
echo *******End Comment**************
echo @echo off
setlocal
path=e:\studied\bat_file;%path%
echo %path%
call Bat_SetLocal 2>C:\Windows\superapp.out
endlocal
notepad C:\Windows\superapp.out
