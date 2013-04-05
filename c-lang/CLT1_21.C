#include <stdio.h>
#define TI 8
#define pC(ct, ch) \
for(i=0;i<ct;++i)putchar(ch)
main(){	int c,i,p=0,n=0;
while(EOF!=(c=getchar())){
if(' ' == c)(++n),(TI-1==p%TI)?
((n>0)?putchar((1 == n)? ' ': '\t'):0,n=0):0;
else{if('\t'==c)p=(p/TI+1)*TI-1;
else{('\n'==c)?(p=0):0;pC(n,' ');}
n=0,putchar(c);}++p;}return 0;}