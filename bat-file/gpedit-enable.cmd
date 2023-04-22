@echo off
pushd "%~dp0"
dir /b %SYSTEMROOT%\servicing\Packages\Microsoft-Windows-GroupPolicy-ClientExtensions-Package~3*.mum >gpedit-enable.cmd.list
dir /b %SYSTEMROOT%\servicing\Packages\Microsoft-Windows-GroupPolicy-ClientTools-Package~3*.mum >>gpedit-enable.cmd.list
for /f %%i in ('findstr /i . gpedit-enable.cmd.list 2^>nul') do dism /online /norestart /add-package:"%SYSTEMROOT%\servicing\Packages\%%i"
pause
del gpedit-enable.cmd.list
