:- Action	: 打开Windows7的WiFi热点功能
:- Author	: Tary
@ECHO OFF
CLS
COLOR 2E
ECHO ============= 当前配置 ================
netsh wlan show drivers

ECHO ============= 目标配置 ================
netsh wlan set hostednetwork mode=allow ssid=yanglsh_AP key=19710101

ECHO ============= 网络共享 ================
echo 选中用于连接Internet的网络连接/网卡, 右键属性中选中共享
echo 家庭网络连接选中 ^"无线网络连接 2(Microsoft Virtual WiFi Miniport Adapter)^"
echo 之后无线网卡同时用于联网并当做热点。
echo ^/--------------------------------------------------------------^\
echo ^|请确保物理无线网卡处理未连接状态，否则虚拟连接出现但是不可用。^|
echo ^\--------------------------------------------------------------^/
echo 完成后
pause

ECHO =======================================
netsh wlan start hostednetwork
netsh wlan show hostednetwork

:- ROUTE ADD     0.0.0.0  MASK 0.0.0.0  192.168.8.1  METRIC 50  IF 17
:- ROUTE CHANGE  0.0.0.0  MASK 0.0.0.0  192.168.8.1  METRIC 20  IF 17
:- ROUTE DELETE  0.0.0.0  MASK 0.0.0.0  192.168.8.1

@ECHO ON

