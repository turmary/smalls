#!/bin/sh

exec 3>&1

alias grep='grep --color=auto'

cmd="./oe | grep write"
echo ${cmd}
./oe | grep write

cmd="./oe >/dev/null | grep write"
echo ${cmd}
./oe >/dev/null | grep write

cmd="./oe 1>&- | grep write"
echo ${cmd}
./oe 1>&- | grep write

cmd="./oe 2>&- | grep write"
echo ${cmd}
./oe 2>&- | grep write

exec 3>&-

