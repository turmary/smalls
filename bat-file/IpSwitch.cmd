:- Action	: ������IP��ַ֮���л�
:- Author	: Tary
@ECHO OFF
CLS
COLOR 2E
NETSH interface ip show address >IPLIST.TXT
ECHO ============= ��ǰ���� ================
TYPE IPLIST.TXT

SET THISIP=""
SET THISGATEWAY=192.192.192.101
SET THISMASK=255.255.255.0
SET THISDNS=202.96.128.166

SET IP1=192.192.192.184
SET IP2=192.192.192.154
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

ECHO ============= Ŀ������ ================
ECHO    IP��ַ:	%THISIP%
ECHO    ����:	%THISGATEWAY%
ECHO    DNS:	%THISDNS%
ECHO =======================================
NETSH interface ip set address name="��������" source=static addr=%THISIP% mask=%THISMASK% gateway=%THISGATEWAY% 1
NETSH interface ip set dns name="��������" source=static addr=%THISDNS%

@ECHO ON