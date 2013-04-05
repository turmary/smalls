@ECHO OFF
IF NOT EXIST "%1.ASM" (
	ECHO FILE IN'T EXIST  OR NO ENOUGH PARAMETER! && GOTO END
)
ECHO //////////////////////ASSEMBLING///////////////////////////
TASM %1 %1.OBJ >TOUT.TXT
TYPE TOUT.TXT
IF NOT "%3" == "" (NOTEPAD TOUT.TXT)
IF NOT ERRORLEVEL 0 GOTO END
ECHO.
ECHO //////////////////////LINKING//////////////////////////////
IF NOT "%2" == "c" (TLINK %1;)
IF NOT ERRORLEVEL 0 GOTO END
ECHO.
ECHO //////////////////////RUNNING//////////////////////////////
IF NOT "%2" == "c" %1
IF "%2" == "o" (
	DEL %1.OBJ
	GOTO END )
IF "%2" == "e" (
	DEL %1.EXE | GOTO END)
IF "%2" == "oe" (
	DEL %1.OBJ
	DEL %1.EXE
	DEL %1.MAP
	GOTO END)
:END
@ECHO ON
