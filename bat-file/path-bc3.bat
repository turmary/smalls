@echo off
echo.
IF NOT "%BC3INC%" == "" GOTO END
SET BC3INC=D:\BC30\INCLUDE
SET BC3LIB=D:\BC30\LIB
SET PATH=D:\BC30\BIN;%PATH%
echo 使用下列方式编译FILE.C
echo bcc -c -ml -I%BC3INC% -L%BC3LIB% ^<FILE.C^>
echo.
:END
