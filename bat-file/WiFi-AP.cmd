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
echo ^/--------------------------------------------------------------^\
echo ^|��ȷ������������������δ����״̬�������������ӳ��ֵ��ǲ����á�^|
echo ^\--------------------------------------------------------------^/
echo ��ɺ�
pause

ECHO =======================================
netsh wlan start hostednetwork
netsh wlan show hostednetwork

:- ROUTE ADD     0.0.0.0  MASK 0.0.0.0  192.168.8.1  METRIC 50  IF 17
:- ROUTE CHANGE  0.0.0.0  MASK 0.0.0.0  192.168.8.1  METRIC 20  IF 17
:- ROUTE DELETE  0.0.0.0  MASK 0.0.0.0  192.168.8.1

@ECHO ON

