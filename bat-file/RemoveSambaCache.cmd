@echo off
:: BatchGotAdmin
:-------------------------------------
REM --> Check for permissions
>nul 2>&1 "%SYSTEMROOT%\system32\cacls.exe" "%SYSTEMROOT%\system32\config\system"
REM --> If error flag set, we do not have admin.
if '%errorlevel%' NEQ '0' (
  echo Requesting administrative privileges...
  goto UACPrompt
) else ( goto gotAdmin )
:UACPrompt
  echo Set UAC = CreateObject^("Shell.Application"^) > "%temp%\getadmin.vbs"
  echo UAC.ShellExecute "%~s0", "", "", "runas", 1 >> "%temp%\getadmin.vbs"
  "%temp%\getadmin.vbs"
  exit /B
:gotAdmin
  if exist "%temp%\getadmin.vbs" ( del "%temp%\getadmin.vbs" )
  pushd "%CD%"
  CD /D "%~dp0"

:--------------------------------------
@echo off
set SRV=192.168.2.8
echo 清除上次信息，请稍等......
net use
net use \\%SRV%\IPC$ /DELETE
::删除指定的登录会话的所有票证(Kerberos)
klist purge
::删除win保存的凭据管理器，delete:后面为你共享的地址
cmdkey /delete:%SRV%
echo 清除登录信息完成
@echo off
net stop LanmanWorkstation
net start LanmanWorkstation
start /max "" "\\%SRV%"
