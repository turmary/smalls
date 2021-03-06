#!/bin/bash

# Internet Gateway
GATEWAY=192.168.4.2

# Connection to local network
INTF_IN=usb0

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
iptables -A FORWARD     -t filter  -i $INTF_IN  -j ACCEPT
# open (s)NAT of the internet interface
iptables -A POSTROUTING -t nat     -o $INTF_OUT -j MASQUERADE

# print iptables
for i in raw mangle filter nat; do
	echo;
	echo "=================================$i==================================";
	echo;
	sudo iptables -t $i -L -v -n;
done

exit 0

