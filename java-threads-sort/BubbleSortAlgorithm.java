/**
 * FileName:	BubbleSortAlgorithm.java
 * Description:	MultiThread Sort Vs
 * Copyright:	Copyright (c) 2005 LuoYiSiKe, Inc. All  Rights Reserved.
 * Company:	LuoYiSiKe Co.LTD
 * @author:	Tary
 * @date:	2005-12-21
 * @version	1.0
 */

class BubbleSortAlgorithm extends SortAlgorithm {
	void sort(int a[]) throws Exception {
	for (int i = a.length; --i>=0; ) {
		boolean swapped = false;
		for (int j = 0; j<i; j++) {
		if (stopRequested) {
			return;
		}
		if (a[j] > a[j+1]) {
			int T = a[j];
			a[j] = a[j+1];
			a[j+1] = T;
			swapped = true;
		}
		pause(i,j);
		}
		if (!swapped)
		return;
	}
	}
}
