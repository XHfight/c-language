#include <stdio.h>
#include <stdlib.h>
/*
�������飺(flexible array) C99������
�ṹ���е����һ��Ԫ��������δ֪��С�����顣

*/
typedef struct flexible
{
	int i;
	int a[]; //C99֧�����֣���Щ��������int a[0];��Ϊ�Ǳ�׼��֧�֡�
}flexible;

int main()
{
//	printf("%d\n", sizeof(flexible));  //4 sizeof���ص����ֽṹ���С�������������顣

	flexible *f= (flexible* )malloc(sizeof(flexible) + 100*sizeof(int));

	/*
	    �ṹ��Ĵ�С��������������Ĵ�С����������ֻ����ʹ��ʱ������Ϊ�ṹ���һ����Ա����	ʵ���㲻�ýṹ�����ʽ��Ա��
	*/
	printf("%d\n", sizeof(flexible)); //4  
	printf("%d\n", sizeof(*f)); //4  
	
	return 0;

}