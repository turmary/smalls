/**
 * ClassName:	webserver0_1 
 * Description: a simple webserver 单线程版
 * 这个版本要配合WEBSERVER0_1.BAT文件循环执行,
 * 才可以免强响应浏览器的HTTP请求
 * Copyright:	Copyright (c) 1:37 2007-3-11
 * Company:	http://hi.baidu.com/mcu8051
 * @author:	Tary
 * @version:	0.1
 */

import java.net.*;
import java.io.*;
import java.util.*;
import java.text.DateFormat;


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

public class webserver0_1
{
	static ServerSocket serverSocket;
	static Socket server;
	static BufferedInputStream fin;
	static BufferedOutputStream out = null;
	static String WebRoot;
	static String ContentType;

	private static String GetName(BufferedReader in) throws IOException{
		String sFileName = null;
		String inString = null;
		StringTokenizer st;
		String delimiter = ":, \n", token = null;

		while ((inString = in.readLine()) != null) {
			//System.out.println(inString);
			if (inString.startsWith("GET")) {
				st = new StringTokenizer(inString, delimiter);
				while (st.hasMoreTokens()) {
					token = st.nextToken();
					if (token.equals("GET")) {
						sFileName = st.nextToken();
						//System.out.println("FileName="+sFileName);
					}
				}
			}
			if (inString.equals("") || inString.equals("\n")) break;
		}
		return sFileName;
	}

	private static String GetType(String fname) {
		return (new String(
			fname.substring(1 + fname.lastIndexOf('.'))
			).toLowerCase());
	}

	public static void main(String args[]) throws IOException
	{
		BufferedReader in = null;
		String sFileName = null;
		DateFormat df = DateFormat.getDateInstance();
		String now = new String(df.format(new Date()));

		//下句中80是本地端口
		serverSocket = new ServerSocket(80);

		//注意这里是根文件夹的设置
		WebRoot = "root";
		

		try
		{
			server = serverSocket.accept();
			try{
			in = new BufferedReader(new InputStreamReader(server.getInputStream()));
			out = new BufferedOutputStream(server.getOutputStream());

			String outString = null;


			sFileName = GetName(in);

			fin = new BufferedInputStream (new FileInputStream(WebRoot+sFileName));
			int size = fin.available();


			outString = new String("HTTP/1.1 200 OK\n");
			outString += "Date: " + (new Date()).toGMTString() + "\n";
			outString += "Server: TaryWebServer(Win 32)\n";
			outString += "Accept-Ranges: bytes\n";
			outString += "Content-Length: " + (Integer.toString(size)) + "\n";
			outString += "Keep-Alive: timeout=15, max=100\n";
			outString += "Connection: Keep-Alive\n";
			outString += "Content-Type: ";

			ContentType = GetType(sFileName);
			if (ContentType.equals("htm") || ContentType.equals("html")) {
				outString += "text/html\n";
			} else if (ContentType.equals("gif")) {
				outString += "image/gif\n";
			} else if (ContentType.equals("jpg")) {
				outString += "image/jpg\n";
			} else {
				outString += "*/" + ContentType;
			}
			outString += "\n";
			System.out.println(outString);
			out.write(outString.getBytes());


			byte buffer[] = new byte[size];
			fin.read(buffer, 0, size);
			out.write(buffer);

			//System.out.println(new String(buffer));
			//out.println("\n\n");

			out.flush();		//the key statement, problem with old program

			in.close();
			out.close();
			}
			catch(Exception e){System.out.println("Error catch2:" + e.getMessage());}
			finally	{ server.close();}
		}
		catch(Exception e){System.out.println("Error catch3:" + e.getMessage());}
		finally { serverSocket.close();}
	}
}
