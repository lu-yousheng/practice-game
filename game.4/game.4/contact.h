#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define NAME 20 //������󳤶�
#define TEL 15 //�绰��󳤶�
#define SEX 10 //�Ա���󳤶�
#define ADDR 30 //��ַ��󳤶�
#define MAX_COUNT 100 //�ṹ��������󳤶�
#define FIRST 3 //�ʼ���ٵĿռ�����
#define INCREASE 2//����һ�ε�����

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
	PeoInFo * data;
	int sz;
	int capacity;
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
//void SORT_Peo(contact*);
//����ĺ���
void SAVE_CON(contact* );
//��������
void loadcontat(contact*);
//����
void add_cap(contact*);
