# Microsoft Developer Studio Generated NMAKE File, Based on First_DLL.dsp
!IF "$(CFG)" == ""
CFG=First_DLL - Win32 Debug
!MESSAGE No configuration specified. Defaulting to First_DLL - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "First_DLL - Win32 Release" && "$(CFG)" != "First_DLL - Win32 Debug"
!MESSAGE 指定的配置 "$(CFG)" 无效.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "First_DLL.mak" CFG="First_DLL - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "First_DLL - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "First_DLL - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "First_DLL - Win32 Release"

OUTDIR=.
INTDIR=.
# 开始自定义宏
OutDir=.
# 结束自定义宏

ALL : "$(OUTDIR)\First_DLL.dll"


CLEAN :
	-@erase "$(INTDIR)\First_DLL.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\First_DLL.dll"
	-@erase "$(OUTDIR)\First_DLL.exp"
	-@erase "$(OUTDIR)\First_DLL.lib"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "FIRST_DLL_EXPORTS" /Fp"$(INTDIR)\First_DLL.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\First_DLL.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /incremental:no /pdb:"$(OUTDIR)\First_DLL.pdb" /machine:I386 /out:"$(OUTDIR)\First_DLL.dll" /implib:"$(OUTDIR)\First_DLL.lib" 
LINK32_OBJS= \
	"$(INTDIR)\First_DLL.obj"

"$(OUTDIR)\First_DLL.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "First_DLL - Win32 Debug"

OUTDIR=.
INTDIR=.
# 开始自定义宏
OutDir=.
# 结束自定义宏

ALL : "$(OUTDIR)\First_DLL.dll"


CLEAN :
	-@erase "$(INTDIR)\First_DLL.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\First_DLL.dll"
	-@erase "$(OUTDIR)\First_DLL.exp"
	-@erase "$(OUTDIR)\First_DLL.ilk"
	-@erase "$(OUTDIR)\First_DLL.lib"
	-@erase "$(OUTDIR)\First_DLL.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "FIRST_DLL_EXPORTS" /Fp"$(INTDIR)\First_DLL.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ  /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\First_DLL.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /incremental:yes /pdb:"$(OUTDIR)\First_DLL.pdb" /debug /machine:I386 /out:"$(OUTDIR)\First_DLL.dll" /implib:"$(OUTDIR)\First_DLL.lib" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\First_DLL.obj"

"$(OUTDIR)\First_DLL.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("First_DLL.dep")
!INCLUDE "First_DLL.dep"
!ELSE 
!MESSAGE Warning: cannot find "First_DLL.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "First_DLL - Win32 Release" || "$(CFG)" == "First_DLL - Win32 Debug"
SOURCE=.\First_DLL.C

"$(INTDIR)\First_DLL.obj" : $(SOURCE) "$(INTDIR)"



!ENDIF 

