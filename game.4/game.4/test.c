#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"


void menu()
{
	printf("**********************************\n");
	printf("******** 1. ����   2.�޸� ********\n");
	printf("******** 3. ɾ��   4.��ѯ ********\n");
	printf("******** 5. ����   0.�˳� ********\n");
	printf("**********************************\n");
}
enum option
{
	EXIT,
	ADD,
	REVISE,
	DELET,
	QUERY,
	SORT
};
int main(void)
{
	contact con;
	//��ʼ��ͨѶ¼
	Init_con(&con);
	int input = 0;
	do
	{
		menu();
		printf("��ѡ��->\n");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			ADD_Peo(&con);
			break;
		case REVISE:
			REVISE_Peo(&con);
			break;
		case DELET:
			DELET_Peo(&con);
			break;
		case QUERY:
			QUERY_Peo(&con);
			break;
		case SORT:
			SORT_Peo(&con);
			break;
		default:
			break;
		}

	} while (input);
	return 0;
}