@echo off
rem F2C TABLE
if /i "%1" EQU "300" goto EOF
if not "%1" == "" goto process

rem 该脚本成功!
rem INIT PROC
set /a fahr=-20


:process
set /a fahr="%fahr% + 20"
set /a cel="5 * (%fahr% - 32) / 9"
if "%fahr%" == "100" set sign=1
if "%fahr%" == "0" (
	echo %fahr%   %cel%
	goto endEcho
)
if /i defined sign goto elifEcho
	echo %fahr%  %cel%
	goto endEcho
:elifEcho
	echo %fahr% %cel%
:endEcho
%0 %fahr%

:EOF
set fahr=
set sign=
set cel=
echo on
