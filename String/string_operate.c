typedef unsigned int size_t;
#include <stdio.h>

char* my_strcpy(char *dst, const char *src)  //�ַ�����������
{
	assert(dst);
	assert(src);

	char *copyDst = dst;
	while (*copyDst++ = *src++);
	return dst;
}

size_t my_strlen(const char *str)  //���ַ������ȵĺ���
{
	assert(str);

	//����1��
	/*
	const char *copyStr = str;
	size_t count = 0;
	while (*copyStr++)
	{
		count++;
	}
	return count;
	*/

	//�����������տ��ļ�ʵ��
	const char *copyStr = str;
	while ( *copyStr++ );
	return ( copyStr - str - 1 );
}

char* my_strcat(char *dst, const char *src)  //�ַ������Ӻ��������������ַ���
{
	assert(dst);
	assert(src);

	char *copyDst = dst;

	while (*copyDst)
	{
		copyDst++;
	}

	while (*copyDst++ = *src++);
	return dst;
}

int my_strcmp(const char *str1,const char *str2)
{
	assert(str1);
	assert(str2);

	while (*str1 || *str2)
	{
		if (*str1 > *str2)
		{
			return 1;
		}
		else if (*str1 < *str2)
		{
			return -1;
		}
		str1++;
		str2++;
	}
	if (*str1 == 0 && *str2 == 0)
	{
		return 0;
	}
	if (*str1 == 0)
	{
		return -1;
	}
	return 1;
}

char* my_strchr(const char *str, char c)
{
	assert(str);

	while (*str)
	{
		if (*str == c)
		{
			return (char *)str;
		}
		str++;
	}
	return NULL;
}

char* my_strstr(const char *str1, const char *str2)
{
	assert(str1);
	assert(str2);

	const char *cp1 = NULL;
	const char *cp2 = NULL;

	while (*str1)
	{
		cp1 = str1;
		cp2 = str2;

		while ( *cp1 && *cp2 && (*cp1 == *cp2) )
		{
			cp1++;
			cp2++;
		}
		if (*cp2 == '\0')
		{
			return (char *)str1;
		}

		str1++;

	}
	return NULL;
}