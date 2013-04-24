#!/bin/sh

# convert a html file into a c source variable

if [ $# -ne 1 ]; then
	echo "usage: $0 filename";
	exit 1;
fi;

if [ ! -r $1 ]; then
	echo "$0 unexist";
	exit 2;
fi;

fname=${1/./_}
flen=`cat $1 | wc -c`

echo "UINT code ${fname}_len = ${flen};" | awk -F'\n' '{printf("%s\r\n", $1);}'
echo "char code ${fname}[] = {" | awk -F'\n' '{printf("%s\r\n", $1);}'
cat $1 | sed -e 's,\",\\\",g' | awk -F'\n' '{printf("\"%s\\n\"\r\n", $1);}'
echo "};" | awk -F'\n' '{printf("%s\r\n", $1);}'

exit 0;
