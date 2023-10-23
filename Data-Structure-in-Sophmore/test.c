#define _CRT_SECURE_NO_WARNINGS 1
#include"seqlist.h"

void SeqListTest1()
{
	SL sl;
	SeqListInit(&sl);
	
	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 4);
	SeqListPushBack(&sl, 5);

	SeqListPrint(&sl);
}

void SeqListTest2()
{
	SL sl;
	SeqListInit(&sl);

	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 1);

	SeqListPopBack(&sl);
	
	SeqListPrint(&sl);
}

void SeqListTest3()
{
	SL sl;
	SeqListInit(&sl);

	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 4);
	SeqListPushBack(&sl, 5);
	SeqListPushBack(&sl, 6);

	SeqListInsert(&sl, 1, -1);
	SeqListInsert(&sl, 6, -1);
	//SeqListInsert(&sl, 0, -17);

	SeqListPrint(&sl);
}
//int main()
//{
//	
//	//SeqListTest1();
//	SeqListTest3();
//
//
//
//	return 0;
//}