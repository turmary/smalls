#define N 50

main(){
	int p, *q;
	char *r;

	/*ע��,����ֻ��һ���˺�,��Ϊsizeof��qָ��Ķ���(*q)��Ϊ������
	*��sizeof�������ȼ���ͬ,���ҽ��.
	sizeof�Ĳ����������ͱ����(),����Ǳ����򲻱�
	(��Ϊ�����ʹ����Ϊ���Ǻ���)*/
	p = N * sizeof * q;
	r = (char *)malloc(p);
	gets(r);
	printf("You inputed--->%s\n", r);

	/*�����������便����ǿ��ת��*q,��������sizeof(int)��?
	���ǲ���,�ڶ����ı�������,������ͨ��
	��Ϊ���������Ҽ�������,sizeof(int)�����ȼ���*/
	*q = 10;
	p = (sizeof(int)) * q;
	printf("(sizeof(int) * q) = %d", p);
}