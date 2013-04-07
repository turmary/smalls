/**
 * FileName:	QSortAlgorithm.java
 * Description:	MultiThread Sort Vs
 * Copyright:	Copyright (c) 2005 LuoYiSiKe, Inc. All  Rights Reserved.
 * Company:	LuoYiSiKe Co.LTD
 * @author:	Tary
 * @date:	2005-12-21
 * @version	1.0
 */

public class QSortAlgorithm extends SortAlgorithm {
	private boolean pauseTrue(int lo, int hi) throws Exception {
		super.pause(lo, hi);
		return true;
	}

	void QuickSort(int a[], int lo0, int hi0) throws Exception
	{
		int lo = lo0;
		int hi = hi0;
		int mid;

		if ( hi0 > lo0) {
		mid = a[ ( lo0 + hi0 ) / 2 ];

		while( lo <= hi ) {
			while( ( lo < hi0 ) && pauseTrue(lo0, hi0) && ( a[lo] < mid ))
				++lo;
			while( ( hi > lo0 ) && pauseTrue(lo0, hi0) && ( a[hi] > mid ))
				--hi;
			if( lo <= hi ){
				swap(a, lo, hi);
				++lo;
				--hi;
			}
		}
		if( lo0 < hi )
			QuickSort( a, lo0, hi );
		 if( lo < hi0 )
			QuickSort( a, lo, hi0 );
		}
	}

	private void swap(int a[], int i, int j) {
		int T;
		T = a[i];
		a[i] = a[j];
		a[j] = T;
	}

	public void sort(int a[]) throws Exception {
		QuickSort(a, 0, a.length - 1);
	}
}
