#!/bin/bash

touch NEWS README AUTHORS ChangeLog
# automake --add-missing --copy
autoreconf -v -f -i
./configure
make
