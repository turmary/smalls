REM ����LCC-WIN 3.2 �Ļ���·��
REM ���б��ļ���,ʹ�����·�������FILE.C�ļ�
REM LCC -c -g2 -S -I%%LCCINC%% -L%%LCCLIB%% <FILE.C>
REM ʹ�����·�������FILE.OBJ
REM LCCLNK -subsystem console -o <FILE.EXE> FILE.OBJ $(LIBS)
IF NOT "%LCCINC%" == "" GOTO END
SET PATH=D:\LCC\BIN;%PATH%
SET LCCINC=D:\LCC\INCLUDE
SET LCCLIB=D:\LCC\LIB
:END