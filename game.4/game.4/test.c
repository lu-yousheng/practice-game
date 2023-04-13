#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"


void menu()
{
	printf("**********************************\n");
	printf("******** 1. 增加   2.修改 ********\n");
	printf("******** 3. 删除   4.查询 ********\n");
	printf("******** 5. 排序   0.退出 ********\n");
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
	//初始化通讯录
	Init_con(&con);
	int input = 0;
	do
	{
		menu();
		printf("请选择->\n");
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