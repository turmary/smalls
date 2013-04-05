/**
 * ClassName:	webserver
 * Description: a simple webserver
 * Copyright:	Copyright (c) 16:12 2007-6-4
 * Company:	http://hi.baidu.com/mcu8051
 * @author:	Tary
 * @version:	0.2
 */

import java.net.*;
import java.io.*;
import java.util.*;
import java.text.DateFormat;


//这是一段典型的HTTP回应
//注意,最后一行是必要的,
//它是一个空行,仅有一个"\n"
/*
HTTP/1.1 200 OK
Date: Sat, 10 Mar 2007 18:22:15 GMT
Server: Apache/1.3.37 (Win32)
Last-Modified: Mon, 11 Sep 2006 11:09:46 GMT
ETag: "0-1af-450543fa"
Accept-Ranges: bytes
Content-Length: 431
Keep-Alive: timeout=15, max=100
Connection: Keep-Alive
Content-Type: text/html

*/


//这是个多线程的程序,所以实现了Runable接口
public class webserver implements Runnable {
	//以下三个变量分别是
	//	服务器套接字
	//	根目录文件夹
	//	服务器端口
	//是唯一的,所以设置为static
	private static ServerSocket serverSocket;
	private static String webroot;
	private static int port;

	private String filename;	//请求的文件
	private Socket server;		//对应于每个客户的套接字


	webserver(Socket serv) {	//对每个对象,套接字是最重要的
		server = serv;
	}

	//从HTTP请求中找出请求的文件名
	private String getRequest(BufferedReader in) throws IOException{
		String name = null;
		String si = null;
		StringTokenizer st;
		String delimiter = ":, \n", token = null;

		while ((si = in.readLine()) != null) {
			System.out.println(si);
			if (si.startsWith("GET")) {
				st = new StringTokenizer(si, delimiter);
				while (st.hasMoreTokens()) {
					token = st.nextToken();
					if (token.equals("GET")) {
						name = st.nextToken();
					}
				}
			}
			if (si.equals("") || si.equals("\n")) break;
		}
		return name;
	}

	//找到请求的文件类型
	private String getType(String name) {
		String filetype;

		filetype = (new String(
		  name.substring(1 + name.lastIndexOf('.'))
		  ).toLowerCase());

		if (filetype.equals("htm") || filetype.equals("html")) {
			return "text/html";
		} else if (filetype.equals("gif")) {
			return "image/gif";
		} else if (filetype.equals("jpg")) {
			return "image/jpg";
		};
		return "*/" + filetype;
	}

	//实例化根文件夹和服务器端口
	public static void init(String s, int np) {
		if (s == null || s.equals("")) {
			webroot = "E:/webstudy/bin/tary_anyf_cn";
		} else {
			webroot = s;
		}
		port = np;
	}

	public static void main(String args[]) throws IOException
	{
		//看见了吧,参数的解释在这儿呢
		if (1 > args.length || args.length > 2) {
			System.out.println("usage:\n  java webserver <wwwroot> [port]\n");
			System.exit(1);
		} else if ( args.length == 1) {
			init(args[0], 80);
		} else {
			init(args[0], Integer.parseInt(args[1]));
		}

		try {
			serverSocket = new ServerSocket(port);
			for (;;) {
				//多线程的生成及调用部分
				//java很好用,线程很简单
				Thread th = new Thread(new webserver(serverSocket.accept()));
				th.start();
			}
		} catch (Exception e){
			System.out.println("Error catch:" + e.getMessage());
		} finally {
			serverSocket.close();
		}
		System.exit(0);
	}

	//文件的HTTP回应部分
	//这里传送文件内容给客户机
	//run()是Runable接口必须实现在的一个函数
	//在线程开始(start())后,线程的执行转到这里
	public void run(){
		DateFormat df = DateFormat.getDateInstance();	//
		String now = new String(df.format(new Date()));	//日期暂时示用
		BufferedInputStream fin;			//文件输入流
		BufferedReader in = null;			//HTTP请求的输入
		BufferedOutputStream out = null;		//HTTP响应的输出
		String so;

		try
		{
			try {
		
			in = new BufferedReader(new InputStreamReader(server.getInputStream()));
			out = new BufferedOutputStream(server.getOutputStream());

			filename = getRequest(in);
			fin = new BufferedInputStream(new FileInputStream(webroot+filename));
			int size = fin.available();

			//这里就是响应的主要部分
			so = new String("HTTP/1.1 200 OK\n");
			so += "Date: " + (new Date()).toGMTString() + "\n";
			so += "Server: TaryWebServer(Win 32)\n";
			so += "Accept-Ranges: bytes\n";
			so += "Content-Length: " + (Integer.toString(size)) + "\n";	//内容长度
			so += "Keep-Alive: timeout=15, max=100\n";
			so += "Connection: Keep-Alive\n";
			so += "Content-Type: ";			//文件内容的类型
			so += getType(filename) + "\n";	
			so += "\n";				//必不可少,从这儿后是正式的文件内容
			System.out.println(so);
			out.write(so.getBytes());

			byte buffer[] = new byte[size];
			fin.read(buffer, 0, size);
			out.write(buffer);
			out.flush();		// 必不可少
						//原来少了这么一句,一直调试不成功,
						//是因为内容没有及时传给客户机

			} catch(Exception e){
				System.out.println("Error catch:" + e.getMessage());
			} finally {		//如果出错不关闭它们的话,会停止响应
				in.close();
				out.close();
				server.close();
			}
		} catch(Exception e){
			System.out.println("Error catch:" + e.getMessage());
		} finally {
		}
	}
}
