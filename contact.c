#define _CRT_SECURE_NO_WARNINGS 1

#include"contact.h"

int arr[MAX];
void InitContact(Con* ps) 
{
	memset(ps->data, 0, sizeof(ps->data));
	ps->size = 0;//设置只有0个元素
}
//输入函数
void AddCon(Con* ps)
{
	printf("\n");
	printf("请输入名字> ");
	scanf("%s", ps->data[ps->size].name);
	printf("请输入年龄> ");
	scanf("%d", &(ps->data[ps->size].age));
	printf("请输入性别> ");
	scanf("%s", ps->data[ps->size].sex);
	printf("请输入电话> ");
	scanf("%s", ps->data[ps->size].tele);
	ps->size++;
	printf("\n输入成功\n\n");
}
//打印函数
void ShowCon(const Con* ps)
{
	if (ps->size == 0)
	{
		printf("通讯录为空\n");
	}
	else
	{
		int i = 0;
		printf("\n");
		printf("有以下联系人:\n");
		printf("\t%-10s\t%-9s\t%-8s\t%-17s\n", "名字", "年龄", "性别", "电话");
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

//删除函数
void DelCon(Con* ps)
{

	if (ps->size == 0)
	{
		printf("通讯录为空\n");
	}
	else 
	{
		printf("请输入所要删除联系人的名字>");
		int count = SearchCon2(ps);
		if (count != ps->size)
		{
			int input = 0, i = 0;
			printf("请输入你要删除的序号>");
			printf("\n");
			scanf("%d", &input);
		/*	int a = arr[input - 1];*/
			for (i = arr[input - 1]; i < ps->size - 1; i++)
			{
				ps->data[i] = ps->data[i + 1];
			}
			ps->size--;
			printf("\n删除成功\n\n");
		}
	}
}

//查找函数
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
			if (strcmp(ps->data[i].name, Name) != 0)//一个一个比找不到
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
			printf("\n查无此人\n\n");
		}
		if (count != ps->size)
		{
			printf("\n查找有以下联系人:\n\n");
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
		printf("通讯录为空\n");
	}
}


//修改函数
void ModifyCon(Con* ps)
{

	if (ps->size == 0)
	{
		printf("通讯录为空\n");
	}
	else
	{
		printf("\n");
		printf("请输入要修改的联系人姓名>");
		int count = SearchCon2(ps);

		if (count != ps->size)
		{
			int input = 0;
			printf("\n");
			printf("选择你要修改的序号>");
			scanf("%d", &input);
			printf("\n");
			printf("请输入名字> ");
			scanf("%s", ps->data[arr[input - 1]].name),
			printf("请输入年龄> ");
			scanf("%d", &(ps->data[arr[input - 1]].age));
			printf("请输入性别> ");
			scanf("%s", ps->data[arr[input - 1]].sex);
			printf("请输入电话> ");
			scanf("%s", ps->data[arr[input - 1]].tele);

			printf("\n修改成功\n\n");
		}
	}
}
	
//排序函数的qsort中的函数
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
//排序函数
void SortCon(const Con* ps) 
{
	if (ps->size == 0)
	{
		printf("通讯录为空\n");
	}
	else 
	{
		int input = 0;
		printf("请选择排序方法> 1.姓名\t2.年龄\n");
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
		printf("\n排序成功\n\n");
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
			if (strcmp(ps->data[i].name, Name) != 0)//一个一个比找不到
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
			printf("\n查无此人\n\n");
		}
		if (count != ps->size)
		{
			printf("\n查找有以下联系人:\n\n");
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
		printf("通讯录为空\n");
	}
	return count;
}
//
//
////count 函数
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
//			if (strcmp(ps->data[i].name, Name) != 0)//一个一个比找不到
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
//printf("请输入你要删除的序号>");
//scanf("%d", &input);
//printf("\t%-10s\t%-9d\t%-8s\t%-17s\n",
//	ps->data[arr[input]].name,
//	ps->data[arr[input]].age,
//	ps->data[arr[input]].sex,
//	ps->data[arr[input]].tele);
