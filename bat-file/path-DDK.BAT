set DDKBASE=D:\DDK\ddk2000
pushd .
call %DDKBASE%\bin\setenv %DDKBASE% checked
path=%DDKBASE%\bin\i386\free;%path%
popd
