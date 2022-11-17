#pragma once


#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 1000
#define MAX_name 20
#define MAX_sex 4
#define MAX_tele 12

int arr[MAX];


struct PeopleInfo
{
	char name[MAX_name];
	int age;
	char sex[MAX_sex];
	char tele[MAX_tele];
};

typedef struct Contact
{
	struct PeopleInfo data[MAX];
	int size;
}Con;

enum {
	Exit,
	add,
	del,
	search,
	modify,
	show,
	sort
};

void InitContact(Con* ps);
void AddCon(Con* ps);
void ShowCon(const Con* ps);
void DelCon(Con* ps);
void SearchCon(const Con* ps);
void ModifyCon(Con* ps);
void SortCon(const Con* ps);

int cmp_Con_date_age(const void* e1, const void* e2);
int cmp_Con_date_name(const void* e1, const void* e2);
int SearchCon2(const Con* ps);

//int count(const Con* ps);