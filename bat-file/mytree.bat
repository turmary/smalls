@rem //////////////////////main////////////////
@echo off

if NOT "%2" == "" (cd %1 && echo %2[%1])

rem 1. process directory
set my=%2+___
for /D %%i IN (*) do (
	call d:\myexe\mytree.bat "%%i" %my%
)
set my=

rem 2. echo file
for %%j IN (*) do echo %2+---%%j

if NOT "%2" == "" cd ..


rem //////////////////////main end////////////////