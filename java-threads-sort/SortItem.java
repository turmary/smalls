/**
 * FileName:	SortItem.java
 * Description:	MultiThread Sort Vs
 * Copyright:	Copyright (c) 2005 LuoYiSiKe, Inc. All  Rights Reserved.
 * Company:	LuoYiSiKe Co.LTD
 * @author:	Tary
 * @date:	2005-12-21
 * @version	1.0
 */

import java.applet.*;

public class SortItem implements Runnable {
	public int h1 = -1, h2 = -1;
	public static int threadID = -1;
	private int aindex;
	private Thread kicker;
	private Applet pApplet;
	String algName;
	SortAlgorithm algorithm;

	SortItem(Applet pA, String alN, int a) {
		pApplet = pA;
		algName = alN;
		threadID = aindex = a;
		/*pApplet.repaint();*/
	}

	void pause() {
		pause(-1, -1);
	}

	void pause(int H1) {
		pause(H1, -1);
	}

	void pause(int H1, int H2) {
		h1 = H1;
		h2 = H2;

		threadID = aindex;
		if (kicker != null) {
			pApplet.repaint();
		}
		try {
			Thread.sleep(20);
		}catch (InterruptedException e){
		}
	}

	public void run() {
		try {
			if (algorithm == null) {
				algorithm = (SortAlgorithm)Class.forName(algName).newInstance();
				algorithm.setParent(this);
			}
			algorithm.init();
			algorithm.sort(TarySortVs.arr[aindex]);
		} catch(Exception e) {
		}
	}

	private synchronized void stop() {
		if (algorithm != null){
			try {
				algorithm.stop();
			} catch (IllegalThreadStateException e) {
				// ignore this exception
			}
			kicker = null;
		}
	}

	public synchronized void startSort() {
		if (kicker == null || !kicker.isAlive()) {
			kicker = new Thread(this);
			kicker.start();
		}
	}
}
