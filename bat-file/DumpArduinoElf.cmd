:- Action    : Copy the latest Arduino built elf file to current directory
:- License   : MIT License
:- Author    : Tary
:- Date      : 2020-01-08

@ECHO OFF
SETLOCAL EnableExtensions
SETLOCAL EnableDelayedExpansion

SET TOOLPATH=%LOCALAPPDATA%\Arduino15\packages\arduino\tools\arm-none-eabi-gcc\4.8.3-2014q1\bin
SET OBJDUMP=arm-none-eabi-objdump


SETLOCAL

CALL :FindLatestFile "%TMP%" "*.elf" FULLPATH
IF "!FULLPATH!" EQU "" (
	ECHO Not found any Arduino ELF ^^!^^!^^!
	PAUSE
	GOTO :EOF
)

ECHO ############ Latest Arduino ELF ############
ECHO !FULLPATH!
ECHO --------------------------------------------

CALL :GetFilePath FILEPATH !FULLPATH!
:- ECHO Latest file path = !FILEPATH!

CALL :GetFileName  FILENAME !FULLPATH!
CALL :GetMainName MAIN_NAME !FILENAME!
:- ECHO Latest main name = !MAIN_NAME!

COPY %FILEPATH%\%MAIN_NAME%.elf . >NUL
ECHO COPIED    %MAIN_NAME%.elf ^^!

COPY %FILEPATH%\%MAIN_NAME%.map . >NUL
ECHO COPIED    %MAIN_NAME%.map ^^!

%TOOLPATH%\%OBJDUMP% -x -d -S -z %FILEPATH%\%MAIN_NAME%.elf > %MAIN_NAME%.lss
IF %ERRORLEVEL% EQU 0 (
	ECHO GENERATED %MAIN_NAME%.lss ^^!
) ELSE (
	ECHO GENERATE  %MAIN_NAME%.lss failed
	ECHO Try fix the path of objdump
	ECHO  Current objdump PATH: %TOOLPATH%
	ECHO  Current objdump NAME: %OBJDUMP%
)


GOTO :EOF





:FindLatestFile locate filter name
:: -- locate [in] root folder to find file
:: -- filter [in] to match the file name, exclude path part.
:: -- name  [out] latest(changed) file
	SETLOCAL
	SET F=

	PUSHD %~1
	FOR /R %%I IN (%~2) DO (
		IF "!F!" EQU "" (
			SET F=%%I
			:- Not allowed GOTO :LABEL in for loop
			REM GOTO :NEXT_FOR
		) ELSE (
			:NEXT_FOR
			CALL :CmpFTime GTR %%I !F!
			:- echo ERRORLEVEL=!ERRORLEVEL!
			IF !ERRORLEVEL! EQU 0 ( SET F=%%I )
		)
	)
	POPD
	(
		ENDLOCAL
		SET %~3=%F%
	)
EXIT /B



:GetFileName
REM -- Get the file name in the path
	SETLOCAL
	SET FILENAME=%~nx2
	(
		ENDLOCAL & REM -- RETURN VALUES
		IF "%~1" NEQ "" (
			SET %~1=%FILENAME%
		)
	)
GOTO :EOF



:GetFilePath
REM -- Get the file path in the full path
	SETLOCAL
	SET FILEPATH=%~dp2
	(
		ENDLOCAL & REM -- RETURN VALUES
		IF "%~1" NEQ "" (
			SET %~1=%FILEPATH%
		)
	)
GOTO :EOF



:GetMainName
REM -- Get the file name main part, exclude ext name
	SETLOCAL
	SET MAINNAME=%~n2
	(
		ENDLOCAL & REM -- RETURN VALUES
		IF "%~1" NEQ "" (
			SET %~1=%MAINNAME%
		)
	)
GOTO :EOF



:CmpFTime op file1 file2 attr1 attr2 -- compares the time of two files, succeeds if condition is met, fails otherwise
::  -- op    [in]     - compare operator, see 'IF /?', i.e.EQU, NEQ, LSS, LEQ, GTR, GEQ
::  -- fileL [in]     - file name, left side of comparisation
::  -- file2 [in]     - file name, right side of comparisation
::  -- attrL [in,opt] - time field to be used for fileL, see 'dir /?', i.e. /tc, /ta, /tw, default is /tw
::  -- attrR [in,opt] - time field to be used for fileR, default is attrL
:$created 20060101 :$changed 20080219 :$categories DateAndTime,FileOperation
:$source https://www.dostips.com
	SETLOCAL
	set op=%~1
	set fileL=%~2
	set fileR=%~3
	set attrL=%~4
	set attrR=%~5
	if "%op%"=="" set op===
	if "%attrL%"=="" set attrL=/tw
	if "%attrR%"=="" set attrR=%attrL%
	for /f "tokens=1-6 delims=/: " %%a in ('"dir %attrL% /-c "%fileL%"|findstr "^^[0-9]""') do (
		set TL=%%a%%b%%c%%d%%e
	)
	for /f "tokens=1-6 delims=/: " %%a in ('"dir %attrR% /-c "%fileR%"|findstr "^^[0-9]""') do (
		set TR=%%a%%b%%c%%d%%e
	)
	:- ECHO TL=%TL% TR=%TR%
	if "%TL%" %op% "%TR%" (rem.) ELSE set=2>NUL
EXIT /b
