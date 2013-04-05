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


//����һ�ε��͵�HTTP��Ӧ
//ע��,���һ���Ǳ�Ҫ��,
//����һ������,����һ��"\n"
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


//���Ǹ����̵߳ĳ���,����ʵ����Runable�ӿ�
public class webserver implements Runnable {
	//�������������ֱ���
	//	�������׽���
	//	��Ŀ¼�ļ���
	//	�������˿�
	//��Ψһ��,��������Ϊstatic
	private static ServerSocket serverSocket;
	private static String webroot;
	private static int port;

	private String filename;	//������ļ�
	private Socket server;		//��Ӧ��ÿ���ͻ����׽���


	webserver(Socket serv) {	//��ÿ������,�׽���������Ҫ��
		server = serv;
	}

	//��HTTP�������ҳ�������ļ���
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

	//�ҵ�������ļ�����
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

	//ʵ�������ļ��кͷ������˿�
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
		//�����˰�,�����Ľ����������
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
				//���̵߳����ɼ����ò���
				//java�ܺ���,�̺ܼ߳�
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

	//�ļ���HTTP��Ӧ����
	//���ﴫ���ļ����ݸ��ͻ���
	//run()��Runable�ӿڱ���ʵ���ڵ�һ������
	//���߳̿�ʼ(start())��,�̵߳�ִ��ת������
	public void run(){
		DateFormat df = DateFormat.getDateInstance();	//
		String now = new String(df.format(new Date()));	//������ʱʾ��
		BufferedInputStream fin;			//�ļ�������
		BufferedReader in = null;			//HTTP���������
		BufferedOutputStream out = null;		//HTTP��Ӧ�����
		String so;

		try
		{
			try {
		
			in = new BufferedReader(new InputStreamReader(server.getInputStream()));
			out = new BufferedOutputStream(server.getOutputStream());

			filename = getRequest(in);
			fin = new BufferedInputStream(new FileInputStream(webroot+filename));
			int size = fin.available();

			//���������Ӧ����Ҫ����
			so = new String("HTTP/1.1 200 OK\n");
			so += "Date: " + (new Date()).toGMTString() + "\n";
			so += "Server: TaryWebServer(Win 32)\n";
			so += "Accept-Ranges: bytes\n";
			so += "Content-Length: " + (Integer.toString(size)) + "\n";	//���ݳ���
			so += "Keep-Alive: timeout=15, max=100\n";
			so += "Connection: Keep-Alive\n";
			so += "Content-Type: ";			//�ļ����ݵ�����
			so += getType(filename) + "\n";	
			so += "\n";				//�ز�����,�����������ʽ���ļ�����
			System.out.println(so);
			out.write(so.getBytes());

			byte buffer[] = new byte[size];
			fin.read(buffer, 0, size);
			out.write(buffer);
			out.flush();		// �ز�����
						//ԭ��������ôһ��,һֱ���Բ��ɹ�,
						//����Ϊ����û�м�ʱ�����ͻ���

			} catch(Exception e){
				System.out.println("Error catch:" + e.getMessage());
			} finally {		//��������ر����ǵĻ�,��ֹͣ��Ӧ
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
