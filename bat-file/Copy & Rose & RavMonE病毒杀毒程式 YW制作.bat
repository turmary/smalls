
@ echo off
title 湖南科技大学建筑与城乡规划学院 YW制作
@echo.
@ECHO.    ********************************************
@echo     *  欢迎使用YW校园版杀毒程式 版本号 V1.1.0  *
@echo     *  湖南科技大学建筑与城乡规划学院 YW 制作  *
@echo     *  联系E-mail:yw1530@126.com  QQ:50199907  *
@ECHO.    ********************************************
@echo.
@echo     本程式专杀copy.exe、host.exe、rose.exe和RavMonE.exe病毒，在杀毒之前请确认yw.reg文件与本程式在同一个目录下。
@ECHO.
@echo     病毒症状：双击盘符不能正常打开，在盘符上单击右键，出现的菜单第一项为“自动播放”。
@ECHO.
@echo     本程式能够查杀所有盘符内的病毒，包括软驱和光驱（只针对刻录机和可刻录光盘）。
@ECHO.
@Pause
@ECHO.
@ECHO.
@ECHO.
@echo -------------正在停止病毒进程...-------------
@taskkill /im temp1.exe /f /t
@taskkill /im temp2.exe /t /f
@taskkill /im RavMonE.exe /t /f
@echo -------------停止病毒进程成功！-------------
@ECHO.
@echo -------------正在删除关键性病毒文件...-------------
@ del c:\windows\xcopy.exe /a /f
@ del c:\windows\svchost.exe /a /f
@ del c:\windows\system32\temp1.exe /a /f
@ del c:\windows\system32\temp2.exe /a /f

@ del d:\windows\xcopy.exe /a /f
@ del d:\windows\svchost.exe /a /f
@ del d:\windows\system32\temp1.exe /a /f
@ del d:\windows\system32\temp2.exe /a /f

@ del e:\windows\xcopy.exe /a /f
@ del e:\windows\svchost.exe /a /f
@ del e:\windows\system32\temp1.exe /a /f
@ del e:\windows\system32\temp2.exe /a /f

@ del f:\windows\xcopy.exe /a /f
@ del f:\windows\svchost.exe /a /f
@ del f:\windows\system32\temp1.exe /a /f
@ del f:\windows\system32\temp2.exe /a /f

@ del g:\windows\xcopy.exe /a /f
@ del g:\windows\svchost.exe /a /f
@ del g:\windows\system32\temp1.exe /a /f
@ del g:\windows\system32\temp2.exe /a /f
@echo -------------关键性病毒文件删除成功！-------------
@echo.
@echo -------------正在删除病毒文件...-------------
@ del a:\autorun.inf /a /f
@ del a:\copy.exe /a /f
@ del a:\host.exe /a /f
@ del a:\rose.exe /a /f
@ del a:\RavMonE.exe /a /f

@ del b:\autorun.inf /a /f
@ del b:\copy.exe /a /f
@ del b:\host.exe /a /f
@ del b:\rose.exe /a /f
@ del b:\RavMonE.exe /a /f

@ del c:\autorun.inf /a /f
@ del c:\copy.exe /a /f
@ del c:\host.exe /a /f
@ del c:\rose.exe /a /f
@ del c:\RavMonE.exe /a /f

@ del d:\autorun.inf /a /f
@ del d:\copy.exe /a /f
@ del d:\host.exe /a /f
@ del d:\rose.exe /a /f
@ del d:\RavMonE.exe /a /f

@ del e:\autorun.inf /a /f
@ del e:\copy.exe /a /f
@ del e:\host.exe /a /f
@ del e:\rose.exe /a /f
@ del e:\RavMonE.exe /a /f

@ del f:\autorun.inf /a /f
@ del f:\copy.exe /a /f
@ del f:\host.exe /a /f
@ del f:\rose.exe /a /f
@ del f:\RavMonE.exe /a /f

@ del g:\autorun.inf /a /f
@ del g:\copy.exe /a /f
@ del g:\host.exe /a /f
@ del g:\rose.exe /a /f
@ del g:\RavMonE.exe /a /f

@ del h:\autorun.inf /a /f
@ del h:\copy.exe /a /f
@ del h:\host.exe /a /f
@ del h:\rose.exe /a /f
@ del h:\RavMonE.exe /a /f

@ del i:\autorun.inf /a /f
@ del i:\copy.exe /a /f
@ del i:\host.exe /a /f
@ del i:\rose.exe /a /f
@ del i:\RavMonE.exe /a /f

@ del j:\autorun.inf /a /f
@ del j:\copy.exe /a /f
@ del j:\host.exe /a /f
@ del j:\rose.exe /a /f
@ del j:\RavMonE.exe /a /f

@ del k:\autorun.inf /a /f
@ del k:\copy.exe /a /f
@ del k:\host.exe /a /f
@ del k:\rose.exe /a /f
@ del k:\RavMonE.exe /a /f

@ del l:\autorun.inf /a /f
@ del l:\copy.exe /a /f
@ del l:\host.exe /a /f
@ del l:\rose.exe /a /f
@ del l:\RavMonE.exe /a /f

@ del m:\autorun.inf /a /f
@ del m:\copy.exe /a /f
@ del m:\host.exe /a /f
@ del m:\rose.exe /a /f
@ del m:\RavMonE.exe /a /f

@ del n:\autorun.inf /a /f
@ del n:\copy.exe /a /f
@ del n:\host.exe /a /f
@ del n:\rose.exe /a /f
@ del n:\RavMonE.exe /a /f

@ del o:\autorun.inf /a /f
@ del o:\copy.exe /a /f
@ del o:\host.exe /a /f
@ del o:\rose.exe /a /f
@ del o:\RavMonE.exe /a /f

@ del p:\autorun.inf /a /f
@ del p:\copy.exe /a /f
@ del p:\host.exe /a /f
@ del p:\rose.exe /a /f
@ del p:\RavMonE.exe /a /f

@ del q:\autorun.inf /a /f
@ del q:\copy.exe /a /f
@ del q:\host.exe /a /f
@ del q:\rose.exe /a /f
@ del q:\RavMonE.exe /a /f

@ del r:\autorun.inf /a /f
@ del r:\copy.exe /a /f
@ del r:\host.exe /a /f
@ del r:\rose.exe /a /f
@ del r:\RavMonE.exe /a /f

@ del s:\autorun.inf /a /f
@ del s:\copy.exe /a /f
@ del s:\host.exe /a /f
@ del s:\rose.exe /a /f
@ del s:\RavMonE.exe /a /f

@ del t:\autorun.inf /a /f
@ del t:\copy.exe /a /f
@ del t:\host.exe /a /f
@ del t:\rose.exe /a /f
@ del t:\RavMonE.exe /a /f

@ del u:\autorun.inf /a /f
@ del u:\copy.exe /a /f
@ del u:\host.exe /a /f
@ del u:\rose.exe /a /f
@ del u:\RavMonE.exe /a /f

@ del v:\autorun.inf /a /f
@ del v:\copy.exe /a /f
@ del v:\host.exe /a /f
@ del v:\rose.exe /a /f
@ del v:\RavMonE.exe /a /f

@ del w:\autorun.inf /a /f
@ del w:\copy.exe /a /f
@ del w:\host.exe /a /f
@ del w:\rose.exe /a /f
@ del w:\RavMonE.exe /a /f

@ del x:\autorun.inf /a /f
@ del x:\copy.exe /a /f
@ del x:\host.exe /a /f
@ del x:\rose.exe /a /f
@ del x:\RavMonE.exe /a /f

@ del y:\autorun.inf /a /f
@ del y:\copy.exe /a /f
@ del y:\host.exe /a /f
@ del y:\rose.exe /a /f
@ del y:\RavMonE.exe /a /f

@ del z:\autorun.inf /a /f
@ del z:\copy.exe /a /f
@ del z:\host.exe /a /f
@ del z:\rose.exe /a /f
@ del z:\RavMonE.exe /a /f
@echo -------------病毒文件删除成功！-------------
@ECHO.
@echo -------------正在修复注册表...-------------
@regedit /s yw.reg
@echo -------------注册表修复成功！-------------
@ECHO.
@echo =============病毒清除成功，感谢你使用本杀毒程式=============
@ECHO.
@echo 如有问题请发邮件至:yw1530@126.com 或 QQ与我联系:50199907
@ECHO.
SET /p c=重新启动计算机后才会生效，是否重新启动？[y,n]
if "%c%"=="y" shutdown /r /t 0
if "%c%"=="Y" shutdown /r /t 0
