#include <stdio.h>

void *my_memmove(void *dest, const void *src, size_t count) //解决了内存重叠拷贝的问题
{
	void *ret = dest;
	if(dest == src)
	{
		return ret;
	}
	else if(dest > src)
	{
		while(count--)
		{
			*((char*)dest+count) = *((char*)src+count);
		}
	}
	else
	{
		while(count--)
		{
			*((char*)dest)++ = *((char*)src)++;
		}
	}
	return ret;
}


int main()
{
	char str[10] = {'a','b','c'};
	my_memmove(&str[2], str, 4);
	printf("%s\n", str);
	return 0;
}