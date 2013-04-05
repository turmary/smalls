@echo off
echo a
if "%1" == "" (set var=*) else (set var=%1)
echo b
for %%j IN (%var%) do (
        echo %%j
        echo //////////////////Content/////////////////////
        type %%j
        echo.
        echo.
)
echo on
