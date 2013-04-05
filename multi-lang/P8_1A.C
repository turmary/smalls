void mputc(char c){
	_DL = c;
	_AH = 2;
	asm int 0x21;
}

char* i2str(int t){
	static char st[11];
	char k;
	int i = 0, j = 0;

	if(0 > t){
		st[i++] = '-';
		j++;
		t = -t;
	}else if(0 == t)
		st[i++] = '0';
	for(;0 != t;){
		st[i++] = t % 10 + '0';
		t /= 10;
	}
	st[i--] = '\0';
	while(j < i){
		k = st[i];
		st[i--] = st[j];
		st[j++] = k;
	}
	return st;
}

int print(int n){
	char* p;

	p = i2str(n);
	while(*p)
		mputc(*p++);
	return 0;
}

int main(){
	int fahr, celsius;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	fahr = lower;
	while(fahr <= upper) {
		celsius = 5 * (fahr - 32) / 9;
		print(fahr);
		mputc('\t');
		print(celsius);
		mputc(13);
		mputc('\n');
		fahr += step;
	}
	return 0;
}