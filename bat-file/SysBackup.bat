@ECHO OFF
ECHO Backup Begin

PUSHD D:\
IF EXIST \Backup GOTO BACKEXIST
MKDIR \Backup

:BACKEXIST

ECHO 桌面备份中...
MKDIR "\Backup\桌面"
XCOPY /S /C /F /H /Y "%ALLUSERSPROFILE%\桌面" "\Backup\桌面"
XCOPY /S /C /F /H /Y "%USERPROFILE%\桌面" "\Backup\桌面"
ECHO 桌面备份完毕...


ECHO .
ECHO 环境变量备份中...
MKDIR "\Backup\REG"
REG EXPORT "HKLM\SYSTEM\CurrentControlSet\Control\Session Manager\Environment" "\Backup\REG\HKLM_Env.reg"
REG EXPORT "HKCU\Environment" "\Backup\REG\HKCU_Env.reg"
ECHO 环境变量备份完毕...


ECHO .
ECHO 命令提示符备份中...
REM MKDIR "\Backup\REG"
REG EXPORT "HKLM\SOFTWARE\Microsoft\Command Processor" "\Backup\REG\HKLM_Cmd.reg"
REG EXPORT "HKCU\SOFTWARE\Microsoft\Command Processor" "\Backup\REG\HKCU_Cmd.reg"
ECHO 命令提示符备份完毕...


ECHO .
ECHO 文件夹选项备份中...
REM MKDIR "\Backup\REG"
REG EXPORT "HKLM\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced" "\Backup\REG\HKLM_Adv.reg"
REG EXPORT "HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced" "\Backup\REG\HKCU_Adv.reg"
ECHO 文件夹选项备份完毕...


ECHO .
ECHO 发送到备份中...
MKDIR "\Backup\SendTo"
XCOPY /S /C /F /H /Y "%USERPROFILE%\SendTo" "\Backup\SendTo"
ECHO 发送到备份完毕...


ECHO .
ECHO 发送到备份中...
MKDIR "\Backup\SendTo"
XCOPY /S /C /F /H /Y "%USERPROFILE%\SendTo" "\Backup\SendTo"
ECHO 发送到备份完毕...


ECHO .
ECHO 快速启动备份中...
MKDIR "\Backup\QuickLaunch"
XCOPY /S /C /F /H /Y "%USERPROFILE%\Application Data\Microsoft\Internet Explorer\Quick Launch" "\Backup\QuickLaunch"
ECHO 快速启动备份完毕...

POPD
