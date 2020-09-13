@echo off
setlocal ENABLEDELAYEDEXPANSION
set N=%1
set S=

for /F "skip=1 tokens=2,5" %%I in ('wmic service list brief') do (
	:- echo %%I %%J
	if "%%I" equ "!N!" (
		set S=%%J
	)
)

echo SERVICE !N! STATE IS !S!
