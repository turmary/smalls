:- Action	: 打开Windows7的WiFi热点功能
:- Author	: Tary
@ECHO OFF
CLS
COLOR 2E
ECHO ============= 当前配置 ================
netsh wlan show drivers

ECHO ============= 目标配置 ================
netsh wlan set hostednetwork mode=allow ssid=yanglsh_AP key=19710101

ECHO =======================================
netsh wlan start hostednetwork

@ECHO ON
