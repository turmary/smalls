
DELAY=${SHELL}
IM:=${SHELL}

c:n

ifeq (y,y)
define macro
a:b
c
$(warning $0() )
endef

define multiline
multi;
echo -ne line
endef
 
# "c:n"
w:x y e

e:f g

x:a

f: p q i

g:h i

$(shell echo $(call macro) 1>&2 )
# $(call macro)
$(strip $(call macro))
X:=$(call multiline)
# $(eval $(call macro))

endif # (y,y)
# macro=ab:helloworld

# $(error Hello World!)

$(shell { echo -n '$(call macro)' | od -t x1; } 1>&2 )

n:
	echo -n $(value X) | od -t x1
	echo $(addprefix hello, world list)
	# $(foreach v,1 2,$(addprefix foreach,$(v)))
	$(foreach v,1 2,$(warning $(addprefix foreach,$(v))))
	@echo > /dev/null
#	echo hello

        # echo A $$0
	# echo B $$0
# $(foreach v,$(.VARIABLES),$(warning $v = $(value $v)))

# $(foreach v,$(.VARIABLES),$(warning $v = $(value $v)))

h: n

.PHONY: w e x y f g a p q h i b c n

$(warning endfile)
