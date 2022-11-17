#define _CRT_SECURE_NO_WARNINGS 1

#include"contact.h"

int arr[MAX];
void InitContact(Con* ps) 
{
	memset(ps->data, 0, sizeof(ps->data));
	ps->size = 0;//����ֻ��0��Ԫ��
}
//���뺯��
void AddCon(Con* ps)
{
	printf("\n");
	printf("����������> ");
	scanf("%s", ps->data[ps->size].name);
	printf("����������> ");
	scanf("%d", &(ps->data[ps->size].age));
	printf("�������Ա�> ");
	scanf("%s", ps->data[ps->size].sex);
	printf("������绰> ");
	scanf("%s", ps->data[ps->size].tele);
	ps->size++;
	printf("\n����ɹ�\n\n");
}
//��ӡ����
void ShowCon(const Con* ps)
{
	if (ps->size == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
	}
	else
	{
		int i = 0;
		printf("\n");
		printf("��������ϵ��:\n");
		printf("\t%-10s\t%-9s\t%-8s\t%-17s\n", "����", "����", "�Ա�", "�绰");
		for (i = 0; i < ps->size; i++)
		{
			
			printf("%d.\t%-10s\t%-9d\t%-8s\t%-17s\n",
				i + 1,
				ps->data[i].name,
				ps->data[i].age,
				ps->data[i].sex,
				ps->data[i].tele);
		}
	}
}

//ɾ������
void DelCon(Con* ps)
{

	if (ps->size == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
	}
	else 
	{
		printf("��������Ҫɾ����ϵ�˵�����>");
		int count = SearchCon2(ps);
		if (count != ps->size)
		{
			int input = 0, i = 0;
			printf("��������Ҫɾ�������>");
			printf("\n");
			scanf("%d", &input);
		/*	int a = arr[input - 1];*/
			for (i = arr[input - 1]; i < ps->size - 1; i++)
			{
				ps->data[i] = ps->data[i + 1];
			}
			ps->size--;
			printf("\nɾ���ɹ�\n\n");
		}
	}
}

//���Һ���
void SearchCon(const Con* ps)
{
	int count = 0;
	if (ps->size != 0)
	{
		int num = 0, i = 0, j = 1;
		char Name[MAX_name] = { 0 };
		scanf("%s", Name);
		for (i = 0; i < ps->size; i++)
		{
			if (strcmp(ps->data[i].name, Name) != 0)//һ��һ�����Ҳ���
			{
				count++;
			}
			else
			{
				break;
			}
		}
		if (count == ps->size)
		{
			printf("\n���޴���\n\n");
		}
		if (count != ps->size)
		{
			printf("\n������������ϵ��:\n\n");
			for (i = 0; i < ps->size; i++)
			{
				if (strcmp(ps->data[i].name, Name) == 0)
				{
					printf("%d.\t%-10s\t%-9d\t%-8s\t%-17s\n",
						j++,
						ps->data[i].name,
						ps->data[i].age,
						ps->data[i].sex,
						ps->data[i].tele);
					arr[num] = i;
					num++;
				}
		
			}
			printf("\n");
		}
	}
	else
	{
		printf("ͨѶ¼Ϊ��\n");
	}
}


//�޸ĺ���
void ModifyCon(Con* ps)
{

	if (ps->size == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
	}
	else
	{
		printf("\n");
		printf("������Ҫ�޸ĵ���ϵ������>");
		int count = SearchCon2(ps);

		if (count != ps->size)
		{
			int input = 0;
			printf("\n");
			printf("ѡ����Ҫ�޸ĵ����>");
			scanf("%d", &input);
			printf("\n");
			printf("����������> ");
			scanf("%s", ps->data[arr[input - 1]].name),
			printf("����������> ");
			scanf("%d", &(ps->data[arr[input - 1]].age));
			printf("�������Ա�> ");
			scanf("%s", ps->data[arr[input - 1]].sex);
			printf("������绰> ");
			scanf("%s", ps->data[arr[input - 1]].tele);

			printf("\n�޸ĳɹ�\n\n");
		}
	}
}
	
//��������qsort�еĺ���
int cmp_Con_date_age(const void* e1, const void* e2)
{
	int x = ((Con*)e1)->data->age - ((Con*)e2)->data->age;
	return x;
}

int cmp_Con_date_name(const void* e1, const void* e2)
{
	int y = strcmp(((Con*)e1)->data->name, ((Con*)e2)->data->name);
	return y;
}
//������
void SortCon(const Con* ps) 
{
	if (ps->size == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
	}
	else 
	{
		int input = 0;
		printf("��ѡ�����򷽷�> 1.����\t2.����\n");
		scanf("%d", &input);
		int sz = (sizeof(ps->data[0]) * (ps->size));
		int s = sizeof(ps->data[0]);
		if (input == 1)
		{
			qsort(ps->data, sz, sizeof(ps->data[0]), cmp_Con_date_name);
		}
		else
		{
			qsort(ps->data, sz, sizeof(ps->data[0]), cmp_Con_date_age);
		}
		printf("\n����ɹ�\n\n");
	}
}




int SearchCon2(const Con* ps)
{
	int count = 0;
	if (ps->size != 0)
	{
		int num = 0, i = 0, j = 1;
		char Name[MAX_name] = { 0 };
		scanf("%s", Name);
		for (i = 0; i < ps->size; i++)
		{
			if (strcmp(ps->data[i].name, Name) != 0)//һ��һ�����Ҳ���
			{
				count++;
			}
			else
			{
				break;
			}
		}
		if (count == ps->size)
		{
			printf("\n���޴���\n\n");
		}
		if (count != ps->size)
		{
			printf("\n������������ϵ��:\n\n");
			for (i = 0; i < ps->size; i++)
			{
				if (strcmp(ps->data[i].name, Name) == 0)
				{
					printf("%d.\t%-10s\t%-9d\t%-8s\t%-17s\n",
						j++,
						ps->data[i].name,
						ps->data[i].age,
						ps->data[i].sex,
						ps->data[i].tele);
					arr[num] = i;
					num++;
				}

			}
			printf("\n");
		}
	}
	else
	{
		printf("ͨѶ¼Ϊ��\n");
	}
	return count;
}
//
//
////count ����
//int count(Con* ps)
//{
//	int count = 0;
//		int count = 0;
//	if (ps->size != 0)
//	{
//		int num = 0, i = 0;
//		char Name[MAX_name] = { 0 };
//		scanf("%s", Name);
//		for (i = 0; i < ps->size; i++)
//		{
//			if (strcmp(ps->data[i].name, Name) != 0)//һ��һ�����Ҳ���
//			{
//				count++;
//			}
//			else
//			{
//				break;
//			}
//		}
//}







//
//int input = 0;
//printf("��������Ҫɾ�������>");
//scanf("%d", &input);
//printf("\t%-10s\t%-9d\t%-8s\t%-17s\n",
//	ps->data[arr[input]].name,
//	ps->data[arr[input]].age,
//	ps->data[arr[input]].sex,
//	ps->data[arr[input]].tele);
