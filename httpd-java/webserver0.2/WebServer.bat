rem 1>
rem 如果你的JAVA程序可以正常的编译并且运行
rem 这步可以不设置
rem 这个批处理用于设置JRE环境
rem 即PATH,CLASSPATH环境变量
@call javapath.bat


rem 2>
rem 如果该文件(WebServer.bat)与webserver.class
rem 放在同一个文件夹下,这步可以不用设置
rem 在我的电脑上,这个程序是放在
rem D:\tmp
rem 请根据你的JAVA编译的设置修改下面的部分
rem D:
rem cd \tmp

rem 3>
rem 下句用于运行webserver程序,必须设置
rem 使用方法参数如下
rem java webserver <wwwroot> [port]
rem  <wwwroot> --- 所有网页文件的根文件夹
rem  [port]    --- 端口号,可以不要,默认80
rem  我的网页文件放在root文件夹下
rem  请根据须要修改
:label
@java webserver "root" 80
@goto label

rem 4>
rem 打开浏览器,在地址栏内输入http://127.0.0.1/文件名
rem 比如在我的机子上
rem 存在文件.\root\index.html
rem 所以我输入http://127.0.0.1/index.html即可浏览该网页

rem 5>
rem 如果要停止该程序,
rem 在命令行下,可以按Ctrl + C
rem 当然也可点击右上角X型关闭按钮
