1	�����÷�/////////////////////////////



REM rem�����������ļ������ע���˵��

REM ��Сдһ��ͨ��

pause
rem ��ͣ��������򣬲���ʾ������Ϣ:�밴���������. . .

@echo off
REM ����ʾ��������رջ���

@echo on
REM ����ʾ��������򿪻���

echo.
REM ��ʾһ������

echo
REM ������ʾ��������״̬

echo hello
REM ��ʾһ�С�hello"

%1%*
rem ���ò���1������0����������侳������*�����������еĲ���

:if1
	if NOT "%0" == "" (shift && echo %0 && goto if1)
REM �÷���Ҳ�����г����в���

shift 
REM ����ǰ�ƣ�ԭ%1���%0

set lib=%classpath%\pack1;%v6%
REM �½���������LIB����ʹLIB����CLASSPATH��ֵ���ϡ�PACK1�������ټ���V6��ֵ                                                                                                                                       set Lib=%v6%
REM ʹ���еĻ�������LIB��ֵ���v6��ֵ��lib�ǵ�ַ��%LIB%��LIBָ���ַ�Ĵ洢ֵ

%classpath%
rem ���û�������CLASSPATH

%TRACE% The value of variable USE_TRACE_FMT is %USE_TRACE_FMT%
rem �����������ã��û�������������ؼ���

:myuse2
REM ������MYUSE2

goto finish
REM ��BASIC�е�GOTO��ͬ���������FINISH

goto :EOF
REM EOF��������EOF������������ļ�

IF "%1" == "a" goto myuse1
REM ������1��aʱ������MYUSE1

IF ��%classpath%" == "e:\java\ch9\my\" goto finish
REM ����������Ϊclasspath����e:\java\ch9\my\ʱ

IF errorlevel 1 goto errlev
REM ������ִ�е����������Ϊ1�Ļ��������ERRLEV

IF [NOT] EXIST hello.java command
REM ���[��]�����ļ�HELLO.JAVA�Ļ�ִ������COMMAND

if "%DEBUG%"=="1" (set TRACE=echo) else (set TRACE=rem)
REM WINXP�������Ļ�������DEBUGΪ1ʱִ��ǰ���֣�����ִ�к󲿷�

FOR %%P IN ��ONE,TWO,three,four,five) DO del %%p.txt
REM ɾ��one.txt,two.txt,three.txt,four.txt,five.txt,ע��IN,DO��д

for %%i in (*) do dir %%i
REM �г���ǰĿ¼�е������ļ���*���������ļ�

FOR /L %variable IN (start,step,end) DO command [command-parameters]
�ü���ʾ��������ʽ�ӿ�ʼ��������һ���������С�
��ˣ�(1,1,5) ���������� 1 2 3 4 5��(5,-1,1) ������
���� (5 4 3 2 1)��

call do_else.bat
REM ����DO_BAT�ļ�,������CALL����ת�ƣ������ǵ���

call :end
REM ���ñ�ǩEND��ʼ����䵽�ļ������󷵻�

del startw.exe > nul
REM ɾ���ļ�STARTW.EXE�������κ����

nk <do_else.out >nk.out
REM ִ��NK�����do_else.out�ļ���Ϊ���룬��NK.out��Ϊ���

type readme.doc | more
REM ͨ���÷�����ǰһ����������Ϊ��һ���������

doskey dw=dir *.com $t dir *.txt $t pause $t cls
REM �����DW��������ִ���ĸ�����




2	���õ�ϵͳ��������/////////////////////////////



%SystemRoot%
ϵͳ��Ŀ¼

%WinDir%
WINDOWS��·��

%OS%
����ϵͳ����

%path%
��ִ���ļ�����·��




3	����������Ҫ������Ķ�����/////////////////////////////

@echo off
rem ��������V6TOOLSΪ��ʱ��ʾ�÷�1
IF "%V6TOOLS%" == "" goto Usage1

rem �����ļ�NMKTOBATʱ�����
if exist nmktobat.exe goto built_exe
echo =-=-=-=-= Building NMKtoBAT.EXE =-=-=-=-= 
echo This program is used in the MSVC CRTL build process
cl /W4 /WX /Za nmktobat.c
if errorlevel 1 goto errlev

:built_exe
rem ������1��pMAC��pMac��pmacʱ��MAC������
rem ������1Ϊ��ʱ��PC������
rem ����1����������ʱ����ʾ�÷�
IF "%1" == "PMAC" goto buildpmac
IF "%1" == "PMac" goto buildpmac
IF "%1" == "pmac" goto buildpmac
IF "%1" == "" goto buildx86
goto Usage2

:buildpmac
rem ��PMAC���������ò������ٱ���
set PROCESSOR_ARCHITECTURE=PMAC
set PATH=%V6TOOLS%\mac\mppc\bin;%V6TOOLS%\mac\bin;%PATH%
set INCLUDE=%V6TOOLS%\mac\include;%V6TOOLS%\mac\include\macos;%INCLUDE%
set LIB=%V6TOOLS%\mac\mppc\lib;%LIB%
shift
goto dobuild

:buildx86
rem ��PC���������ò������ٱ���
if "%PROCESSOR_ARCHITECTURE%"=="" set PROCESSOR_ARCHITECTURE=x86

:dobuild
ͳһ����
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
rem ���г���
echo.
echo ***
echo *** BUILD ABORTED -- ErrorLevel is non-zero!
echo ***
goto finish

:Usage1
rem �÷�1����������V6TOOLS����
echo The environment variable V6TOOLS must be set to point
echo to the root of your VC++ 6.0 installation.
goto finish

:Usage2
rem �÷�2����ʾ�������PMac���Ը�MAC������
echo "bldwin95" builds the runtimes for Intel platforms.
echo "bldwin95 PMac" builds the runtimes for the Power Macintosh.
:finish
