1	命令用法/////////////////////////////



REM rem是在批处理文件里加上注解或说明

REM 大小写一般通用

pause
rem 暂停批处理程序，并显示以下消息:请按任意键继续. . .

@echo off
REM 不显示该命令，并关闭回显

@echo on
REM 不显示该命令，并打开回显

echo.
REM 显示一个空行

echo
REM 用来显示回显设置状态

echo hello
REM 显示一行“hello"

%1%*
rem 引用参数1，参数0是命令本身临其境，参数*表整个命令行的参数

:if1
	if NOT "%0" == "" (shift && echo %0 && goto if1)
REM 该方法也可以列出所有参数

shift 
REM 参数前移，原%1变成%0

set lib=%classpath%\pack1;%v6%
REM 新建环境变量LIB，并使LIB等于CLASSPATH的值加上“PACK1；”，再加上V6的值                                                                                                                                       set Lib=%v6%
REM 使已有的环境变量LIB的值变成v6的值，lib是地址，%LIB%是LIB指向地址的存储值

%classpath%
rem 引用环境变量CLASSPATH

%TRACE% The value of variable USE_TRACE_FMT is %USE_TRACE_FMT%
rem 还可以这样用，用环境变量作命令关键词

:myuse2
REM 定义标号MYUSE2

goto finish
REM 与BASIC中的GOTO相同，跳到标号FINISH

goto :EOF
REM EOF定义了则到EOF，否则出本批文件

IF "%1" == "a" goto myuse1
REM 当参数1是a时，跳到MYUSE1

IF “%classpath%" == "e:\java\ch9\my\" goto finish
REM 当环境变量为classpath等于e:\java\ch9\my\时

IF errorlevel 1 goto errlev
REM 如果最近执行的命令出口码为1的话跳到标号ERRLEV

IF [NOT] EXIST hello.java command
REM 如果[不]存在文件HELLO.JAVA的话执行命令COMMAND

if "%DEBUG%"=="1" (set TRACE=echo) else (set TRACE=rem)
REM WINXP中新增的环境变量DEBUG为1时执行前部分，否则执行后部分

FOR %%P IN （ONE,TWO,three,four,five) DO del %%p.txt
REM 删除one.txt,two.txt,three.txt,four.txt,five.txt,注意IN,DO大写

for %%i in (*) do dir %%i
REM 列出当前目录中的所有文件，*代表所有文件

FOR /L %variable IN (start,step,end) DO command [command-parameters]
该集表示以增量形式从开始到结束的一个数字序列。
因此，(1,1,5) 将产生序列 1 2 3 4 5，(5,-1,1) 将产生
序列 (5 4 3 2 1)。

call do_else.bat
REM 调用DO_BAT文件,若不用CALL则是转移，而不是调用

call :end
REM 调用标签END开始的语句到文件结束后返回

del startw.exe > nul
REM 删除文件STARTW.EXE并不作任何输出

nk <do_else.out >nk.out
REM 执行NK命令，以do_else.out文件作为输入，以NK.out作为输出

type readme.doc | more
REM 通道用法，将前一命令的输出作为后一命令的输入

doskey dw=dir *.com $t dir *.txt $t pause $t cls
REM 定义宏DW，它可以执行四个命令




2	常用的系统环境变量/////////////////////////////



%SystemRoot%
系统根目录

%WinDir%
WINDOWS的路径

%OS%
操作系统类型

%path%
可执行文件搜索路径




3	请运用上面要点分析阅读下例/////////////////////////////

@echo off
rem 环境变量V6TOOLS为空时提示用法1
IF "%V6TOOLS%" == "" goto Usage1

rem 存在文件NMKTOBAT时则编译
if exist nmktobat.exe goto built_exe
echo =-=-=-=-= Building NMKtoBAT.EXE =-=-=-=-= 
echo This program is used in the MSVC CRTL build process
cl /W4 /WX /Za nmktobat.c
if errorlevel 1 goto errlev

:built_exe
rem 当参数1是pMAC或pMac或pmac时给MAC机编译
rem 当参数1为空时给PC机编译
rem 参数1都不是上叙时到提示用法
IF "%1" == "PMAC" goto buildpmac
IF "%1" == "PMac" goto buildpmac
IF "%1" == "pmac" goto buildpmac
IF "%1" == "" goto buildx86
goto Usage2

:buildpmac
rem 给PMAC机编译设置参数，再编译
set PROCESSOR_ARCHITECTURE=PMAC
set PATH=%V6TOOLS%\mac\mppc\bin;%V6TOOLS%\mac\bin;%PATH%
set INCLUDE=%V6TOOLS%\mac\include;%V6TOOLS%\mac\include\macos;%INCLUDE%
set LIB=%V6TOOLS%\mac\mppc\lib;%LIB%
shift
goto dobuild

:buildx86
rem 给PC机编译设置参数，再编译
if "%PROCESSOR_ARCHITECTURE%"=="" set PROCESSOR_ARCHITECTURE=x86

:dobuild
统一编译
echo =-=-=-=-= Doing MSVC40 CRTL Source build (Objects) =-=-=-=-= 
nmake -nologo -i -n BLD_OBJ=1 %1 %2 %3 %4 %5 > do_build.out
nmktobat < do_build.out > do_build.bat
call do_build.bat
if errorlevel 1 goto errlev
echo =-=-=-=-= Doing MSVC40 CRTL Source build (Libraries) =-=-=-=-= 
nmake -nologo BLD_LIB=1 %1 %2 %3 %4 %5
if errorlevel 1 goto errlev
goto finish

:errlev
rem 运行出错
echo.
echo ***
echo *** BUILD ABORTED -- ErrorLevel is non-zero!
echo ***
goto finish

:Usage1
rem 用法1，环境变量V6TOOLS不对
echo The environment variable V6TOOLS must be set to point
echo to the root of your VC++ 6.0 installation.
goto finish

:Usage2
rem 用法2，提示加入参数PMac可以给MAC机编译
echo "bldwin95" builds the runtimes for Intel platforms.
echo "bldwin95 PMac" builds the runtimes for the Power Macintosh.
:finish
