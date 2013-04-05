@echo off
:- set bc3inc=
set bc3lib=
rem call bc3path.bat
rem call m5path.bat
:- 使用BC++的TLINK,最好使用BC++的TASM
:- 不然可能会出问题哦......
:-

if "%1" == "" goto usage

del %1.OBJ >NUL
del %1.MAP >NUL
del %1.EXE >NUL
del %1.COM >NUL
del A:\%1.COM >NUL

if "%bc3inc%" == "" goto label_m5
	tasm /c /la %1.asm
	tlink /Tdc /m /3 %1.obj
	goto complete
:label_m5
	d:\masm\masm %1.asm;
	d:\masm\link %1.obj;
	exe2bin %1.exe %1.com

:complete

copy %1.com a:\

if exist a:\%1.com (
	@echo Generate Complete!!!
	if "%2" == "R" @call E:\OSStudy\Tinix\Tinix\chapter3\a\godbg.bat
	@goto end
)
@echo mpmbuild: there may be some error!!!
goto end

:usage
@echo.
@echo Usage: pmbuild ^<FILE^>
@echo      FILE: master file name of a assembly file.
@echo      That's all ^^_^^.
@echo.

:end
@echo on
