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
echo 完成后
pause

ECHO =======================================
netsh wlan start hostednetwork

@ECHO ON
