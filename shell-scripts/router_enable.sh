#!/bin/bash

# Action
AC=${1-A}

# Internet Gateway
GATEWAY=192.168.1.1

# Connection to local network
INTF_IN=enp0s10

# Connection to Internet
INTF_OUT=enp0s9

# System control configuration
SYSCTL_CONF=/etc/sysctl.conf


function get_gateway() {
	route -n | grep "UG " | awk '{print $2}'
	return 0
}

: <<'EOF'
function get_address() {
	local fields
	local inf

	inf=${1:-eth0}
	while read line; do
		fields=( $line )
		if [ "${fields[0]}" == inet ]; then
			# echo fields = ${fields[*]}
			break
		fi
	done < <(ifconfig ${inf})

	# fields[1] = addr:192.168.4.152
	echo ${fields[1]} | sed -nr 's/addr:([0-9]+.[0-9]+.[0-9]+.[0-9]+)$/\1/gp'
	return 0
}
EOF

# : <<'EOF'
# Enable network ip forward
grep -Enr "^net.ipv4.ip_forward *= *1" $SYSCTL_CONF > /dev/null; r=$?

if [ "$r" -ne 0 ]; then
	echo "net.ipv4.ip_forward=1" > $SYSCTL_CONF
	sysctl -p
fi

echo 1 > /proc/sys/net/ipv4/ip_forward

# Delete current default route
route del default gw $(get_gateway)
# Add new gateway
route add default gw $GATEWAY

# Accept ip pkts from incoming interface
while iptables -D FORWARD     -t filter  -i $INTF_IN  -j ACCEPT; do :; done
iptables -A FORWARD     -t filter  -i $INTF_IN  -j ACCEPT
# open (s)NAT of the internet interface
while iptables -D POSTROUTING -t nat     -o $INTF_OUT -j MASQUERADE; do :; done
iptables -A POSTROUTING -t nat     -o $INTF_OUT -j MASQUERADE
# EOF

# print iptables
for i in raw mangle filter nat; do
	echo;
	echo -e "\e[32m=================================$i==================================\e[0m";
	echo;
	sudo iptables -t $i -L -v -n;
done

exit 0

