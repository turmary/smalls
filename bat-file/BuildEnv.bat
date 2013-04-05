@ECHO oFF
:-  本程序用于建立一个Visual C++的命令行编译环境
:-  请根据Visual C++的安装位置修改变量MSVS
:-  默认情况下是C:\Program Files\Microsoft Visual Studio
:-  以下是在我机器上的安装文件夹
SET MSVS=F:\TaryInstalled\Microsoft Visual Studio

:-  以下请不要改动
IF NOT EXIST "%MSVS%\VC98\BIN\VCVARS32.BAT" (
	ECHO.
	ECHO 请修改本文件中的下句等号右边为适当值
	ECHO SET MSVS=%MSVS%
	ECHO 用于指定Visual C++的安装文件夹
	ECHO.
	PAUSE 按任意键退出
	GOTO :EOF
)
CHCP 936
SET VCBIN=%MSVS%\VC98\BIN
PATH=%VCBIN%;%PATH% && CALL VCVARS32.BAT
:-  START
cmd.exe /E:ON /T:1A /V:ON /K "CLS"
:-  完毕

@ECHO ON
