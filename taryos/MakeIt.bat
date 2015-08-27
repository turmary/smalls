rem @echo off

cd .\bin
del *.exe *.map *.lst
del boot.img
call Makeboot.bat bootsctr
cd ..
pause

cd .\kernel
nmake clean
pause
call mlpath.bat
nmake
pause
call build.bat
cd ..

cd .\test
pause
call run.bat
cd ..

