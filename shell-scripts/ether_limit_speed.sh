#!/bin/bash

# Action
AC=${1-A}

function ether_dev_get() {
	local i

	for i in $(ls /sys/class/net); do
		if [ -e "/sys/class/net/${i}/phydev" -o \
		     -e "/sys/class/net/${i}/device" ]; then
			echo -ne "${i}"
			break
		fi
	done
	return 0
}

function show_setting() {
	tc qdisc  show dev $ETH
	tc class  show dev $ETH
	tc filter show dev $ETH
	return 0
}

function limit_speed() {
	tc qdisc del dev $ETH root
	tc qdisc add dev $ETH root sfq perturb 10

	# Samba incomming speed limitation
	: <<-EOF
	# bad effect, made SAMBA transfer unstable
	AC=A
	FILTER_RULE="-t filter  -p tcp -s 10.0.85.56 -m limit --limit 7000/second -j ACCEPT"
	iptables -$AC INPUT $FILTER_RULE

	FILTER_RULE="-t filter  -p tcp -s 10.0.85.56 -j DROP"
	iptables -$AC INPUT $FILTER_RULE

	# no obvious effect
	FILTER_RULE="-t filter  -p tcp -s 10.0.85.56 -m limit --limit 7000/second -j ACCEPT"
	iptables -$AC INPUT $FILTER_RULE

	FILTER_RULE="-t filter  -p tcp -s 10.0.85.56 -j DROP"
	iptables -$AC INPUT $FILTER_RULE
	EOF


	# https://making.pusher.com/per-ip-rate-limiting-with-iptables/index.html
	[ "X$AC" == "XD" ] || {
		iptables --new-chain SAMBA-RATE
	}
	iptables -$AC SAMBA-RATE --match hashlimit \
	  --hashlimit-mode srcip --hashlimit-upto 2000/sec --hashlimit-burst 4000 \
	  --hashlimit-name conn_rate_limit --jump ACCEPT
	iptables -$AC SAMBA-RATE --jump DROP
	iptables -$AC INPUT -p tcp --dport 139 --jump SAMBA-RATE
	iptables -$AC INPUT -p tcp --dport 445 --jump SAMBA-RATE
	[ "X$AC" == "XD" ] && {
		iptables --delete-chain SAMBA-RATE
	}

	iptables -v -L SAMBA-RATE
	return 0
}

ETH=$(ether_dev_get)
BORDER=$(printf '=%.0s' {1..80})

echo "$BORDER"
echo -e "HISTORY tc settings on \e[32m$ETH\e[0m"
echo "$BORDER"
show_setting
echo -e "\n\n\n"

limit_speed

echo "$BORDER"
echo -e "CURRENT tc settings on \e[32m$ETH\e[0m"
echo "$BORDER"
show_setting
echo -e "\n\n\n"

