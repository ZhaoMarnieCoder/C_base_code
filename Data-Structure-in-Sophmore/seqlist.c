#define _CRT_SECURE_NO_WARNINGS 1


#include"seqlist.h"

void SeqListInit(SL* ps)
{
	assert(ps);

	ps->a = NULL;
	ps->size = 0;
	ps->capacity = 0;
}

void SeqListDestory(SL* ps)
{
	assert(ps);

	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->size = 0;
}

// 检查容器是否满了
void SeqListCheckCapacity(SL* ps)
{
	assert(ps);

	// 满了之后进行扩容
	if (ps->size == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SQDataType* tmp = (SQDataType*)realloc(ps->a, newcapacity * sizeof(SQDataType));
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);

		}
		else
		{
			ps->a = tmp;
			ps->capacity = newcapacity;
		}
	}
}

void SeqListPushBack(SL* ps, SQDataType x)
{
	assert(ps);
	SeqListCheckCapacity(ps);


	ps->a[ps->size] = x;
	ps->size++;

}

void SeqListPopBack(SL* ps)
{
	assert(ps);

	
	ps->size--;
}


void SeqListInsert(SL* ps, int pos, SQDataType x)
{
	assert(ps);

	SeqListCheckCapacity(ps);

	int end = ps->size;
	while (end >= pos)
	{
		ps->a[end] = ps->a[end - 1];
		end--;
	}
	ps->a[pos] = x;
	ps->size++;
}

void SeqListPrint(SL* ps)
{
	assert(ps);

	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);

	}
	printf("\n");
}