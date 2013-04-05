/**
 *ClassName:	P8_1
 *Author:	Tary
 *Product date:	2005-8-1
 */

public class P8_1{
	private int lower, upper, step;

	public void printTable(){
		int fahr, celsius;
		fahr = lower;
		while(fahr <= upper) {
			celsius = 5 * (fahr - 32) / 9;
			System.out.println(fahr + "\t" + celsius);
			fahr += step;
		}
	}
	
	public static void main(String args[]){
		P8_1 t = new P8_1();

		t.lower = 0;
		t.upper = 300;
		t.step = 20;
		t.printTable();
	}
}