@echo off
rem F2C TABLE
set fahr=0
rem 这样以后的%fahr%都用0代替了...
rem goto print

rem 该脚本(for)不成功!
rem 因为for语句(包括循环部分)只扩展一次的原因.
rem 打开延迟变量可以解决这个问题
setlocal enabledelayedexpansion

for /l %%f in (0,20,300) do (
	set /a cel="5 * (%%f - 32) / 9"
	rem 失败的脚本
	rem echo %%f %cel%
	echo %%f !cel!
)

goto :EOF

:print
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
if "%fahr%" == "300" goto EOF
set /a fahr=%fahr% + 20
goto print

:EOF
set fahr=
set sign=
set cel=
echo on
