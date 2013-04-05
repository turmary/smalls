@ECHO OFF
ECHO Backup Begin

PUSHD D:\
IF EXIST \Backup GOTO BACKEXIST
MKDIR \Backup

:BACKEXIST

ECHO ���汸����...
MKDIR "\Backup\����"
XCOPY /S /C /F /H /Y "%ALLUSERSPROFILE%\����" "\Backup\����"
XCOPY /S /C /F /H /Y "%USERPROFILE%\����" "\Backup\����"
ECHO ���汸�����...


ECHO .
ECHO ��������������...
MKDIR "\Backup\REG"
REG EXPORT "HKLM\SYSTEM\CurrentControlSet\Control\Session Manager\Environment" "\Backup\REG\HKLM_Env.reg"
REG EXPORT "HKCU\Environment" "\Backup\REG\HKCU_Env.reg"
ECHO ���������������...


ECHO .
ECHO ������ʾ��������...
REM MKDIR "\Backup\REG"
REG EXPORT "HKLM\SOFTWARE\Microsoft\Command Processor" "\Backup\REG\HKLM_Cmd.reg"
REG EXPORT "HKCU\SOFTWARE\Microsoft\Command Processor" "\Backup\REG\HKCU_Cmd.reg"
ECHO ������ʾ���������...


ECHO .
ECHO �ļ���ѡ�����...
REM MKDIR "\Backup\REG"
REG EXPORT "HKLM\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced" "\Backup\REG\HKLM_Adv.reg"
REG EXPORT "HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced" "\Backup\REG\HKCU_Adv.reg"
ECHO �ļ���ѡ������...


ECHO .
ECHO ���͵�������...
MKDIR "\Backup\SendTo"
XCOPY /S /C /F /H /Y "%USERPROFILE%\SendTo" "\Backup\SendTo"
ECHO ���͵��������...


ECHO .
ECHO ���͵�������...
MKDIR "\Backup\SendTo"
XCOPY /S /C /F /H /Y "%USERPROFILE%\SendTo" "\Backup\SendTo"
ECHO ���͵��������...


ECHO .
ECHO ��������������...
MKDIR "\Backup\QuickLaunch"
XCOPY /S /C /F /H /Y "%USERPROFILE%\Application Data\Microsoft\Internet Explorer\Quick Launch" "\Backup\QuickLaunch"
ECHO ���������������...

POPD
