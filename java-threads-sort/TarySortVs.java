/**
 * FileName:	TarySortVs.java
 * Description:	MultiThread Sort Vs
 * Copyright:	Copyright (c) 2005 LuoYiSiKe, Inc. All	Rights Reserved.
 * Company:	LuoYiSiKe Co.LTD
 * @author:	Tary
 * @date:	2005-12-21
 * @version	1.0
 */

import java.applet.*;
import java.awt.*;
import java.awt.event.*;

public class TarySortVs extends Applet implements MouseListener {
	static int arr[][];
	public SortItem S[];

	void scramble() {
		int a[] = new int[getSize().height / 2];
		int b[] = new int[getSize().height / 2];
		double f = getSize().width / (double) a.length / 2.0;
		for (int i = a.length; --i >= 0;) {
			a[i] = (int)(i * f);
		}
		for (int i = a.length; --i >= 0;) {
			int j = (int)(i * Math.random());
			int t = a[i];
			a[i] = a[j];
			a[j] = t;
			b[i] = a[i];
		}
		arr[0] = a;
		arr[1] = b;
	}

	public void init() {
		resize(600, 150);
		arr = new int[2][];
		S = new SortItem[2];
		S[0] = new SortItem(this, "BubbleSortAlgorithm", 0);
		S[1] = new SortItem(this, "QSortAlgorithm", 1);
		addMouseListener(this);
	}

	public void start() {
		scramble();
	}

	public void destroy() {
		removeMouseListener(this);
	}

	public void paint(Graphics g) {
		int ID /*= SortItem.threadID*/;
		int nDL;

		for (int k = 0; k < 2; k++){
			ID = k;
			if (ID == 0)
				nDL = 0;
			else
				nDL = (int)getSize().width / 2;
			System.out.println("paint(" + ID + ")");
			if (ID < 0 || 1 < ID) return;
			int[] a = arr[ID];
			g.setColor(getBackground());
			int y = getSize().height - 1;
			for (int i = a.length; --i >= 0; y -= 2) {
				g.drawLine(nDL + a[i], y, nDL + getSize().width / 2, y);
			}

			g.setColor(Color.black);
			y = getSize().height - 1;
			for (int i = a.length; --i >= 0; y -= 2) {
				g.drawLine(nDL, y, nDL + a[i], y);
			}
			if (S[ID].h1 >= 0) {
				g.setColor(Color.red);
				y = S[ID].h1 * 2 + 1;
				g.drawLine(nDL, y, nDL + getSize().width / 2, y);
			}
			if (S[ID].h2 >= 0) {
				g.setColor(Color.blue);
				y = S[ID].h2 * 2 + 1;
				g.drawLine(nDL, y, nDL + getSize().width / 2, y);
			}
		}
	}

	public void update(Graphics g) {
		/*System.out.println("update(Graphics)"); */
		paint(g);
	}

	public void mouseClicked(MouseEvent e)
	{
		System.out.println("mouse Clicked");
	}

	public void mousePressed(MouseEvent e)
	{
		System.out.println("mouse Pressed");
	}

	public void mouseReleased(MouseEvent e) {
		S[0].startSort();
		S[1].startSort();
		e.consume();
	}

	public void mouseEntered(MouseEvent e)
	{
		System.out.println("mouse Entered");
	}

	public void mouseExited(MouseEvent e)
	{
		System.out.println("mouse Exited");
	}

	public String getAppletInfo() {
		return "Title: TarySortVs \nAuthor: Tary 1.00, 2005-12-21 \nA simple applet class to demonstrate a multithread sort algorithm.	\nWhen you click on the applet, a thread is forked which animates \nthe sorting algorithm.";
	}

	public String[][] getParameterInfo() {
		String[][] info = {
		  {"NULL", "NULL", "No Parameters"}
		};
		return info;
	}
}