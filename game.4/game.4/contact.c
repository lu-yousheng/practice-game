#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"

//初始化通讯录结构体
void Init_con(contact* pc)
{
	pc->sz = 0;
	memset(pc->data, 0, sizeof(pc->data));
}

//增加人员
void ADD_Peo(contact* pc)
{
	if (pc->sz == MAX_COUNT)
	{
		printf("数据已满，不能进行增加！\n");
		return;
	}
	printf("请输入姓名：\n");
	scanf("%s", pc->data[pc->sz].name);
	printf("请输入性别：\n");
	scanf("%s", pc->data[pc->sz].sex);
	printf("请输入年龄：\n");
	scanf("%d", &(pc->data[pc->sz].age));
	printf("请输入电话：\n");
	scanf("%s", pc->data[pc->sz].tel);
	printf("请输入地址：\n");
	scanf("%s", pc->data[pc->sz].addr);
	pc->sz++;
	printf("添加成功!\n");

}
//查询
void QUERY_Peo(contact* pc)
{
	printf("%s\t%s\t%s\t%-20s\t%-30s\n", "姓名", "性别", "年龄", "电话", "地址");
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
//查找名字
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
//修改
void REVISE_Peo(contact* pc)
{
	char name[NAME] = { 0 };
	int choose = 0;
	if (pc->sz == 0)
	{
		printf("通讯录没人！\n");
		return;
	}
	printf("请输入你要修改的名字：\n");
	scanf("%s", name);
	//匹配出名字，并将匹配到的下标返回
	int ret = Find_name(pc,name);
	if (ret < 0)
	{
		printf("你输入的名字不存在！\n");
		return;
	}
	else
	{
		printf("%s\t%s\t%s\t%-20s\t%-30s\n", "姓名", "性别", "年龄", "电话", "地址");
		printf("%s\t%s\t%d\t%-20s\t%-30s\n", pc->data[ret].name,
			pc->data[ret].sex,
			pc->data[ret].age,
			pc->data[ret].tel,
			pc->data[ret].addr);
	}
	//printf("请输入姓名：\n");
	//scanf("%s", pc->data[ret].name);
	//printf("请输入性别：\n");
	//scanf("%s", pc->data[ret].sex);
	//printf("请输入年龄：\n");
	//scanf("%d", &(pc->data[ret].age));
	//printf("请输入电话：\n");
	//scanf("%s", pc->data[ret].tel);
	//printf("请输入地址：\n");
	//scanf("%s", pc->data[ret].addr);
	//printf("修改成功!\n");
	do
	{
		printf("请输入你想要修改的数值：\n");
		printf("%-s\t%-s\t%-s\t%-s\t%-s\t%-s\n", "1.姓名", "2.性别", "3.年龄", "4.电话", "5.地址","0.退出");
		scanf("%d", &choose);
		switch (choose)
		{
		case 1:
			printf("请输入姓名：\n");
			scanf("%s", pc->data[ret].name);
			break;
		case 2:
			printf("请输入性别：\n");
			scanf("%s", pc->data[ret].sex);
			break;
		case 3:
			printf("请输入年龄：\n");
			scanf("%d", &(pc->data[ret].age));
			break;
		case 4:
			printf("请输入电话：\n");
			scanf("%s", pc->data[ret].tel);
			break;
		case 5:
			printf("请输入地址：\n");
			scanf("%s", pc->data[ret].addr);
			break;
		default:
			break;
		}
	} while (choose);
}

//删除
void DELET_Peo(contact* pc)
{
	char name[NAME] = { 0 };
	char def[10] = {0};
	if (pc->sz == 0)
	{
		printf("通讯录没人！\n");
		return;
	}
	printf("请输入你要删除的名字：\n");
	scanf("%s", name);
	//匹配出名字，并将匹配到的下标返回
	int ret = Find_name(pc, name);
	if (ret < 0)
	{
		printf("你输入的名字不存在！\n");
		return;
	}
	else
	{
		printf("%s\t%s\t%s\t%-20s\t%-30s\n", "姓名", "性别", "年龄", "电话", "地址");
		printf("%s\t%s\t%d\t%-20s\t%-30s\n", pc->data[ret].name,
			pc->data[ret].sex,
			pc->data[ret].age,
			pc->data[ret].tel,
			pc->data[ret].addr);
	}
	printf("确认删除？yes/no\n");
	scanf("%s", def);
	if (strcmp("yes", def) == 0)
	{
		int i = 0;
		for (i = ret;i < pc->sz;i++)
		{
			pc->data[i] = pc->data[i + 1];
		}
		pc->sz--;
		printf("删除成功！\n");
	}

}

//排序
//int cmp(const void* elem1, const void* elem2)
//{
//	return ((con.data->age)*)elem1 - ((con.data->age)*)elem2;
//}
//void SORT_Peo(const contact* pc)
//{
//	qsort(pc->data, sizeof(pc->data), sizeof(pc->data) / sizeof(pc->data[0]), cmp);
//	printf("%s\t%s\t%s\t%-20s\t%-30s\n", "姓名", "性别", "年龄", "电话", "地址");
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