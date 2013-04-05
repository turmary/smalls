@echo off
for %%i in (hello my name is kate green) do echo %%i
set i=5
echo %i%
set /A i=%i%+1
echo %i%
pause
