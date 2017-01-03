#include <stdio.h>
# include <stdlib.h> 

# define LEN sizeof(struct Student)

//��������
void creat(struct Student **pHead);
void search (struct Student*head);
void cut(struct Student*head);
void print(struct Student*head);
void change(struct Student*head);
void order(void);
void Write(struct Student* head);  //��ѧ����Ϣд�뵽�ļ���


struct Student
{
	long num;
	char name[20];
	float c;  //chinese
	float m;  //math
	float e;  //english
	struct Student *next;
};

int main()
{   
	printf("\n");
	printf("\n");
	printf("\t\t\t# # # # # # # # # # # # # # #\n");
	printf("\t\t\t*****************************\n");
	printf("\t\t\t��ӭ����ѧ������ϵͳ\n");
	printf("\t\t\t*****************************\n");
	order();
	return 0;
}
void order (void) //���湦��ѡ����
{
	struct Student* pt = NULL;

	while(1)
	{
		int x;
		printf("\n");
		printf("\n");
		printf("\t\t\t�����������ѧ������Ϣ���밴1\n");
		printf("\t\t\t����������ѧ������Ϣ���밴2\n");
		printf("\t\t\t��������޸�ѧ������Ϣ���밴3\n");
		printf("\t\t\t�������ɾ��ѧ������Ϣ���밴4\n"); 
		printf("\t\t\t����������ѧ������Ϣ���밴5\n");
		printf("\t\t\t�������������β�����  �밴6\n");
		scanf("%d",&x);
		switch(x)
		{
			case 1:creat(&pt);break;
			case 2:search(pt);break;
			case 3:change(pt);break;
			case 4:cut(pt);break;
			case 5:print(pt);break;
			case 6:
				Write(pt);
				break;
		}
		if(x==6) break;
	}
}

void creat(struct Student** pHead)  //����ѧ����Ϣ�ĺ���
{
	struct Student *head = *(pHead); 
	struct Student * p1 = (struct Student*)malloc(LEN);
	printf("please input student's ѧ��:");
	scanf("%ld",&p1->num);
	printf("please input student's ����:");
	scanf("%s",&p1->name);
	printf("please input student's ���ĳɼ�:");
	scanf("%f",&p1->c);
	printf("please input student's ��ѧ�ɼ�:");
	scanf("%f",&p1->m);
	printf("please input student's Ӣ��ɼ�:");
	scanf("%f",&p1->e);
	
	//����ͷ��
	p1->next = head;
	*pHead = p1;
	printf("����ɹ�\n");
}


void print(struct Student*head)  //��ӡ����ѧ������Ϣ
{
	struct Student*p;
	p=head;
	if(head!=NULL)
	do
	{
		printf("\t\t%ld",p->num);
		printf("\t%s",p->name);
		printf("\t%5.1f",p->c);
		printf("\t%5.1f",p->m);
		printf("\t%5.1f",p->e);
		printf("\n");
		p=p->next;
	}while(p!=NULL);
}

void change(struct Student*head)   //�޸�ѧ����Ϣ
{  
	long number;
	struct Student*p;

	printf("please enter ѧ��:");
	scanf("%ld",&number);
	p=head;
	while(1)
	{
		if(p == NULL)
		{
			printf("δ�ҵ���ѧ�ŵ�ѧ��\n");
			return;
		}

		if(number == p->num)
		{ 
			printf("\t\t%ld",p->num);
			printf("\t%s",p->name);
			printf("\t%5.1f",p->c);
			printf("\t%5.1f",p->m);
			printf("\t%5.1f\n",p->e);break;
		}
		else p=p->next;
	}
	printf("�������޸ĺ����Ϣ��\n");
	printf("please input student's num:");
	scanf("%ld",&p->num);
	printf("please input student's name:");
	scanf("%s",&p->name);
	printf("please input student's c:");
	scanf("%f",&p->c);
	printf("please input student's m:");
	scanf("%f",&p->m);
	printf("please input student's e:");
	scanf("%f",&p->e);
}

void search (struct Student*head)  //����ѧ�Ų���ѧ����Ϣ
{
	long number;
	struct Student*p;

	printf("please enter a ѧ��:");
	scanf("%ld",&number);
	p=head;
	while(1)
	{
		if(p == NULL)
		{
			printf("δ�ҵ���ѧ�ŵ�ѧ��\n");
			return;
		}

		if(number==p->num)
		{ 
			printf("\t\t%ld",p->num);
			printf("\t%s",p->name);
			printf("\t%5.1f",p->c);
			printf("\t%5.1f",p->m);
			printf("\t%5.1f\n",p->e);break;
		}
		else p=p->next;
	}
}
void cut(struct Student*head)  //ɾ����Ӧѧ�ŵ�ѧ����Ϣ
{
	long number;
	struct Student*p,*p1;

	printf("please input student's ѧ��:");
	scanf("%ld",&number);
	p=head;
	while(1)
	{
		if(number==p->next->num)
		{
			printf("\t\t%ld",p->next->num);
			printf("\t%s",p->next->name);
			printf("\t%5.1f",p->next->c);
			printf("\t%5.1f",p->next->m);
			printf("\t%5.1f",p->next->e);
			break;
		}
		else p=p->next;
	}
	p1=p->next;
	p->next=p1->next;
	free(p1);
	p1=NULL;
}

void Write(struct Student* head)  //��ѧ����Ϣд�뵽�ļ���
{
	struct Student* cur = head;
	FILE* f = fopen("ѧ����Ϣ.txt", "w");
	if(f == NULL)
	{
		printf("��ѧ����Ϣ�ļ�����\n");
		return;
	}
	
	fputs("ѧ��	����	 ����	��ѧ	Ӣ��\n", f);
	while(cur != NULL)
	{
		fprintf(f,"%ld	%s	%5.1f	%5.1f	%5.1f\n",
			cur->num, cur->name, cur->c, cur->m, cur->e);
		cur = cur->next;
	}

	fclose(f);
}
