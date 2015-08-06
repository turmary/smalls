#!/bin/sh
################################################
#
# this program convert the Fahr to Celsius
#
################################################


function main(){
	lower=0;
	upper=300;
	step=20;

	echo "Fahr    Celsius";
	fahr=$lower
	while test "$fahr" -le "$upper" ; do
		celsius=`expr $fahr - 32`;
		celsius=`expr 5 \* $celsius`;
		celsius=`expr $celsius / 9`;
		echo "$fahr     $celsius" \
		  | awk '{ printf("%-3d%10d\n", $1, $2) }';
		fahr=`expr $fahr + $step`;
	done
}

main;

