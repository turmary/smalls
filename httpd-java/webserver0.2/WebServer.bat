rem 1>
rem ������JAVA������������ı��벢������
rem �ⲽ���Բ�����
rem �����������������JRE����
rem ��PATH,CLASSPATH��������
@call javapath.bat


rem 2>
rem ������ļ�(WebServer.bat)��webserver.class
rem ����ͬһ���ļ�����,�ⲽ���Բ�������
rem ���ҵĵ�����,��������Ƿ���
rem D:\tmp
rem ��������JAVA����������޸�����Ĳ���
rem D:
rem cd \tmp

rem 3>
rem �¾���������webserver����,��������
rem ʹ�÷�����������
rem java webserver <wwwroot> [port]
rem  <wwwroot> --- ������ҳ�ļ��ĸ��ļ���
rem  [port]    --- �˿ں�,���Բ�Ҫ,Ĭ��80
rem  �ҵ���ҳ�ļ�����root�ļ�����
rem  �������Ҫ�޸�
:label
@java webserver "root" 80
@goto label

rem 4>
rem �������,�ڵ�ַ��������http://127.0.0.1/�ļ���
rem �������ҵĻ�����
rem �����ļ�.\root\index.html
rem ����������http://127.0.0.1/index.html�����������ҳ

rem 5>
rem ���Ҫֹͣ�ó���,
rem ����������,���԰�Ctrl + C
rem ��ȻҲ�ɵ�����Ͻ�X�͹رհ�ť
