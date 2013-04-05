DIM fahr, celsius
DIM lower, upper, deta

lower = 0
upper = 300
deta = 20

fahr = lower
WHILE fahr <= upper
	celsius = 5 * (fahr - 32) / 9
	PRINT fahr; CHR$(9); INT(celsius * 10) / 10
	fahr = fahr + deta
WEND

