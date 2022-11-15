#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>


int my_strlen(const char* str)
{
	assert(str != NULL);
	if (*str == '\0')
	{
		return 0;
	}
	else
	{
		return 1 + my_strlen(str + 1);
	}
}

int main()
{
	char arr[] = "abcdef";
	printf("%d ", my_strlen(arr));

	return 0;
}