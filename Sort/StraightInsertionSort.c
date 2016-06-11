#include <stdio.h>
#include <stdlib.h>

void StraightInsertionSort(int* arr, int len)
{
	int i = 0;
	for(i = 1; i < len; i++) //��¼Ҫ�������
	{
		//�Ƚ�ǰ�����е����һ������Ҫ������������û������Ҫ����
		if(arr[i]<arr[i-1])     
		{
			int j = 0;
			int tmp = arr[i];   //��¼Ҫ����������

			//��ǰ��������е���Ŀ����0�� �� ǰ���������Ҫ����������ʱ����ѭ��
			for(j = i-1; j>=0 && arr[j]>tmp; j--)
			{
				arr[j+1] = arr[j];  //��ǰ���������ƶ�
			}
			arr[j+1] = tmp;//����¼��Ҫ�����������
		}
	}
}

int main()
{
	int i = 0;
	int array[5] = {5,3,2,4,1};

	StraightInsertionSort(array, sizeof(array)/sizeof(int));

	for(i = 0; i < sizeof(array)/sizeof(int); i++)
	{
		printf("%d ",array[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}