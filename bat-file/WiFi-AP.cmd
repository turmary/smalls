:- Action	: ��Windows7��WiFi�ȵ㹦��
:- Author	: Tary
@ECHO OFF
CLS
COLOR 2E
ECHO ============= ��ǰ���� ================
netsh wlan show drivers

ECHO ============= Ŀ������ ================
netsh wlan set hostednetwork mode=allow ssid=yanglsh_AP key=19710101

ECHO ============= ���繲�� ================
echo ѡ����������Internet����������/����, �Ҽ�������ѡ�й���
echo ��ͥ��������ѡ�� ^"������������ 2(Microsoft Virtual WiFi Miniport Adapter)^"
echo ֮����������ͬʱ���������������ȵ㡣
echo ��ɺ�
pause

ECHO =======================================
netsh wlan start hostednetwork

@ECHO ON
