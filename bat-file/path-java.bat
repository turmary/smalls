rem �ҵ�J2SDKװ��F:\TaryInstalled\j2sdk1.5.0��
rem ���������Ҫ�滻����һ���е�F:\TaryInstalled\j2sdk1.5.0
set JAVA_HOME=F:\TaryInstalled\j2sdk1.5.0

IF NOT "%classpath%" == "" GOTO END
set PATH=%JAVA_HOME%\bin;%PATH%
set classpath=.;%JAVA_HOME%\lib\dt.jar;%JAVA_HOME%\lib\tools.jar;%JAVA_HOME%\lib;%JAVA_HOME%\jre\lib\jaws.jar;%JAVA_HOME%\jre\lib\jce.jar;%JAVA_HOME%\jre\lib\sunrsasign.jar;%JAVA_HOME%\jre\lib\jsse.jar;%JAVA_HOME%\jre\lib\charsets.jar;%JAVA_HOME%\jre\lib\rt.jar;%JAVA_HOME%\jre\lib\plugin.jar

:END
