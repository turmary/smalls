@echo off
IF "%1" == "" goto enter
IF "%1" == "/n" goto enter

IF "%1" == "/e" goto edit

IF "%1" == "?" goto usage
If "%1" == "/?" goto usage
if NOT "%5" == "" goto usage

if "%2" =="" goto main
if "%2" =="/r" goto main
if "%2"== "/c" goto main
if "%2"== "/a" goto main
if "%2"== "/rc" goto main
goto usage



:main
set filename=%1.java
echo File Name :%filename%
if "%2" == "/c" goto if2
goto endif2
:if2
	echo file content
	type %filename%
:endif2 
echo.
echo //////////////////////////////compile/////////////////////////////////////
if exist %filename% (
	if NOT exist %1.class (
		echo compile %filename% for you
		goto compile
	)
	if "%2"=="/r" (echo recompile %filename%)&(goto compile)
	if "%2"=="/rc" (echo recompile %filename%)&(goto compile)
	echo cann't compile %filename% for you
	goto endif1
	
:compile
	javac %filename%	
	goto endif1	
)
rem else
	echo cann't compile %filename% for you
:endif1

echo.
echo /////////////////////////////run/////////////////////////////////////////
if exist %1.class (
	echo run %1.class for you
	if "%3"=="/a" ("C:\Program Files\Internet Explorer\iexplore.exe" file://e:/Studied/java/%4/applet.html?%1)&(goto endif3)
	if "%2"=="/a" ("C:\Program Files\Internet Explorer\iexplore.exe" file://e:/Studied/java/%3/applet.html?%1)&(goto endif3)
	(java %1)
:endif3
	goto endif4
)
rem else
if NOT %3 == "" (
	echo run %3.class for you
	java %3
) else (
	echo cann't run %1.class or %3.class for you
)

:endif4
if "%2"=="/c" (notepad %filename%)
if "%2"=="/rc" (notepad %filename%)
goto finish



:edit
echo //////////////////////////////edit///////////////////////////////////////
echo editting myself
notepad D:\MyExe\myjava.bat
goto finish



:usage
echo //////////////////////////////help///////////////////////////////////////
echo use 1	type "myjava filename"
echo 		filename is you java file name
echo 		to compile the file for you
echo.
echo use 2	type "myjava filename /c"
echo		correspond to use 1 and type file content for you
echo.
echo use 3	type "myjava" or "myjava /n"
echo		to enter the java directory
echo.
echo use 4	type "myjava /?" or "myjava ?"
echo		to get this help
echo.
echo use 5	type "myjava /e"
echo		go edit this batch file
echo.
goto finish



:enter
e:
cd \Studied\java\
cls
dir /w *.*



:finish
@echo on
