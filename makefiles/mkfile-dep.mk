# tary, 20:28 2016/12/17
# mkfile-dep.mk

ECHO=echo
AWK =awk
DOT =dot
RM  =rm -rf

NEST_MKFILE ?= Makefile
NEST_ARG    ?= 
NEST_TARGET ?= 

_this_file := $(strip ${MAKEFILE_LIST})
TARGET     := mkfile-dep
g          := $(NEST_MKFILE)-dep

all: $(TARGET)

$(shell echo "NEST_TARGET($(_this_file))=${NEST_TARGET}" 1>&2 )

# -include $(NEST_MKFILE)

unexport 		\
MAKEFILES 		\
MAKEFILES_LIST 		\
VPATH 			\
MAKESHELL 		\
MAKE 			\
MAKELEVEL 		\
MAKEFLAGS 		\
MAKECMDGOALS 		\
CURDIR 			\
SUFFIXES 		\
.LIBPATTERNS		\
NEST_MKFILE 		\
NEST_ARG 		\
NEST_TARGET

$(TARGET):
	@ $(ECHO) "digraph g{" > $g.dot
	@ $(ECHO) "$(MAKE) -f $(NEST_MKFILE) $(NEST_ARG) $(NEST_TARGET)"
	@ $(MAKE) -f $(NEST_MKFILE) $(NEST_ARG) $(NEST_TARGET) 	\
			--print-data-base --question |		\
	$(AWK) -F' ' '/^[^.!%][-A-Za-z0-9_.]*:/ {		\
		gsub(/-/, "_");					\
		gsub(/\//, "_");				\
		gsub(/\./, "_");				\
		gsub(/@/, "_");					\
		gsub(/\\/, "_");				\
		print;						\
	}' |							\
	$(AWK) -F' ' '{						\
		arg1 = substr($$1, 1, length($$1)-1);		\
		for(i = 2; i <= NF; i++) {			\
			printf("\t%s -> %s;\n", arg1, $$i);	\
		}						\
	}' >> $g.dot
	@ $(ECHO) "}" >> $g.dot
	@ $(DOT) -Tjpg $g.dot >$g.jpg
	@ $(RM) $g.dot

.PHONY: all $(TARGET)

