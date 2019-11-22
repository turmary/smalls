#!/bin/bash

# set -x

SDIO_BASE="brcmfmac43430a0-sdio.base"
SDIO_TEXT="/lib/firmware/brcm/brcmfmac43430a0-sdio.txt"
OPT_RESULT=$(basename $0)-`date +"%Y%m%d"`.txt

WIFI_AP="192.168.250.1"
THIS_IP="192.168.250.83"
ping_cmd="ping -c 6 -W 1 -s 16384 $WIFI_AP"

#pa2ga0=-168,7161,-820

: > $OPT_RESULT

# for ((i = 700; i < 900; i += 10)); do
# for ((i = 6849; i < 6861; i += 1)); do
for ((i = 100; i < 125; i += 1)); do
	PA2GA0_LINE="pa2ga0=-$i,6854,-820"
	# PA2GA0_LINE="pa2ga0=-168,$i,-820"
	# PA2GA0_LINE="pa2ga0=-105,7161,-$i"

	# Reinsert brcmfmac module
	# to take effect of $SDIO_TEXT changing
	modprobe -r brcmfmac
	sleep 1;
	{
		cat $SDIO_BASE
		echo $PA2GA0_LINE
	} > $SDIO_TEXT
	modprobe brcmfmac

	# Wait the wlan connected some one WiFi AP.
	until ifconfig wlan0 > /dev/null; do
		sleep 1;
	done
	for (( k = 0; k < 8; k++ )); do
		if iw dev wlan0 link | egrep "Connected to" > /dev/null; then
			break
		fi
		sleep 1;
	done

	# Test ping's performance
	ifconfig wlan0 $THIS_IP
	sleep 1

	# A warm up
	ping -c 10 $WIFI_AP

	ping_out=$( $ping_cmd | tee /dev/stderr | tail -n 2)
	{
		echo "# $PA2GA0_LINE"
		echo $ping_out
	} | tee /dev/stderr >> $OPT_RESULT
	echo; echo
done
