#pragma once
#include<stdio.h>
#include<string.h>

#define NAME 20 //名字最大长度
#define TEL 15 //电话最大长度
#define SEX 10 //性别最大长度
#define ADDR 30 //地址最大长度
#define MAX_COUNT 100 //结构体数组最大长度

//定义通讯录里面每个人的类型
typedef struct PeoInFo
{
	char name[NAME];
	char sex[SEX];
	int age;
	char tel[TEL];
	char addr[ADDR];
}PeoInFo;

//定义通信录类型
typedef struct contact
{
	PeoInFo data[MAX_COUNT];
	int sz;
}contact;
//contact con;

//初始化通讯录结构体
void Init_con(contact* );
//增加
void ADD_Peo(contact*);
//查询
void QUERY_Peo(contact*);
//修改
void REVISE_Peo(contact*);
//根据人名查找
int Find_name(const contact*,const char*);
//删除
void DELET_Peo(contact* );
//排序
void SORT_Peo(contact*);