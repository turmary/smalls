#include <stdio.h>
#include <stdlib.h>

typedef char *A;
int *c,E[999 ],L[999 ],M[999 ],P[999 ],l,i,j;
char B[999 ],F[2];A m[12*999 ],
	 p, q, x, y, z, s, d, f;

A Q(s,o)
A s,o;{
	for(x=s;*x;x++){
		for(y=x,z=0;*z&&*y==*z;y++)
			z++;
		if(z>o&&!*z)
			return  x;
	}
	return  0;
}

main(){
	m[11*999 ]="E";
	while(puts("OK"),gets(B))
	switch(*B){
		;break;
		case 'R':
			C=E;
			l=1;
			for(i=0;i<999 ;P[i++]=0);
			while(1){
				while(!(s=m[1]))l++;
				if(!Q(s,"\"")){
					while(p=Q(s,"<>"))
						*p++='#',*p=' ' ;
					while(p=Q(s,"<="))
						*p++='$',*p=' ' ;
					while(p=Q(s,">="))
						*p++='!',*p=' ' ;
			}
			d=B;
			while(*F=*S){
				*s=='"'&&j++;
				if(j&1||!Q("\t", F))
					*d++=*s;s++;
			}
			*d--=j=0;
			if(B[1]!='=')
			switch(*B){
				;break;
				case 'E':
					l=-l ;
					break;
				case 'R':
					B[2]!='M'&&(l=*--C) ;
					break;
				case 'I':
					b[1]='N'
					?gets(p=B),P[*d]=S()
					:*(q=Q(B,"TH"))=0,p=B+2,S()&&(p=q+4,l=s()-1);
					break;
				case 'P':
					B[5]=='"'
					?*d=0,puts(B+6)
					:(p=B+5,printf("%d\n",S()));
					break;
				case 'G':
					p=B+4,
					B[2]=='S'&&(*C++=1,p++),
					l=S()-1 ;
					break;
				case 'F':
					*(q=Q(B,"TO"))=0;
					p=B+5;
					P[i=B[3]]=S();
					p=q+2;
					M[i]=S();
					L[i]=1 ;
					break;
				case 'N':
					++P[*d]<=M[*d]&&(l=L[*d]);
			}else{
				p=B+2,
				P[*B]=S();
				l++;
			};
			break;
		case 'L':
			for(i=0;i<11*999 ;i++)
				m[i]&&  printf("%d %s\n", i, m[i] ) ;
			break;
		case 'N':
			for(i=0;i<11*999 ;i++)
				m[i]&&  free(m[i]), m[i]=0 ;
			break;
		case 'B':
			return  0 ;
			break;
		case  'S':
			f=fopen(B+5,"w");
			for(i=0;i<11*999 ;i++)
				m[i]&&  fprintf(f,"%d %s\n", i, m[i] );
			fclose(f);
			break;
		case  'O':
			f=fopen(B+4,"r");
			while(fgets(B,999 ,f))
				(*Q(B,"\n")=0,G());
			fclose(f);
			break;
		case  0:
		default:
			G();
	}
	return  0;
}

G(){
	l=atoi(B);
	m[l]&&free(m[l]);
	(p=Q(B,""))
	?strcpy(m[l]=malloc(strlen(p)),p+1)
	:(m[l]=0,0);
}

S(){
	int o;
	o=J();
	switch(*p++){
	;break;
	case  '=':
		return  o == S();;
		break;
	case  '#':
		return  o != S();
	default:
		p--;
		return  o;
	}
}

J(){
	int o;
	o=K();
	switch(*p++){
	;break;
	case  '<':
		return  o < J();;
		break;
	case  '>':
		return  o > J();
	default:
		p--;
		return  o;
	}
}

K(){
	int o;
	o=V();
	switch(*p++){
	;break;
	case  '$':
		return  o <= K();;
		break;
	case  '!':
		return  o >= K();
	default:
		p--;
		return  o;
	}
}

V(){
	int o;
	o=W();
	switch(*p++){
	;break;
	case  '+':
		return  o + V();;
		break;
	case  '-':
		return  o - V();
	default:
		p--;
		return  o;
	}
} 

W(){
	int o;
	o=Y();
	switch(*p++){
	;break;
	case  '*':
		return  o * W();;
		break;
	case  '/':
		return  o / W();
	default:
		p--;return  o;
	}
}

Y(){
	int o;
	return *p=='-'
	?p++,-Y():*p>='0'&&*p<='9'
		?atol(p,&p,0)
		:*p=='('
			?p++,o=S(),p++,o
			:P[*p++];) 
}