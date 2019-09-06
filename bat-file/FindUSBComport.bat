
@echo off
setlocal EnableDelayedExpansion

set port=
set find=%SystemRoot%\System32\find

for /f "tokens=2" %%g in ('MODE ^| %find% "COM"') do (
    MODE %%g BAUD=230400 DATA=8 | %find% "COM" >nul

    set errno=!errorlevel!

    if /i !errno! EQU 0 @(
        Rem echo ERRORLEVEL=!errno! PORT=%%g
        set "port=%%g"
    )
)

if not X%port% == X (
	echo %port% is a USB Com Port.
) else (
	echo USB Com Port not found.
)
pause
