IF NOT EXIST A:\NUL CALL ..\TEST\Run.bat NORUN
CALL MLPATH.BAT
:- CALL VCVARS32.BAT
CALL BC5PATH.BAT
NMAKE -A

ECHO w 0100 0 0 1 >Debug.txt
ECHO q >>Debug.txt
DEBUG ..\bin\Bootsctr.img < Debug.txt
REM DEBUG ..\bin\Boot.img ^< Debug.txt
DEL Debug.txt
DEL A:\main.img
COPY main.img A:\
