Option Explicit
dim fahr, celsius
dim lower, upper, deta

lower = 0
upper = 300
deta = 20

fahr = lower
while fahr <= upper
	celsius = 5 * (fahr - 32) / 9
	Wscript.Echo fahr, chr(9), int(celsius * 10) / 10
	fahr = fahr + deta
wend