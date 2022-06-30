@echo off
powershell -Command "(Get-NetIPAddress -InterfaceAlias ArrayNet).IPAddress"
:- pause
