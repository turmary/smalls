@echo off
rem F2C TABLE
set fahr=0
rem �����Ժ��%fahr%����0������...
goto print

rem �ýű�(for)���ɹ�!
rem ��Ϊȫ��������Ĺ�ϵ.
for /l %%f in (0,20,300) do (
        set /a cel="5 * (%%f - 32) / 9"
        echo %%f %cel%
)

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