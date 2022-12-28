#!/bin/sh

# powershell -c "Get-NetAdapter 'vEthernet (WSL)' | Get-NetIPAddress | Remove-NetIPAddress -Confirm:$False; New-NetIPAddress -IPAddress 172.22.0.1 -PrefixLength 24 -InterfaceAlias 'vEthernet (WSL)'; Get-NetNat | ? Name -Eq WSLNat | Remove-NetNat -Confirm:$False; New-NetNat -Name WSLNat -InternalIPInterfaceAddressPrefix 172.22.0.0/24;"

# echo "yanglsh" | sudo -S ip &> /dev/null
#or
#/etc/sudoers
# %sudo ALL=NOPASSWD: /usr/sbin/service
# %sudo ALL=NOPASSWD: /bin/ip


# static ip
if [ "$(ip addr show eth0 | grep 'inet\b' | awk '{print $2}' | head -n 1)" != "172.22.0.2/24" ]; then
	sudo ip addr del $(ip addr show eth0 | grep 'inet\b' | awk '{print $2}' | head -n 1) dev eth0
	sudo ip addr add 172.22.0.2/24 broadcast 172.22.0.255 dev eth0
	sudo ip route add 0.0.0.0/0 via 172.22.0.1 dev eth0
fi

: <<EOF
# /etc/wsl.conf
[network]
generateResolvConf = false # 不自动生成dns配置，必须
generateHosts = false # 是否生成hosts文件，可选

[interop]
enabled = false # 不能调用Windows进程，可选
appendWindowsPath = false # 不添加Windows路径，可选

# wsl.resolv
echo nameserver 10.0.80.1 >> /etc/wsl.resolv

EOF

# sudo ln -s /etc/wsl.resolv /etc/resolv.conf

# sudo service binfmt-support start
sudo service ssh  start
sudo service xrdp start
