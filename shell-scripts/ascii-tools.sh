#!/bin/bash
# tary

hex_digits='0123456789ABCDEF'

dec_to_hex_r=0
dec_to_hex() {
	local low
	local hi

	dec=$1
	# echo $dec
	((hi = $dec / 16))
	((low = $dec % 16))
	hi=${hex_digits:$hi:1}
	low=${hex_digits:$low:1}
	# echo $hi,$low
	dec_to_hex_r=$hi$low
}

# dec_to_hex ${1:-0}
# echo $dec_to_hex_r

for ((i = 0; i < 256; i++)); {
	dec_to_hex $i
	c=`echo -ne "\x$dec_to_hex_r"`
	# echo -ne $c
	pos=$(expr index "$hex_digits" "\\$c")
	r=$?
	if ((r > 1)); then
		echo $i error!
	else
		((pos > 0)) && echo "$i: $pos"
	fi
	# echo -ne $c>>file.txt
}

exit 0

