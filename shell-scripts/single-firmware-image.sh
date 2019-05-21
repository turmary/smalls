#!/bin/bash
# tary, 17:34 2019/3/19

target=mpy-fw-esp32-fpga-20190319.bin

function dup_string() {
	local ch="$1"
	local len=$2

	ret=$(printf "%0${len}d\n" 0 | tr "0" "$(echo -ne "$ch")")

	echo -ne "${ret}"
	return 0;
}

last_addr=0
rm -f ${target}

for i in 0x1000 bootloader/bootloader.bin  0x8000 partitions_mpy.bin 0xf000 phy_init_data.bin 0x10000 MicroPython.bin; do
	if [[ "$i" =~ ^0x[0-9A-Fa-f]+ ]]; then
		# echo $i;
		size=$(( i - last_addr ))

		fill=$(dup_string "\\xFF" $size)
		fn=$(mktemp)
		echo -ne "${fill}" > $fn
	else
		fn=$i
	fi

	fs=`ls -l ${fn} | awk '{ print $5 }'`
	echo "file-name=$fn file-size=${fs}"

	dd if=${fn} of=${target} seek=${last_addr} bs=1 conv=notrunc >/dev/null 2>&1

	last_addr=$(( last_addr + fs ))
done
