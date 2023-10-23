#pragma once

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>


typedef int	SQDataType;

typedef struct SeqList
{
	SQDataType* a; 
	int size; // 实际放数据的容量
	int capacity; //容器的最大容量

}SL;

// 增删改查等接口函数
void SeqListInit(SL* ps);  // 初始化
void SeqListPrint(SL* ps);  // 打印顺序表
void SeqListDestory(SL* ps); // 顺序表的销毁

void SeqListPushBack(SL* ps, SQDataType x); // 尾插
void SeqListPushFront(SL* ps, SQDataType x); // 头插
void SeqListPopBack(SL* ps); // 尾删
void SeqListPopFront(SL* ps); // 头删
void SeqListInsert(SL* ps, int pos, SQDataType x); // 定一个位置的插
void SeqListErase(SL* ps, int pos); // 删除指定位置的数据

int SeqListFind(SL* ps, SQDataType x); // 查询数据
void SeqListModity(SL* ps, int pos, SQDataType x); // 修改指定数据

