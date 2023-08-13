@setlocal enabledelayedexpansion enableextensions

@echo off
for /f "tokens=1 delims= " %%I in ('wmic cpu get NumberOfLogicalProcessors') do (
	set /a NPROC=%%I >NUL 2>&1
	if /i !NPROC! gtr 0 goto end_nproc
)
:end_nproc

echo NPROC=!NPROC!
