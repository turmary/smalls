@ECHO OFF
:-  本程序用于建立一个WinARM的命令行编译环境
:-  请根据WinARM的安装位置修改变量WINARM
:-  默认情况下是F:\WinARM
SET WINARM=C:\WinARM

:-  以下请不要改动
IF NOT EXIST "%WINARM%\bin\arm-elf-gcc.exe" (
	ECHO.
	ECHO 请修改本文件中的下句等号右边为适当值
	ECHO SET WinARM=%WINARM%
	ECHO 用于指定WinARM的安装文件夹
	ECHO.
	PAUSE 按任意键退出
	GOTO :EOF
)
CHCP 936
PATH=%WINARM%\bin;%WINARM%\utils\bin;C:\MinGW\bin;%PATH%
:-  START
TITLE WinARM Environment
COLOR 2E
CMD.EXE /E:ON /V:ON /K "CD /D D:\lpc2131\svn\trunk\02_Project && CLS"
:-  完毕

@ECHO ON
