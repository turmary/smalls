#!/bin/bash

while read line; do
	echo $line;
	echo BLINK;
done < <(dd if=/dev/fd/0 status=progress bs=1)

