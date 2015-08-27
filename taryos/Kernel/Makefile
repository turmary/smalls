ALL : "main.exe" "main.img"


CLEAN :
	-@erase "..\Entry\Entry.obj"
	-@erase "main.obj"
	-@erase "main.exe"
	-@erase "main.map"
	-@erase "main.img"

CC=cl
CC_FLAGS= /nologo /ML /W3 /GX /O2 /c 

.c{$(INTDIR)}.obj::
   $(CC) @<<
   $(CC_FLAGS) $< 
<<
	
LINK=link
LINK_FLAGS= /nologo /base:"0x00000000" /entry:"main" /pdb:none /map:"main.map" /machine:I386 /out:"main.exe" /fixed 
LINK_OBJS= \
	"..\Entry\Entry.obj" \
	"main.obj" 

"main.exe" : $(LINK_OBJS)
    $(LINK) @<<.\TMP00.LNK
  $(LINK_OBJS)
  $(LINK_FLAGS) 
<<

"main.img" : $(SOURCE)
	Exe2Img /verbose main.exe



SOURCE=.\main.c

"main.obj" : $(SOURCE)


"..\Entry\Entry.obj":
	@cd ..\Entry
	@nmake -A
	@cd ..\Kernel
