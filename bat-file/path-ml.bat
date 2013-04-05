@IF NOT "%MLINC%" == "" GOTO END
@SET PATH=D:\MASM32\BIN;%PATH%
@SET MLINC=D:\MASM32\INCLUDE
@SET MLLIB=D:\MASM32\LIB
@echo Now you can use ml , options below
@ml /?
@echo such as ml /I%%MLINC%% /coff ^<FILE.ASM^> /link /LIBPATH:%%MLLIB%%
@echo         usage: LINK [options] [files] [@commandfile]
:END
