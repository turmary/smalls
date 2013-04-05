@IF NOT "%M5%" == "" GOTO END
@SET M5=D:\MASM
@SET PATH=%M5%;%PATH%
@echo Now you can use ml , options below
@masm /help
:END
