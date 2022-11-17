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
	//创建通讯录
	Con con;
	//初始化通讯录
	InitContact(&con);
	int input = 0;
	do
	{
		menu();
		printf("请选择功能->");
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
				printf("请输入所要查找联系人的名字>");
				SearchCon(&con);
				break;
			}
			else {
				printf("通讯录为空\n");
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
			printf("退出程序");
			break;
		default:
			printf("选择错误，请重新选择\n");
			break;
		}
	} while (input);
	return 0;
}