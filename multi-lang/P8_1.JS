var fahr, celsius;
var lower, upper, step;

lower = 0;
upper = 300;
step = 20;

fahr = lower;
while(fahr <= upper) {
	celsius = 5 * (fahr - 32) / 9;
	WScript.Echo(fahr, (fahr >= 100 ? " ": (fahr > 0 ? "  ": "   ")), Math.ceil(celsius * 10) / 10);
	fahr += step;
}