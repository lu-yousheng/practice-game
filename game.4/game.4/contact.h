#pragma once
#include<stdio.h>
#include<string.h>

#define NAME 20 //������󳤶�
#define TEL 15 //�绰��󳤶�
#define SEX 10 //�Ա���󳤶�
#define ADDR 30 //��ַ��󳤶�
#define MAX_COUNT 100 //�ṹ��������󳤶�

//����ͨѶ¼����ÿ���˵�����
typedef struct PeoInFo
{
	char name[NAME];
	char sex[SEX];
	int age;
	char tel[TEL];
	char addr[ADDR];
}PeoInFo;

//����ͨ��¼����
typedef struct contact
{
	PeoInFo data[MAX_COUNT];
	int sz;
}contact;
//contact con;

//��ʼ��ͨѶ¼�ṹ��
void Init_con(contact* );
//����
void ADD_Peo(contact*);
//��ѯ
void QUERY_Peo(contact*);
//�޸�
void REVISE_Peo(contact*);
//������������
int Find_name(const contact*,const char*);
//ɾ��
void DELET_Peo(contact* );
//����
void SORT_Peo(contact*);