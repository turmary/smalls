rem 我的J2SDK装在F:\TaryInstalled\j2sdk1.5.0下
rem 根据你的需要替换下面一行中的F:\TaryInstalled\j2sdk1.5.0
set JAVA_HOME=F:\TaryInstalled\j2sdk1.5.0

IF NOT "%classpath%" == "" GOTO END
set PATH=%JAVA_HOME%\bin;%PATH%
set classpath=.;%JAVA_HOME%\lib\dt.jar;%JAVA_HOME%\lib\tools.jar;%JAVA_HOME%\lib;%JAVA_HOME%\jre\lib\jaws.jar;%JAVA_HOME%\jre\lib\jce.jar;%JAVA_HOME%\jre\lib\sunrsasign.jar;%JAVA_HOME%\jre\lib\jsse.jar;%JAVA_HOME%\jre\lib\charsets.jar;%JAVA_HOME%\jre\lib\rt.jar;%JAVA_HOME%\jre\lib\plugin.jar

:END
