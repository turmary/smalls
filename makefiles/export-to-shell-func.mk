#MAKFILE

# get only the variables with plain names
MAKE_ENV := $(shell echo '$(.VARIABLES)' | awk -v RS=' ' '/^[a-zA-Z0-9]+$$/')
SHELL_EXPORT := $(foreach v,$(MAKE_ENV),$(v)='$($(v))')

export SUFFIX
TARGETS1:=$(shell ./targets.sh)
TARGETS2:=$(shell $(SHELL_EXPORT) ./targets.sh)

.PHONY: all $(TARGETS1) $(TARGETS2)
all: $(TARGETS1) $(TARGETS2)

$(TARGETS1):
	echo TARGET1: $@

$(TARGETS2):
	echo TARGET2: $@

#(targets.sh)
#!/bin/bash
#eval echo target$SUFFIX.txt

