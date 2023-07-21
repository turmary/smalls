@setlocal enabledelayedexpansion enableextensions

@echo off
for /f "tokens=1 delims= " %%I in ('wmic cpu get NumberOfLogicalProcessors') do (
	set /A V=%%I >NUL 2>&1
	if not X!V!==X (
		set NPROC=!V!
	)
)

echo !NPROC!
