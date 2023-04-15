#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"

//��ʼ��ͨѶ¼�ṹ��
//��̬
//void Init_con(contact* pc)
//{
//	pc->sz = 0;
//	memset(pc->data, 0, sizeof(pc->data));
//}

void loadcontat(contact* pc)
{
	FILE* pf = fopen("contact.dat", "r");
	if (pf == NULL)
	{
		perror("loadcontat");
		return;
	}
	PeoInFo tmp = { 0 };
	while (fread(&tmp, sizeof(PeoInFo), 1, pf))
	{
		//�ж�����
		add_cap(pc);
		pc->data[pc->sz] = tmp;
		pc->sz++;
	}
	fclose(pf);
	pf = NULL;
}
//��ʼ��ͨѶ¼�ṹ��
//��̬�汾
void Init_con(contact* pc)
{
	pc->sz = 0;
	pc->data = (PeoInFo*)malloc(sizeof(PeoInFo) * FIRST);
	if (pc->data == NULL)
	{
		perror("Init_con");
	}
	pc->capacity = FIRST;
	//�������ݺ���
	loadcontat(pc);
}
//����
void SAVE_CON(contact* pc)
{
	FILE* pf = fopen("contact.dat", "w");
	if (pf == NULL)
	{
		perror("SAVE_CON");
		return;
	}
	int i = 0;
	for (i = 0;i < pc->sz;i++)
	{
		fwrite(pc->data, sizeof(PeoInFo), 1, pf);
	}
	fclose(pf);
	pf = NULL;
}

//������Ա
//��̬
//void ADD_Peo(contact* pc)
//{
//	if (pc->sz == MAX_COUNT)
//	{
//		printf("�������������ܽ������ӣ�\n");
//		return;
//	}
//	printf("������������\n");
//	scanf("%s", pc->data[pc->sz].name);
//	printf("�������Ա�\n");
//	scanf("%s", pc->data[pc->sz].sex);
//	printf("���������䣺\n");
//	scanf("%d", &(pc->data[pc->sz].age));
//	printf("������绰��\n");
//	scanf("%s", pc->data[pc->sz].tel);
//	printf("�������ַ��\n");
//	scanf("%s", pc->data[pc->sz].addr);
//	pc->sz++;
//	printf("��ӳɹ�!\n");
//
//}
// 
// ����
void add_cap(contact* pc)
{
	PeoInFo* tmp = NULL;
	if (pc->sz == pc->capacity)
	{
		tmp = (PeoInFo*)realloc(pc->data, sizeof(PeoInFo) * (pc->capacity + INCREASE));
		if (tmp != NULL)
		{
			pc->data = tmp;
			pc->capacity += INCREASE;
			printf("���ݳɹ���\n");
		}
	}
}
//������Ա
//��̬
void ADD_Peo(contact* pc)
{
	add_cap(pc);
	printf("������������\n");
	scanf("%s", pc->data[pc->sz].name);
	printf("�������Ա�\n");
	scanf("%s", pc->data[pc->sz].sex);
	printf("���������䣺\n");
	scanf("%d", &(pc->data[pc->sz].age));
	printf("������绰��\n");
	scanf("%s", pc->data[pc->sz].tel);
	printf("�������ַ��\n");
	scanf("%s", pc->data[pc->sz].addr);
	pc->sz++;
	printf("��ӳɹ�!\n");

}

//��ѯ
void QUERY_Peo(contact* pc)
{
	printf("%s\t%s\t%s\t%-20s\t%-30s\n", "����", "�Ա�", "����", "�绰", "��ַ");
	int i = 0;
	for (i = 0;i < pc->sz;i++)
	{
		printf("%s\t%s\t%d\t%-20s\t%-30s\n", pc->data[i].name, 
			pc->data[i].sex, 
			pc->data[i].age,
			pc->data[i].tel,
			pc->data[i].addr);
	}
}
//��������
int Find_name(const contact* pc,const char* name)
{
	int i = 0;
	for (i = 0;i < pc->sz;i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;
}
//�޸�
void REVISE_Peo(contact* pc)
{
	char name[NAME] = { 0 };
	int choose = 0;
	if (pc->sz == 0)
	{
		printf("ͨѶ¼û�ˣ�\n");
		return;
	}
	printf("��������Ҫ�޸ĵ����֣�\n");
	scanf("%s", name);
	//ƥ������֣�����ƥ�䵽���±귵��
	int ret = Find_name(pc,name);
	if (ret < 0)
	{
		printf("����������ֲ����ڣ�\n");
		return;
	}
	else
	{
		printf("%s\t%s\t%s\t%-20s\t%-30s\n", "����", "�Ա�", "����", "�绰", "��ַ");
		printf("%s\t%s\t%d\t%-20s\t%-30s\n", pc->data[ret].name,
			pc->data[ret].sex,
			pc->data[ret].age,
			pc->data[ret].tel,
			pc->data[ret].addr);
	}
	//printf("������������\n");
	//scanf("%s", pc->data[ret].name);
	//printf("�������Ա�\n");
	//scanf("%s", pc->data[ret].sex);
	//printf("���������䣺\n");
	//scanf("%d", &(pc->data[ret].age));
	//printf("������绰��\n");
	//scanf("%s", pc->data[ret].tel);
	//printf("�������ַ��\n");
	//scanf("%s", pc->data[ret].addr);
	//printf("�޸ĳɹ�!\n");
	do
	{
		printf("����������Ҫ�޸ĵ���ֵ��\n");
		printf("%-s\t%-s\t%-s\t%-s\t%-s\t%-s\n", "1.����", "2.�Ա�", "3.����", "4.�绰", "5.��ַ","0.�˳�");
		scanf("%d", &choose);
		switch (choose)
		{
		case 1:
			printf("������������\n");
			scanf("%s", pc->data[ret].name);
			break;
		case 2:
			printf("�������Ա�\n");
			scanf("%s", pc->data[ret].sex);
			break;
		case 3:
			printf("���������䣺\n");
			scanf("%d", &(pc->data[ret].age));
			break;
		case 4:
			printf("������绰��\n");
			scanf("%s", pc->data[ret].tel);
			break;
		case 5:
			printf("�������ַ��\n");
			scanf("%s", pc->data[ret].addr);
			break;
		default:
			break;
		}
	} while (choose);
}

//ɾ��
void DELET_Peo(contact* pc)
{
	char name[NAME] = { 0 };
	char def[10] = {0};
	if (pc->sz == 0)
	{
		printf("ͨѶ¼û�ˣ�\n");
		return;
	}
	printf("��������Ҫɾ�������֣�\n");
	scanf("%s", name);
	//ƥ������֣�����ƥ�䵽���±귵��
	int ret = Find_name(pc, name);
	if (ret < 0)
	{
		printf("����������ֲ����ڣ�\n");
		return;
	}
	else
	{
		printf("%s\t%s\t%s\t%-20s\t%-30s\n", "����", "�Ա�", "����", "�绰", "��ַ");
		printf("%s\t%s\t%d\t%-20s\t%-30s\n", pc->data[ret].name,
			pc->data[ret].sex,
			pc->data[ret].age,
			pc->data[ret].tel,
			pc->data[ret].addr);
	}
	printf("ȷ��ɾ����yes/no\n");
	scanf("%s", def);
	if (strcmp("yes", def) == 0)
	{
		int i = 0;
		for (i = ret;i < pc->sz;i++)
		{
			pc->data[i] = pc->data[i + 1];
		}
		pc->sz--;
		printf("ɾ���ɹ���\n");
	}

}

//����
//int cmp(const void* elem1, const void* elem2)
//{
//	return ((con.data->age)*)elem1 - ((con.data->age)*)elem2;
//}
//void SORT_Peo(const contact* pc)
//{
//	qsort(pc->data, sizeof(pc->data), sizeof(pc->data) / sizeof(pc->data[0]), cmp);
//	printf("%s\t%s\t%s\t%-20s\t%-30s\n", "����", "�Ա�", "����", "�绰", "��ַ");
//	int i = 0;
//	for (i = 0;i <pc->sz;i++)
//	{
//		printf("%s\t%s\t%d\t%-20s\t%-30s\n", pc->data[i].name,
//			pc->data[i].sex,
//			pc->data[i].age,
//			pc->data[i].tel,
//			pc->data[i].addr);
//
//	}
//}