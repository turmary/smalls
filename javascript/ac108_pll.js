
function ac101_pll_out(fin, ni, nf, m) {
	return fin * (ni + nf * 0.2) / (m * 3);
}

function ac108_pll_out(fin, n, m1, m2, k1, k2) {
	return fin * n / ((m1 + 1.0) * (m2 + 1.0) * (k1 + 1.0) * (k2 + 1.0));
}

function stdOut(s) {
	if (typeof WScript !== "undefined") {
		WScript.echo(s);
	} else if (typeof navigator !== "undefined") {
		document.write(s + "<br>");
	} else {

	}
}


dist = 1000000;
freq_in = 24000000;
freq_want = 24576000;

for (var n = 1; n < 1024; n++)
for (var m1 = 0; m1 < 32; m1++)
for (var m2 = 0; m2 < 2; m2++)
for (var k1 = 0; k1 < 32; k1++)
for (var k2 = 0; k2 < 2; k2++) {
	var freq = ac108_pll_out(freq_in, n, m1, m2, k1, k2);
	var dis = Math.abs(freq - freq_want);
	if (dis < dist) {
		dist = dis;
		stdOut(	"n=" + n +
			" m1=" + m1 + 
			" m2=" + m2 + 
			" k1=" + k1 + 
			" k2=" + k2 + 
			" dist=" + dist + "\n");
	}
}

stdOut("AC108 PLL_OUT=" + ac108_pll_out(freq_in,128,4,0,24,0));
stdOut("AC108 PLL_OUT=" + ac108_pll_out(freq_in,588,24,0,24,0));

dist = 1000000;
freq_in = 24000000;
freq_want = 22579200;

for (var ni = 0; ni < 1024; ni++)
for (var nf = 0; nf < 8; nf++)
for (var m  = 1; m < 65; m++) {
	var freq = ac101_pll_out(freq_in, ni, nf, m);
	var dis = Math.abs(freq - freq_want);
	if (dis < dist) {
		dist = dis;
		stdOut(	" ni=" + ni +
			" nf=" + nf + 
			" m =" + m  + 
			" dist=" + dist + "\n");
	}
}

stdOut("AC101 PLL_OUT=" + ac101_pll_out(freq_in,177,4,63));
stdOut("AC101 PLL_OUT=" + ac101_pll_out(freq_in,76,4,25));

var stdin = WScript.StdIn;
var str = stdin.ReadLine();
