:- Action	: ��Windows7��WiFi�ȵ㹦��
:- Author	: Tary
@ECHO OFF
CLS
COLOR 2E
ECHO ============= ��ǰ���� ================
netsh wlan show drivers

ECHO ============= Ŀ������ ================
netsh wlan set hostednetwork mode=allow ssid=yanglsh_AP key=19710101

ECHO =======================================
netsh wlan start hostednetwork

@ECHO ON
