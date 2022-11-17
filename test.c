#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"

int arr[MAX];


void menu()
{
	printf("###################################\n");
	printf("###    1.add         2.del      ###\n");
	printf("###    3.search      4.modify   ###\n");
	printf("###    5.show        6.sort     ###\n");
	printf("###    0.Exit                   ###\n");
	printf("###################################\n");
}


int main()
{
	//����ͨѶ¼
	Con con;
	//��ʼ��ͨѶ¼
	InitContact(&con);
	int input = 0;
	do
	{
		menu();
		printf("��ѡ����->");
		scanf("%d", &input);
		switch (input)
		{
		case add:
			AddCon(&con);
			break;
		case del:
			DelCon(&con);
			break;
		case search:
			if (con.size != 0)
			{
				printf("��������Ҫ������ϵ�˵�����>");
				SearchCon(&con);
				break;
			}
			else {
				printf("ͨѶ¼Ϊ��\n");
				break;
			}
		case modify:
			ModifyCon(&con);
			break;
		case show:
			ShowCon(&con);
			break;
		case sort:
			SortCon(&con);
			break;
		case Exit:
			printf("�˳�����");
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}
	} while (input);
	return 0;
}