#include <stdio.h>
#include <stdlib.h>

/*

斐波那契数列：
n = 0,F（n）= 0;
n = 1,F（n）= 1;
n > 1,F（n）= F(n-1) + F(n-2);

*/

//输出斐波那契数列的前40个数。

//方法1：普通方式
//int main()
//{
//	int fib[40] = { 0 };
//	int i = 0;
//
//	fib[0] = 0;
//	fib[1] = 1;
//
//	printf("%d ", fib[0]);
//	printf("%d ", fib[1]);
//
//	for (i = 2; i < 40; i++)
//	{
//		fib[i] = fib[i - 1] + fib[i - 2];
//		printf("%d ", fib[i]);
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}

//方法二：递归方法
int Fib(int i)
{
	if (i == 0)
	{
		return 0;
	}
	else if (i == 1)
	{
		return 1;
	}
	else
	{
		return Fib(i - 1) + Fib(i - 2);
	}
}

int main()
{
	int i = 0;
	for (; i < 40; i++)
	{
		printf("%d ", Fib(i));
		if ((i + 1) % 5 == 0)
		{
			printf("\n");
		}
	}
	system("pause");
	return 0;
}