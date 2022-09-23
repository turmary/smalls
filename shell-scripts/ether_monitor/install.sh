#!/bin/bash

if [[ $EUID -ne 0 ]]; then
	echo "This script must be run as root (use sudo)" 1>&2
	exit 1
fi

cp ether-monitor /usr/bin/
cp ether-monitor.service /etc/systemd/system/
systemctl enable ether-monitor.service
systemctl start  ether-monitor

exit 0

