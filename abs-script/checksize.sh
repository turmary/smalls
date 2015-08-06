#!/bin/sh
# Name: checksize
# Project: PowerSwitch/AVR-USB
# Author: Christian Starkjohann
# Creation Date: 2004-12-29
# Tabsize: 4
# Copyright: (c) 2005 OBJECTIVE DEVELOPMENT Software GmbH.
# Revision: $Id: checksize 83 2006-01-05 22:20:53Z cs $

error=0
codelimit=2048  # default value
datalimit=96    # default value; leave 32 bytes for stack

if [ $# -gt 1 ]; then
	codelimit="$2"
fi
if [ $# -gt 2 ]; then
	datalimit="$3"
fi

set -- `avr-size -d "$1" | awk '/[0-9]/ {print $1 + $2, $2 + $3, $2}'`

if [ $1 -gt $codelimit ]; then
	echo "*** code size $1 exceeds limit of $codelimit"
	error=1
else
	echo "ROM: $1 bytes (data=$3)"
fi
if [ $2 -gt $datalimit ]; then
	echo "*** data size $2 exceeds limit of $datalimit"
	error=1
else
	echo "RAM: $2 bytes"
fi

exit $error
