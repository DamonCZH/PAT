#include<cstdio>
#include<cstring>
using namespace std;

struct student
{
	char id[20];
	char intime[10];
	char outime[10];
}stu[100];

int main()
{
	//输入同学数量，在循环中输入同学的数据，使用结构数组
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s%s%s", &stu[i].id, &stu[i].intime, &stu[i].outime);
	}

	//对结构数组中的元素进行比较，找出最小进门时间和最大
	//出门时间，同时记录其ID
	int min = 0, max = 0,i;
	for (i = 0; i < n; i++)
	{
		if (strcmp(stu[i].intime,stu[min].intime)<0)
			min = i;
		if (strcmp(stu[i].outime,stu[max].outime)>0)
			max = i;
	}

	//对两位同学的ID进行输出
	printf("%s %s", stu[min].id, stu[max].id);
	return 0;
}