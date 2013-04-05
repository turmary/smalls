rem 1>
rem 如果你的JAVA程序可以正常的编译并且运行
rem 这步可以不设置
rem 这个批处理用于设置JRE环境
rem 即PATH,CLASSPATH环境变量
@call javapath.bat


rem 2>
rem 修改源代码中注释指明的端口和根据文件夹
rem 并重新编译生成webserver0_1.class

rem 3>
rem 下面用循环是因为这个程序是单线程的
rem 用循环来响应多个请求

:label
@java webserver0_1
@goto label