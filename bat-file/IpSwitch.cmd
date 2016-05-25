:- Action	: 在两个IP地址之间切换
:- Author	: Tary
@ECHO OFF
CLS
COLOR 2E
NETSH interface ip show address >IPLIST.TXT
ECHO ============= 当前配置 ================
TYPE IPLIST.TXT

SET THISIP=""
SET THISGATEWAY=192.192.192.101
SET THISMASK=255.255.255.0
SET THISDNS=192.192.192.248
SET THISDNS2=8.8.8.8

SET IP1=192.192.192.147
SET IP2=192.192.192.202
:- default value if no set
SET THISIP=%IP1%

FIND "%IP1%" IPLIST.TXT >IPITEM.TXT
FOR /F "skip=1 tokens=3" %%I IN (IPITEM.TXT) DO (
	IF "PRE%%I"=="PRE%IP1%" (
		SET THISIP=%IP2%
	)
)

DEL IPLIST.TXT
DEL IPITEM.TXT

ECHO ============= 目标配置 ================
ECHO    IP地址:	%THISIP%
ECHO    网关:	%THISGATEWAY%
ECHO    DNS:	%THISDNS%
ECHO =======================================
NETSH interface ip set address name="本地连接" source=static addr=%THISIP% mask=%THISMASK% gateway=%THISGATEWAY% 1
NETSH interface ip set dns name="本地连接" source=static addr=%THISDNS%
NETSH interface ip add dns name="本地连接" addr=%THISDNS2% index=2

@ECHO ON
