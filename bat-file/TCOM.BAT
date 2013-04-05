@echo off
set TC20=d:\tc20
%TC20%\tcc -S -I%TC20%\include -L%TC20%\lib -n%TC20%\tmp %1.c %TC20%\lib\graphics.lib
@echo on
