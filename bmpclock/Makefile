NAME = bmpclock
OBJS = $(NAME).obj
RES  = $(NAME).res

LINK_FLAG = /MAP /subsystem:windows kernel32.lib gdi32.lib user32.lib
CL_FLAG = /c /nologo

$(NAME).exe: $(OBJS) $(RES)
	link $(LINK_FLAG) $(OBJS) $(RES)

.c.obj:
	cl $(CL_FLAG) $<

.rc.res:
	rc $<

clean:
	del *.obj
	del *.res
