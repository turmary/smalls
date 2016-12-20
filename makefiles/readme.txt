# Makefile生成依赖关系图
make -f mkfile-dep.mk NEST_MKFILE=Makefile NEST_TARGET="ARCH=arm help"

make --debug w 2>&1 | ./mkfile-dot.sh | dot -Tjpg > Makefile-dynamic.jpg
